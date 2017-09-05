/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGETERMINAL_H
#define PAGETERMINAL_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class PageTerminal;
}

class PageTerminal : public QWidget
{
    Q_OBJECT

public:
    explicit PageTerminal(QWidget *parent = 0);
    ~PageTerminal();
    void clearTerminal();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void printReceived(QString str);

    void on_sendButton_clicked();
    void on_helpButton_clicked();

private:
    Ui::PageTerminal *ui;
    VescInterface *mVesc;

};

#endif // PAGETERMINAL_H
