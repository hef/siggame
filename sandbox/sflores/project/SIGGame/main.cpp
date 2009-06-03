#include <stdio.h>
#include <iostream>
#include "Utils.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	Utils utils1;				// Instance of Utilities in Stack
	Utils* utils2 = new Utils;	// Instance of Utilities in Heap
	delete utils2;
	
	// Test Utils' sumUp method
	int nSigned = -1;
	unsigned int nUnsigned = 5;
	float fFloat = 2.0;
	double dDouble = 5.5;

	cout << "sumUp( nUnsigned = 5 ) = " << utils1.sumUp( nUnsigned ) << endl;

	/* The following should produce a compile error; Commented out. */
	// cout << "sumUp( nSigned = -1 ) = " << utils1.sumUp( nSigned ) << endl;
	// cout << "sumUp( fFloat = 2.0 ) = " << utils1.sumUp( fFloat ) << endl;
	// cout << "sumUp( dDouble = 5.5 ) = " << utils1.sumUp( dDouble ) << endl;
	cin.get();

	return 0;
}