#include "Utils.h"
/* The sum from 1 to n is given by:
   ( n( n + 1 ) ) / 2 .
   This algorithm should run in O( 1 ).
*/
unsigned int Utils::sumUp( unsigned int n )
{
	/* If zero, we don't want to compute: 0 * ( 0 + 1 ) / 2
	   if the answer is 0. Commenting out anyway */
	// if( n <= 0 )
	// { 
	//     return 0;
	// }
	return( ( n * ( n + 1 ) ) >> 1 ); // n( n + 1 ) / 2
}
