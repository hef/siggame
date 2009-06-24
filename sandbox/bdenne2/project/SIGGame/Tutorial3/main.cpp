#include "Util.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	Util utilOnStack; 
	Util* utilOnHeap = new Util;
	cout << "The sumUp(5) = " << utilOnStack.sumUp( (unsigned int) 5) << endl;
	cout << "The sumUp(4) = " << utilOnStack.sumUp( (unsigned int) 4) << endl;
	cout << "The sumUp(3) = " << utilOnStack.sumUp( (unsigned int) 3) << endl;
	cout << "The sumUp(2) = " << utilOnStack.sumUp( (unsigned int) 2) << endl;
	cout << "The sumUp(1) = " << utilOnStack.sumUp( (unsigned int) 1) << endl;
	delete utilOnHeap;
	system("PAUSE"); //to see the output
	return 0;
};