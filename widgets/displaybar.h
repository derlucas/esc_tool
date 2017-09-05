/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef DISPLAYBAR_H
#define DISPLAYBAR_H

#include <QWidget>
#include <QPaintEvent>

class DisplayBar : public QWidget
{
    Q_OBJECT
public:
    explicit DisplayBar(QWidget *parent = 0);

    QString name() const;
    void setName(const QString &name);
    double range() const;
    void setRange(double range);
    double val() const;
    void setVal(double val);
    QString unit() const;
    void setUnit(const QString &unit);
    int decimals() const;
    void setDecimals(int decimals);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event);

private:
    QString mName;
    double mRange;
    double mVal;
    QString mUnit;
    int mDecimals;

};

#endif // DISPLAYBAR_H
