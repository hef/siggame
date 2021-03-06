#include "Utils.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	int inputNumber = 0;

	Utils* utilHeap = new Utils; // heap implementation of Utilities
	Utils utilStack; // stack implementation of Utilities

	// these will both compile and run
	cout << "utilStack.sumUp( (unsigned int )( 10 ) ) = " << utilStack.sumUp( ( unsigned int )( 10 ) ) << "\n";
	cout << "utilHeap->sumUp( (unsigned int )( 10 ) ) = " << utilHeap->sumUp( ( unsigned int )( 10 ) ) << "\n";

	// these will both cause a compiler error
	//cout << utilStack.sumUp( -10 );
	//cout << utilHeap->sumUp( -10 );

	cout << "Please enter the number you would like to add up to: ";
	cin >> inputNumber; 

	if ( inputNumber >= 0 )
	{
		unsigned int addUpToNumber = static_cast<unsigned int>( inputNumber );
		cout << "The sum is:  " << utilStack.sumUp( addUpToNumber ) << endl;
	}
	else
	{
		cout << "Please use an input greater than 0 \n";
	}

	delete utilHeap;

    system( "PAUSE" );

	return 0;
}

