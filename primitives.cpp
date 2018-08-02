/*!
\author Ken Jinks
\date Aug 2018
\file primitives.cpp
\brief Primitives are modeled here. Primitives are basic geometries that can be
brought together to build more complex geometries.
\brief Doxygen documentation can be found in the header file
*/
#include "primitives.h"

#include <math.h>
#include <iostream>

#define _DEBUG_

namespace JinksDraw
{
    /**************************************************************************
    Templates
    **************************************************************************/

    /**************************************************************************
    Aquired Code Snippets
    **************************************************************************/
    //August 1 2018 02:48
    //from https://gist.github.com/TimSC/47203a0f5f15293d2099507ba5da44e6
    inline double Det(double a, double b, double c, double d)
    {
    	return a*d - b*c;
    }
    ///Calculate intersection of two lines.
    ///\return true if found, false if not found or error
    bool LineLineIntersect(double x1, double y1, //Line 1 start
    	double x2, double y2, //Line 1 end
    	double x3, double y3, //Line 2 start
    	double x4, double y4, //Line 2 end
    	double &ixOut, double &iyOut) //Output
    {
    	//http://mathworld.wolfram.com/Line-LineIntersection.html

    	double detL1 = Det(x1, y1, x2, y2);
    	double detL2 = Det(x3, y3, x4, y4);
    	double x1mx2 = x1 - x2;
    	double x3mx4 = x3 - x4;
    	double y1my2 = y1 - y2;
    	double y3my4 = y3 - y4;

    	double xnom = Det(detL1, x1mx2, detL2, x3mx4);
    	double ynom = Det(detL1, y1my2, detL2, y3my4);
    	double denom = Det(x1mx2, y1my2, x3mx4, y3my4);
    	if(denom == 0.0)//Lines don't seem to cross
    	{
    		ixOut = NAN;
    		iyOut = NAN;
    		return false;
    	}

    	ixOut = xnom / denom;
    	iyOut = ynom / denom;
    	if(!isfinite(ixOut) || !isfinite(iyOut)) //Probably a numerical issue
    		return false;

    	return true; //All OK
    }

    /**************************************************************************
    Class Point
    **************************************************************************/
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

    void Point::setByPolar(double radius, double angle)
    {
      this->x = cos(angle) * radius;
      this->y = sin(angle) * radius;
    }


    std::ostream& operator<<(std::ostream& os, const Point& pt)
    {
      os << "Point(" << pt.x << "," << pt.y << ")";
      return os;
    }

    Point operator*(Point& lhs, double rhs)
    {
      return Point(lhs.getX() * rhs, lhs.getY() * rhs);
    }
    Point operator*(double lhs, Point& rhs)
    {
      return rhs * lhs;
    }

    Point operator/(Point& lhs, double rhs)
    {
      return Point(lhs.getX() / rhs, lhs.getY() / rhs);
    }
    Point operator/(double lhs, Point& rhs)
    {
      return rhs / lhs;
    }

    Point operator+(Point& lhs, Point& rhs)
    {
      return Point(lhs.getX() + rhs.getX(), lhs.getY() + rhs.getY());
    }
    Point operator-(Point& lhs, Point& rhs)
    {
      return Point(lhs.getX() - rhs.getX(), lhs.getY() - rhs.getY());
    }

    /**************************************************************************
    Class Line
    **************************************************************************/
    Line::Line(Point& newStart, Point& newEnd)
    {
      this->reset();

      this->start = &newStart;

      this->end = &newEnd;
    }

    void Line::reset()
    {
      //nothing to reset
    }

    Point& Line::getStart()
    {
      return *(this->start);
    }

    Point& Line::getEnd()
    {
      return *(this->end);
    }

    void Line::setStart(Point& newStart)
    {
      if (this->start != &newStart)
      {
        this->start = &newStart;
      };
    }

    void Line::setEnd(Point& newEnd)
    {
      if (this->end != &newEnd)
      {
        this->end = &newEnd;
      };
    }

    double Line::calcSlope()
    {
      double width = this->getEnd().getX() - this->getStart().getX();
      double height = this->getEnd().getY() - this->getStart().getY();

#ifdef _DEBUG_
  std::cout << "\nDEBUG Line::calcSlope" << '\n';

  std::cout << "width :" << width << " height :" << height << '\n';
#endif

      if (width == 0.0)
      {
        //do something to stop the divide by zero
        return INFINITY;
      };

      return height / width;
    }

    std::vector<Point> Line::intersection(Line& intersectingLine)
    {
      std::vector<Point> result;

      double x1 = this->getStart().getX();
      double y1 = this->getStart().getY();
      double x2 = this->getEnd().getX();
      double y2 = this->getEnd().getY();

      double x3 = intersectingLine.getStart().getX();
      double y3 = intersectingLine.getStart().getY();
      double x4 = intersectingLine.getEnd().getX();
      double y4 = intersectingLine.getEnd().getY();

      double xOut = 0.0;
      double yOut = 0.0;

      if (LineLineIntersect(x1, y1, x2, y2, x3, y3, x4, y4, xOut, yOut))
      {
        result.push_back(Point(xOut, yOut));
      }

      return result;
    }

