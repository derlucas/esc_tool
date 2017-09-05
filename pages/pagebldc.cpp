/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "pagebldc.h"
#include "ui_pagebldc.h"

PageBldc::PageBldc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageBldc)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;
}

PageBldc::~PageBldc()
{
    delete ui;
}

VescInterface *PageBldc::vesc() const
{
    return mVesc;
}

void PageBldc::setVesc(VescInterface *vesc)
{
    mVesc = vesc;

    if (mVesc) {
        ui->detectBldc->setVesc(mVesc);

        ui->generalTab->addParamRow(mVesc->mcConfig(), "sensor_mode");
        ui->generalTab->addParamRow(mVesc->mcConfig(), "comm_mode");
        ui->generalTab->addParamRow(mVesc->mcConfig(), "cc_startup_boost_duty");

        ui->sensorlessTab->addParamRow(mVesc->mcConfig(), "sl_cycle_int_limit");
        ui->sensorlessTab->addParamRow(mVesc->mcConfig(), "sl_min_erpm");
        ui->sensorlessTab->addParamRow(mVesc->mcConfig(), "sl_min_erpm_cycle_int_limit");
        ui->sensorlessTab->addParamRow(mVesc->mcConfig(), "sl_bemf_coupling_k");

        ui->sensorTab->addParamRow(mVesc->mcConfig(), "hall_sl_erpm");
        for (int i = 0;i < 8;i++) {
            QString str;
            str.sprintf("hall_table_%d", i);
            ui->sensorTab->addParamRow(mVesc->mcConfig(), str);
        }

        ui->advancedTab->addParamRow(mVesc->mcConfig(), "sl_phase_advance_at_br");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "sl_cycle_int_rpm_br");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "pwm_mode");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "cc_gain");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "cc_ramp_step_max");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "m_duty_ramp_step");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "m_current_backoff_gain");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "m_bldc_f_sw_min");
        ui->advancedTab->addParamRow(mVesc->mcConfig(), "m_bldc_f_sw_max");
    }
}
