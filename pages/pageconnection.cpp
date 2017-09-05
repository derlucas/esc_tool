/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "pageconnection.h"
#include "ui_pageconnection.h"
#include "widgets/helpdialog.h"
#include "util.h"
#include <QMessageBox>

PageConnection::PageConnection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageConnection)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mVesc = 0;
    mTimer = new QTimer(this);

    connect(mTimer, SIGNAL(timeout()),
            this, SLOT(timerSlot()));

    mTimer->start(20);
}

PageConnection::~PageConnection()
{
    delete ui;
}

VescInterface *PageConnection::vesc() const
{
    return mVesc;
}

void PageConnection::setVesc(VescInterface *vesc)
{
    mVesc = vesc;
    on_serialRefreshButton_clicked();
}

void PageConnection::timerSlot()
{
    if (mVesc) {
        QString str = mVesc->getConnectedPortName();
        if (str != ui->statusLabel->text()) {
            ui->statusLabel->setText(mVesc->getConnectedPortName());
        }

        // CAN fwd
        if (ui->canFwdButton->isChecked() != mVesc->commands()->getSendCan()) {
            ui->canFwdButton->setChecked(mVesc->commands()->getSendCan());
        }
    }
}

void PageConnection::on_serialRefreshButton_clicked()
{
    if (mVesc) {
        ui->serialPortBox->clear();
        QList<VSerialInfo_t> ports = mVesc->listSerialPorts();
        foreach(const VSerialInfo_t &port, ports) {
            ui->serialPortBox->addItem(port.name, port.systemPath);
        }
        ui->serialPortBox->setCurrentIndex(0);

        on_canFwdBox_valueChanged(ui->canFwdBox->value());
    }
}

void PageConnection::on_serialDisconnectButton_clicked()
{
    if (mVesc) {
        mVesc->disconnectPort();
    }
}

void PageConnection::on_serialConnectButton_clicked()
{
    if (mVesc) {
        mVesc->connectSerial(ui->serialPortBox->currentData().toString(),
                             ui->serialBaudBox->value());
    }
}

void PageConnection::on_tcpDisconnectButton_clicked()
{
    if (mVesc) {
        mVesc->disconnectPort();
    }
}

void PageConnection::on_tcpConnectButton_clicked()
{
    if (mVesc) {
        mVesc->connectTcp(ui->tcpServerEdit->text(), ui->tcpPortBox->value());
    }
}

void PageConnection::on_canFwdBox_valueChanged(int arg1)
{
    if (mVesc) {
        mVesc->commands()->setCanSendId(arg1);
    }
}

void PageConnection::on_helpButton_clicked()
{
    if (mVesc) {
        HelpDialog::showHelp(this, mVesc->infoConfig(), "help_can_forward");
    }
}

void PageConnection::on_canFwdButton_toggled(bool checked)
{
    if (mVesc) {
        mVesc->commands()->setSendCan(checked);
    }
}

void PageConnection::on_autoConnectButton_clicked()
{
    util::autoconnectBlockingWithProgress(mVesc, this);
}
