/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef RTDATATEXT_H
#define RTDATATEXT_H

#include <QWidget>
#include "datatypes.h"

class RtDataText : public QWidget
{
    Q_OBJECT
public:
    explicit RtDataText(QWidget *parent = 0);
    void setValues(const MC_VALUES &values);

    QSize sizeHint() const;

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event);

private:
    MC_VALUES mValues;
    int mBoxH;
    int mBoxW;
    int mTxtOfs;

};

#endif // RTDATATEXT_H
