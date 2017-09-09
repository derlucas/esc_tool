/**
 * ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef ADCMAPEV_H
#define ADCMAPEV_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class AdcMapEv;
}

class AdcMapEv : public QWidget
{
    Q_OBJECT

public:
    explicit AdcMapEv(QWidget *parent = 0);
    ~AdcMapEv();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void decodedEvReceived(double value1, double voltage1, double value2, double voltage2);

    void on_helpButton_clicked();
    void on_resetButton_clicked();
    void on_applyButton_clicked();

private:
    Ui::AdcMapEv *ui;
    VescInterface *mVesc;
    bool mResetDone;

};

#endif // ADCMAPEV_H
