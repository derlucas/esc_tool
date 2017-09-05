/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PARAMEDITSTRING_H
#define PARAMEDITSTRING_H

#include <QWidget>
#include "configparams.h"

namespace Ui {
class ParamEditString;
}

class ParamEditString : public QWidget
{
    Q_OBJECT

public:
    explicit ParamEditString(QWidget *parent = 0);
    ~ParamEditString();
    void setConfig(ConfigParams *config);
    QString name() const;
    void setName(const QString &name);

private slots:
    void paramChangedQString(QObject *src, QString name, QString newParam);

    void on_helpButton_clicked();
    void on_valueEdit_textChanged(const QString &arg1);

private:
    Ui::ParamEditString *ui;
    ConfigParams *mConfig;
    QString mName;

};

#endif // PARAMEDITSTRING_H
