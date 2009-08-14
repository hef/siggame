#include <iostream>
#include "Utils.h"

int main()
{
	// Calls the default constructor, allocates space on the stack
	Utils utilStackVersion;

	// Creates a pointer to a new Utils allocated on the heap
	Utils* utilHeapVersion = new Utils;

	// Failed tests
	//unsigned int uiSumOfOneToFive = utilHeapVersion->sumUp( -5 );
	//unsigned int uiSumOfOneToFive = utilHeapVersion->sumUp( float( 5 ) );
	//unsigned int uiSumOfOneToFive = utilHeapVersion->sumUp( double( 5 ) );
	//unsigned int uiSumOfOneToFive = utilHeapVersion->sumUp( long( 5 ) );

	// Let's use the heap verson to sum 1-5
	unsigned int uiSumOfOneToFive = utilHeapVersion->sumUp( unsigned int( 5 ) );

	std::cout << uiSumOfOneToFive << std::endl;

	// Delete it for good measure
	delete utilHeapVersion;

	return 0;
}