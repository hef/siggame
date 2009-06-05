#include <iostream>
#include "Utils.h"
int main( int argc, char **argv )
{
  Utils* pUtil = new Utils;
  Utils  Util;
  std::cout << pUtil->sumUp(5) << std::endl;
  delete pUtil;
}
