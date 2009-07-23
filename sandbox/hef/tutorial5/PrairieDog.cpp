#include "PrairieDog.h"
PrairieDog::PrairieDog( const Dog& oldDog ) : 
	Dog( oldDog)
{
}
void PrairieDog::bark()
{
	std::cout << "Yelp!" << std::endl;
}
