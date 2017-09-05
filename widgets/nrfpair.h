/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef NRFPAIR_H
#define NRFPAIR_H

#include <QWidget>
#include <QTimer>
#include "vescinterface.h"

namespace Ui {
class NrfPair;
}

class NrfPair : public QWidget
{
    Q_OBJECT

public:
    explicit NrfPair(QWidget *parent = 0);
    ~NrfPair();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);
    void startPairing();

private slots:
    void nrfPairingRes(NRF_PAIR_RES res);
    void timerSlot();

    void on_startButton_clicked();
    void on_helpButton_clicked();

private:
    Ui::NrfPair *ui;
    VescInterface *mVesc;
    double mPairCnt;
    QTimer *mTimer;
    bool mRunning;

};

#endif // NRFPAIR_H
