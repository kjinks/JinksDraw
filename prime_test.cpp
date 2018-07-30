#include <iostream>
#include "primitives.h"
using namespace JinksDraw;

bool testClassPoint()
{
  bool result = true;
  Point* p = new Point(10.0, 10.0);
  std::cout << "Point class instantiated successfully" << '\n';
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
