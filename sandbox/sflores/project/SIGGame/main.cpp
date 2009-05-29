#include <stdio.h>
#include "Utilities.h"

int main()
{
	Utilities utils1;						// Instance of Utilities in Stack
	Utilities* utils2 = new Utilities;	// Instance of Utilities in Heap
	return 0;
}