/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef PPMMAP_H
#define PPMMAP_H

#include <QWidget>
#include "vescinterface.h"

namespace Ui {
class PpmMap;
}

class PpmMap : public QWidget
{
    Q_OBJECT

public:
    explicit PpmMap(QWidget *parent = 0);
    ~PpmMap();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void decodedPpmReceived(double value, double last_len);

    void on_controlTypeBox_currentIndexChanged(int index);
    void on_helpButton_clicked();
    void on_resetButton_clicked();
    void on_applyButton_clicked();

private:
    Ui::PpmMap *ui;
    VescInterface *mVesc;
    bool mResetDone;

};

#endif // PPMMAP_H
