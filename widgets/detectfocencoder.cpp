/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "detectfocencoder.h"
#include "ui_detectfocencoder.h"
#include "helpdialog.h"
#include <QMessageBox>

DetectFocEncoder::DetectFocEncoder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetectFocEncoder)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;
}

DetectFocEncoder::~DetectFocEncoder()
{
    delete ui;
}

void DetectFocEncoder::on_helpButton_clicked()
{
    if (mVesc) {
        HelpDialog::showHelp(this, mVesc->infoConfig(), "help_foc_encoder_detect");
    }
}

void DetectFocEncoder::on_startButton_clicked()
{
    if (mVesc) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this,
                                     tr("Detect FOC Encoder Parameters"),
                                     tr("This is going to turn the motor slowly. Make "
                                        "sure that nothing is in the way."),
                                     QMessageBox::Ok | QMessageBox::Cancel);

        if (reply == QMessageBox::Ok) {
            mVesc->commands()->measureEncoder(ui->currentBox->value());
        }
    }
}

void DetectFocEncoder::on_applyButton_clicked()
{
    if (mVesc) {
        mVesc->mcConfig()->updateParamDouble("foc_encoder_offset", ui->offsetBox->value());
        mVesc->mcConfig()->updateParamDouble("foc_encoder_ratio", ui->ratioBox->value());
        mVesc->mcConfig()->updateParamBool("foc_encoder_inverted", ui->invertedBox->currentIndex() != 0);
        mVesc->emitStatusMessage(tr("Encoder Parameters Applied"), true);
    }
}

VescInterface *DetectFocEncoder::vesc() const
{
    return mVesc;
}

void DetectFocEncoder::setVesc(VescInterface *vesc)
{
    mVesc = vesc;

    if (mVesc) {
        connect(mVesc->commands(), SIGNAL(encoderParamReceived(double,double,bool)),
                this, SLOT(encoderParamReceived(double,double,bool)));
    }
}

void DetectFocEncoder::encoderParamReceived(double offset, double ratio, bool inverted)
{
    if (offset > 1000.0) {
        mVesc->emitStatusMessage(tr("Encoder not enabled in firmware"), false);
        QMessageBox::critical(this, "Error", "Encoder support is not enabled. Enable it in the general settings.");
    } else {
        mVesc->emitStatusMessage(tr("Encoder Result Received"), true);
        ui->offsetBox->setValue(offset);
        ui->ratioBox->setValue(ratio);
        ui->invertedBox->setCurrentIndex(inverted ? 1 : 0);
    }
}
