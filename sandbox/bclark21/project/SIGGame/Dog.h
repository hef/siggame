
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
/*		float dogHeight,
			  dogWeight;  
		char*	startDog;
*/
	//protected members
	protected:


	//public members
	public:
		//public data
			float dogHeight,
			  dogWeight;  
		char*	startDog;	

		//for pure virtual function thereby making Dog an abstract class
		virtual void bark()=0;		//delete const for pure virtual

		//Default constructor:
		Dog();

		//Parameterized constructor:
		Dog(const float initDogHeight, const float initDogWeight , 
			const char* newDogID   );

		//copy constructor
		//using a constant pointer as parameter
		Dog::Dog(const Dog*  Fido);
		//using a pass by reference parameter
		Dog::Dog(const Dog& MasterDog);

		//accessor methods
		float Dog::getDogHeight() const;
		float Dog::getDogWeight() const;
		char*  Dog::getDogName() const;
		void  Dog::getDogName(char retrieveDogID []);

		//mutator methods
		void Dog::setDogHeight(const float newDogHeight);
		void Dog::setDogWeight(const float newDogWeight);

		//Destructor method
		 ~Dog();

};

#endif /* DOG_H */  //end of compiler directive ndef

//-----------------------------------------------------------------------------
