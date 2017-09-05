/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef DISPLAYPERCENTAGE_H
#define DISPLAYPERCENTAGE_H

#include <QWidget>

class DisplayPercentage : public QWidget
{
    Q_OBJECT
public:
    explicit DisplayPercentage(QWidget *parent = 0);

    QString text() const;
    void setText(const QString &text);

    bool isDual() const;
    void setDual(bool isDual);

    double value() const;
    void setValue(double value);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event);

private:
    QString mText;
    bool mIsDual;
    double mValue;

};

#endif // DISPLAYPERCENTAGE_H
