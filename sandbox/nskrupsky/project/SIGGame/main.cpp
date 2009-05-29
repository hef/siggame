#include <stdio.h>
#include "Utils.h"

int main()
{
	Utils uObject1; // on the stack
	Utils* pUObject2 = new Utils; // on the heap
	return 0;
}
