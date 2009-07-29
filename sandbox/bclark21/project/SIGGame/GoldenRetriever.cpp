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
		GoldenRetriever::GoldenRetriever() 
		{
			//implicitly calls default constructor of base class Dog::Dog()
			//same result as including :Dog() as initialization
			cout<<"GoldenRetriever default constructor for "<<this<<endl;
		}

		//Parameterized constructor:
		GoldenRetriever::GoldenRetriever( float initDogHeight, 
			float initDogWeight ,  char* newDogID ):
			Dog(initDogHeight, initDogWeight, newDogID   )  
		{
			//base class's default constructor is called implicitly unless, the 
			//parameterized constructor explicitly calls the base class's 
			//paraterized constructor
			cout<<"GoldenRetriever parameterized constructor for "<<this<<endl;
		}

/*	
//--overrides base class methods-----------------------------------------

		//default constructor		
		GoldenRetriever::GoldenRetriever(): dogHeight(0.0f), dogWeight(0.0f),
			startDog(new char[17])
		{
			//startDog = new char[17];
			for ( int i = 0; i <= 15; ++i )
			{
				startDog [i] = '?';
			}
			startDog[16] = '\0';
			cout<<"GoldenRetriever default constructor for "<<this<<endl;
		}


		//Parameterized constructor:
		GoldenRetriever::GoldenRetriever( float initDogHeight, 
			float initDogWeight,  char* newDogID):
			dogHeight(initDogHeight), dogWeight(initDogWeight),
			startDog(new char[17])

		{
			//base class's default constructor is called implicitly unless, the 
			//parameterized constructor explicitly calls the base class's 
			//paraterized constructor
			//ignore compiler warning: cannot use strncpy_s with char*
			//alternative using strncpy(dest, source, length of dest)
			cout<<"Dog parameterized constructor for "<<this<<endl;
			strncpy(startDog, newDogID, 17);
			if ( startDog[17-1] != '\0' )
			{
				startDog[16] = '\0';
			}
			cout<<"GoldenRetriever parameterized constructor for "<<this<<endl;
		}
 */
// ------------------------ copy constructors ----------------------------------
	
	
		//quasi-copy constructor passes a pointer, uses derererencing
			GoldenRetriever::GoldenRetriever(const GoldenRetriever*  oldDog):
				Dog(oldDog) 
		{
			//dogHeight = oldDog->dogHeight;
			//dogWeight = oldDog->dogWeight;
			//startDog = new char [17];
			for ( int i = 0; i <= 15; ++i )
			{
				//initialize this.startDog
				startDog[i] = '\0';
			}
			//ignore compiler warning: cannot use strncpy_s with char*
			strncpy(startDog, oldDog->startDog, 17);
			if ( startDog[16] != '\0' )
			{
				startDog[16] = '\0';
			}	
		}



	//copy constructor
		GoldenRetriever::GoldenRetriever(const GoldenRetriever& MasterDog):
			Dog(MasterDog)
		{
			cout<<"GR copy constructor at "<<this<<endl;
		}


//--------------------------------------Derived Accessor Class Methods--------

		//accessor methods
		float GoldenRetriever::getDogHeight() const
		{
			return Dog::getDogHeight();
		}

		float GoldenRetriever::getDogWeight() const
		{
			return Dog::getDogWeight();
		}

		//returns Golden Retriever's name by a char*
		char* GoldenRetriever::getDogName() const
		{
			return Dog::getDogName();
		}

		//copies Golden Retriever's name to an array in main
		void GoldenRetriever::getDogName(char retrieveDogID[])
		{
			Dog::getDogName(retrieveDogID);
		}

//---------------------overridding base class accessor methods------------
/*
		//accessor methods
		float GoldenRetriever::getDogHeight() const
		{
			return dogHeight;
		}

		float GoldenRetriever::getDogWeight() const
		{
			return dogWeight;
		}

		//returns Golden Retriever's name by a char*
		char* GoldenRetriever::getDogName() const
		{
			return startDog;
		}

		//copies Golden Retriever's name to an array in main
		void GoldenRetriever::getDogName(char retrieveDogID[])
		{
			strncpy(retrieveDogID, startDog,17);
			if ( retrieveDogID[17-1] != '\0' )
			{
				retrieveDogID[16] = '\0';
			}
		}

*/
//-------------------------------------------------------------------------
		//mutator methods
		void GoldenRetriever::setDogHeight(const float newDogHeight)
		{
			Dog::setDogHeight(newDogHeight);
		}

		void GoldenRetriever::setDogWeight(const float newDogWeight)
		{
			Dog::setDogWeight(newDogWeight);	
		}

/*
//------------------------------overriding base class mutators------------------

		//mutator methods
		void GoldenRetriever::setDogHeight(const float newDogHeight)
		{
			dogHeight = newDogHeight;
		}

		void GoldenRetriever::setDogWeight(const float newDogWeight)
		{
			dogWeight = newDogWeight;	
		}

*/
//------------------------------------------------------------------------------

		void GoldenRetriever::bark() const
		{
			Dog::bark();	   //comment out for pure virtual

			cout<<"roof"<<endl;
		}
/* 
//----------------------------overriding bark method --------------------------

		void GoldenRetriever::bark() const
		{
			cout<<"roof"<<endl;
		}

*/
//-----------------------------------------------------------------------------
		//Destructor method
		GoldenRetriever::~GoldenRetriever()
		{
			 Dog::~Dog();

		}

/*	
//---------------------------overriding destructor ---------------------------

		//destructor method
		GoldenRetriever::~GoldenRetriever()
		{
			delete [] startDog;
		}
*/
//---------------------------------------------------------------------------*/