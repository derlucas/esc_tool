/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef VTEXTBROWSER_H
#define VTEXTBROWSER_H

#include <QTextEdit>

class VTextBrowser : public QTextEdit
{
    Q_OBJECT

public:
    explicit VTextBrowser(QWidget *parent = 0);

    void mousePressEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *e) Q_DECL_OVERRIDE;

private:
    QString mLastAnchor;

};

#endif // VTEXTBROWSER_H
