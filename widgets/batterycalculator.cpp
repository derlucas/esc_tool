/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "batterycalculator.h"
#include "ui_batterycalculator.h"
#include "widgets/helpdialog.h"

BatteryCalculator::BatteryCalculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BatteryCalculator)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;
    on_batteryCellBox_valueChanged(ui->batteryCellBox->value());
}

BatteryCalculator::~BatteryCalculator()
{
    delete ui;
}

void BatteryCalculator::on_batteryCalcButton_clicked()
{
    if (mVesc) {
        mVesc->mcConfig()->updateParamDouble("l_battery_cut_start", mValStart);
        mVesc->mcConfig()->updateParamDouble("l_battery_cut_end", mValEnd);
    }
}

VescInterface *BatteryCalculator::vesc() const
{
    return mVesc;
}

void BatteryCalculator::setVesc(VescInterface *vesc)
{
    mVesc = vesc;
}

void BatteryCalculator::on_batteryCellBox_valueChanged(int arg1)
{
    (void)arg1;
    calc();
}

void BatteryCalculator::on_batteryTypeBox_currentIndexChanged(int index)
{
    (void)index;
    calc();
}

void BatteryCalculator::calc()
{
    switch (ui->batteryTypeBox->currentIndex()) {
    case 0:
        mValStart = 3.4;
        mValEnd = 3.1;
        break;

    default:
        break;
    }

    mValStart *= (double)ui->batteryCellBox->value();
    mValEnd *= (double)ui->batteryCellBox->value();

    ui->batteryCutoffLabel->setText(tr("[%1, %2]").
                                    arg(mValStart, 0, 'f', 2).
                                    arg(mValEnd, 0, 'f', 2));
}

void BatteryCalculator::on_helpButton_clicked()
{
    if (mVesc) {
        HelpDialog::showHelp(this, mVesc->infoConfig(), "help_battery_cutoff");
    }
}
