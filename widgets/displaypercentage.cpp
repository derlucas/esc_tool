/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "displaypercentage.h"
#include <QPainter>
#include <QPaintEvent>
#include <QFont>
#include <cmath>

DisplayPercentage::DisplayPercentage(QWidget *parent) : QWidget(parent)
{
    mText = "";
    mIsDual = false;
    mValue = 0.0;
}

QString DisplayPercentage::text() const
{
    return mText;
}

void DisplayPercentage::setText(const QString &text)
{
    mText = text;
    update();
}

bool DisplayPercentage::isDual() const
{
    return mIsDual;
}

void DisplayPercentage::setDual(bool hasNegative)
{
    mIsDual = hasNegative;
    update();
}

double DisplayPercentage::value() const
{
    return mValue;
}

void DisplayPercentage::setValue(double value)
{
    mValue = value;
    update();
}

void DisplayPercentage::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QColor c_bg = Qt::black;
    QColor c_hl = Qt::darkGreen;
    QColor c_vl = Qt::darkRed;
    QColor c_neg = Qt::red;
    QColor c_pos = Qt::green;
    QColor c_text = Qt::white;

    if (!isEnabled()) {
        int c = 80;
        c_bg = QColor(c, c, c);

        c = 120;
        c_hl = QColor(c, c, c);

        c = 120;
        c_vl = QColor(c, c, c);

        c = 120;
        c_neg = QColor(c, c, c);

        c = 180;
        c_pos = QColor(c, c, c);

        c = 180;
        c_text = QColor(c, c, c);
    }

    int w = width();
    int h = height();

    painter.fillRect(event->rect(), Qt::transparent);
    painter.setBrush(c_bg);
    painter.drawRoundedRect(event->rect(), 5.0, 5.0);

    if (mIsDual) {
        painter.fillRect(w / 2 - 1, 0, 2, h / 3, c_vl);
    }

    painter.fillRect(0, h / 3 - 1, w, 2, c_hl);

    QPen pen;
    QFont font;

    // Text
    pen.setColor(c_text);
    font.setFamily("Monospace");
    font.setBold(true);
    font.setPixelSize(2 * h / 3 - 2);
    painter.setPen(pen);
    painter.setFont(font);
    painter.drawText(QRect(0, h / 3 + 1, w - 2, 2 * h / 3 - 1), Qt::AlignCenter, mText);

    double valh = (double)h / 3.0 - 2.0;
    if (mIsDual) {
        double xsp = (double)w / 2.0 + 1.0;
        double xsm = (double)w / 2.0 - 1.0;
        double valw = (mValue / 100.0) * ((double)w / 2.0 - 2.0);

        if (fabs(valw) > 0.1) {
            if (valw >= 0.0) {
                painter.setBrush(c_pos);
                painter.drawRect(xsp, 0, valw, valh);
            } else {
                painter.setBrush(c_neg);
                painter.drawRect(xsm + valw, 1, -valw, valh);
            }
        }
    } else {
        if (mValue >= 0.0) {
            painter.setBrush(c_pos);
            painter.drawRect(0, 1, (w * mValue) / 100.0, valh);
        } else {
            painter.setBrush(c_neg);
            painter.drawRect(w + w * (mValue / 100.0), 1, w, valh);
        }
    }
}
