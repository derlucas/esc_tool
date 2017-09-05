/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef DETECTFOCHALL_H
#define DETECTFOCHALL_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class DetectFocHall;
}

class DetectFocHall : public QWidget
{
    Q_OBJECT

public:
    explicit DetectFocHall(QWidget *parent = 0);
    ~DetectFocHall();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void focHallTableReceived(QVector<int> hall_table, int res);

    void on_helpButton_clicked();
    void on_startButton_clicked();
    void on_applyButton_clicked();

private:
    Ui::DetectFocHall *ui;
    VescInterface *mVesc;

};

#endif // DETECTFOCHALL_H
