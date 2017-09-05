/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "parameditstring.h"
#include "ui_parameditstring.h"
#include "helpdialog.h"

ParamEditString::ParamEditString(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParamEditString)
{
    ui->setupUi(this);
}

ParamEditString::~ParamEditString()
{
    delete ui;
}

void ParamEditString::setConfig(ConfigParams *config)
{
    mConfig = config;

    ConfigParam *param = mConfig->getParam(mName);

    if (param) {
        ui->valueEdit->setText(param->valString);
    }

    connect(mConfig, SIGNAL(paramChangedQString(QObject*,QString,QString)),
            this, SLOT(paramChangedQString(QObject*,QString,QString)));
}

QString ParamEditString::name() const
{
    return mName;
}

void ParamEditString::setName(const QString &name)
{
    mName = name;
}

void ParamEditString::paramChangedQString(QObject *src, QString name, QString newParam)
{
    if (src != this && name == mName) {
        ui->valueEdit->setText(newParam);
    }
}

void ParamEditString::on_helpButton_clicked()
{
    if (mConfig) {
        HelpDialog::showHelp(this, mConfig, mName);
    }
}

void ParamEditString::on_valueEdit_textChanged(const QString &arg1)
{
    if (mConfig) {
        if (mConfig->getUpdateOnly() != mName) {
            mConfig->setUpdateOnly("");
        }
        mConfig->updateParamString(mName, arg1, this);
    }
}
