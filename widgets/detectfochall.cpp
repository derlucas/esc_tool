/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "detectfochall.h"
#include "ui_detectfochall.h"
#include "helpdialog.h"
#include <QMessageBox>

DetectFocHall::DetectFocHall(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetectFocHall)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;
}

DetectFocHall::~DetectFocHall()
{
    delete ui;
}

void DetectFocHall::on_helpButton_clicked()
{
    if (mVesc) {
        HelpDialog::showHelp(this, mVesc->infoConfig(), "help_foc_hall_detect");
    }
}

void DetectFocHall::on_startButton_clicked()
{
    if (mVesc) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this,
                                     tr("Detect FOC Hall Sensor Parameters"),
                                     tr("This is going to turn the motor slowly. Make "
                                        "sure that nothing is in the way."),
                                     QMessageBox::Ok | QMessageBox::Cancel);

        if (reply == QMessageBox::Ok) {
            mVesc->commands()->measureHallFoc(ui->currentBox->value());
        }
    }
}

void DetectFocHall::on_applyButton_clicked()
{
    if (mVesc) {
        mVesc->mcConfig()->updateParamInt("foc_hall_table_0", ui->hall0Box->value());
        mVesc->mcConfig()->updateParamInt("foc_hall_table_1", ui->hall1Box->value());
        mVesc->mcConfig()->updateParamInt("foc_hall_table_2", ui->hall2Box->value());
        mVesc->mcConfig()->updateParamInt("foc_hall_table_3", ui->hall3Box->value());
        mVesc->mcConfig()->updateParamInt("foc_hall_table_4", ui->hall4Box->value());
        mVesc->mcConfig()->updateParamInt("foc_hall_table_5", ui->hall5Box->value());
        mVesc->mcConfig()->updateParamInt("foc_hall_table_6", ui->hall6Box->value());
        mVesc->mcConfig()->updateParamInt("foc_hall_table_7", ui->hall7Box->value());
        mVesc->emitStatusMessage(tr("Hall Sensor Parameters Applied"), true);
    }
}

VescInterface *DetectFocHall::vesc() const
{
    return mVesc;
}

void DetectFocHall::setVesc(VescInterface *vesc)
{
    mVesc = vesc;

    if (mVesc) {
        connect(mVesc->commands(), SIGNAL(focHallTableReceived(QVector<int>,int)),
                this, SLOT(focHallTableReceived(QVector<int>,int)));
    }
}

void DetectFocHall::focHallTableReceived(QVector<int> hall_table, int res)
{
    if (res != 0) {
        mVesc->emitStatusMessage(tr("Bad FOC Hall Detection Result Received"), false);
    } else {
        mVesc->emitStatusMessage(tr("FOC Hall Result Received"), true);
        ui->hall0Box->setValue(hall_table.at(0));
        ui->hall1Box->setValue(hall_table.at(1));
        ui->hall2Box->setValue(hall_table.at(2));
        ui->hall3Box->setValue(hall_table.at(3));
        ui->hall4Box->setValue(hall_table.at(4));
        ui->hall5Box->setValue(hall_table.at(5));
        ui->hall6Box->setValue(hall_table.at(6));
        ui->hall7Box->setValue(hall_table.at(7));
    }
}
