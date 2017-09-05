/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "pagedataanalysis.h"
#include "ui_pagedataanalysis.h"

PageDataAnalysis::PageDataAnalysis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageDataAnalysis)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;
}

PageDataAnalysis::~PageDataAnalysis()
{
    delete ui;
}

VescInterface *PageDataAnalysis::vesc() const
{
    return mVesc;
}

void PageDataAnalysis::setVesc(VescInterface *vesc)
{
    mVesc = vesc;

    if (mVesc) {
        ConfigParam *p = mVesc->infoConfig()->getParam("data_analysis_description");
        if (p != 0) {
            ui->textEdit->setHtml(p->description);
        } else {
            ui->textEdit->setText("Data Analysis Description not found.");
        }
    }
}
