/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "pagedc.h"
#include "ui_pagedc.h"

PageDc::PageDc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageDc)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;
}

PageDc::~PageDc()
{
    delete ui;
}

VescInterface *PageDc::vesc() const
{
    return mVesc;
}

void PageDc::setVesc(VescInterface *vesc)
{
    mVesc = vesc;

    if (mVesc) {
        ui->paramTab->addParamRow(mVesc->mcConfig(), "cc_gain");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "cc_ramp_step_max");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "m_duty_ramp_step");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "m_current_backoff_gain");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "m_dc_f_sw");
    }
}
