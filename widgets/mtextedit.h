/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef _MTEXTEDIT_H_
#define _MTEXTEDIT_H_

#include <QTextEdit>
#include <QMimeData>
#include <QImage>

class MTextEdit : public QTextEdit {
    Q_OBJECT
public:
    MTextEdit(QWidget *parent);
    void dropImage(const QImage& image, const QString& format);

protected:
    bool canInsertFromMimeData(const QMimeData *source) const;
    void insertFromMimeData(const QMimeData *source);
    QMimeData *createMimeDataFromSelection() const;

};

#endif
