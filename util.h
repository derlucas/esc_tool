/**
 * This file is part of ESC Tool
 *
 *  Copyright 2016-2017 by it's authors. 
 *  Some rights reserved. See COPYING, AUTHORS.
 */

#ifndef UTIL_H
#define UTIL_H

#include "vescinterface.h"
#include <QWidget>

namespace util {

double map(double x, double in_min, double in_max, double out_min, double out_max);
float throttle_curve(float val, float curve_acc, float curve_brake, int mode);
bool autoconnectBlockingWithProgress(VescInterface *vesc, QWidget *parent = 0);

}

#endif // UTIL_H
