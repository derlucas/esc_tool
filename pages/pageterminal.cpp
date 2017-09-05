/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "pageterminal.h"
#include "ui_pageterminal.h"

PageTerminal::PageTerminal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageTerminal)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;
}

PageTerminal::~PageTerminal()
{
    delete ui;
}

void PageTerminal::clearTerminal()
{
    ui->terminalBrowser->clear();
}

VescInterface *PageTerminal::vesc() const
{
    return mVesc;
}

void PageTerminal::setVesc(VescInterface *vesc)
{
    mVesc = vesc;

    if (mVesc) {
        connect(mVesc->commands(), SIGNAL(printReceived(QString)),
                this, SLOT(printReceived(QString)));
    }
}

void PageTerminal::printReceived(QString str)
{
    ui->terminalBrowser->append(str);
}

void PageTerminal::on_sendButton_clicked()
{
    if (mVesc) {
        mVesc->commands()->sendTerminalCmd(ui->terminalEdit->text());
        ui->terminalEdit->clear();
    }
}

void PageTerminal::on_helpButton_clicked()
{
    if (mVesc) {
        mVesc->commands()->sendTerminalCmd("help");
    }
}
