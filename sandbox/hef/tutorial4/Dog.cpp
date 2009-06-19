#include "Dog.h"
Dog::Dog( std::string newName, int weight, int height )
  : height( height ),
    weight( weight ),
    name( newName )
{
}
Dog::Dog( const Dog& oldDog )
  : height( oldDog.height ),
    weight( oldDog.weight ),
    name( oldDog.name )
{
}
int Dog::getHeight() const
{
	return height;
}
void Dog::setHeight(const int n)
{
	height=n;
        return;
}
int Dog::getWeight() const
{
	return weight;
}
void Dog::setWeight(const int n)
{
        weight=n;
	return;
}
std::string Dog::getName() const
{
	return name;
}
