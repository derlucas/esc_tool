/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "pageappnrf.h"
#include "ui_pageappnrf.h"

PageAppNrf::PageAppNrf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageAppNrf)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;
}

PageAppNrf::~PageAppNrf()
{
    delete ui;
}

VescInterface *PageAppNrf::vesc() const
{
    return mVesc;
}

void PageAppNrf::setVesc(VescInterface *vesc)
{
    mVesc = vesc;

    if (mVesc) {
        ui->nrfPair->setVesc(mVesc);

        ui->generalTab->addRowSeparator(tr("Radio"));
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_nrf_conf.power");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_nrf_conf.speed");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_nrf_conf.channel");
        ui->generalTab->addRowSeparator(tr("Integrity"));
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_nrf_conf.crc_type");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_nrf_conf.send_crc_ack");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_nrf_conf.retry_delay");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_nrf_conf.retries");
        ui->generalTab->addRowSeparator(tr("Address"));
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_nrf_conf.address_0");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_nrf_conf.address_1");
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_nrf_conf.address_2");
    }
}
