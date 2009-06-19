#include <iostream>
#include "Dog.h"
int main( int argc, char **argv )
{
  Dog* puppy = new Dog("Ralph");
  puppy->setHeight(5);
  puppy->setWeight(6);
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
