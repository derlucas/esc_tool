/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "vtextbrowser.h"
#include <QDesktopServices>
#include <QMouseEvent>

VTextBrowser::VTextBrowser(QWidget *parent)
    : QTextEdit(parent)
{
    setReadOnly(true);
    setTextInteractionFlags(Qt::TextSelectableByMouse |
                            Qt::LinksAccessibleByMouse |
                            Qt::LinksAccessibleByKeyboard);

    viewport()->setMouseTracking(true);
}

void VTextBrowser::mousePressEvent(QMouseEvent *e)
{
    mLastAnchor = (e->button() & Qt::LeftButton) ? anchorAt(e->pos()) : QString();
    QTextEdit::mousePressEvent(e);
}

void VTextBrowser::mouseReleaseEvent(QMouseEvent *e)
{
    if ((e->button() & Qt::LeftButton) &&
            !mLastAnchor.isEmpty() &&
            anchorAt(e->pos()) == mLastAnchor) {
        QDesktopServices::openUrl(mLastAnchor);
    }

    QTextEdit::mouseReleaseEvent(e);
}

void VTextBrowser::mouseMoveEvent(QMouseEvent *e)
{
    if (!anchorAt(e->pos()).isEmpty()) {
        viewport()->setCursor(Qt::PointingHandCursor);
    } else {
        viewport()->setCursor(Qt::ArrowCursor);
    }

    QTextEdit::mouseMoveEvent(e);
}
