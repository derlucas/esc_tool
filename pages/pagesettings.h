/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGESETTINGS_H
#define PAGESETTINGS_H

#include <QWidget>
#include <QSettings>

namespace Ui {
class PageSettings;
}

class PageSettings : public QWidget
{
    Q_OBJECT

public:
    explicit PageSettings(QWidget *parent = 0);
    ~PageSettings();

private slots:
    void on_uiScaleBox_valueChanged(double arg1);

    void on_uiAutoScaleBox_toggled(bool checked);

private:
    Ui::PageSettings *ui;
    QSettings mSettings;

};

#endif // PAGESETTINGS_H
