#include "Utils.h"

unsigned int Utils::sumUp( const unsigned int upTo )
{
	//Use summation formula to calculate sum
	return ( upTo * ( upTo + 1)) >> 1;
}