#include "Dog.h"
#include <string.h>

Dog::Dog( const char* dogName ):height(0),weight(0)
{
	name = new char[17];
	strncpy( name, dogName, 16 );
	name[16] = '\0';
}

Dog::Dog(Dog &oldDog)
{
	name = new char[17];
	strncpy( name, oldDog.getName(), 16 );
	name[16] = '\0';

	height = oldDog.getHeight();
	weight = oldDog.getWeight();
}

Dog::~Dog()
{
	delete[]( name );
}

float Dog::getHeight() const
{
	return height;
}

void Dog::setHeight( const float newHeight )
{
	height = newHeight;
}

float Dog::getWeight() const
{
	return weight;
}

void Dog::setWeight( const float newWeight )
{
	weight = newWeight;
}

const char* Dog::getName() const
{
	return name;
}
