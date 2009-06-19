#include <iostream>
#include "Dog.h"
int main( int argc, char **argv )
{
  Dog* puppy = new Dog("Ralph");
  std::cout << puppy->getName() << std::endl;
  delete puppy;
}
