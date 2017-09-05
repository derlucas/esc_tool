/**
 * ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef ADCMAP_H
#define ADCMAP_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class AdcMap;
}

class AdcMap : public QWidget
{
    Q_OBJECT

public:
    explicit AdcMap(QWidget *parent = 0);
    ~AdcMap();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void decodedAdcReceived(double value, double voltage, double value2, double voltage2);

    void on_controlTypeBox_currentIndexChanged(int index);
    void on_helpButton_clicked();
    void on_resetButton_clicked();
    void on_applyButton_clicked();

private:
    Ui::AdcMap *ui;
    VescInterface *mVesc;
    bool mResetDone;

};

#endif // ADCMAP_H
