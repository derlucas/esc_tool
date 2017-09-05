/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGECONTROLLERS_H
#define PAGECONTROLLERS_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class PageControllers;
}

class PageControllers : public QWidget
{
    Q_OBJECT

public:
    explicit PageControllers(QWidget *parent = 0);
    ~PageControllers();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private:
    Ui::PageControllers *ui;
    VescInterface *mVesc;

};

#endif // PAGECONTROLLERS_H
