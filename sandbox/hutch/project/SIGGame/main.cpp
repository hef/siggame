#include "Utils.h"
#include "iostream"

int main()
{
	
	Utils aStack;
	Utils* aHeap = new Utils;
	std::cout << sumUp( 5 ) << std::endl;
	std::cout << sumUp( 4 ) << std::endl;
	std::cin.get();
	return 0;
}