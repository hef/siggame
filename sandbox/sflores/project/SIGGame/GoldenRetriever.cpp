#include "GoldenRetriever.h"
#include <iostream>

GoldenRetriever::GoldenRetriever( const char *name )
: Dog( name )
{ }

void GoldenRetriever::bark() const
{
	std::cout << "Roof!\n";
}

GoldenRetriever::~GoldenRetriever()
{ }