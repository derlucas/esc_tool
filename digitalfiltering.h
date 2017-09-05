/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef DIGITALFILTERING_H
#define DIGITALFILTERING_H

#include <QVector>

class DigitalFiltering
{
public:
    DigitalFiltering();

    static void fft(int dir,int m,double *real,double *imag);
    static void dft(int dir, int len, double *real, double *imag);
    static void fftshift(double *data, int len);
    static void hamming(double *data, int len);
    static void zeroPad(double *data, double *result, int dataLen, int resultLen);
    static int whichPowerOfTwo(unsigned int number);

    static QVector<double> filterSignal(const QVector<double> &signal, const QVector<double> &filter, bool padAfter = false);
    static QVector<double> generateFirFilter(double f_break, int bits, bool useHamming);
    static QVector<double> fftWithShift(QVector<double> &signal, int resultBits, bool scaleByLen = false);
};

#endif // DIGITALFILTERING_H
