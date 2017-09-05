/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGEDATAANALYSIS_H
#define PAGEDATAANALYSIS_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class PageDataAnalysis;
}

class PageDataAnalysis : public QWidget
{
    Q_OBJECT

public:
    explicit PageDataAnalysis(QWidget *parent = 0);
    ~PageDataAnalysis();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private:
    Ui::PageDataAnalysis *ui;
    VescInterface *mVesc;

};

#endif // PAGEDATAANALYSIS_H
