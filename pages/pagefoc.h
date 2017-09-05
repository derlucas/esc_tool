/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGEFOC_H
#define PAGEFOC_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class PageFoc;
}

class PageFoc : public QWidget
{
    Q_OBJECT

public:
    explicit PageFoc(QWidget *parent = 0);
    ~PageFoc();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private:
    Ui::PageFoc *ui;
    VescInterface *mVesc;

};

#endif // PAGEFOC_H
