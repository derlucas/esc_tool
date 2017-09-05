/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "pageappuart.h"
#include "ui_pageappuart.h"

PageAppUart::PageAppUart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageAppUart)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;
}

PageAppUart::~PageAppUart()
{
    delete ui;
}

VescInterface *PageAppUart::vesc() const
{
    return mVesc;
}

void PageAppUart::setVesc(VescInterface *vesc)
{
    mVesc = vesc;

    if (mVesc) {
        ui->generalTab->addParamRow(mVesc->appConfig(), "app_uart_baudrate");
    }
}
