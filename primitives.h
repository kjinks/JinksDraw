/*!
\author Ken Jinks
\date Aug 2018
\file primitives.h
\brief This file contains the prototypes for primitives.cpp
*/

#ifndef _PRIMITIVES_H_
#define _PRIMITIVES_H_

#include <vector>

namespace JinksDraw
{
  /*!
    \class Primitive
    \brief Empty class that all primitives inhert from. Useful for making lists.
  */
  class Primitive
  {
    //empty class
  };

  /*!
    \class Point : public Primitive
    \brief This class models a point in 2D space with an x and a y coordinate
  */
  class Point : public Primitive
  {
  private:
    /*!
    \var double x
    \brief the x coordinate
    \var double y
    \brief the y coordinate
    */
    double x;
    double y;

  public:
    /*!
    \fn Point(double x, double y)
    \brief the Point constructor
    \param double x
    \brief the x coordinate
    \param double y
    \brief the y coordinate
    */
    Point(double x, double y);

    /*!
    \fn double getX()
    \brief access the x coordinate
    \fn double getY()
    \brief access the y coordinate
    */
    double getX();
    double getY();

    /*!
    \fn void setX(double x)
    \brief sets the x coordinate
    \param double x
    \brief the value to set the x coordinate
    \fn void setY(double y)
    \brief sets the y coordinate
    \param double y
    \brief the value to set the y coordinate
    */
    void setX(double x);
    void setY(double y);
  };

  /*!
  \class Line : public Primitive
  \brief This class models a 2D line with starting and ending points.
  \brief Methods include Intersection, Midpoint, Length, Angle...
  \brief more methods may be created in the future
  */
  class Line : public Primitive
  {
  private:
    /*!
    \var Point* start
    \brief a pointer to the start Point
    \var Point* end
    \brief a point to the end Point
    */
    Point* start;
    Point* end;
  public:
    /*!
    \fn Line(const Point& start, const Point& end)
    \brief the constructor for a 2D line
    \param const Point& start
    \brief a reference to a start Point
    \param const Point& end
    \brief a reference to an end Point
    */
    Line(const Point& start, const Point& end);

    /*!
    \fn Point* getStart()
    \brief returns a pointer to the start Point
    \fn Point* getEnd()
    \brief returns a pointer to the end Point
    */
    Point* getStart();
    Point* getEnd();

    /*!
    \fn void setStart(const Point& newStart)
    \brief sets the start to a new Point
    \fn void setEnd(const Point& newEnd)
    \brief sets the end to a new Point
    */
    void setStart(const Point& newStart);
    void setEnd(const Point& newEnd);

    /*!
    \fn std::vector<Point*> intersection(const Line& intersectingLine)
    \brief returns the intersection of this line and another line if any
    \brief future plans to turn this into a template that will accept any primitive
    */
    std::vector<Point*> intersection(const Line& intersectingLine);

  };

  class Circle : public Primitive
  {
  private:
    Point* origin;
    double radius;
  public:
    Circle(const Point& origin, double radius);
  };

  class Rectangle : public Primitive
  {
  private:
    Point* lowerLeft;
    Point* upperRight;
  public:
    Rectangle(const Point& lowerLeft, const Point& upperRight);
  };
}

#endif
