/*****************************************************************************/

// Implementation of class PrairieDog
/* filename: PrairieDog.cpp			*/

//included files
#include <iostream>
#include "Dog.h"
#include "PrairieDog.h"

//incorporating input/output commands  used when class is in a separate file
using std::cout;
//using std::cin;
using std::endl;



		//0-argument constructor:
		PrairieDog::PrairieDog() 
		{
			//implicitly calls default constructor of base class Dog::Dog()
			//same result as including :Dog() as initialization
			cout<<"PrairieDog default constructor for "<<this<<endl;
		}


		//Parameterized constructor:
		PrairieDog::PrairieDog( float initDogHeight, 
			float initDogWeight    ,  char* newDogID   ):
			Dog(initDogHeight, initDogWeight, newDogID )  
		{
			//base class's default constructor is called implicitly unless, the 
			//parameterized constructor explicitly calls the base class's 
			//paraterized constructor
			cout<<"PrairieDog parameterized constructor for "<<this<<endl;
		}


		//copy constructor

		PrairieDog::PrairieDog(const Dog* oldDog)
			:Dog(oldDog) 
		{
			dogHeight = oldDog->dogHeight;
			dogWeight = oldDog->dogWeight;
			startDog = new char [17];
			for ( int i = 0; i <= 15; ++i )
			{
				//initialize this.startDog
				startDog[i] = '\0';
			
				//test oldDog.startDog's value and assign to this.startDog
				if ( oldDog->startDog[i] != '\0' )
					startDog[i] = oldDog->startDog[i];
			}
			//set this.startDog to null
			startDog[16] = '\0';
			//ignore compiler warning: cannot use strncpy_s with char*
			strncpy(startDog, oldDog->startDog, 17);
			if ( startDog[16] != '\0' )
			{
				startDog[16] = '\0';
			}  
		}


		
		PrairieDog::PrairieDog(const PrairieDog& MasterDog):
			Dog(MasterDog)
		{
			cout<<"GR copy constructor at "<<this<<endl;
		}



		//accessor methods
		float PrairieDog::getDogHeight() const
		{
			return Dog::getDogHeight();
		}

		float PrairieDog::getDogWeight() const
		{
			return Dog::getDogWeight();
		}

		//returns Golden Retriever's name by a char*
		char* PrairieDog::getDogName() const
		{
			return Dog::getDogName();
		}

		//copies Golden Retriever's name to an array in main
		void PrairieDog::getDogName(char retrieveDogID[])
		{
			Dog::getDogName(retrieveDogID);
		}


		void PrairieDog::bark() const
		{
			Dog::bark();	   //comment out for pure virtual

			cout<<"yelp"<<endl;
		}


		//Destructor method
		PrairieDog::~PrairieDog()
		{
			 Dog::~Dog();

		}

/*---------------------------------------------------------------------------*/