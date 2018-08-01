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
  T lerp (const T& value1, const T& value2, double d)
  {
    return (value1 * (1.0 - d)) + (value2 * (d));
  }
}

#endif
