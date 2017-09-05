/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */
 
#ifndef PARAMDIALOG_H
#define PARAMDIALOG_H

#include <QDialog>
#include "configparams.h"

namespace Ui {
class ParamDialog;
}

class ParamDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ParamDialog(QString title,
                         QString text,
                         ConfigParams *params,
                         QStringList names,
                         QWidget *parent = 0);
    ~ParamDialog();

    static void showParams(QString title,
                           QString text,
                           ConfigParams *params,
                           QStringList names,
                           QWidget *parent = 0);

private slots:
    void on_closeButton_clicked();

private:
    Ui::ParamDialog *ui;
    ConfigParams mConfig;

};

#endif // PARAMDIALOG_H
