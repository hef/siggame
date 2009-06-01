#ifndef UTILS_H
#define UTILS_H

#include <assert.h>
class Utils
{
public:
	Utils()
	{
	}

	~Utils()
	{
	}

	unsigned int sumUp( unsigned int n );

private:
	unsigned int sumUp( int n ){ return 0; }
	unsigned int sumUp( float n ){ return 0; }
	unsigned int sumUp( double n ){ return 0; }
	
};

unsigned int Utils::sumUp( unsigned int n )
{
	return (n*(n+1))/2;
}

#endif

