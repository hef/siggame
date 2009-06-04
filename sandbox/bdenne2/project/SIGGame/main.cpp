#include "Util.h"


int main()
{
	Util utilOnStack; 
	Util* utilOnHeap = new Util;
	delete utilOnHeap;
	return 0;
};