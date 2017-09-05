/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGEAPPSETTINGS_H
#define PAGEAPPSETTINGS_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class PageAppSettings;
}

class PageAppSettings : public QWidget
{
    Q_OBJECT

public:
    explicit PageAppSettings(QWidget *parent = 0);
    ~PageAppSettings();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void on_appWizardButton_clicked();

private:
    Ui::PageAppSettings *ui;
    VescInterface *mVesc;

};

#endif // PAGEAPPSETTINGS_H
