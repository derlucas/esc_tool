/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "pagemotorsettings.h"
#include "ui_pagemotorsettings.h"
#include "setupwizardmotor.h"

PageMotorSettings::PageMotorSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageMotorSettings)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;
}

PageMotorSettings::~PageMotorSettings()
{
    delete ui;
}

VescInterface *PageMotorSettings::vesc() const
{
    return mVesc;
}

void PageMotorSettings::setVesc(VescInterface *vesc)
{
    mVesc = vesc;

    if (mVesc) {
        ConfigParam *p = mVesc->infoConfig()->getParam("motor_setting_description");
        if (p != 0) {
            ui->textEdit->setHtml(p->description);
        } else {
            ui->textEdit->setText("Motor Setting Description not found.");
        }
    }
}

void PageMotorSettings::on_motorSetupWizardButton_clicked()
{
    if (mVesc) {
        SetupWizardMotor w(mVesc, this);
        w.exec();
    }
}
