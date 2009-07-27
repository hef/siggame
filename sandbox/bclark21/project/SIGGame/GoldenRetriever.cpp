/*****************************************************************************/

// Implementation of class GoldenRetriever
/* filename: GoldenRetriever.cpp			*/

//included files
#include <iostream>
#include "Dog.h"
#include "GoldenRetriever.h"

//incorporating input/output commands  used when class is in a separate file
using std::cout;
//using std::cin;
using std::endl;



		//Default constructor:
		GoldenRetriever::GoldenRetriever() : Dog() 
		{}


		//Parameterized constructor:
		
/*		GoldenRetriever::GoldenRetriever(const float initDogHeight, 
			const float initDogWeight, const char newDogID[]):
			Dog(initDogHeight, initDogWeight, 
			newDogID[])
		{}
*/

/*		//copy constructor

		GoldenRetriever::GoldenRetriever:Dog(const Dog*  oldDog) 
		{
			dogHeight = oldDog->dogHeight;
			dogWeight = oldDog->dogWeight;
			startDog = new char [17];
			for ( int i = 0; i <= 15; ++i )
			{
				//initialize this.startDog
				startDog[i] = '\0';
			}
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

*/

		//accessor method
		float GoldenRetriever::getDogHeight() const
		{
			return Dog::getDogHeight();
		}


		void GoldenRetriever::bark() const
		{
			cout<<"roof";
		}


		//Destructor method
/*		GoldenRetreiver::~GoldenRetriever:~Dog()
		{
			delete [] startDog;
		}*/

/*---------------------------------------------------------------------------*/