/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef DETECTBLDC_H
#define DETECTBLDC_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class DetectBldc;
}

class DetectBldc : public QWidget
{
    Q_OBJECT

public:
    explicit DetectBldc(QWidget *parent = 0);
    ~DetectBldc();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

    void showEvent(QShowEvent *event) Q_DECL_OVERRIDE;

private slots:
    void bldcDetectReceived(bldc_detect param);

    void on_runButton_clicked();
    void on_applyButton_clicked();
    void on_helpButton_clicked();

private:
    Ui::DetectBldc *ui;
    VescInterface *mVesc;
    bldc_detect mResult;
    bool mResultReceived;
    bool mRunning;

};

#endif // DETECTBLDC_H
