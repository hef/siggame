#include <stdio.h>
#include <iostream>
#include "Utils.h"

int main()
{
	Utils utilityStack;
	Utils* utilityHeap = new Utils;

	float f = 4.0f;
	double d = 3.0;
	int i = 2;
	unsigned int ui = 3;
	long l = 10;

	//std::cout<< utilityStack.sumUp(i) <<std::endl;

	std::cout<< utilityHeap->sumUp(ui) <<std::endl;

	delete utilityHeap;
	system("pause");
	return 0;	
}

