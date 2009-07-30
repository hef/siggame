
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

		//private data members
		//these should be declared in the base class-not derived class
/*	float dogHeight,
			  dogWeight;  
		char*	startDog;	*/

public:
	//default constructor
	GoldenRetriever();

	
	//parameterized constructor
	GoldenRetriever(float initDogHeight, float initDogWeight, 
		char* newDogID);

	//copy constructor
	GoldenRetriever::GoldenRetriever(const GoldenRetriever& MasterDog);

	//quasi-copy constructor
	GoldenRetriever::GoldenRetriever(const GoldenRetriever* oldDog);


	//accessor method
	float getDogHeight()const;

	float getDogWeight() const;

	char* getDogName()const;

	void getDogName(char retrieveDogID[]);

	//mutator methods
	void GoldenRetriever::setDogHeight(const float newDogHeight);
	void GoldenRetriever::setDogWeight(const float newDogWeight);

	//method of derived class
	void GoldenRetriever::bark();	

	//derived from pure virtual function in base class

	//Destructor method
	GoldenRetriever::~GoldenRetriever();


};

#endif /* GOLDENRETRIEVER_H */  //end of compiler directive ndef