/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PARAMETEREDITOR_H
#define PARAMETEREDITOR_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include "configparams.h"

namespace Ui {
class ParameterEditor;
}

class ParameterEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit ParameterEditor(QWidget *parent = 0);
    ~ParameterEditor();
    void setParams(const ConfigParams *params);

private slots:
    void timerSlot();

    void on_paramRemoveButton_clicked();
    void on_paramDownButton_clicked();
    void on_paramUpButton_clicked();
    void on_paramOpenButton_clicked();
    void on_paramSaveButton_clicked();
    void on_paramResetButton_clicked();
    void on_serRemoveButton_clicked();
    void on_serDownButton_clicked();
    void on_serUpButton_clicked();
    void on_serAddButton_clicked();
    void on_paramList_doubleClicked(const QModelIndex &index);
    void on_enumAddButton_clicked();
    void on_enumRemoveButton_clicked();
    void on_enumMoveUpButton_clicked();
    void on_enumMoveDownButton_clicked();
    void on_actionLoad_XML_triggered();
    void on_actionSave_XML_as_triggered();
    void on_actionDeleteAll_triggered();
    void on_doubleTxTypeBox_currentIndexChanged(int index);

private:
    Ui::ParameterEditor *ui;
    ConfigParams mParams;
    QTimer *mTimer;
    QLabel *mStatusLabel;
    int mStatusInfoTime;

    void updateUi();
    void setEditorValues(QString name, ConfigParam p);
    QString getEditorValues(ConfigParam *p);
    void addEnum(QString name);
    void showStatusInfo(QString info, bool isGood);

};

#endif // PARAMETEREDITOR_H
