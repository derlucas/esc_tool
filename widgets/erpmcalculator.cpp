/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "erpmcalculator.h"
#include "ui_erpmcalculator.h"
#include "widgets/helpdialog.h"
#include <math.h>

ErpmCalculator::ErpmCalculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ErpmCalculator)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;
}

ErpmCalculator::~ErpmCalculator()
{
    delete ui;
}

VescInterface *ErpmCalculator::vesc() const
{
    return mVesc;
}

void ErpmCalculator::setVesc(VescInterface *vesc)
{
    mVesc = vesc;
}



void ErpmCalculator::calc()
{

    double inputDiameter;   // in meters
    double inputSpeed;

    if(ui->comboWheelUnits->currentIndex() == 0) {
        inputDiameter = ui->spinWheelDiameter->value() / 100;
    } else {
        // convert input inches to m
        inputDiameter = ( ui->spinWheelDiameter->value() * 2.54 ) / 100;
    }

    if(ui->comboSpeedUnits->currentIndex() == 0) {
        // input is km/h, convert to m/s
        inputSpeed = ui->spinInputSpeed->value() / 3.6;

    } else {
        // input is mph, convert to m/s
        inputSpeed = ui->spinInputSpeed->value() / 2.23694;
    }

    double rpm = (60 * inputSpeed) / (inputDiameter * M_PI);

    double erpm = ( rpm * ui->spinMotorPoles->value() / 2 ) /  ((double)ui->spinTeethMotor->value() / (double)ui->spinTeethWheel->value() );

    ui->erpmResult->setText(QString::number(erpm,'g',10));

}

void ErpmCalculator::on_helpButton_clicked()
{
    if (mVesc) {
        HelpDialog::showHelp(this, mVesc->infoConfig(), "help_erpm");
    }
}

void ErpmCalculator::on_btnCalculate_clicked()
{
    calc();
}
