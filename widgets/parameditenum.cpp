/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "parameditenum.h"
#include "ui_parameditenum.h"
#include <QDebug>
#include "helpdialog.h"

ParamEditEnum::ParamEditEnum(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParamEditEnum)
{
    ui->setupUi(this);
    mConfig = 0;
}

ParamEditEnum::~ParamEditEnum()
{
    delete ui;
}

void ParamEditEnum::setConfig(ConfigParams *config)
{
    mConfig = config;

    ConfigParam *param = mConfig->getParam(mName);

    if (param) {
        ui->readButton->setVisible(param->transmittable);
        ui->readDefaultButton->setVisible(param->transmittable);

        int val = param->valInt;
        ui->valueBox->insertItems(0, param->enumNames);
        if (val >= 0 && val < param->enumNames.size()) {
            ui->valueBox->setCurrentIndex(val);
        }
    }

    connect(mConfig, SIGNAL(paramChangedEnum(QObject*,QString,int)),
            this, SLOT(paramChangedEnum(QObject*,QString,int)));
}

QString ParamEditEnum::name() const
{
    return mName;
}

void ParamEditEnum::setName(const QString &name)
{
    mName = name;
}

void ParamEditEnum::paramChangedEnum(QObject *src, QString name, int newParam)
{
    if (src != this && name == mName) {
        ui->valueBox->setCurrentIndex(newParam);
    }
}

void ParamEditEnum::on_readButton_clicked()
{
    if (mConfig) {
        mConfig->setUpdateOnly(mName);
        mConfig->requestUpdate();
    }
}

void ParamEditEnum::on_readDefaultButton_clicked()
{
    if (mConfig) {
        mConfig->setUpdateOnly(mName);
        mConfig->requestUpdateDefault();
    }
}

void ParamEditEnum::on_helpButton_clicked()
{
    if (mConfig) {
        HelpDialog::showHelp(this, mConfig, mName);
    }
}

void ParamEditEnum::on_valueBox_currentIndexChanged(int index)
{
    if (mConfig) {
        if (mConfig->getUpdateOnly() != mName) {
            mConfig->setUpdateOnly("");
        }
        mConfig->updateParamEnum(mName, index, this);
    }
}
