/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "paramtable.h"
#include <QDebug>
#include <QHeaderView>
#include <QLabel>

ParamTable::ParamTable(QWidget *parent) : QTableWidget(parent)
{
    setColumnCount(2);

    QStringList headers;
    headers.append("Name");
    headers.append("Edit");

    setHorizontalHeaderLabels(headers);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    setSelectionMode(QAbstractItemView::NoSelection);
    horizontalHeader()->setStretchLastSection(true);
    horizontalHeader()->setVisible(false);
    verticalHeader()->setVisible(false);
}

bool ParamTable::addParamRow(ConfigParams *params, QString paramName)
{
    bool res = false;
    QWidget *editor = params->getEditor(paramName);
    QString name = params->getLongName(paramName);

    if (editor) {
        int row = rowCount();
        setRowCount(row + 1);
        QTableWidgetItem *item = new QTableWidgetItem(name);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        setItem(row, 0, item);
        setCellWidget(row, 1, editor);
        res = true;

        resizeColumnToContents(0);
        resizeRowsToContents();
    }

    return res;
}

void ParamTable::addRowSeparator(QString text)
{
    int row = rowCount();
    setRowCount(row + 1);

    QLabel *label = new QLabel(text);
    label->setAlignment(Qt::AlignHCenter);
    QFont font;
    font.setBold(true);
    label->setFont(font);
    label->setStyleSheet("QLabel { background-color : lightblue; color : black; }");

    setCellWidget(row, 0, label);
    setSpan(row, 0, 1, 2);

    resizeColumnToContents(0);
    resizeRowsToContents();
}
