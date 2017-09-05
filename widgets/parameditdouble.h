/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PARAMEDITDOUBLE_H
#define PARAMEDITDOUBLE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include "configparams.h"
#include "displaypercentage.h"

namespace Ui {
class ParamEditDouble;
}

class ParamEditDouble : public QWidget
{
    Q_OBJECT

public:
    explicit ParamEditDouble(QWidget *parent = 0);
    ~ParamEditDouble();
    void setConfig(ConfigParams *config);
    QString name() const;
    void setName(const QString &name);
    void setSuffix(const QString &suffix);
    void setDecimals(int decimals);
    void setShowAsPercentage(bool showAsPercentage);
    void showDisplay(bool show);

private slots:
    void paramChangedDouble(QObject *src, QString name, double newParam);
    void percentageChanged(int p);
    void doubleChanged(double d);

    void on_readButton_clicked();
    void on_readDefaultButton_clicked();
    void on_helpButton_clicked();

private:
    Ui::ParamEditDouble *ui;
    ConfigParams *mConfig;
    ConfigParam mParam;
    QString mName;
    double mMaxVal;

    DisplayPercentage *mDisplay;
    QDoubleSpinBox *mDoubleBox;
    QSpinBox *mPercentageBox;

    void updateDisplay(double val);

};

#endif // PARAMEDITDOUBLE_H
