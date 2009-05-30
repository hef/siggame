#include <stdio.h>
#include "Utilities.h"

int main()
{
	Utilities	utilitiesOnStack;					//Utilities declared on the stack
	Utilities*	pUtilitiesObject = new Utilities();	//Utilities on the heap

	return 0;
}