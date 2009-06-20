#include <iostream>
#include "Dog.h"

void testDog( Dog& d );

int main(){
	Dog d( "Snoop Dog Dog Dog" ); //Shouldn't print last g

	testDog( d );

	Dog dCopy = d;

	testDog( dCopy );

	system( "pause" );
	return 0;
}

void testDog( Dog& d )
{
	d.setHeight( 10 );
	d.setWeight( 200 );

	std::cout << "Name:" << d.getName() << std::endl;
	std::cout << "Height:" << d.getHeight() << std::endl;
	std::cout << "Weight:" << d.getWeight() << std::endl;
	std::cout << std::endl;
}
