/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PARAMEDITINT_H
#define PARAMEDITINT_H

#include <QWidget>
#include <QSpinBox>
#include "configparams.h"
#include "displaypercentage.h"

namespace Ui {
class ParamEditInt;
}

class ParamEditInt : public QWidget
{
    Q_OBJECT

public:
    explicit ParamEditInt(QWidget *parent = 0);
    ~ParamEditInt();

    void setConfig(ConfigParams *config);
    QString name() const;
    void setName(const QString &name);
    void setSuffix(const QString &suffix);
    void setShowAsPercentage(bool showAsPercentage);
    void showDisplay(bool show);

private slots:
    void paramChangedInt(QObject *src, QString name, int newParam);
    void percentageChanged(int p);
    void intChanged(int i);

    void on_readButton_clicked();
    void on_readDefaultButton_clicked();
    void on_helpButton_clicked();

private:
    Ui::ParamEditInt *ui;
    ConfigParams *mConfig;
    ConfigParam mParam;
    QString mName;
    int mMaxVal;

    DisplayPercentage *mDisplay;
    QSpinBox *mIntBox;
    QSpinBox *mPercentageBox;

    void updateDisplay(int val);
    int multScale(int val);
    int divScale(int val);

};

#endif // PARAMEDITINT_H
