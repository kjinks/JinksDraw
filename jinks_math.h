/*!
\author Ken Jinks
\date Aug 2018
\file jinks_math.h
\brief This file contains math functions not in math.h
*/

#ifndef _JINKS_MATH_H_
#define _JINKS_MATH_H_

#include <math.h>

namespace JinksMath
{
  template <class T>
  T lerp ( T& value1, T& value2, double d)
  {
    T wane = (value1 * (1.0 - d));
    T wax = (value2 * (d));
    return wane + wax;
  }
}

#endif
