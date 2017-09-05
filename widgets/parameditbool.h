/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PARAMEDITBOOL_H
#define PARAMEDITBOOL_H

#include <QWidget>
#include "configparams.h"

namespace Ui {
class ParamEditBool;
}

class ParamEditBool : public QWidget
{
    Q_OBJECT

public:
    explicit ParamEditBool(QWidget *parent = 0);
    ~ParamEditBool();
    void setConfig(ConfigParams *config);
    QString name() const;
    void setName(const QString &name);

private slots:
    void paramChangedBool(QObject *src, QString name, bool newParam);

    void on_readButton_clicked();
    void on_readDefaultButton_clicked();
    void on_helpButton_clicked();
    void on_valueBox_currentIndexChanged(int index);

private:
    Ui::ParamEditBool *ui;
    ConfigParams *mConfig;
    QString mName;
};

#endif // PARAMEDITBOOL_H
