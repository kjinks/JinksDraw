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
    \brief operators on this class include:

    \brief ostream,
    \code{.cpp}
    cout << Point(10.0, 10.0) << endl; // (10.0, 10.0)
    \endcode

    \brief scale,
    \code{.cpp}
    double d = 10.0;

    Point p1 = Point(1.0, 2.0) * d;
    Point p2 = d * Point(3.0, 4.0);

    cout << p1 << endl; // (10.0, 20.0)
    cout << p2 << endl; // (30.0, 40.0)
    \endcode

    \brief add and subtract.
    \code{.cpp}
    Point p1 = Point(1.0, 2.0)
    Point p2 = Point(3.0, 4.0)

    Point p3 = p1 + p2;
    Point p4 = p2 - p1;

    cout << p3 << endl; // (4.0, 6.0)
    cout << p4 << endl; // (2.0, 2.0)
    \endcode
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
    double x = 0.0;
    double y = 0.0;

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

    /*!
    \fn void setByPolar(double radius, double angle)
    \brief sets the x and y coordinates based on radius and angle from origin (0,0)
    \param double radius
    \brief distance from origin (0,0)
    \param double angle
    \brief angle in radians from origin (0,0)
    */
    void setByPolar(double radius, double angle);

    /*!
    \fn friend std::ostream& operator<<(std::ostream& os, const Point& pt)
    \brief this allows Point to have a stream representation
    \code{.cpp}
    cout << Point(10.0, 10.0) << endl; // (10.0, 10.0)
    \endcode
    */
    friend std::ostream& operator<<(std::ostream& os, const Point& pt);

    /*!
    \fn friend Point operator*(const Point& lhs, const double rhs)
    \brief The * is to scale the coordinates of the Point
    \code{.cpp}
    double d = 10.0;

    Point p1 = Point(1.0, 2.0) * d;

    cout << p1 << endl; // (10.0, 20.0)
    \endcode
    */
    friend Point operator*(const Point& lhs, const double rhs);

    /*!
    \fn friend Point operator*(const double lhs, const Point& rhs)
    \brief The * is to scale the coordinates of the Point
    \code{.cpp}
    double d = 10.0;

    Point p2 = d * Point(3.0, 4.0);

    cout << p2 << endl; // (30.0, 40.0)
    \endcode
    */
    friend Point operator*(const double lhs, const Point& rhs);

    /*!
    \fn friend Point operator/(const double lhs, const Point& rhs)
    \brief The / is to scale the coordinates of the Point
    \code{.cpp}
    double d = 5.0;

    Point p2 = Point(5.0, 25.0) / d;

    cout << p2 << endl; // (1.0, 5.0)
    \endcode
    */
    friend Point operator/(const Point& lhs, const double rhs);

    /*!
    \fn friend Point operator/(const double lhs, const Point& rhs)
    \brief The / is to scale the coordinates of the Point
    \code{.cpp}
    double d = 50.0;

    Point p2 = d / Point(5.0, 25.0);

    cout << p2 << endl; // (10.0, 2.0)
    \endcode
    */
    friend Point operator/(const double lhs, const Point& rhs);


    /*!
    \fn friend Point operator+(const Point& lhs, const Point& rhs)
    \brief Allows adding two Points
    \code{.cpp}
    Point p1 = Point(1.0, 2.0)
    Point p2 = Point(3.0, 4.0)

    Point p3 = p1 + p2;

    cout << p3 << endl; // (4.0, 6.0)
    \endcode
    */
    friend Point operator+(const Point& lhs, const Point& rhs);

    /*!
    \fn friend Point operator-(const Point& lhs, const Point& rhs)
    \brief Allows subtracting two Points
    \code{.cpp}
    Point p1 = Point(1.0, 2.0)
    Point p2 = Point(3.0, 4.0)

    Point p4 = p2 - p1;

    cout << p4 << endl; // (2.0, 2.0)
    \endcode
    */
    friend Point operator-(const Point& lhs, const Point& rhs);
  };


  /*!
  \class Line : public Primitive
  \brief This class models a 2D line with a start point and an end point
  \brief Methods include Intersection, Subpoint, Length, Angle...
  \brief more methods may be created in the future
  \brief Operator ostream is implemented
  \code{.cpp}
  Point p1 = Point(1.0, 2.0)
  Point p2 = Point(3.0, 4.0)
  cout << Line(p1, p2) << endl; // ((1.0, 2.0), (3.0, 4.0))
  \endcode
  */
  class Line : public Primitive
  {
  private:
    /*!
    \var Point* start = new Point();
    \brief start point of line
    \var Point* end = new Point();
    \brief end point of line
    */
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
    \fn void setByPolar(Point start, double radius, double angle
    \brief set the line with an start, radius and angle
    \param Point start
    \brief starting point of the line
    \param double radius
    \brief distance from starting point
    \param double angle
    \brief angle in radians from starting point
    */
    void setByPolar(Point origin, double radius, double angle);

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

    /*!
    \fn Line getUnitLine()
    \brief recalculates end point to be at 1 unit and same angle from start point
    */
    Line getUnitLine();

    /*!
    \fn friend std::ostream& operator<<(std::ostream& os, const Line& ln)
    \brief this allows Line to have a stream representation
    \code{.cpp}
    Point p1 = Point(1.0, 2.0);
    Point p2 = Point(3.0, 4.0);
    cout << Line(p1, p2) << endl; // Line(Point(1.0, 2.0), Point(3.0, 4.0))
    \endcode
    */
    friend std::ostream& operator<<(std::ostream& os, const Line& ln);

    /*!
    \fn friend Point operator-(const Line& lhs, const Point& rhs)
    \brief Allows subtracting two Points
    \code{.cpp}
    Point p1 = Point(1.0, 2.0)
    Point p2 = Point(3.0, 4.0)
    Line l = Line(p1, p2)

    cout << (l - p1) << endl; // Line(Point(0.0, 0.0), Point(2.0, 2.0))
    \endcode
    */
    friend Line operator-(const Line& lhs, const Point& rhs);
  };

  /*!
  \class Circle : public Primitive
  \brief This class models a 2D circle with an origin and a radius
  \brief Methods include Intersection, Subpoint, Subline...
  \brief more methods may be created in the future
  \brief Operator ostream is implemented
  \code{.cpp}
  Point origin = Point(1.0, 2.0);
  double radius = 10.0;
  cout << Circle(origin, radius) << endl; // Circle(O:Point(1.0, 2.0), R:10.0)
  \endcode
  */
  class Circle : public Primitive
  {
  private:
    /*!
    \var Point* origin = new Point()
    \brief origin point of circle
    \var double radius = 0.0
    \brief radius of circle
    */
    Point* origin = new Point();
    double radius = 0.0;
  public:
    Circle(Point& origin, double radius);

    void reset();

    /*!
    \fn Point getOrigin()
    \brief gets the origin

    \fn double getRadius()
    \brief gets the radius
    */
    Point getOrigin();
    double getRadius();

    /*!
    \fn void setOrigin(Point& newOrigin)
    \brief sets the origin

    \fn void setRadius(double newRadius)
    \brief sets the radius
    */
    void setOrigin(Point& newOrigin);
    void setRadius(double newRadius);

    /*!
    \fn std::vector<Point> intersection(Line& line)
    \brief calculates the intersection of this circle and a line
    \param Line& line
    \brief the line to intersect the circle
    \return a vector containing the points of intersection if any
    */
    std::vector<Point> intersection(Line& line);

    /*!
    \fn std::vector<Point> intersection(Circle& circle)
    \brief calculates the intersection of this circle and another circle
    \param Circle& circle
    \brief the circle to intersect the circle
    \return a vector containing the points of intersection if any
    */
    std::vector<Point> intersection(Circle& circle);

    /*!
    \fn std::vector<Point> subpoint(int numDivisions, double phase)
    \brief creates a vector of points about the circle's circumference
    \param int numDivisions
    \brief number of subdivisions around circle
    \param double phase
    \brief the angle offset in radians of the points
    */
    std::vector<Point> subpoint(int numDivisions, double phase);

    /*!
    \fn std::vector<Line> subline(int numDivisions, double phase)
    \brief create a vector of line about the circle's circumference
    \param int numDivisions
    \brief number of subdivisions around circle
    \param double phase
    \brief the angle offset in radians of the lines 
    */
    std::vector<Line> subline(int numDivisions, double phase);

    /*!
    \fn friend std::ostream& operator<<(std::ostream& os, const Circle& cr)
    \brief this allows Circle to have a stream representation
    \code{.cpp}
    Point origin = Point(1.0, 2.0);
    double radius = 10.0;
    cout << Circle(origin, radius) << endl; // Circle(O:Point(1.0, 2.0), R:10.0)
    \endcode
    */
    friend std::ostream& operator<<(std::ostream& os, const Circle& cr);
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
