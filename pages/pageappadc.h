/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGEAPPADC_H
#define PAGEAPPADC_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class PageAppAdc;
}

class PageAppAdc : public QWidget
{
    Q_OBJECT

public:
    explicit PageAppAdc(QWidget *parent = 0);
    ~PageAppAdc();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void paramChangedDouble(QObject *src, QString name, double newParam);
    void paramChangedEnum(QObject *src, QString name, int newParam);

private:
    Ui::PageAppAdc *ui;
    VescInterface *mVesc;

};

#endif // PAGEAPPADC_H
