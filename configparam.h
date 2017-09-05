/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef CONFIGPARAM_H
#define CONFIGPARAM_H

#include <QImage>
#include "datatypes.h"

class ConfigParam
{
public:
    ConfigParam();

    void reset();
    void setInt(int val, int max = 99, int min = 0, int step = 0);
    void setDouble(double val, double max = 99.0, double min = 0.0,
                   double step = 1.0, int decimals = 2);
    void setDoubleTx(VESC_TX_T tx, double scale);
    void setEnum(int val, QStringList names);
    void setString(QString val);
    void setBool(bool val);

    CFG_T type;
    QString longName;
    QString description;
    QString cDefine;
    double valDouble;
    int valInt;
    QString valString;
    QStringList enumNames;
    double maxDouble;
    double minDouble;
    double stepDouble;
    int editorDecimalsDouble;
    int maxInt;
    int minInt;
    int stepInt;
    VESC_TX_T vTx;
    double vTxDoubleScale;
    QString suffix;
    double editorScale;
    bool editAsPercentage;
    bool showDisplay;
    bool transmittable;

};

#endif // CONFIGPARAM_H
