/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGEDEBUGPRINT_H
#define PAGEDEBUGPRINT_H

#include <QWidget>

namespace Ui {
class PageDebugPrint;
}

class PageDebugPrint : public QWidget
{
    Q_OBJECT

public:
    explicit PageDebugPrint(QWidget *parent = 0);
    ~PageDebugPrint();

    static PageDebugPrint* currentMsgHandler;

public slots:
    void printConsole(QString str);

private:
    Ui::PageDebugPrint *ui;
};

#endif // PAGEDEBUGPRINT_H
