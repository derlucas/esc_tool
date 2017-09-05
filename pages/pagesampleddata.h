/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGESAMPLEDDATA_H
#define PAGESAMPLEDDATA_H

#include <QWidget>
#include <QVector>
#include <QTimer>
#include "vescinterface.h"

namespace Ui {
class PageSampledData;
}

class PageSampledData : public QWidget
{
    Q_OBJECT

public:
    explicit PageSampledData(QWidget *parent = 0);
    ~PageSampledData();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void timerSlot();
    void samplesReceived(QByteArray bytes);
    void replotAll();

    void on_sampleNowButton_clicked();
    void on_sampleStartButton_clicked();
    void on_sampleTriggerStartButton_clicked();
    void on_sampleTriggerFaultButton_clicked();
    void on_sampleTriggerStartNosendButton_clicked();
    void on_sampleTriggerFaultNosendButton_clicked();
    void on_sampleLastButton_clicked();
    void on_sampleStopButton_clicked();
    void on_zoomHButton_toggled(bool checked);
    void on_zoomVButton_toggled(bool checked);
    void on_rescaleButton_clicked();
    void on_filterLogScaleBox_toggled(bool checked);
    void on_plotModeBox_currentIndexChanged(int index);

private:
    Ui::PageSampledData *ui;
    VescInterface *mVesc;
    QTimer *mTimer;

    int mSampleInt;

    QVector<double> curr1Vector;
    QVector<double> curr2Vector;
    QVector<double> ph1Vector;
    QVector<double> ph2Vector;
    QVector<double> ph3Vector;
    QVector<double> vZeroVector;
    QVector<double> currTotVector;
    QVector<double> fSwVector;
    QByteArray statusArray;
    QByteArray phaseArray;

    QVector<double> tmpCurr1Vector;
    QVector<double> tmpCurr2Vector;
    QVector<double> tmpPh1Vector;
    QVector<double> tmpPh2Vector;
    QVector<double> tmpPh3Vector;
    QVector<double> tmpVZeroVector;
    QVector<double> tmpCurrTotVector;
    QVector<double> tmpFSwVector;
    QByteArray tmpStatusArray;
    QByteArray tmpPhaseArray;

    bool mDoReplot;
    bool mDoRescale;
    bool mDoFilterReplot;
    int mSamplesToWait;

    void clearBuffers();
    void updateZoom();

};

#endif // PAGESAMPLEDDATA_H
