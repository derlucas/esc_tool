/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "pagemotorinfo.h"
#include "ui_pagemotorinfo.h"
#include "widgets/helpdialog.h"

PageMotorInfo::PageMotorInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageMotorInfo)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;
}

PageMotorInfo::~PageMotorInfo()
{
    delete ui;
}

VescInterface *PageMotorInfo::vesc() const
{
    return mVesc;
}

void PageMotorInfo::setVesc(VescInterface *vesc)
{
    mVesc = vesc;

    if (mVesc) {
        ui->descriptionEdit->document()->setHtml(mVesc->mcConfig()->getParamQString("motor_description"));
        ui->qualityEdit->document()->setHtml(mVesc->mcConfig()->getParamQString("motor_quality_description"));

        ui->generalTab->addParamRow(mVesc->mcConfig(), "motor_brand");
        ui->generalTab->addParamRow(mVesc->mcConfig(), "motor_model");
        ui->generalTab->addParamRow(mVesc->mcConfig(), "motor_weight");
        ui->generalTab->addParamRow(mVesc->mcConfig(), "motor_poles");
        ui->generalTab->addParamRow(mVesc->mcConfig(), "motor_sensor_type");
        ui->generalTab->addParamRow(mVesc->mcConfig(), "motor_loss_torque");

        ui->qualityTab->addParamRow(mVesc->mcConfig(), "motor_quality_bearings");
        ui->qualityTab->addParamRow(mVesc->mcConfig(), "motor_quality_magnets");
        ui->qualityTab->addParamRow(mVesc->mcConfig(), "motor_quality_construction");

        connect(mVesc->mcConfig(), SIGNAL(paramChangedQString(QObject*,QString,QString)),
                this, SLOT(paramChangedQString(QObject*,QString,QString)));
        connect(mVesc->mcConfig(), SIGNAL(savingXml()),
                this, SLOT(savingXml()));
    }
}

void PageMotorInfo::savingXml()
{
    mVesc->mcConfig()->updateParamString("motor_description",
                                         ui->descriptionEdit->document()->toHtml(),
                                         this);

    mVesc->mcConfig()->updateParamString("motor_quality_description",
                                         ui->qualityEdit->document()->toHtml(),
                                         this);
}

void PageMotorInfo::paramChangedQString(QObject *src, QString name, QString newParam)
{
    if (src != this) {
        if (name == "motor_description") {
            ui->descriptionEdit->document()->setHtml(newParam);
        } else if (name == "motor_quality_description") {
            ui->qualityEdit->document()->setHtml(newParam);
        }
    }
}

void PageMotorInfo::on_descriptionHelpButton_clicked()
{
    if (mVesc) {
        HelpDialog::showHelp(this, mVesc->mcConfig(), "motor_description");
    }
}
