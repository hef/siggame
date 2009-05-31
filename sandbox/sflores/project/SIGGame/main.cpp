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
	
	// Test Utils' sumUp method
	int n;
	cout << "Enter n to calculate the sum from 1 to n: ";
	// Works with any integer value >= 1. Otherwise, returns zero.
	cin >> n;
	cout << "The sum from 1 to " << n << " is: " << utils1.sumUp( n ) << endl;
	cin >> n;

	return 0;
}