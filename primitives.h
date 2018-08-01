/*!
\author Ken Jinks
\date Aug 2018
\file primitives.h
\brief This file contains the prototypes for primitives.cpp
\brief and is documented using Doxygen markup
*/

#ifndef _PRIMITIVES_H_
#define _PRIMITIVES_H_

#include "jinks_math.h"
#include <iostream>
#include <string>
#include <vector>

using namespace JinksMath;

namespace JinksDraw
{


  /*!
    \class Primitive
    \brief Empty class that all primitives inherit from. Useful for making lists.
  */
  class Primitive
  {
    //empty class
  };

  const Primitive PRIME_NULL = Primitive();
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
    Point(double x = 0.0, double y = 0.0);

    /*!
    \fn double getX()
    \brief access the x coordinate
    \return the x coordinate as a double

    \fn double getY()
    \brief access the y coordinate
    \return the y coordinate as a double
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

    friend std::ostream& operator<<(std::ostream& os, const Point& pt);

    friend Point operator*(const Point& lhs, const double rhs);
    friend Point operator*(const double lhs, const Point& rhs);

    friend Point operator+(const Point& lhs, const Point& rhs);
    friend Point operator-(const Point& lhs, const Point& rhs);
  };


  /*!
  \class Line : public Primitive
  \brief This class models a 2D line with a deque of points.
  \brief Methods include Intersection, Subpoint, Length, Angle...
  \brief more methods may be created in the future
  */
  class Line : public Primitive
  {
  private:
    Point* start = new Point();
    Point* end = new Point();

  public:
    /*!
    \fn Line(Point* start, Point* end)
    \brief the constructor for a 2D line
    \param const Point& start
    \brief a reference to a start Point
    \param const Point& end
    \brief a reference to an end Point
    */
    Line(Point& newStart, Point& newEnd);

    /*!
    \fn void reset()
    \brief this method resets the class attributes to their default state
    */
    void reset();

    /*!
    \fn Point* getStart()
    \brief returns a pointer to the start Point
    \return a pointer to a Point object

    \fn Point* getEnd()
    \brief returns a pointer to the end Point
    \return a pointer to a Point object
    */
    Point& getStart();
    Point& getEnd();

    /*!
    \fn void setStart(const Point& newStart)
    \brief sets the start to a new Point

    \fn void setEnd(const Point& newEnd)
    \brief sets the end to a new Point
    */
    void setStart(Point& newStart);
    void setEnd(Point& newEnd);

    /*!
    \fn double calcSlope()
    \brief calculates the slope of the line
    \return a slope as a double
    */
    double calcSlope();

    /*!
    \fn std::vector<Point> intersection(Line& intersectingLine)
    \brief returns the intersection of this line and another line if any
    \brief future plans to turn this into a template that will accept any primitive
    \param Line* intersectingLine
    \brief the line intersecting this line
    \return a vector of Point objects
    */
    std::vector<Point> intersection(Line& intersectingLine);

    /*!
    \fn std::vector<Point> subpoint(int divisions = 2)
    \brief returns a vector of points that subdivide the line,
    \brief the default of 2 gives the midpoint
    \param int divisions = 2
    \brief the number of divisions of the line
    \return a vector of Point objects
    */
    std::vector<Point> subpoint(int divisions = 2);

    /*!
    \fn std::vector<Line> subline(int divisions = 2)
    \brief returns a vector of lines that subdivide the line
    \brief the default of 2 gives 2 equal halves
    \param int divisions = 2
    \brief the number of divisions of the line
    \return a vector of Line objects
    */
    std::vector<Line> subline(int divisions = 2);

    /*!
    \fn double getLength()
    \brief calculates and returns the length of the line
    \return the length as a double
    */
    double getLength();

    /*!
    \fn double getAngle()
    \brief calculates and returns the angle of the line in radians
    \return the angle in radians
    */
    double getAngle();
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
