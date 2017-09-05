/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGEAPPPPM_H
#define PAGEAPPPPM_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class PageAppPpm;
}

class PageAppPpm : public QWidget
{
    Q_OBJECT

public:
    explicit PageAppPpm(QWidget *parent = 0);
    ~PageAppPpm();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void paramChangedDouble(QObject *src, QString name, double newParam);
    void paramChangedEnum(QObject *src, QString name, int newParam);

private:
    Ui::PageAppPpm *ui;
    VescInterface *mVesc;

};

#endif // PAGEAPPPPM_H
