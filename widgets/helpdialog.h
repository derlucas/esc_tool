/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>
#include "configparams.h"

namespace Ui {
class HelpDialog;
}

class HelpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HelpDialog(QString title, QString text, QWidget *parent = 0);
    ~HelpDialog();

    void showEvent(QShowEvent *event) override;

    static void showHelp(QWidget *parent, ConfigParams *params, QString name, bool modal = true);
    static void showHelp(QWidget *parent, QString title, QString text);

private slots:
    void on_okButton_clicked();

private:
    Ui::HelpDialog *ui;
};

#endif // HELPDIALOG_H
