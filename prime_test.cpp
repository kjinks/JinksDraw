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

int main(int argc, char *argv[])
{
  //TEST CLASS POINT

  if(testClassPoint())
  {
    std::cout << "Point class passed test" << '\n';
  };

  return 0;
}
