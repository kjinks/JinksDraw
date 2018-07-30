/*!
\author Ken Jinks
\date Aug 2018
\file primitives.h
\brief This file contains the prototypes for primitives.cpp
*/

#ifndef _PRIMITIVES_H_
#define _PRIMITIVES_H_

namespace JinksDraw
{
  /*!
    \class Point
    \brief This class models a point in 2D space
  */

  class Point
  {
  private:
    double x;
    double y;

  public:
    Point(double x, double y);

    double getX();
    double getY();

    void setX(double x);
    void setY(double y);
  };

  class Line
  {
  private:
    Point start;
    Point end;
  public:
    Line(Point& start, Point& end);
  };

  class Circle
  {
  private:
    Point origin;
    double radius;
  public:
    Circle(Point& origin, double radius);
  };

  class Rectangle
  {
  private:
    Point lowerLeft;
    Point upperRight;
  public:
    Rectangle(Point& lowerLeft, Point& upperRight);
  };
}

#endif
