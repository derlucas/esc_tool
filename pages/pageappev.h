/**
 * This file is part of ESC Tool
 *
 *  Copyright 2017 by Lucas Pless
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGEAPPEV_H
#define PAGEAPPEV_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class PageAppEv;
}

class PageAppEv : public QWidget
{
    Q_OBJECT

public:
    explicit PageAppEv(QWidget *parent = 0);
    ~PageAppEv();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void paramChangedDouble(QObject *src, QString name, double newParam);
    void paramChangedEnum(QObject *src, QString name, int newParam);

private:
    Ui::PageAppEv *ui;
    VescInterface *mVesc;

};

#endif // PAGEAPPEV_H
