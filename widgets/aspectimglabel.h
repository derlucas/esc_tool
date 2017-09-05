/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef ASPECTIMGLABEL_H
#define ASPECTIMGLABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class AspectImgLabel : public QLabel
{
    Q_OBJECT

public:
    AspectImgLabel(Qt::Orientation orientatio = Qt::Vertical,
                   QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *event);

private:
    Qt::Orientation mOrientation;

};

#endif // ASPECTIMGLABEL_H
