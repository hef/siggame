#include <stdio.h>
#include "Utilities.h"

int main()
{
	Utilities utilityStack;
	Utilities* utilityHeap = new Utilities;

	delete utilityHeap;
	return 0;
}