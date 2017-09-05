/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PARAMTABLE_H
#define PARAMTABLE_H

#include <QWidget>
#include <QTableWidget>
#include "configparams.h"

class ParamTable : public QTableWidget
{
public:
    ParamTable(QWidget *parent = 0);
    bool addParamRow(ConfigParams *params, QString paramName);
    void addRowSeparator(QString text);

};

#endif // PARAMTABLE_H
