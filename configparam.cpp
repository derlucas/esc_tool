/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "configparam.h"

ConfigParam::ConfigParam()
{
    reset();
}

void ConfigParam::reset()
{
    type = CFG_T_UNDEFINED;
    longName = "none";
    description = "TODO";
    cDefine.clear();

    valDouble = 0.0;
    valInt = 0;
    maxDouble = 99.0;
    minDouble = 0.0;
    stepDouble = 1.0;
    editorDecimalsDouble = 2;
    editorScale = 1.0;
    maxInt = 99;
    minInt = 0;
    stepInt = 1;
    vTx = VESC_TX_UNDEFINED;
    vTxDoubleScale = 1.0;
    suffix = "";
    enumNames.clear();
    editAsPercentage = false;
    showDisplay = false;
    transmittable = true;
}

void ConfigParam::setInt(int val, int max, int min, int step)
{
    type = CFG_T_INT;
    valInt = val;
    maxInt = max;
    minInt = min;
    stepInt = step;
}

void ConfigParam::setDouble(double val, double max, double min, double step, int decimals)
{
    type = CFG_T_DOUBLE;
    valDouble = val;
    maxDouble = max;
    minDouble = min;
    stepDouble = step;
    editorDecimalsDouble = decimals;
}

void ConfigParam::setDoubleTx(VESC_TX_T tx, double scale)
{
    vTx = tx;
    vTxDoubleScale = scale;
}

void ConfigParam::setEnum(int val, QStringList names)
{
    type = CFG_T_ENUM;
    valInt = val;
    enumNames = names;
}

void ConfigParam::setString(QString val)
{
    type = CFG_T_QSTRING;
    valString = val;
}

void ConfigParam::setBool(bool val)
{
    type = CFG_T_BOOL;
    valInt = val;
}
