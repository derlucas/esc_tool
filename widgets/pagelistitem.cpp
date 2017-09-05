/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "pagelistitem.h"
#include <QHBoxLayout>

PageListItem::PageListItem(QString name,
                           QString icon,
                           QString groupIcon,
                           QWidget *parent) : QWidget(parent)
{
    mIconLabel = new QLabel;
    mNameLabel = new QLabel;
    mGroupLabel = new QLabel;
    mSpaceStart = new QSpacerItem(2, 0);

    mIconLabel->setScaledContents(true);
    mGroupLabel->setScaledContents(true);

    setName(name);
    setIcon(icon);
    setGroupIcon(groupIcon);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(0);

    layout->addSpacerItem(mSpaceStart);
    layout->addWidget(mIconLabel);
    layout->addWidget(mNameLabel);
    layout->addStretch();
    layout->addWidget(mGroupLabel);
    layout->addSpacing(2);

    this->setLayout(layout);
}

void PageListItem::setName(const QString &name)
{
    mNameLabel->setText(name);
}

void PageListItem::setIcon(const QString &path)
{
    if (!path.isEmpty()) {
        mIconLabel->setPixmap(QPixmap(path));
        mIconLabel->setFixedSize(15, 15);
    } else {
        mIconLabel->setPixmap(QPixmap());
    }
}

void PageListItem::setGroupIcon(const QString &path)
{
    if (!path.isEmpty()) {
        QPixmap pix(path);
        mGroupLabel->setPixmap(pix);
        mGroupLabel->setFixedSize((15 * pix.width()) / pix.height(), 15);
    } else {
        mSpaceStart->changeSize(2, 0);
        mGroupLabel->setPixmap(QPixmap());
    }
}

QString PageListItem::name()
{
    return mNameLabel->text();
}

void PageListItem::setBold(bool bold)
{
    QFont f = mNameLabel->font();
    f.setBold(bold);
    mNameLabel->setFont(f);
}

void PageListItem::setIndented(bool indented)
{
    mSpaceStart->changeSize(indented ? 15 : 2, 0);
}
