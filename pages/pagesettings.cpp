/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "pagesettings.h"
#include "ui_pagesettings.h"

PageSettings::PageSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageSettings)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);

    if (mSettings.contains("app_scale_factor")) {
        ui->uiScaleBox->setValue(mSettings.value("app_scale_factor").toDouble());
    }

    if (mSettings.contains("app_scale_auto")) {
        ui->uiAutoScaleBox->setChecked(mSettings.value("app_scale_auto").toBool());
    }

    ui->uiScaleBox->setEnabled(!ui->uiAutoScaleBox->isChecked());
}

PageSettings::~PageSettings()
{
    delete ui;
}

void PageSettings::on_uiScaleBox_valueChanged(double arg1)
{
    mSettings.setValue("app_scale_factor", arg1);
}

void PageSettings::on_uiAutoScaleBox_toggled(bool checked)
{
    mSettings.setValue("app_scale_auto", checked);
    ui->uiScaleBox->setEnabled(!checked);
}
