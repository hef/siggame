#include "Dog.h"
#include "PrairieDog.h"
#include "GoldenRetriever.h"
#include <iostream>



int main()
{
	Dog* a = new PrairieDog;
	Dog* b = new GoldenRetriever;
	//Dog* c = new Dog( "Fido", 1.30f, 2.9f );
	//^^ Doesnt work, Dog is abstract
	GoldenRetriever c; //works on stack again
	b -> bark();
	a -> bark();
	c.bark();

	std::cout << a -> getName() << std::endl;
	std::cout << b -> getWeight() << std::endl;
	delete a;
	delete b;
	std::cin.get();
	
	return 0;
}