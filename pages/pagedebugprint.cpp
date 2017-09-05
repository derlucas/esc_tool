/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "pagedebugprint.h"
#include "ui_pagedebugprint.h"
#include <QDateTime>

// Static member initialization
PageDebugPrint *PageDebugPrint::currentMsgHandler = 0;

PageDebugPrint::PageDebugPrint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageDebugPrint)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    currentMsgHandler = this;
}

PageDebugPrint::~PageDebugPrint()
{
    delete ui;
}

void PageDebugPrint::printConsole(QString str)
{
    ui->consoleBrowser->moveCursor(QTextCursor::End);
    ui->consoleBrowser->insertHtml(QDateTime::currentDateTime().
                                   toString("yyyy-MM-dd hh:mm:ss: ")
                                   + str);
    ui->consoleBrowser->moveCursor(QTextCursor::End);
}
