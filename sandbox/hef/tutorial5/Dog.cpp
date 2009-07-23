#include "Dog.h"
Dog::Dog( char const * const newName, int const weight, int const height )
  : height( height ),
    weight( weight ),
    name( new char[17] )
{
  strncpy(name,newName,16);
}
Dog::Dog( const Dog& oldDog )
  : height( oldDog.height ),
    weight( oldDog.weight ),
    name( new char[17] )
{
  strncpy(name,oldDog.name,16);
}
Dog::~Dog()
{
  delete[] name;
}
int Dog::getHeight() const
{
	return height;
}
void Dog::setHeight(const int n)
{
	height = n;
}
int Dog::getWeight() const
{
	return weight;
}
void Dog::setWeight(const int n)
{
        weight = n;
}
char const * const Dog::getName() const
{
  return name;
}
