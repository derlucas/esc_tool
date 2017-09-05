/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGELISTITEM_H
#define PAGELISTITEM_H

#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QSpacerItem>
#include <QResizeEvent>
#include "datatypes.h"

class PageListItem : public QWidget
{
    Q_OBJECT
public:
    explicit PageListItem(QString name = "",
                          QString icon = "",
                          QString groupIcon = "",
                          QWidget *parent = 0);
    void setName(const QString &name);
    void setIcon(const QString &path);
    void setGroupIcon(const QString &path);
    QString name();
    void setBold(bool bold);
    void setIndented(bool indented);

signals:

public slots:

private:
    QLabel *mIconLabel;
    QLabel *mNameLabel;
    QLabel *mGroupLabel;
    QSpacerItem *mSpaceStart;

};

#endif // PAGELISTITEM_H
