/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGECONNECTION_H
#define PAGECONNECTION_H

#include <QWidget>
#include <QTimer>
#include "vescinterface.h"

namespace Ui {
class PageConnection;
}

class PageConnection : public QWidget
{
    Q_OBJECT

public:
    explicit PageConnection(QWidget *parent = 0);
    ~PageConnection();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void timerSlot();

    void on_serialRefreshButton_clicked();
    void on_serialDisconnectButton_clicked();
    void on_serialConnectButton_clicked();
    void on_tcpDisconnectButton_clicked();
    void on_tcpConnectButton_clicked();
    void on_canFwdBox_valueChanged(int arg1);
    void on_helpButton_clicked();
    void on_canFwdButton_toggled(bool checked);
    void on_autoConnectButton_clicked();

private:
    Ui::PageConnection *ui;
    VescInterface *mVesc;
    QTimer *mTimer;

};

#endif // PAGECONNECTION_H
