
/*****************************************************************************/
//header guards to prevent multiple compilation of definitions
#ifndef DOG_H
#define DOG_H

// Declaration of class Dog
/* filename: Dog.h			*/
#include <iostream>


class Dog{
	
	//private members
	private:
		//private data members
		float dogHeightMeters,
			  dogWeight;
		  
		char 	dogID [16];
		char*	startDog;
	
	//public members
	public:
		//public data


		//Default constructor:
		Dog();

		//Parameterized constructor:
		Dog(float initDogHeightMeters, float initDogWeight);
		Dog(float initDogHeightMeters, float initDogWeight, char newDogID[]);

		//copy constructor

		//accessor methods
		float Dog::getDogHeightMeters() const;
		float Dog::getDogWeight() const;
		void  Dog::getDogName();
		void  Dog::getDogName(char retrieveDogID []);

		//mutator methods
		void Dog::setDogHeightMeters(float newDogHeightMeters);
		void Dog::setDogWeight(float newDogWeight);

		//Destructor method
		~Dog();

};

#endif /* DOG_H */  //end of compiler directive ndef

//-----------------------------------------------------------------------------
