#include "Utils.h"
#include <iostream>

int main()
{
	Utils stackUtil;
	Utils* heapUtil = new Utils;
	delete( heapUtil );

	std::cout << "Sum with n = 1 is " << stackUtil.sumUp( (unsigned int) 1 ) << std::endl;
	std::cout << "Sum with n = 5 is " << stackUtil.sumUp( (unsigned int) 5 ) << std::endl;
	
	// These next lines doen't compile
	// std::cout << "Sum with n = -3 is " << stackUtil.sumUp( -3 ) << std::endl;
	// std::cout << "Sum with n = -3 is " << stackUtil.sumUp( (float) 3 ) << std::endl;
	// std::cout << "Sum with n = -3 is " << stackUtil.sumUp( (double) 3 ) << std::endl;
	
	system( "pause" );	// Forces windows console to pause so that output of tests can be seen

	return 0;
}

