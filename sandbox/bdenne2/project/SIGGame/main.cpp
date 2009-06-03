#include "Utilities.h"


int main()
{
	Utilities utilOnStack; 
	Utilities* utilOnHeap = new Utilities;
	delete utilOnHeap;
	return 0;
};