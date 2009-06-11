#ifndef Utilties_H 
#define Utilities_H
#include <iostream>
using namespace std;

class Utilities
{

public:
	Utilities();
	~Utilities();
	int sumUp(int n);

};

Utilities::Utilities(){}
Utilities::~Utilities(){}

int Utilities::sumUp(int n )
{
	

	if(n==1) {return 1;}

	return ( n + sumUp(n-1) );
}

#endif;
