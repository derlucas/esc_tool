/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PARAMEDITENUM_H
#define PARAMEDITENUM_H

#include <QWidget>
#include "configparams.h"

namespace Ui {
class ParamEditEnum;
}

class ParamEditEnum : public QWidget
{
    Q_OBJECT

public:
    explicit ParamEditEnum(QWidget *parent = 0);
    ~ParamEditEnum();
    void setConfig(ConfigParams *config);
    QString name() const;
    void setName(const QString &name);

private slots:
    void paramChangedEnum(QObject *src, QString name, int newParam);

    void on_readButton_clicked();
    void on_readDefaultButton_clicked();
    void on_helpButton_clicked();
    void on_valueBox_currentIndexChanged(int index);

private:
    Ui::ParamEditEnum *ui;
    ConfigParams *mConfig;
    QString mName;

};

#endif // PARAMEDITENUM_H
