/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGEMOTORINFO_H
#define PAGEMOTORINFO_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class PageMotorInfo;
}

class PageMotorInfo : public QWidget
{
    Q_OBJECT

public:
    explicit PageMotorInfo(QWidget *parent = 0);
    ~PageMotorInfo();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void savingXml();
    void paramChangedQString(QObject *src, QString name, QString newParam);

private slots:
    void on_descriptionHelpButton_clicked();

private:
    Ui::PageMotorInfo *ui;
    VescInterface *mVesc;

};

#endif // PAGEMOTORINFO_H
