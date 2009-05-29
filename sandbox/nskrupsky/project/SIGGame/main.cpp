#include <stdio.h>
#include "Utilities.h"

int main()
{
	Utilities uObject1; // on the stack
	Utilities* pUObject2 = new Utilities(); // on the heap
	return 0;
}