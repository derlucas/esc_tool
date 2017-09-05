/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "imagewidget.h"
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

ImageWidget::ImageWidget(QWidget *parent) : QWidget(parent)
{

}

void ImageWidget::paintEvent(QPaintEvent *event)
{
    (void)event;
    if (!mPixmap.isNull()) {
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
        painter.fillRect(rect(), Qt::transparent);

        int pw = mPixmap.width();
        int ph = mPixmap.height();
        int h = height();

        painter.drawPixmap(0, 0, (pw * h) / ph, h, mPixmap);
    }
}

QPixmap ImageWidget::pixmap() const
{
    return mPixmap;
}

void ImageWidget::setPixmap(const QPixmap &pixmap)
{
    mPixmap = pixmap;
}