    std::vector<Point> Line::subpoint(int divisions)
    {
      std::vector<Point> result;

      double stepSize = 1.0 / divisions;

      for (int i = 0; i <= divisions; i++)
      {
        //lerp
        double delta = stepSize * i;
        // Point a = *(this->start) * (1.0 - delta);
        // Point b = *(this->end) * (delta);
        // Point c = a + b;
        Point c = lerp<Point>(*(this->start), *(this->end), delta);
        result.push_back(c);
      }

      return result;
    }

    std::vector<Line> Line::subline(int divisions)
    {
      std::vector<Point> points = this->subpoint(divisions);
      std::vector<Line> lines;

      for (int i = 0; i < divisions; i++)
      {
        //connect the adjacent points into lines
        Line l = Line(points.at(i), points.at(i +1));
        lines.push_back(l);
      }
      return lines;
    }

    std::ostream& operator<<(std::ostream& os, const Line& ln)
    {
      os << "Line(" << *(ln.start) << "," << *(ln.end) << ")";
      return os;
    }

    double Line::getLength()
    {
      Point delta = this->end - this->start;
      return sqrt( pow(delta.getX(), 2.0) + pow(delta.getY(), 2.0) );
    }

    double Line::getAngle()
    {
      Point delta = this->end - this->start;
      return atan2(delta.getY(), delta.getX());
    }

    Line Line::getUnitLine()
    {
      //subtract the start point, scale then readd the start point
      Point start = *(this->start);
      Point end = *(this->end);
      Point transEnd = end - start;
      Point scaleEnd = transEnd / this->getLength();
      Point newEnd = scaleEnd + start;
      return Line(start, newEnd);
    }

    Line operator-(Line& lhs, Point& rhs)
    {
      Point newStart = lhs.getStart() - rhs;
      Point newEnd = lhs.getEnd() - rhs;
      return Line(newStart, newEnd);
    }
    /**************************************************************************
    Class Circle
    **************************************************************************/
    Circle::Circle(Point& origin, double radius)
    {
      this->reset();
      this->origin = &origin;
      this->radius = radius;
    }

    void Circle::reset()
    {
      //nothing to reset
    }

    Point Circle::getOrigin()
    {
      return *(this->origin);
    }

    double Circle::getRadius()
    {
      return this->radius;
    }

    void Circle::setOrigin(Point& newOrigin)
    {
      if (this->origin != &newOrigin)
      {
        this->origin = &newOrigin;
      };
    }

    void Circle::setRadius(double newRadius)
    {
      this->radius = newRadius;
    }

    std::vector<Point> Circle::intersection(Line& line)
    {
      std::vector<Point> points;

      //formulae calculates as though circle is at origin (0,0)
      //line needs to be moved to accomodate
      //reference August 2 2018 14:06
      //http://mathworld.wolfram.com/Circle-LineIntersection.html
      Line lineAtOrigin = line - *(this->origin);
      Point lineStart = lineAtOrigin.getStart();
      Point lineEnd = lineAtOrigin.getEnd();

      Point delta = lineAtOrigin.getEnd() - lineAtOrigin.getStart();

      double r = this->radius;
      double dx = delta.getX();
      double dy = delta.getY();

      double dr = sqrt( pow(dx, 2.0) + pow(dy, 2.0));

      double deter = Det(lineStart.getX(), lineEnd.getX(), lineStart.getY(), lineEnd.getY());

      double sgnDy = dy < 0.0 ? -1.0 : 1.0;

      double disc = pow(r, 2.0) * pow(dr, 2.0) - pow(deter, 2.0);

      double xPos = ((deter * dy) + (sgnDy * dx * sqrt((pow(r, 2.0) * pow(dr, 2.0)) - pow(deter, 2.0)))) / pow(dr, 2.0);
      double xNeg = ((deter * dy) - (sgnDy * dx * sqrt((pow(r, 2.0) * pow(dr, 2.0)) - pow(deter, 2.0)))) / pow(dr, 2.0);

      double yPos = ((-deter * dx) + (abs(dy) * sqrt((pow(r, 2.0) * pow(dr, 2.0)) - pow(deter, 2.0)))) / pow(dr, 2.0);
      double yNeg = ((-deter * dx) - (abs(dy) * sqrt((pow(r, 2.0) * pow(dr, 2.0)) - pow(deter, 2.0)))) / pow(dr, 2.0);

      if (disc < 0.0)
      {
        //no intersection (zero points)
      }
      else if (disc == 0.0)
      {
        //tangent intersection (one point)
        Point tangent = Point(xPos, yPos);
        points.push_back(tangent  + *(this->origin));
      }
      else if (disc > 0.0)
      {
        //intersection (two points)
        Point inter1 = Point(xPos, yPos);
        Point inter2 = Point(xNeg, yNeg);
        points.push_back(inter1  + *(this->origin));
        points.push_back(inter2  + *(this->origin));
      }
      else
      {
        //error (zero points)
      }

      return points;
    }

    std::ostream& operator<<(std::ostream& os, const Circle& cr)
    {
      os << "Circle(O:" << *(cr.origin) << ", R:" << cr.radius << ")";
      return os;
    }
}
