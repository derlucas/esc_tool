/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "parameditbool.h"
#include "ui_parameditbool.h"
#include <QMessageBox>
#include "helpdialog.h"

ParamEditBool::ParamEditBool(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParamEditBool)
{
    ui->setupUi(this);
}

ParamEditBool::~ParamEditBool()
{
    delete ui;
}

void ParamEditBool::setConfig(ConfigParams *config)
{
    mConfig = config;

    ConfigParam *param = mConfig->getParam(mName);

    if (param) {
        ui->readButton->setVisible(param->transmittable);
        ui->readDefaultButton->setVisible(param->transmittable);
        ui->valueBox->setCurrentIndex(param->valInt ? 1 : 0);
    }

    connect(mConfig, SIGNAL(paramChangedBool(QObject*,QString,bool)),
            this, SLOT(paramChangedBool(QObject*,QString,bool)));
}

QString ParamEditBool::name() const
{
    return mName;
}

void ParamEditBool::setName(const QString &name)
{
    mName = name;
}

void ParamEditBool::paramChangedBool(QObject *src, QString name, bool newParam)
{
    if (src != this && name == mName) {
        ui->valueBox->setCurrentIndex(newParam ? 1 : 0);
    }
}

void ParamEditBool::on_readButton_clicked()
{
    if (mConfig) {
        mConfig->setUpdateOnly(mName);
        mConfig->requestUpdate();
    }
}

void ParamEditBool::on_readDefaultButton_clicked()
{
    if (mConfig) {
        mConfig->setUpdateOnly(mName);
        mConfig->requestUpdateDefault();
    }
}

void ParamEditBool::on_helpButton_clicked()
{
    if (mConfig) {
        HelpDialog::showHelp(this, mConfig, mName);
    }
}

void ParamEditBool::on_valueBox_currentIndexChanged(int index)
{
    if (mConfig) {
        if (mConfig->getUpdateOnly() != mName) {
            mConfig->setUpdateOnly("");
        }
        mConfig->updateParamBool(mName, index, this);
    }
}
