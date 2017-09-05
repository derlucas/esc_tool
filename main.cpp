/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>
#include <QSettings>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    // Settings
    QCoreApplication::setOrganizationName("ESC");
    QCoreApplication::setApplicationName("ESC Tool");

    // DPI settings
    // TODO: http://www.qcustomplot.com/index.php/support/forum/1344

    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QCoreApplication::setAttribute(Qt::AA_Use96Dpi);

    QSettings set;
    bool scaleAuto = true;
    double scale = 1.0;

    if (set.contains("app_scale_auto")) {
        scaleAuto = set.value("app_scale_auto").toBool();
    } else {
        set.setValue("app_scale_auto", scaleAuto);
    }

    if (scaleAuto) {
        QApplication tmp(argc, argv);
        QRect rec = tmp.desktop()->screenGeometry();
        int height = rec.height();
        int width = rec.width();
        double ptFont = tmp.font().pointSizeF();
        if (ptFont < 0.0) {
            ptFont = tmp.font().pixelSize();
        }

        if (width > 3000 && height > 1700) {
            scale = 1.5;
        } else {
            if (ptFont > 11.0) {
                scale = ptFont / 11.0;
            }
        }

        set.setValue("app_scale_factor", scale);
    } else if (set.contains("app_scale_factor")) {
        scale = set.value("app_scale_factor").toDouble();
    }

    set.setValue("app_scale_factor", scale);

    if (scale > 1.01) {
        qputenv("QT_SCALE_FACTOR", set.value("app_scale_factor").toByteArray());
        qputenv("QT_SCALE_FACTOR", QString::number(scale).toLocal8Bit());
    }

    QApplication a(argc, argv);

    // Ignore the OS font settings and do scaling with the method above.
    QFont font = qApp->font();
    if (font.pixelSize() > 0) {
        font.setPixelSize(11);
    } else {
        font.setPointSize(11);
    }
    qApp->setFont(font);

    // Style
    a.setStyleSheet("");
    a.setStyle(QStyleFactory::create("Fusion"));

    MainWindow w;
    w.show();

    return a.exec();
}
