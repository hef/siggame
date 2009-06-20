#include "PrairieDog.h"
#include <iostream>

PrairieDog::PrairieDog( const char* name )
: Dog( name )
{ }

void PrairieDog::bark()
{
	std::cout << "Yelp!\n";
}

PrairieDog::~PrairieDog()
{

}