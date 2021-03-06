/* Copyright (c) 2012-2016 Big Ladder Software. All rights reserved.
* See the LICENSE file for additional terms and conditions. */

#ifndef Functions_HPP
#define Functions_HPP

#include "libkiva_export.h"

#include <fstream>
#include <math.h>
#include <algorithm>
#include <vector>

namespace Kiva {

bool LIBKIVA_EXPORT isLessThan(double first, double second);
bool LIBKIVA_EXPORT isLessOrEqual(double first, double second);
bool LIBKIVA_EXPORT isEqual(double first, double second);
bool LIBKIVA_EXPORT isEqual(double first, double second, double epsilon);
bool LIBKIVA_EXPORT isGreaterThan(double first, double second);
bool LIBKIVA_EXPORT isGreaterOrEqual(double first, double second);
bool LIBKIVA_EXPORT isEven(int N);
bool LIBKIVA_EXPORT isOdd(int N);
void solveTDM(const std::vector<double>& a1, const std::vector<double>& a2,
          std::vector<double>& a3, std::vector<double>& b,
              std::vector<double>& x);
}

#endif
