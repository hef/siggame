#include "Utils.h"

int Utils::sumUp( const int &upTo )
{
	//Use summation formula to calculate sum
	return ( upTo * ( upTo + 1)) >> 1;
}