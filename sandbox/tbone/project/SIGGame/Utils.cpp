#include "Utils.h"

// Default constructor
Utils::Utils() {}

// Destructor
Utils::~Utils() {}

/**
 * Returns the sum of 1-n
 *
 * @param n Upper bound of summation
 */
unsigned int Utils::sumUp( const unsigned int n ) const
{
	return ( n * ( n + 1 ) ) / 2;
}