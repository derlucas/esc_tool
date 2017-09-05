/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "pagecontrollers.h"
#include "ui_pagecontrollers.h"

PageControllers::PageControllers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageControllers)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;
}

PageControllers::~PageControllers()
{
    delete ui;
}

VescInterface *PageControllers::vesc() const
{
    return mVesc;
}

void PageControllers::setVesc(VescInterface *vesc)
{
    mVesc = vesc;

    if (mVesc) {
        ui->paramTab->addRowSeparator(tr("Speed Controller"));
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_pid_kp");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_pid_ki");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_pid_kd");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_pid_min_erpm");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "s_pid_allow_braking");

        ui->paramTab->addRowSeparator(tr("Position Controller"));
        ui->paramTab->addParamRow(mVesc->mcConfig(), "p_pid_kp");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "p_pid_ki");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "p_pid_kd");
        ui->paramTab->addParamRow(mVesc->mcConfig(), "p_pid_ang_div");
    }
}
