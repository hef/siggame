#include <iostream>
#include "Utils.h"

int main()
{
	Utils test0;
	Utils* test1 = new Utils;
	
	//loops through values to test sumUp to show sumUp of 1-x
	for(int x = 5; x!=0; x--)
	{
		std::cout<< (test0.sumUp(x))<<"\n";	//prints out the summed up number
	}

	delete test1;

	int temp;
	std::cin>>temp;		//is here to wait after the output is done

	return 0;
};