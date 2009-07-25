
/*****************************************************************************/
//header guards to prevent multiple compilation of definitions
#ifndef GOLDENRETRIEVER_H
#define GOLDENRETRIEVER_H

// Declaration of class GoldenRetriever
/* filename: GoldenRetriever.h			*/
#include <iostream>
#include "Dog.h"


class GoldenRetriever : public Dog		//derived from Dog class
{
protected:

private:

public:
	//default constructor
	GoldenRetriever();

	
	//parameterized constructor
/*	GoldenRetriever(float initDogHeight, float initDogWeight, 
		char newDogID[]);
*/

	//accessor method
	float getDogHeight()const;

	//method of derived class
	void bark()const;
	//derived from pure virtual function in base class


};

#endif /* GOLDENRETRIEVER_H */  //end of compiler directive ndef