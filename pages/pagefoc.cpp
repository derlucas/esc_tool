/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "pagefoc.h"
#include "ui_pagefoc.h"

PageFoc::PageFoc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageFoc)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;
}

PageFoc::~PageFoc()
{
    delete ui;
}

VescInterface *PageFoc::vesc() const
{
    return mVesc;
}

void PageFoc::setVesc(VescInterface *vesc)
{
    mVesc = vesc;

    if (mVesc) {
        ui->detectFoc->setVesc(mVesc);
        ui->detectFocHall->setVesc(mVesc);
        ui->detectFocEncoder->setVesc(mVesc);

        ui->generalTab->addParamRow(mVesc->mcConfig(), "foc_sensor_mode");
        ui->generalTab->addParamRow(mVesc->mcConfig(), "foc_motor_r");
        ui->generalTab->addParamRow(mVesc->mcConfig(), "foc_motor_l");
        ui->generalTab->addParamRow(mVesc->mcConfig(), "foc_motor_flux_linkage");
        ui->generalTab->addParamRow(mVesc->mcConfig(), "foc_current_kp");
        ui->generalTab->addParamRow(mVesc->mcConfig(), "foc_current_ki");
        ui->generalTab->addParamRow(mVesc->mcConfig(), "foc_observer_gain");

        ui->sensorlessTab->addParamRow(mVesc->mcConfig(), "foc_openloop_rpm");
        ui->sensorlessTab->addParamRow(mVesc->mcConfig(), "foc_sl_openloop_hyst");
        ui->sensorlessTab->addParamRow(mVesc->mcConfig(), "foc_sl_openloop_time");
        ui->sensorlessTab->addParamRow(mVesc->mcConfig(), "foc_sat_comp");
        ui->sensorlessTab->addParamRow(mVesc->mcConfig(), "foc_temp_comp");
        ui->sensorlessTab->addParamRow(mVesc->mcConfig(), "foc_temp_comp_base_temp");

        ui->hallTab->addParamRow(mVesc->mcConfig(), "foc_sl_erpm");
        ui->hallTab->addParamRow(mVesc->mcConfig(), "foc_hall_table_0");
        ui->hallTab->addParamRow(mVesc->mcConfig(), "foc_hall_table_1");
        ui->hallTab->addParamRow(mVesc->mcConfig(), "foc_hall_table_2");
        ui->hallTab->addParamRow(mVesc->mcConfig(), "foc_hall_table_3");
        ui->hallTab->addParamRow(mVesc->mcConfig(), "foc_hall_table_4");
        ui->hallTab->addParamRow(mVesc->mcConfig(), "foc_hall_table_5");
        ui->hallTab->addParamRow(mVesc->mcConfig(), "foc_hall_table_6");
        ui->hallTab->addParamRow(mVesc->mcConfig(), "foc_hall_table_7");

        ui->encoderTab->addParamRow(mVesc->mcConfig(), "foc_sl_erpm");
        ui->encoderTab->addParamRow(mVesc->mcConfig(), "foc_encoder_offset");
        ui->encoderTab->addParamRow(mVesc->mcConfig(), "foc_encoder_ratio");
        ui->encoderTab->addParamRow(mVesc->mcConfig(), "foc_encoder_inverted");

        ui->advancedTab->addParamRow(mVesc->mcConfig(), "foc_f_sw");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "foc_dt_us");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "foc_pll_kp");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "foc_pll_ki");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "foc_duty_dowmramp_kp");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "foc_duty_dowmramp_ki");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "foc_sl_d_current_duty");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "foc_sl_d_current_factor");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "foc_sample_v0_v7");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "foc_sample_high_current");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "foc_observer_gain_slow");
    }
}
