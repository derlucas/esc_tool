/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGEAPPNUNCHUK_H
#define PAGEAPPNUNCHUK_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class PageAppNunchuk;
}

class PageAppNunchuk : public QWidget
{
    Q_OBJECT

public:
    explicit PageAppNunchuk(QWidget *parent = 0);
    ~PageAppNunchuk();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void decodedChukReceived(double value);
    void paramChangedDouble(QObject *src, QString name, double newParam);
    void paramChangedEnum(QObject *src, QString name, int newParam);

private:
    Ui::PageAppNunchuk *ui;
    VescInterface *mVesc;

};

#endif // PAGEAPPNUNCHUK_H
