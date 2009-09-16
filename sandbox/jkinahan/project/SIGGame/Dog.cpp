#include "Dog.h"

Dog::Dog( float height, float weight, const char* tagID )
{
	dogHeight = height;
	dogWeight = weight;
	dogTagID = tagID;
}

Dog::Dog( const Dog &thisDog )
{
	dogHeight = thisDog.dogHeight;
	dogWeight = thisDog.dogWeight;
	dogTagID = thisDog.dogTagID;
}


Dog::Dog()
{
	dogHeight = 0.0f;
	dogWeight = 0.0f;
	dogTagID = new char [17];
}
Dog::~Dog()
{
	delete &dogHeight;
	delete &dogWeight;
	delete dogTagID;
}

float Dog::getHeight() 
{
	return dogHeight;
}

float Dog::getWeight() 
{
	return dogWeight;
}

const char* Dog::getTagID() const
{
	return dogTagID;
}

void Dog::setHeight( float height ) 
{
	this -> dogHeight = height;
}

void Dog::setWeight( float weight ) 
{
	this -> dogWeight = weight;
}
