#include <iostream>
#include "Dog.h"
#include <string.h>
int main( int argc, char **argv )
{
  char* name = new char[17];
  strncpy(name,"ralph",16);
  
  Dog* puppy = new Dog(name, 5, 6);
  Dog* puppy2 = new Dog( *(puppy) );
  puppy->setHeight(7);
  puppy->setWeight(8);

  std::cout << puppy->getName() << std::endl;
  std::cout << puppy->getHeight() << std::endl;
  std::cout << puppy->getWeight() << std::endl;
  std::cout << puppy2->getName() << std::endl;
  std::cout << puppy2->getHeight() << std::endl;
  std::cout << puppy2->getWeight() << std::endl;
  delete puppy;
  delete puppy2;
}
