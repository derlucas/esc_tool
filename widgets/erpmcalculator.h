/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef ErpmCalculator_H
#define ErpmCalculator_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class ErpmCalculator;
}

class ErpmCalculator : public QWidget
{
    Q_OBJECT

public:
    explicit ErpmCalculator(QWidget *parent = 0);
    ~ErpmCalculator();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void on_helpButton_clicked();

    void on_btnCalculate_clicked();

private:
    Ui::ErpmCalculator *ui;
    VescInterface *mVesc;


    void calc();

};

#endif // ErpmCalculator_H
