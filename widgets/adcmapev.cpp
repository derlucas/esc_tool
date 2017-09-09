/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "adcmapev.h"
#include "ui_adcmapev.h"
#include "helpdialog.h"
#include <QMessageBox>

AdcMapEv::AdcMapEv(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdcMapEv)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;
    mResetDone = true;
    ui->displayCh1->setDual(false);
}

AdcMapEv::~AdcMapEv()
{
    delete ui;
}

VescInterface *AdcMapEv::vesc() const
{
    return mVesc;
}

void AdcMapEv::setVesc(VescInterface *vesc)
{
    mVesc = vesc;

    if (mVesc) {
    
        connect(mVesc->commands(), SIGNAL(decodedEvReceived(double,double,double,double)),
                this, SLOT(decodedEvReceived(double,double,double,double)));
    }
}

void AdcMapEv::decodedEvReceived(double value1, double voltage1, double value2, double voltage2)
{

    double p = value1 * 100.0;

    ui->displayCh1->setValue(p);
    ui->displayCh1->setText(tr("%1 V (%2 %)").
                            arg(voltage1, 0, 'f', 4).
                            arg(p, 0, 'f', 1));


    p = value2 * 100.0;

    ui->displayCh2->setValue(p);
    ui->displayCh2->setText(tr("%1 V (%2 %)").
                            arg(voltage2, 0, 'f', 4).
                            arg(p, 0, 'f', 1));


    if (mResetDone) {
        mResetDone = false;
        ui->minCh1Box->setValue(voltage1);
        ui->maxCh1Box->setValue(voltage1);
        ui->minCh2Box->setValue(voltage2);
        ui->maxCh2Box->setValue(voltage2);
    } else {
        if (voltage1 < ui->minCh1Box->value()) {
            ui->minCh1Box->setValue(voltage1);
        }

        if (voltage1 > ui->maxCh1Box->value()) {
            ui->maxCh1Box->setValue(voltage1);
        }

        if (voltage2 < ui->minCh2Box->value()) {
            ui->minCh2Box->setValue(voltage2);
        }

        if (voltage2 > ui->maxCh2Box->value()) {
            ui->maxCh2Box->setValue(voltage2);
        }
    }


}

void AdcMapEv::on_helpButton_clicked()
{
    if (mVesc) {
        HelpDialog::showHelp(this, mVesc->infoConfig(), "app_adc_mapping_help");
    }
}

void AdcMapEv::on_resetButton_clicked()
{
    mResetDone = true;
    ui->minCh1Box->setValue(0.0);
    ui->maxCh1Box->setValue(0.0);
    ui->minCh2Box->setValue(0.0);
    ui->maxCh2Box->setValue(0.0);
}

void AdcMapEv::on_applyButton_clicked()
{
    if (mVesc) {
        if (ui->maxCh1Box->value() > 1e-10) {
            mVesc->appConfig()->updateParamDouble("app_ev_conf.voltage1_start", ui->minCh1Box->value());
            mVesc->appConfig()->updateParamDouble("app_ev_conf.voltage1_end", ui->maxCh1Box->value());
            mVesc->appConfig()->updateParamDouble("app_ev_conf.voltage2_start", ui->minCh2Box->value());
            mVesc->appConfig()->updateParamDouble("app_ev_conf.voltage2_end", ui->maxCh2Box->value());
            mVesc->emitStatusMessage(tr("Start and End ADC Voltages Applied"), true);
        } else {
            mVesc->emitStatusMessage(tr("Applying Pulselengths Failed"), false);
            QMessageBox::warning(this,
                                 tr("Apply Voltages"),
                                 tr("Please activate RT app data and measure the ADC voltages first."));
        }
    }
}
