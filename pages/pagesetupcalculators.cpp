/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "pagesetupcalculators.h"
#include "ui_pagesetupcalculators.h"

PageSetupCalculators::PageSetupCalculators(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageSetupCalculators)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;

}

PageSetupCalculators::~PageSetupCalculators()
{
    delete ui;
}

void PageSetupCalculators::on_addSetupButton_clicked()
{

}

void PageSetupCalculators::on_removeSetupButton_clicked()
{

}

VescInterface *PageSetupCalculators::vesc() const
{
    return mVesc;
}

void PageSetupCalculators::setVesc(VescInterface *vesc)
{
    mVesc = vesc;
}
