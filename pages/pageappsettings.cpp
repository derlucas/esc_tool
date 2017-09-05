/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "pageappsettings.h"
#include "ui_pageappsettings.h"
#include "setupwizardapp.h"

PageAppSettings::PageAppSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageAppSettings)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;
}

PageAppSettings::~PageAppSettings()
{
    delete ui;
}

VescInterface *PageAppSettings::vesc() const
{
    return mVesc;
}

void PageAppSettings::setVesc(VescInterface *vesc)
{
    mVesc = vesc;

    if (mVesc) {
        ConfigParam *p = mVesc->infoConfig()->getParam("app_setting_description");
        if (p != 0) {
            ui->textEdit->setHtml(p->description);
        } else {
            ui->textEdit->setText("App Setting Description not found.");
        }
    }
}

void PageAppSettings::on_appWizardButton_clicked()
{
    if (mVesc) {
        SetupWizardApp w(mVesc, this);
        w.exec();
    }
}
