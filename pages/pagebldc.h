/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGEBLDC_H
#define PAGEBLDC_H

#include <QWidget>
#include "vescinterface.h"
#include "widgets/paramtable.h"

namespace Ui {
class PageBldc;
}

class PageBldc : public QWidget
{
    Q_OBJECT

public:
    explicit PageBldc(QWidget *parent = 0);
    ~PageBldc();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private:
    Ui::PageBldc *ui;
    VescInterface *mVesc;

};

#endif // PAGEBLDC_H
