/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGEWELCOME_H
#define PAGEWELCOME_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class PageWelcome;
}

class PageWelcome : public QWidget
{
    Q_OBJECT

public:
    explicit PageWelcome(QWidget *parent = 0);
    ~PageWelcome();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

public slots:
    void startSetupWizardMotor();
    void startSetupWizardApp();

private slots:
    void on_autoConnectButton_clicked();

private:
    Ui::PageWelcome *ui;
    VescInterface *mVesc;

};

#endif // PAGEWELCOME_H
