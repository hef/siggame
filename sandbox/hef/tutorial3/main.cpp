#include <iostream>
#include "Utils.h"
int main( int argc, char **argv )
{
  unsigned int x = 5;
  Utils* pUtil = new Utils;
  Utils  Util;
  std::cout << pUtil->sumUp( x ) << std::endl;
  delete pUtil;
}
