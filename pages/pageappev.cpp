/**
 * This file is part of ESC Tool
 *
 *  Copyright 2017 by Lucas Pless
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "pageappev.h"
#include "ui_pageappev.h"
#include "util.h"

PageAppEv::PageAppEv(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageAppEv)
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

PageAppEv::~PageAppEv()
{
    delete ui;
}

VescInterface *PageAppEv::vesc() const
{
    return mVesc;
}

void PageAppEv::setVesc(VescInterface *vesc)
{
    mVesc = vesc;

    if (mVesc) {
        ui->generalTab->addRowSeparator(tr("General App work&feel"));
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_ev_conf.use_filter");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_ev_conf.update_rate_hz");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_ev_conf.ramp_time_pos");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_ev_conf.ramp_time_neg");
        ui->mappingTab->addParamRow(mVesc->appConfig(), "app_ev_conf.hyst");

        ui->generalTab->addRowSeparator(tr("Wheel and EV Config"));
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_ev_conf.use_display");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_ev_conf.use_pas");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_ev_conf.wheel_perimeter");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_ev_conf.pulse_per_revolution");

        ui->generalTab->addParamRow(mVesc->appConfig(), "app_ev_conf.use_throttle");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_ev_conf.use_throttle_brake");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_ev_conf.use_display_vmax");


        ui->generalTab->addRowSeparator(tr("Power Modes (0: off)"));
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_ev_conf.mode_1_current");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_ev_conf.mode_2_current");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_ev_conf.mode_3_current");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_ev_conf.mode_4_current");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_ev_conf.mode_5_current");



        ui->mappingTab->addRowSeparator(tr("ADC 1"));
        ui->mappingTab->addParamRow(mVesc->appConfig(), "app_ev_conf.voltage1_start");
        ui->mappingTab->addParamRow(mVesc->appConfig(), "app_ev_conf.voltage1_end");

        ui->mappingTab->addRowSeparator(tr("ADC 2"));
        ui->mappingTab->addParamRow(mVesc->appConfig(), "app_ev_conf.voltage2_start");
        ui->mappingTab->addParamRow(mVesc->appConfig(), "app_ev_conf.voltage2_end");



        ui->throttleCurveTab->addParamRow(mVesc->appConfig(), "app_ev_conf.throttle_exp");
        ui->throttleCurveTab->addParamRow(mVesc->appConfig(), "app_ev_conf.throttle_exp_brake");
        ui->throttleCurveTab->addParamRow(mVesc->appConfig(), "app_ev_conf.throttle_exp_mode");

        ui->adcMap->setVesc(mVesc);

        connect(mVesc->appConfig(), SIGNAL(paramChangedDouble(QObject*,QString,double)),
                this, SLOT(paramChangedDouble(QObject*,QString,double)));
        connect(mVesc->appConfig(), SIGNAL(paramChangedEnum(QObject*,QString,int)),
                this, SLOT(paramChangedEnum(QObject*,QString,int)));

        paramChangedEnum(0, "app_ev_conf.throttle_exp_mode", 0);
    }
}

void PageAppEv::paramChangedDouble(QObject *src, QString name, double newParam)
{
    (void)src;
    (void)newParam;

    if (name == "app_ev_conf.throttle_exp" || name == "app_ev_conf.throttle_exp_brake") {
        int mode = mVesc->appConfig()->getParamEnum("app_ev_conf.throttle_exp_mode");
        float val_acc = mVesc->appConfig()->getParamDouble("app_ev_conf.throttle_exp");
        float val_brake = mVesc->appConfig()->getParamDouble("app_ev_conf.throttle_exp_brake");

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

void PageAppEv::paramChangedEnum(QObject *src, QString name, int newParam)
{
    (void)src;
    (void)newParam;

    if (name == "app_ev_conf.throttle_exp_mode") {
        paramChangedDouble(0, "app_ev_conf.throttle_exp", 0.0);
    }
}
