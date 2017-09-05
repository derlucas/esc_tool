/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGEMOTOR_H
#define PAGEMOTOR_H

#include <QWidget>
#include "vescinterface.h"
#include "widgets/paramtable.h"

namespace Ui {
class PageMotor;
}

class PageMotor : public QWidget
{
    Q_OBJECT

public:
    explicit PageMotor(QWidget *parent = 0);
    ~PageMotor();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private:
    Ui::PageMotor *ui;
    VescInterface *mVesc;

};

#endif // PAGEMOTOR_H
