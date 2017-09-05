/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "helpdialog.h"
#include "ui_helpdialog.h"
#include <QDebug>
#include <QMessageBox>

HelpDialog::HelpDialog(QString title, QString text, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpDialog)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle(title);
    ui->textEdit->setText(text);
    ui->textEdit->viewport()->setAutoFillBackground(false);
}

HelpDialog::~HelpDialog()
{
    delete ui;
}

void HelpDialog::showHelp(QWidget *parent, ConfigParams *params, QString name, bool modal)
{
    ConfigParam *param = params->getParam(name);

    if (param) {
        HelpDialog *h = new HelpDialog(param->longName,
                                       param->description,
                                       parent);
        if (modal) {
            h->exec();
        } else {
            h->show();
        }
    } else {
        QMessageBox::warning(parent,
                             tr("Show help"),
                             tr("Help text for %1 not found.").arg(name));
    }
}

void HelpDialog::showHelp(QWidget *parent, QString title, QString text)
{
    HelpDialog *h = new HelpDialog(title, text, parent);
    h->exec();
}

void HelpDialog::showEvent(QShowEvent *event)
{
    QSize s = ui->textEdit->document()->size().toSize();
    int tot = (this->height() - ui->textEdit->height()) + s.height() + 5;

    if (tot < 140) {
        this->resize(this->width(), 140);
    } else if (tot > 450) {
        this->resize(this->width(), 450);
    } else {
        this->resize(this->width(), tot);
    }

    QDialog::showEvent(event);
}

void HelpDialog::on_okButton_clicked()
{
    close();
}
