/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef DETECTFOCENCODER_H
#define DETECTFOCENCODER_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class DetectFocEncoder;
}

class DetectFocEncoder : public QWidget
{
    Q_OBJECT

public:
    explicit DetectFocEncoder(QWidget *parent = 0);
    ~DetectFocEncoder();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void encoderParamReceived(double offset, double ratio, bool inverted);

    void on_helpButton_clicked();
    void on_startButton_clicked();
    void on_applyButton_clicked();

private:
    Ui::DetectFocEncoder *ui;
    VescInterface *mVesc;

};

#endif // DETECTFOCENCODER_H
