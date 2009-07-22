#ifndef UTILS_H
#define UTILS_H
#include <math.h>

const static float SMALL_NUMBER = 0.0001f;
const static float VERY_SMALL_NUMBER = 0.000001f;

bool smallNumberEquality( const float a, const float b )
{
	float diff = a - b;
	return( SMALL_NUMBER > fabs( diff ) );
}

bool verySmallNumberEquality( const float a, const float b )
{
	float diff = a - b;
	return( VERY_SMALL_NUMBER > fabs( diff ) );
}
#endif
