/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "aspectimglabel.h"

AspectImgLabel::AspectImgLabel(Qt::Orientation orientation, QWidget *parent) :
    QLabel(parent), mOrientation(orientation)
{

}

void AspectImgLabel::resizeEvent(QResizeEvent *event)
{
    QLabel::resizeEvent(event);

    const QPixmap *pix = pixmap();

    if (pix) {
        int wLabel = width();
        int hLabel = height();
        int wImg = pix->width();
        int hImg = pix->height();

        if (mOrientation == Qt::Horizontal) {
            setMaximumHeight((wLabel * hImg) / wImg);
        } else if (hLabel != hImg) {
            setMaximumWidth((hLabel * wImg) / hImg);
        }
    }
}
