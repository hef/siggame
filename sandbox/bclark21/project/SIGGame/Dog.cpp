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
		Dog::Dog():dogHeight(0.0f), dogWeight(0.0f),
			startDog(new char[17])
		{
			//dogHeight = 0.0f;
			//dogWeight = 0.0f;
			//cout<<"From default constructor Dog's height is: "
			//<<dogHeight<<endl;
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
		
		Dog::Dog(const float initDogHeight, const float initDogWeight, 
			const char newDogID[]):
			dogHeight(initDogHeight), dogWeight(initDogWeight),
			startDog(new char [17])
		{
			//dogHeight = initDogHeight;
			//dogWeight = initDogWeight;
			//startDog = new char [17];
/*			for ( int i = 0; i <= 15; ++i )
			{
				startDog[i] = '\0';
				if ( newDogID[i] != '\0' )
					startDog[i] = newDogID[i];
				cout<<startDog[i];
			}
			startDog[16] = '\0';*/
			//ignore compiler warning: cannot use strncpy_s with char*
			//alternative using strncpy(dest, source, length of dest)
			strncpy(startDog, newDogID, 17);
			if ( startDog[17-1] != '\0' )
			{
				startDog[16] = '\0';
			}
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
			dogHeight = oldDog->dogHeight;
			dogWeight = oldDog->dogWeight;
			startDog = new char [17];
			for ( int i = 0; i <= 15; ++i )
			{
				//initialize this.startDog
				startDog[i] = '\0';
			}
/*				//test oldDog.startDog's value and assign to this.startDog
				if ( oldDog->startDog[i] != '\0' )
					startDog[i] = oldDog->startDog[i];
			}
			//set this.startDog to null
			startDog[16] = '\0';
*/			//ignore compiler warning: cannot use strncpy_s with char*
			strncpy(startDog, oldDog->startDog, 17);
			if ( startDog[16] != '\0' )
			{
				startDog[16] = '\0';
			}
		}

		Dog::Dog(const Dog& MasterDog)
		{}

		//accessor methods
		float Dog::getDogHeight() const
		{
			return dogHeight;
		}

		float Dog::getDogWeight()	const
		{
			return dogWeight;
		}


		void  Dog::getDogName(char retrieveDogID [])	
		{
			
			//retrieve each element of the char array; copy it to an array
			//startDog = new char[17];

		/*	for ( int i = 0; i <= 16; ++i )
			{
					retrieveDogID[i] = startDog[i];
			}*/
			//ignore compiler warning: cannot use strncpy_s with char*
			strncpy(retrieveDogID, startDog,17);
			if ( retrieveDogID[17-1] != '\0' )
			{
				retrieveDogID[16] = '\0';
			}
			
		}

		char* Dog::getDogName() const
		{
			
			return startDog;
		}
		
		//mutator methods
		void Dog::setDogHeight(const float newDogHeight)
		{
			dogHeight = newDogHeight;
		}

		void Dog::setDogWeight(const float newDogWeight)
		{
			dogWeight = newDogWeight;	
		}
/*
		virtual void bark (int noise)
		{
		}
*/

		//Destructor method
		Dog::~Dog()
		{
			delete [] startDog;
		}

/*---------------------------------------------------------------------------*/