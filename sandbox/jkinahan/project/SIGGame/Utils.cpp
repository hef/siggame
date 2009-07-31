#include "Utils.h"

unsigned int Utils::sumUp( const unsigned int numberToSum )
{
	unsigned int result;
	result = ( (numberToSum * (numberToSum + 1) ) / 2);
	return result;
}	
