#include "Dog.h"
#include <string.h>

Dog::Dog()
{
	name = new char[17];
	char* theName = "AsusDog";
	strncpy ( name, theName, 16 );
	name[16] = '\0';
	height = 40;
	weight = 200;
}

Dog::Dog( char* theName, const float theHeight, const float theWeight )
{
	name = new char[17];
	strncpy( name, theName, 16 );
	name[16] = '\0';
	height = theHeight;
	weight = theWeight;
}

Dog::~Dog(){ delete[] name; }

Dog::Dog( const Dog& dog )
{
	name = new char[17];
	strncpy( name, dog.name, 16 );
	name[16] = '\0';
	height = dog.height;
	weight = dog.weight;
}

Dog& Dog::operator=( const Dog& dog )
{
	if( this != &dog )
	{
		name = new char[17];
		strncpy( name, dog.name, 16 );
		name[16] = '\0';
		height = dog.height;
		weight = dog.weight;
	}
	return *this;
}

char const * const Dog::getName() const { return name; }
float Dog::getHeight() const { return height; }
float Dog::getWeight() const { return weight; }

void Dog::setHeight( const float newHeight ){ height = newHeight; }
void Dog::setWeight( const float newWeight ){ weight = newWeight; }
