/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGESETUPCALCULATORS_H
#define PAGESETUPCALCULATORS_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class PageSetupCalculators;
}

class PageSetupCalculators : public QWidget
{
    Q_OBJECT

public:
    explicit PageSetupCalculators(QWidget *parent = 0);
    ~PageSetupCalculators();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void on_addSetupButton_clicked();
    void on_removeSetupButton_clicked();

private:
    Ui::PageSetupCalculators *ui;
    VescInterface *mVesc;

};

#endif // PAGESETUPCALCULATORS_H
