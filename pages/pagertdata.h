/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGERTDATA_H
#define PAGERTDATA_H

#include <QWidget>
#include <QVector>
#include <QTimer>
#include "vescinterface.h"

namespace Ui {
class PageRtData;
}

class PageRtData : public QWidget
{
    Q_OBJECT

public:
    explicit PageRtData(QWidget *parent = 0);
    ~PageRtData();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void timerSlot();
    void valuesReceived(MC_VALUES values);
    void rotorPosReceived(double pos);

    void on_zoomHButton_toggled(bool checked);
    void on_zoomVButton_toggled(bool checked);
    void on_rescaleButton_clicked();
    void on_posInductanceButton_clicked();
    void on_posObserverButton_clicked();
    void on_posEncoderButton_clicked();
    void on_posPidButton_clicked();
    void on_posPidErrorButton_clicked();
    void on_posEncoderObserverErrorButton_clicked();
    void on_posStopButton_clicked();
    void on_tempShowMosfetBox_toggled(bool checked);
    void on_tempShowMotorBox_toggled(bool checked);

private:
    Ui::PageRtData *ui;
    VescInterface *mVesc;
    QTimer *mTimer;

    QVector<double> mTempMosVec;
    QVector<double> mTempMotorVec;
    QVector<double> mCurrInVec;
    QVector<double> mCurrMotorVec;
    QVector<double> mIdVec;
    QVector<double> mIqVec;
    QVector<double> mDutyVec;
    QVector<double> mRpmVec;
    QVector<double> mPositionVec;

    bool mUpdateValPlot;
    bool mUpdatePosPlot;

    void appendDoubleAndTrunc(QVector<double> *vec, double num, int maxSize);
    void updateZoom();

};

#endif // PAGERTDATA_H
