/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "pagemotor.h"
#include "ui_pagemotor.h"

PageMotor::PageMotor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageMotor)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;
}

PageMotor::~PageMotor()
{
    delete ui;
}

VescInterface *PageMotor::vesc() const
{
    return mVesc;
}

void PageMotor::setVesc(VescInterface *vesc)
{
    mVesc = vesc;

    if (mVesc) {
        ui->batteryCalc->setVesc(mVesc);

        ui->motorTab->addParamRow(mVesc->mcConfig(), "motor_type");
        ui->motorTab->addParamRow(mVesc->mcConfig(), "m_invert_direction");
        ui->motorTab->addParamRow(mVesc->mcConfig(), "m_sensor_port_mode");
        ui->motorTab->addParamRow(mVesc->mcConfig(), "m_encoder_counts");

        ui->currentTab->addRowSeparator(tr("Motor"));
        ui->currentTab->addParamRow(mVesc->mcConfig(), "l_current_max");
        ui->currentTab->addParamRow(mVesc->mcConfig(), "l_current_min");
        ui->currentTab->addParamRow(mVesc->mcConfig(), "l_abs_current_max");
        ui->currentTab->addParamRow(mVesc->mcConfig(), "l_slow_abs_current");
        ui->currentTab->addRowSeparator(tr("Battery"));
        ui->currentTab->addParamRow(mVesc->mcConfig(), "l_in_current_max");
        ui->currentTab->addParamRow(mVesc->mcConfig(), "l_in_current_min");
        ui->currentTab->addRowSeparator(tr("DRV8301"));
        ui->currentTab->addParamRow(mVesc->mcConfig(), "m_drv8301_oc_mode");
        ui->currentTab->addParamRow(mVesc->mcConfig(), "m_drv8301_oc_adj");

        ui->voltageTab->addParamRow(mVesc->mcConfig(), "l_battery_cut_start");
        ui->voltageTab->addParamRow(mVesc->mcConfig(), "l_battery_cut_end");

        ui->rpmTab->addParamRow(mVesc->mcConfig(), "l_max_erpm");
        ui->rpmTab->addParamRow(mVesc->mcConfig(), "l_min_erpm");
        ui->rpmTab->addParamRow(mVesc->mcConfig(), "l_erpm_start");

        ui->wattageTab->addParamRow(mVesc->mcConfig(), "l_watt_max");
        ui->wattageTab->addParamRow(mVesc->mcConfig(), "l_watt_min");

        ui->tempTab->addRowSeparator(tr("MOSFET"));
        ui->tempTab->addParamRow(mVesc->mcConfig(), "l_temp_fet_start");
        ui->tempTab->addParamRow(mVesc->mcConfig(), "l_temp_fet_end");
        ui->tempTab->addRowSeparator(tr("Motor"));
        ui->tempTab->addParamRow(mVesc->mcConfig(), "l_temp_motor_start");
        ui->tempTab->addParamRow(mVesc->mcConfig(), "l_temp_motor_end");

        ui->advancedTab->addParamRow(mVesc->mcConfig(), "l_min_vin");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "l_max_vin");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "l_min_duty");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "l_max_duty");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "cc_min_current");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "m_fault_stop_time_ms");
    }
}
