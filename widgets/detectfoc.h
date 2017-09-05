/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef DETECTFOC_H
#define DETECTFOC_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class DetectFoc;
}

class DetectFoc : public QWidget
{
    Q_OBJECT

public:
    explicit DetectFoc(QWidget *parent = 0);
    ~DetectFoc();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);
    bool allValuesOk() const;
    bool lastOkValuesApplied() const;

private slots:
    void motorRLReceived(double r, double l);
    void motorLinkageReceived(double flux_linkage);

    void on_rlButton_clicked();
    void on_lambdaButton_clicked();
    void on_helpButton_clicked();
    void on_applyAllButton_clicked();
    void on_calcKpKiButton_clicked();
    void on_calcGainButton_clicked();

private:
    Ui::DetectFoc *ui;
    VescInterface *mVesc;
    bool mLastCalcOk;
    bool mAllValuesOk;
    bool mLastOkValuesApplied;
    bool mRunning;

    void updateColors();

};

#endif // DETECTFOC_H
