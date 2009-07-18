#include "Utils.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	int addUpToNumber = 0;
	Utils* utilHeap = new Utils; // heap implementation of Utilities
	Utils utilStack; // stack implementation of Utilities
	
	cout << "Please enter the number you would like to add up to: ";
	cin >> addUpToNumber; 
	cout << "The sum is:  " << utilStack.sumUp(addUpToNumber) << endl;
	
	delete utilHeap;

    system( "PAUSE" );

	return 0;
}

