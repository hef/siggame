#include <stdio.h>
#include <iostream>
#include "Utils.h"

using std::cout;
using std::endl;

int main()
{
	Utils uObject1; // on the stack
	Utils* pUObject2 = new Utils; // on the heap
	
	
	cout << "sumUp( 0 ): " << pUObject2->sumUp( 0u ) << endl;
	// the following test cases will cause a compiler error
	// cout << "sumUp( -5 ): " << pUObject2->sumUp( -5 ) << endl;
	// cout << "sumUp( 1.5 ): " << pUObject2->sumUp( 1.5 ) << endl;
	// cout << "sumUp( 1.5f ): " << pUObject2->sumUp( 1.5f ) << endl;
	cout << "sumUp( 5 ): " << pUObject2->sumUp( 5u ) << endl;
	cout << "sumUp( 1337 ): " << pUObject2->sumUp( 1337u ) << endl;

	return 0;
}
