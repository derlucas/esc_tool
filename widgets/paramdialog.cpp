/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "paramdialog.h"
#include "ui_paramdialog.h"

ParamDialog::ParamDialog(QString title,
                         QString text,
                         ConfigParams *params,
                         QStringList names,
                         QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParamDialog)
{
    ui->setupUi(this);
    setWindowTitle(title);
    ui->textLabel->setText(text);
    mConfig = *params;

    for (QString s: names) {
        ConfigParam *p = mConfig.getParam(s);

        if (p) {
            p->transmittable = false; // To hide the read buttons.
            ui->paramTable->addParamRow(&mConfig, s);
        }
    }
}

ParamDialog::~ParamDialog()
{
    delete ui;
}

void ParamDialog::showParams(QString title,
                             QString text,
                             ConfigParams *params,
                             QStringList names,
                             QWidget *parent)
{
    ParamDialog *p = new ParamDialog(title, text, params, names, parent);
    p->exec();
}

void ParamDialog::on_closeButton_clicked()
{
    close();
}
