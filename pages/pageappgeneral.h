/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGEAPPGENERAL_H
#define PAGEAPPGENERAL_H

#include <QWidget>
#include "vescinterface.h"
#include "widgets/paramtable.h"

namespace Ui {
class PageAppGeneral;
}

class PageAppGeneral : public QWidget
{
    Q_OBJECT

public:
    explicit PageAppGeneral(QWidget *parent = 0);
    ~PageAppGeneral();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private:
    Ui::PageAppGeneral *ui;
    VescInterface *mVesc;

};

#endif // PAGEAPPGENERAL_H
