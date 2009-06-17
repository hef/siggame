#include "Dog.h"
#include <string.h>

float Dog::getHeight() const
{
	return height;
}

float Dog::getWeight() const
{
	return weight;
}

const char* Dog::getName() const
{
	return NAME;
}

void Dog::setHeight( const float newHeight )
{
	height = newHeight;
}

void Dog::setWeight( const float newWeight )
{
	weight = newWeight;
}

Dog::Dog( const char* name )
: height( 0 ), weight( 0 )
{
	NAME = new char[ MAXSIZE + 1 ];
	strncpy( NAME, name, MAXSIZE );
}

Dog::Dog( const Dog& otherDog )
: height( otherDog.getHeight() ), weight( otherDog.getWeight() )
{
	NAME = new char[ MAXSIZE + 1 ];
	strncpy( NAME, otherDog.getName(), MAXSIZE );
}

const Dog& Dog::operator=( const Dog& otherDog )
{
	if( this != &otherDog )
	{
		setHeight( otherDog.getHeight() );
		setWeight( otherDog.getWeight() );
	}
	return *this;
}

Dog::~Dog()
{
	delete [] NAME;	// Delete
	NAME = NULL;	// Point to NULL
}