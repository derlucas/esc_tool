/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef BATTERYCALCULATOR_H
#define BATTERYCALCULATOR_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class BatteryCalculator;
}

class BatteryCalculator : public QWidget
{
    Q_OBJECT

public:
    explicit BatteryCalculator(QWidget *parent = 0);
    ~BatteryCalculator();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void on_batteryCalcButton_clicked();
    void on_batteryCellBox_valueChanged(int arg1);
    void on_batteryTypeBox_currentIndexChanged(int index);
    void on_helpButton_clicked();

private:
    Ui::BatteryCalculator *ui;
    VescInterface *mVesc;
    double mValStart;
    double mValEnd;

    void calc();

};

#endif // BATTERYCALCULATOR_H
