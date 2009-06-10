#include "Dog.h"
#include <iostream>



int main()
{
	Dog a;	
	Dog b( "MORETHAN15CHAROMG", 2.33, 4.44 );
	Dog c = a;
	std::cout << c.getName() << std::endl;
	std::cout << b.getName() << std::endl;
	std::cin.get();
	return 0;
}