/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGEMOTORSETTINGS_H
#define PAGEMOTORSETTINGS_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class PageMotorSettings;
}

class PageMotorSettings : public QWidget
{
    Q_OBJECT

public:
    explicit PageMotorSettings(QWidget *parent = 0);
    ~PageMotorSettings();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void on_motorSetupWizardButton_clicked();

private:
    Ui::PageMotorSettings *ui;
    VescInterface *mVesc;

};

#endif // PAGEMOTORSETTINGS_H
