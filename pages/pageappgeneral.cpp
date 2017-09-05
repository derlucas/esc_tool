/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "pageappgeneral.h"
#include "ui_pageappgeneral.h"

PageAppGeneral::PageAppGeneral(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageAppGeneral)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;
}

PageAppGeneral::~PageAppGeneral()
{
    delete ui;
}

VescInterface *PageAppGeneral::vesc() const
{
    return mVesc;
}

void PageAppGeneral::setVesc(VescInterface *vesc)
{
    mVesc = vesc;

    if (mVesc) {
        ui->appTab->addParamRow(mVesc->appConfig(), "app_to_use");
        ui->appTab->addParamRow(mVesc->appConfig(), "controller_id");
        ui->appTab->addParamRow(mVesc->appConfig(), "timeout_msec");
        ui->appTab->addParamRow(mVesc->appConfig(), "timeout_brake_current");
        ui->appTab->addParamRow(mVesc->appConfig(), "send_can_status");
        ui->appTab->addParamRow(mVesc->appConfig(), "send_can_status_rate_hz");
    }
}
