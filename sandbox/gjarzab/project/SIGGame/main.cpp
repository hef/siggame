#include <iostream>
#include "Utils.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	unsigned int userInput = 0;
	Utils	utilitiesOnStack;				// Utilities declared on the stack
	Utils*	pUtilitiesObject = new Utils();	// Utilities on the heap

	// Test sumUp method. Both calls should return 15
	cout << "utilitiesOnStack.sumUp( 5 ) = " << utilitiesOnStack.sumUp( static_cast<unsigned int>( 5 ) ) << endl;
	cout << "pUtilitiesObject->sumUp( 5 ) = " << pUtilitiesObject->sumUp( static_cast<unsigned int>( 5 ) ) << endl;

	// The line below will not compile if uncommented
	// cout << "pUtilitiesObject->sumUp( -5 ) = " << pUtilitiesObject->sumUp( -5 ) << endl;

	cout << "Enter a number: ";
	cin >> userInput;

	cout << "pUtilitiesObject->sumUp( " << userInput << " ) = " << pUtilitiesObject->sumUp( userInput ) << endl;

	delete pUtilitiesObject;

	return 0;
}