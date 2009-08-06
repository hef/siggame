#include <stdio.h>
#include "Utils.h"

int main()
{
	Utils utilityStack;
	Utils* utilityHeap = new Utils;

	delete utilityHeap;
	return 0;
}