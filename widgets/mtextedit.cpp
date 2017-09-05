/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#include "mtextedit.h"
#include <QTextDocument>
#include <QTextCursor>
#include <QImage>
#include <QByteArray>
#include <QBuffer>
#include <stdlib.h>
#include <QInputDialog>

MTextEdit::MTextEdit(QWidget *parent) : QTextEdit(parent) {
}

bool MTextEdit::canInsertFromMimeData(const QMimeData *source) const {
    return source->hasImage() || QTextEdit::canInsertFromMimeData(source);
}

void MTextEdit::insertFromMimeData(const QMimeData *source) {
    if (source->hasImage()) {
        QStringList formats = source->formats();
        QString format;
        for (int i=0; i<formats.size(); i++) {
            if (formats[i] == "image/bmp")  { format = "BMP";  break; }
            if (formats[i] == "image/jpeg") { format = "JPG";  break; }
            if (formats[i] == "image/jpg")  { format = "JPG";  break; }
            if (formats[i] == "image/gif")  { format = "GIF";  break; }
            if (formats[i] == "image/png")  { format = "PNG";  break; }
            if (formats[i] == "image/pbm")  { format = "PBM";  break; }
            if (formats[i] == "image/pgm")  { format = "PGM";  break; }
            if (formats[i] == "image/ppm")  { format = "PPM";  break; }
            if (formats[i] == "image/tiff") { format = "TIFF"; break; }
            if (formats[i] == "image/xbm")  { format = "XBM";  break; }
            if (formats[i] == "image/xpm")  { format = "XPM";  break; }
        }
        if (!format.isEmpty()) {
//          dropImage(qvariant_cast<QImage>(source->imageData()), format);
            dropImage(qvariant_cast<QImage>(source->imageData()), "JPG");
            return;
        }
    }
    QTextEdit::insertFromMimeData(source);
}

QMimeData *MTextEdit::createMimeDataFromSelection() const {
    return QTextEdit::createMimeDataFromSelection();
}

void MTextEdit::dropImage(const QImage& image, const QString& format) {
    bool ok;
    int w = QInputDialog::getInt(this, tr("Insert Image"),
                                 tr("Enter image width to use (source width: %1)").arg(image.width()),
                                 400, 5, 1920, 20, &ok);

    if (ok) {
        int h = (w * image.height()) / image.width();
        QImage img1 = image.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

        QByteArray bytes;
        QBuffer buffer(&bytes);
        buffer.open(QIODevice::WriteOnly);

        img1.save(&buffer, format.toLocal8Bit().data());
        buffer.close();
        QByteArray base64 = bytes.toBase64();
        QByteArray base64l;
        for (int i=0; i<base64.size(); i++) {
            base64l.append(base64[i]);
            if (i%80 == 0) {
                base64l.append("\n");
            }
        }

        QTextCursor cursor = textCursor();
        QTextImageFormat imageFormat;
        imageFormat.setWidth  ( img1.width() );
        imageFormat.setHeight ( img1.height() );
        imageFormat.setName   ( QString("data:image/%1;base64,%2")
                                .arg(QString("%1.%2").arg(rand()).arg(format))
                                .arg(base64l.data())
                                );
        cursor.insertImage    ( imageFormat );
    }
}
