/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PAGEFIRMWARE_H
#define PAGEFIRMWARE_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class PageFirmware;
}

class PageFirmware : public QWidget
{
    Q_OBJECT

public:
    explicit PageFirmware(QWidget *parent = 0);
    ~PageFirmware();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void fwUploadStatus(const QString &status, double progress, bool isOngoing);
    void fwVersionReceived(int major, int minor, QString hw, QByteArray uuid);
    void updateHwList(QString hw = "");
    void updateFwList();
    void updateBlList(QString hw = "");

    void on_chooseButton_clicked();
    void on_uploadButton_clicked();
    void on_readVersionButton_clicked();
    void on_cancelButton_clicked();
    void on_changelogButton_clicked();

private:
    Ui::PageFirmware *ui;
    VescInterface *mVesc;

};

#endif // PAGEFIRMWARE_H
