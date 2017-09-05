/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGEDC_H
#define PAGEDC_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class PageDc;
}

class PageDc : public QWidget
{
    Q_OBJECT

public:
    explicit PageDc(QWidget *parent = 0);
    ~PageDc();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private:
    Ui::PageDc *ui;
    VescInterface *mVesc;

};

#endif // PAGEDC_H
