/*****************************************************************************/

// Implementation of class Dog
/* filename: Dog.cpp			*/

//included files
#include <iostream>
#include "Dog.h"

//incorporating input/output commands  used when class is in a separate file
using std::cout;
using std::cin;
using std::endl;



		//Default constructor:
		Dog::Dog():dogHeightMeters(0.0), dogWeight(0.0),
			startDog(new char[17])
		{
			//dogHeightMeters = 0.0;
			//dogWeight = 0.0;
			//cout<<"From default constructor Dog's height is: "
			//<<dogHeightMeters<<endl;
			//set each element of the char array to '-'
			//startDog = new char[17];
			for ( int i = 0; i <= 15; ++i )
			{
				startDog [i] = '?';
			}
			startDog[16] = '\0';	
			//for ( int i = 0; i <=15; ++i )
			//	cout<<startDog[i];
			//cout<<"\ndefault constructor finished"<<endl;
		}

		//Parameterized constructor:
		
		Dog::Dog(float initDogHeightMeters, float initDogWeight, char newDogID[]):
			dogHeightMeters(initDogHeightMeters), dogWeight(initDogWeight),
			startDog(new char [17])
		{
			//dogHeightMeters = initDogHeightMeters;
			//dogWeight = initDogWeight;
			//startDog = new char [17];
			for ( int i = 0; i <= 15; ++i )
			{
				startDog[i] = '\0';
				if ( newDogID[i] != '\0' )
					startDog[i] = newDogID[i];
				cout<<startDog[i];
			}
			startDog[16] = '\0';
			/*
			startDog = &newDogID[0];
			cout<<"From triple constructor dog's tag is: ";
			char * transDog = startDog;
			while(*(transDog) != '\0')
			{
				cout<<*(transDog);
				(transDog = transDog + 1);
			}	*/
			cout<<endl;	
					

		}

		//copy constructor

		Dog::Dog(const Dog*  oldDog) 
		{
			dogHeightMeters = oldDog->dogHeightMeters;
			dogWeight = oldDog->dogWeight;
			startDog = new char [17];
			for ( int i = 0; i <= 15; ++i )
			{
				startDog[i] = '\0';
				if ( oldDog->startDog[i] != '\0' )
					startDog[i] = oldDog->startDog[i];
			}
			startDog[16] = '\0';
		}

		//accessor methods
		float Dog::getDogHeightMeters() const
		{
			return dogHeightMeters;
		}

		float Dog::getDogWeight()	const
		{
			return dogWeight;
		}


		void  Dog::getDogName(char retrieveDogID [])	
		{
			
			//retrieve each element of the char array
			//startDog = new char[17];

			for ( int i = 0; i <= 16; ++i )
			{
					retrieveDogID[i] = startDog[i];
			}
			
		}
		
		//mutator methods
		void Dog::setDogHeightMeters(float newDogHeightMeters)
		{
			dogHeightMeters = newDogHeightMeters;
		}

		void Dog::setDogWeight(float newDogWeight)
		{
			dogWeight = newDogWeight;	
		}

		//Destructor method
		Dog::~Dog()
		{
			delete [] startDog;
		}

/*---------------------------------------------------------------------------*/