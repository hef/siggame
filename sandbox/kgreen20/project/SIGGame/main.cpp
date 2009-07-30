#include <iostream>
#include <assert.h>
#include "Utils.h"

using std::cout;

int main()
{
	Utils* utilitiesHeap = new Utils();
	Utils utilitiesStack;

	//Tutorial 3

	int testVectors[] = {1,3,5,6,10};
	int testExpected[] = {1,6,15,21,55};
	int actual;

	for(int i = 0; i < 5; i++)
	{
		assert( (utilitiesStack.sumUp(testVectors[i])) == (testExpected[i]));
	}
	cout << "sumUp appears to work...\n" ;

	system( "PAUSE" ); 
	return 0;
}