/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "pageappadc.h"
#include "ui_pageappadc.h"
#include "util.h"

PageAppAdc::PageAppAdc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageAppAdc)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;

    ui->throttlePlot->addGraph();
    ui->throttlePlot->graph()->setName("Throttle Curve");
    ui->throttlePlot->xAxis->setLabel("Throttle Value");
    ui->throttlePlot->yAxis->setLabel("Output Value");
    ui->throttlePlot->legend->setVisible(true);
    ui->throttlePlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignRight|Qt::AlignBottom);
}

PageAppAdc::~PageAppAdc()
{
    delete ui;
}

VescInterface *PageAppAdc::vesc() const
{
    return mVesc;
}

void PageAppAdc::setVesc(VescInterface *vesc)
{
    mVesc = vesc;

    if (mVesc) {
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_adc_conf.ctrl_type");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_adc_conf.use_filter");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_adc_conf.safe_start");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_adc_conf.cc_button_inverted");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_adc_conf.rev_button_inverted");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_adc_conf.update_rate_hz");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_adc_conf.ramp_time_pos");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_adc_conf.ramp_time_neg");
        ui->generalTab->addRowSeparator(tr("Multiple ESCs over CAN-bus"));
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_adc_conf.multi_esc");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_adc_conf.tc");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_adc_conf.tc_max_diff");

        ui->mappingTab->addParamRow(mVesc->appConfig(), "app_adc_conf.hyst");
        ui->mappingTab->addRowSeparator(tr("ADC 1"));
        ui->mappingTab->addParamRow(mVesc->appConfig(), "app_adc_conf.voltage_start");
        ui->mappingTab->addParamRow(mVesc->appConfig(), "app_adc_conf.voltage_end");
        ui->mappingTab->addParamRow(mVesc->appConfig(), "app_adc_conf.voltage_center");
        ui->mappingTab->addParamRow(mVesc->appConfig(), "app_adc_conf.voltage_inverted");
        ui->mappingTab->addRowSeparator(tr("ADC 2"));
        ui->mappingTab->addParamRow(mVesc->appConfig(), "app_adc_conf.voltage2_start");
        ui->mappingTab->addParamRow(mVesc->appConfig(), "app_adc_conf.voltage2_end");
        ui->mappingTab->addParamRow(mVesc->appConfig(), "app_adc_conf.voltage2_inverted");

        ui->throttleCurveTab->addParamRow(mVesc->appConfig(), "app_adc_conf.throttle_exp");
        ui->throttleCurveTab->addParamRow(mVesc->appConfig(), "app_adc_conf.throttle_exp_brake");
        ui->throttleCurveTab->addParamRow(mVesc->appConfig(), "app_adc_conf.throttle_exp_mode");

        ui->adcMap->setVesc(mVesc);

        connect(mVesc->appConfig(), SIGNAL(paramChangedDouble(QObject*,QString,double)),
                this, SLOT(paramChangedDouble(QObject*,QString,double)));
        connect(mVesc->appConfig(), SIGNAL(paramChangedEnum(QObject*,QString,int)),
                this, SLOT(paramChangedEnum(QObject*,QString,int)));

        paramChangedEnum(0, "app_adc_conf.throttle_exp_mode", 0);
    }
}

void PageAppAdc::paramChangedDouble(QObject *src, QString name, double newParam)
{
    (void)src;
    (void)newParam;

    if (name == "app_adc_conf.throttle_exp" || name == "app_adc_conf.throttle_exp_brake") {
        int mode = mVesc->appConfig()->getParamEnum("app_adc_conf.throttle_exp_mode");
        float val_acc = mVesc->appConfig()->getParamDouble("app_adc_conf.throttle_exp");
        float val_brake = mVesc->appConfig()->getParamDouble("app_adc_conf.throttle_exp_brake");

        QVector<double> x;
        QVector<double> y;
        for (float i = -1.0;i < 1.0001;i += 0.002) {
            x.append(i);
            double val = util::throttle_curve(i, val_acc, val_brake, mode);
            y.append(val);
        }
        ui->throttlePlot->graph()->setData(x, y);
        ui->throttlePlot->rescaleAxes();
        ui->throttlePlot->replot();
    }
}

void PageAppAdc::paramChangedEnum(QObject *src, QString name, int newParam)
{
    (void)src;
    (void)newParam;

    if (name == "app_adc_conf.throttle_exp_mode") {
        paramChangedDouble(0, "app_adc_conf.throttle_exp", 0.0);
    }
}
