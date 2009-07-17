#include "Dog.h"
#include "PrairieDog.h"
#include "GoldenRetriever.h"
#include "Impound.h"
#include <iostream>
#include <string>



int main()
{
	Impound* pImpound = Impound::Instance();
	Dog* a = new PrairieDog;
	Dog* b = new GoldenRetriever( "doggy", 1.9f, 1.9f );
	Dog* c = new GoldenRetriever( "Fido", 2.0f, 2.0f );
	Dog* d = new GoldenRetriever( "Fido", 2.0f, 2.0f );
	//some testing
	std::cout << pImpound->addDog( a ) << std::endl;
	std::cout << pImpound->addDog( b ) << std::endl;
	std::cout << pImpound->addDog( c ) << std::endl;
	std::cout << pImpound->addDog( d ) << std::endl;
	std::cout << pImpound->addDog( a ) << std::endl;
	std::cout << pImpound->addDog( b ) << std::endl;
	std::string name = "Fido";
	if( pImpound->findDog( name ) )
		pImpound->visitImpound();
	delete a;
	delete b;
	delete c;
	delete d;
	pImpound->destroy();
	pImpound->visitImpound();
	std::cin.get();
	
	return 0;
}