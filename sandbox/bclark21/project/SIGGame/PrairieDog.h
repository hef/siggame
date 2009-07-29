
/*****************************************************************************/
//header guards to prevent multiple compilation of definitions
#ifndef PRAIRIEDOG_H
#define PRAIRIEDOG_H

// Declaration of class PrairieDog
/* filename: PrairieDog.h			*/
#include <iostream>
#include "Dog.h"


class PrairieDog : public Dog		//derived from Dog class
{
protected:

private:

public:
	//default constructor
	PrairieDog();

	
	//parameterized constructor
	PrairieDog(float initDogHeight, float initDogWeight , 
		char* newDogID );
	
	//copy constructor

	PrairieDog(const PrairieDog& MasterDog);
    PrairieDog::PrairieDog(const Dog* oldDog);

	//accessor method
	float getDogHeight()const;

	float getDogWeight() const;

	char* getDogName()const;

	void getDogName(char retrieveDogID[]);

	//method of derived class
	virtual void bark()const;	

	//derived from pure virtual function in base class

	//Destructor method
	PrairieDog::~PrairieDog();


};

#endif /*	PRAIRIEDOG_H */  //end of compiler directive ndef