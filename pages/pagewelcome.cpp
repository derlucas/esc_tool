/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "pagewelcome.h"
#include "ui_pagewelcome.h"
#include "setupwizardmotor.h"
#include "setupwizardapp.h"
#include "util.h"
#include <QMessageBox>

PageWelcome::PageWelcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageWelcome)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;
    ui->bgWidget->setPixmap(QPixmap("://res/bg.png"));

    connect(ui->wizardMotorButton, SIGNAL(clicked(bool)),
            this, SLOT(startSetupWizardMotor()));
    connect(ui->wizardAppButton, SIGNAL(clicked(bool)),
            this, SLOT(startSetupWizardApp()));
}

PageWelcome::~PageWelcome()
{
    delete ui;
}

void PageWelcome::startSetupWizardMotor()
{
    if (mVesc) {
        SetupWizardMotor w(mVesc, this);
        w.exec();
    }
}

void PageWelcome::startSetupWizardApp()
{
    if (mVesc) {
        SetupWizardApp w(mVesc, this);
        w.exec();
    }
}

VescInterface *PageWelcome::vesc() const
{
    return mVesc;
}

void PageWelcome::setVesc(VescInterface *vesc)
{
    mVesc = vesc;
}

void PageWelcome::on_autoConnectButton_clicked()
{
    util::autoconnectBlockingWithProgress(mVesc, this);
}
