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
    Point* start;
    Point* end;
  public:
    Line(const Point& start, const Point& end);
  };

  class Circle
  {
  private:
    Point* origin;
    double radius;
  public:
    Circle(const Point& origin, double radius);
  };

  class Rectangle
  {
  private:
    Point* lowerLeft;
    Point* upperRight;
  public:
    Rectangle(const Point& lowerLeft, const Point& upperRight);
  };
}

#endif
