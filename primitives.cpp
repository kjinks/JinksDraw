/*!
\author Ken Jinks
\date Aug 2018
\file primitives.cpp
\brief Primitives are modeled here. Primitives are basic geometries that can be
brought together to build more complex geometries.
*/
#include "primitives.h"

namespace JinksDraw
{

    Point::Point(double x, double y)
    {
      this->x = x;
      this->y = y;
    }

    double Point::getX()
    {
      return this->x;
    }

    double Point::getY()
    {
      return this->y;
    }

    void Point::setX(double x)
    {
      this->x = x;
    }

    void Point::setY(double y)
    {
      this->y = y;
    }


}
