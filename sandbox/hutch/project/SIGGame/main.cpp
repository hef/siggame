#include "Utils.h"
#include "iostream"


int main()
{
	Utils aStack;
	Utils* aHeap = new Utils;
	//std::cout << aStack.sumUp( (double) 1.33333332 ) << std::endl;
	//std::cout << aStack.sumUp( 9 ) << std::endl;
	//std::cout << aStack.sumUp( -4 ) << std::endl;
	std::cout << aStack.sumUp( (unsigned int) -4 ) << std::endl; // "only an idiot"
	std::cout << aHeap->sumUp( (unsigned int) 4 ) << std::endl;
	std::cout << aStack.sumUp( (unsigned int) 5 ) << std::endl;
	std::cin.get();
	delete(aHeap);
	return 0;
}