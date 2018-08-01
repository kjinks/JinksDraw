#include <iostream>
#include "primitives.h"
using namespace JinksDraw;

bool testClassPoint()
{
  bool result = true;

  double testX = 1.0;
  double testY = 3.0;

  //test constructor
  Point* p = new Point(testX, testY);
  std::cout << "Point class instantiated successfully" << '\n';

  //test accessors


  if (p->getX() == testX)
  {
    std::cout << "Point class x access passed" << '\n';
  }
  else
  {
    result = false;
    std::cout << "Point class x access failed" << '\n';
  };

  if (p->getY() == testY)
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

  p->setX(newTestX);
  if (p->getX() == newTestX)
  {
    std::cout << "Point class x mutator passed" << '\n';
  }
  else
  {
    result = false;
    std::cout << "Point class x mutator failed" << '\n';
  };

  p->setY(newTestY);
  if (p->getY() == newTestY)
  {
    std::cout << "Point class y mutator passed" << '\n';
  }
  else
  {
    result = false;
    std::cout << "Point class y mutator failed" << '\n';
  };

  //test destructor
  delete p;
  std::cout << "Point class destroyed successfully" << '\n';

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

  //test destructor
  delete(&l);
  std::cout << "Line class destroyed successfully" << '\n';

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
  return 0;
}
