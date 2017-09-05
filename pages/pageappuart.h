/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGEAPPUART_H
#define PAGEAPPUART_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class PageAppUart;
}

class PageAppUart : public QWidget
{
    Q_OBJECT

public:
    explicit PageAppUart(QWidget *parent = 0);
    ~PageAppUart();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private:
    Ui::PageAppUart *ui;
    VescInterface *mVesc;

};

#endif // PAGEAPPUART_H
