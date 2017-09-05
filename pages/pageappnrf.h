/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGEAPPNRF_H
#define PAGEAPPNRF_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class PageAppNrf;
}

class PageAppNrf : public QWidget
{
    Q_OBJECT

public:
    explicit PageAppNrf(QWidget *parent = 0);
    ~PageAppNrf();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private:
    Ui::PageAppNrf *ui;
    VescInterface *mVesc;

};

#endif // PAGEAPPNRF_H
