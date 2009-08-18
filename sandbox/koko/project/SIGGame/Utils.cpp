#include "Utils.h"

	Utils::Utils(){}

	Utils::~Utils(){}
			
	// sumUp returns the sum of the numbers from 1 to n
	unsigned int Utils::sumUp( unsigned int n )
	{
		if ( n < 1 )
			return 0;
		else
			return n + sumUp( n - 1 );
	}

	int Utils::sumUp( int n )
	{
		return 0;
	}

	int Utils::sumUp( float n )
	{
		return 0;
	}

	int Utils::sumUp( double n )
	{
		return 0;
	}

	int Utils::sumUp( long n )
	{
		return 0;
	}
