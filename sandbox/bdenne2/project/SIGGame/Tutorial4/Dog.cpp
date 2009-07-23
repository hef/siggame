#include "Dog.h"
#include <string.h>

Dog::Dog() : 
	itsHeight(0.0f),
	itsWeight(0.0f),
	itsName(new char[17])
{
	itsName = "Rover";
}

Dog::Dog(float height,float weight, char* name) :
	itsHeight(height),
	itsWeight(weight),
	itsName(new char[17])
{
	strncpy( itsName, name, 16);
}

Dog::~Dog()
{
	delete itsName;
}

Dog::Dog(const Dog& oldDog) :
	itsHeight(oldDog.itsHeight),
	itsWeight(oldDog.itsWeight)
{
	strncpy(itsName, oldDog.itsName, 16);
}

float Dog::getHeight() const
{
	return itsHeight;
}

float Dog::getWeight() const 
{
	return itsWeight;
}

const char * const Dog::getName() const 
{
	return itsName;
}

void Dog::setHeight(const float height) 
{
	this->itsHeight = height;
}

void Dog::setWeight(const float weight) 
{
	this->itsWeight = weight;
}