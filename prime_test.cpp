#include <iostream>
#include "primitives.h"
using namespace JinksDraw;

bool testClassPoint()
{
  bool result = true;

  double testX = 1.0;
  double testY = 3.0;

  //test constructor
  Point p = Point(testX, testY);
  std::cout << "Point class instantiated successfully" << '\n';
  std::cout << "Created point " << p << '\n';
  //test accessors


  if (p.getX() == testX)
  {
    std::cout << "Point class x access passed" << '\n';
  }
  else
  {
    result = false;
    std::cout << "Point class x access failed" << '\n';
  };

  if (p.getY() == testY)
  {
    std::cout << "Point class y access passed" << '\n';
  }
  else
  {
    result = false;
    std::cout << "Point class y access failed" << '\n';
  };

  //test mutators
  double newTestX = 4.0;
  double newTestY = 6.0;

  p.setX(newTestX);
  if (p.getX() == newTestX)
  {
    std::cout << "Point class x mutator passed" << '\n';
  }
  else
  {
    result = false;
    std::cout << "Point class x mutator failed" << '\n';
  };

  p.setY(newTestY);
  if (p.getY() == newTestY)
  {
    std::cout << "Point class y mutator passed" << '\n';
  }
  else
  {
    result = false;
    std::cout << "Point class y mutator failed" << '\n';
  };

  return result;
}

bool testClassLine()
{
  bool result = true;

  double testX1 = 1.0;
  double testY1 = 2.0;
  double testX2 = 3.0;
  double testY2 = -4.0;

  //create start and end points
  Point startP = Point(testX1, testY1);
  Point endP = Point(testX2, testY2);


  //test constructor
  Line l = Line(startP, endP);
  std::cout << "Line class instantiated successfully" << '\n';
  std::cout << "Line created : " << l << '\n';

  //test accessors
  if (&(l.getStart()) == &(startP))
  {
    std::cout << "Line class start Point access passed" << '\n';
  }
  else
  {
    result = false;
    std::cout << "Line class start Point access failed" << '\n';
  };

  if (&(l.getEnd()) == &(endP))
  {
    std::cout << "Line class end Point access passed" << '\n';
  }
  else
  {
    result = false;
    std::cout << "Line class end Point access failed" << '\n';
  };

  //create new test data
  double testX3 = 38.0;
  double testY3 = -6.0;
  double testX4 = -7.0;
  double testY4 = -2.0;

  //create start and end points
  Point newStartP = Point(testX3, testY3);
  Point newEndP = Point(testX4, testY4);

  //test mutators
  l.setStart(newStartP);
  if (&(l.getStart()) == &newStartP)
  {
    std::cout << "Line class start Point mutator passed" << '\n';
  }
  else
  {
    result = false;
    std::cout << "Line class start Point mutator failed" << '\n';
  }

  l.setEnd(newEndP);
  if (&(l.getEnd()) == &newEndP)
  {
    std::cout << "Line class end Point mutator passed" << '\n';
  }
  else
  {
    result = false;
    std::cout << "Line class end Point mutator failed" << '\n';
  }

  //create new line
  Line l2 = Line(startP, endP);

  //test intersection

  std::vector<Point> points = l.intersection(l2);

  std::cout << "Line class intersection created " << points.size() << " point(s)" << '\n';

  std::cout << "from lines " << l << " and " << l2 <<  '\n';

  for (auto point = points.begin(); point != points.end(); ++point)
  {
    std::cout << "Point found " << *point << '\n';
  }

  //test subpoint

  points = l.subpoint(4);

  std::cout << "Line class subpoint created " << points.size() << " point(s)" << '\n';

  for (auto point = points.begin(); point != points.end(); ++point)
  {
    std::cout << "Point found " << *point << '\n';
  }

  //test subline

  std::vector<Line> lines = l.subline(4);

  std::cout << "Line class subline created " << lines.size() << " line(s)" << '\n';

  for (auto line = lines.begin(); line != lines.end(); ++line)
  {
    std::cout << "Line found " << *line << '\n';
  }

  return result;
}

bool testClassCircle()
{
  bool result = true;


  Point origin1 = Point(10.0, 20.0);
  double radius1 = 100.0;
  Point origin2 = Point(15.0, 5.0);
  double radius2 = 100.0;

  Circle circle1 = Circle(origin1, radius1);
  Circle circle2 = Circle(origin2, radius2);

  std::cout << "Circle class instantiated successfully" << '\n';
  std::cout << "Created two circles : " << '\n';
  std::cout << circle1 << '\n';
  std::cout << circle2 << '\n';

  Point newOrigin = Point(12.0, 13.0);
  circle1.setOrigin(newOrigin);
  circle1.setRadius(99.0);

  std::cout << "Circle::setOrigin and Circle::setRadius passed" << '\n';
  std::cout << "Result :" << circle1 << '\n';

  std::cout << "Circle::getOrigin and Circle::getRadius test :" << '\n';
  std::cout << "Origin : " << circle1.getOrigin() << " Radius :" << circle1.getRadius() << '\n';
  std::cout << "Circle::getOrigin and Circle::getRadius passed test" << '\n';
  return result;
}

int main(int argc, char *argv[])
{
  //TEST CLASS POINT

  if(testClassPoint())
  {
    std::cout << "Point class passed test" << '\n';
  };

  //TEST CLASS LINE

  if(testClassLine())
  {
    std::cout << "Line class passed test" << '\n';
  };

  //TEST CLASS CIRCLE

  if(testClassCircle())
  {
    std::cout << "Circle class passed test" << '\n';
  };

  return 0;
}
