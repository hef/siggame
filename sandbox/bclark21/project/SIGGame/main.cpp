

/*****************************************************************************/

//  filename:  Utils.cpp	//declares an executable source code

//#include <stdio.h>
#include <iostream>		//required for cin, cout, endl
#include <assert.h>		//required for assert
#include <math.h>		//required for abs()
#include "Dog.h"	//includes class Dog file
#include "GoldenRetriever.h"
#include "PrairieDog.h"
#include "Utils.h"  //used only when the class declaration is in 
					//a separate headerfile

//using namespace std;

//substitute for namespace std by using separate individual files
using std::cout;
using std::cin;
using std::endl;

//function prototype unnecessary when function included in header file
//Utils::sumUp(int);	

int main()
{
	//Declaration of Objects 
	//a de-referenced pointer to useful for an instance on the heap
	//a variable for an instance on the stack
	Utils* useful;
	
	Utils semiuseful;

	//Must declare a dereferenced pointer for an object on the heap
	//Dog pointers for tutorial 4
/*	Dog *Fido,*Fidonew, *FidoCopy;	*/	

	char*  newDogID;
	char	retrieveDogID[17];
	
	float initDogHeight,
		  initDogWeight;

	GoldenRetriever *GR1;
	GoldenRetriever *GR2,
					*GRCopy;


	PrairieDog  *PD1, *PD2, *PDCopy;

	//array of pointers for virtual functions
	Dog*	doggiePtr[9];				

//------------------------Begin user interface----------------------------

	//std output of instance on the stack, declaration uses constructor
	//private data requires accessor method, public data uses . operator
	cout<<"private data on the stack: "<<semiuseful.getDigit()<<endl
		<<"public data on the stack: "<<semiuseful.digitPub<<endl;

	//instantiate object on the heap
	useful = new Utils(5);

	//std output of instance on the heap, declaration uses constructor
	//private data requires accessor method and dereferenced ptr
	cout<<"private data on the heap: "<<useful->getDigit()<<endl;
	//public data requires dereferencing and . operator
	cout<<"public data on the heap: "<<useful->digitPub<<endl;
	
	//public data on the stack is mutated with . operator
	semiuseful.digitPub = 3;
	cout<<semiuseful.digitPub<<endl;
	//private data on the stack is mutated with . operator and mutator method
	semiuseful.set(2);
	cout<<semiuseful.getDigit()<<endl;


	//private data on the heap is mutated with dereference, dot operator and 
	//mutator method
	useful->set(3);
	cout<<useful->getDigit()<<endl;

	//public data on the heap is mutated with dereference, . operator
	useful->digitPub = 3;
	cout<<useful->digitPub<<endl;


//-------------------------tut #3 -------------------------------------------


	//enter a non-negative number and test it
	unsigned int num (0), numberSum (0);
	do
	{
		cout<<"Enter non negative integer to be summed: ";
		cin>>num;
		if(num<0)
			cout<<"Please re-enter a non-negative number."<<endl;
	}while(num<0);

	//function called with scope operator
	//if sum is negative, then exit
	//use assert to check for negative sum	
	assert ( Utils::sumUp(num) >= 0 );
	numberSum = abs( Utils::sumUp(num)); 

	//stream result to std output
	cout<<"The sum of num is: "<<numberSum<<endl;

//--------------------------- tut #4  ----------------------------
/*
	//testing for tutorial 4 on class Dog
	//use default constructor to create Fido
	cout<<"----------"<<endl
		<<"The default constructor for a dog returns the following data: "<<endl;
	Fido = new Dog();
	cout<<"Dog's height is: "<<Fido->getDogHeight()<<endl
		<<"Dog's weight is: "<<Fido->getDogWeight()<<endl;
	cout<<"Dog's tag as returned is: ";
	Fido->getDogName(retrieveDogID);
    for ( int i = 0; i <= 15; ++i )
	{
		if ( retrieveDogID != '\0' )
		{
			cout<<retrieveDogID[i];
		}
	}
	cout<<endl;


//--------------
	
	//To create a record for a dog enter the following data if available
	cout<<"----------"<<endl;
	cout<<"Enter the dog's height in meters: ";
	cin>>initDogHeight;
	if ( initDogHeight <= 0 )
		initDogHeight = 0;
	cout<<"Enter the dog's weight: ";
	cin>>initDogWeight;
	if ( initDogWeight <= 0 )
		initDogWeight = 0;
	cout<<"Enter the dog's tag (16 characters): ";
	//initialize the name char array to null
	newDogID = new char[17];
	for ( int i = 0; i <= 16; ++i )
	{
		newDogID[i] = '\0';
	}
	//input the name up to 16 characters long
	cin>>newDogID;
	int charInd = 0;

	while ( charInd <= 16)
	{
		if (!( newDogID[charInd] >= 32 && newDogID[charInd] <= 126))
		{
			newDogID[charInd] = '\0';
			break;
		}
		charInd += 1;
	}//while loop
		
	
	Fidonew = new Dog(initDogHeight, initDogWeight, newDogID);
	cout<<"The fully parameterized constructor yields the following"<<endl;
	cout<<"Dog's height is: "<<Fidonew->getDogHeight()<<endl
		<<"Dog's weight is: "<<Fidonew->getDogWeight()<<endl;
	Fidonew->getDogName(retrieveDogID);
	cout<<"Dog's name tag reads: ";
	for ( int i = 0; i <= 15; ++i )
	{
			cout<<retrieveDogID[i];
	}
	cout<<endl;

	//------------------------
	//test copy constructor
	cout<<"----------"<<endl
		<<"The copy constructor yields the following"<<endl;
	//declaring with use of copy constructor does not require new!! 
	//Dog strangeDog = new Dog (Fidonew);  //This will give two initializations:
	Dog strangeDog(Fidonew);		//This is sufficient
	FidoCopy = &strangeDog;			//use a ptr to Dog and an object
	//initialize new dog with a ponter to an existing dog
	//copy works with a ptr 
	cout<<"Dog's height is: "<<FidoCopy->getDogHeight()<<endl
    //copy works with an object
		<<"Dog's weight is: "<<strangeDog.getDogWeight()<<endl;
	FidoCopy->getDogName(retrieveDogID);
	cout<<"Dog's name tag reads: ";
	for ( int i = 0; i <= 15; ++i )
	{
			cout<<retrieveDogID[i];
	}
	cout<<endl;

	//-----
	cout<<"After altering the values of the copy a/k/a strangeDog\n"
		<<"and the values of the original a/k/a Fidonew: "<<endl;
	strangeDog.Dog::setDogHeight(1.80000f);
	strangeDog.Dog::setDogWeight(120.0f);
	Fidonew->setDogHeight(1.30000f);
	Fidonew->setDogWeight(80.0f);
	cout<<"strangeDog's height is: "<<strangeDog.getDogHeight()<<endl
		<<"strangeDog's weight is: "<<strangeDog.getDogWeight()<<endl
		<<"strangeDog's tag reads: ";
	strangeDog.getDogName(retrieveDogID);
	for ( int i = 0; i <= 16; ++i )
	{
		if ( retrieveDogID[i] != '\0' )
			cout<<retrieveDogID[i];
	}
	cout<<endl;
	cout<<"Fidonew's height is: "<<Fidonew->getDogHeight()<<endl
		<<"Fidonew's weight is: "<<Fidonew->getDogWeight()<<endl
		<<"Fidonew's tag reads: ";
	Fidonew->getDogName(retrieveDogID);
	for ( int i = 0; i <= 16; ++i )
	{
		if ( retrieveDogID[i] != '\0' )
			cout<<retrieveDogID[i];
	}
	cout<<endl;
*/
//--------------------------tut 5----------------------------------

	cout<<"----------"<<endl;
	GR1 = new GoldenRetriever();	
	//end of addition
	cout<<"For a default GoldenRetriever the results are as follows: "<<endl
		<<"GR1's height is: "<<GR1->GoldenRetriever::getDogHeight()<<endl
		<<"GR1's weight is: "<<GR1->GoldenRetriever::getDogWeight()<<endl
	//access name through a char pointer - option 1 
		<<"GR1's name is: "<<GR1->GoldenRetriever::getDogName()<<endl	
	//acess name through copy to char array in main - option 2
		<<"GR1's tag reads: ";
	GR1->GoldenRetriever::getDogName(retrieveDogID);
	for ( int i = 0; i <= 16; ++i )
	{
		if ( retrieveDogID[i] != '\0' )
			cout<<retrieveDogID[i];
	}
	cout<<endl;
		
	//GoldenRetriever speaks
	GR1->GoldenRetriever::bark();
	//GoldenRet[0]->bark();
	//-------------------------------PraireDog's turn---------------------
	PD1 = new PrairieDog();	
	cout<<"For a default PrairieDog the results are as follows: "<<endl
		<<"PD1's height is: "<<PD1->PrairieDog::getDogHeight()<<endl
		<<"PD1's weight is: "<<PD1->PrairieDog::getDogWeight()<<endl
	//access name through a char pointer - option 1 
		<<"PD1's name is: "<<PD1->PrairieDog::getDogName()<<endl	
	//acess name through copy to char array in main - option 2
		<<"PD1's tag reads: ";
	PD1->PrairieDog::getDogName(retrieveDogID);
	for ( int i = 0; i <= 16; ++i )
	{
		if ( retrieveDogID[i] != '\0' )
			cout<<retrieveDogID[i];
	}
	cout<<endl;


	//PrairieDog speaks
	PD1->PrairieDog::bark();


	//---------------------------------fully parameterized dogs--------------
	//for a fully parameterized GoldenRetriever
	cout<<"----------"<<endl
		<<"Enter the Golden Retriever's height: ";
	cin>>initDogHeight;
	cout<<"Enter the Golden Retriever's weight: ";
	cin>>initDogWeight;
	cout<<"Enter the Golden Retriever's name: ";

	//initialize the name char array to null
	newDogID = new char[17];
	for ( int i = 0; i <= 16; ++i )
	{
		newDogID[i] = '\0';
	}
	//input the name up to 16 characters long
	cin>>newDogID;
	char charInd = 0;

	while ( charInd <= 16)
	{
		if (!( newDogID[charInd] >= 32 && newDogID[charInd] <= 126))
		{
			newDogID[charInd] = '\0';
			break;
		}
		charInd += 1;
	}//while loop

	GR2 = new GoldenRetriever(initDogHeight, initDogWeight, newDogID);	
	cout<<"For a parameterized GoldenRetriever the results are as follows: "
		<<endl
		<<"The Golden Retriever's height is: "<<GR2->GoldenRetriever::getDogHeight()<<endl
		<<"The Golden Retriever's weight is: "<<GR2->GoldenRetriever::getDogWeight()<<endl
	//access name through a char pointer - option 1 	
		<<"The Golden Retriever's name is: "<<GR2->GoldenRetriever::getDogName()<<endl	
	//acess name through copy to char array in main - option 2
		<<"The Golden Retriever's tag reads: ";
	GR2->GoldenRetriever::getDogName(retrieveDogID);
	for ( int i = 0; i <= 16; ++i )
	{
		if ( retrieveDogID[i] != '\0' )
			cout<<retrieveDogID[i];
	}
	cout<<endl;


	//GoldenRetriever speaks
	GR2->GoldenRetriever::bark();


	//------------------- Prairie Dog's turn at full parameterization------------

	//for a fully parameterized PrairieDog
	cout<<"----------"<<endl
		<<"Enter the Prairie Dog's height: ";
	cin>>initDogHeight;
	cout<<"Enter the Prairie Dog's weight: ";
	cin>>initDogWeight;
	cout<<"Enter the Prairie Dog's name: ";

	//initialize the name char array to null
	newDogID = new char[17];
	for ( int i = 0; i <= 16; ++i )
	{
		newDogID[i] = '\0';
	}
	//input the name up to 16 characters long
	cin>>newDogID;
	charInd = 0;

	while ( charInd <= 16)
	{
		if (!( newDogID[charInd] >= 32 && newDogID[charInd] <= 126))
		{
			newDogID[charInd] = '\0';
			break;
		}
		charInd += 1;
	}//while loop

	PD2 = new PrairieDog(initDogHeight, initDogWeight, newDogID);	

	cout<<"For a parameterized Prairie Dog the results are as follows: "
		<<endl
		<<"The Prairie Dog's height is: "<<PD2->PrairieDog::getDogHeight()<<endl
		<<"The Prairie Dog's weight is: "<<PD2->PrairieDog::getDogWeight()<<endl
	//access name through a char pointer - option 1 	
		<<"The Prairie Dog's name is: "<<PD2->PrairieDog::getDogName()<<endl	
	//acess name through copy to char array in main - option 2
		<<"The Prairie Dog's tag reads: ";
	PD2->PrairieDog::getDogName(retrieveDogID);
	for ( int i = 0; i <= 16; ++i )
	{
		if ( retrieveDogID[i] != '\0' )
			cout<<retrieveDogID[i];
	}
	cout<<endl;


	//PrairieDog speaks
	PD2->PrairieDog::bark();

//--------------------------------  copy dogs -------------------------------


	//uses golden retriever copy constructor
	cout<<"----------"<<endl
		<<"For a copy of the golden retriever: "<<endl;
	GoldenRetriever GR3(*GR2);		
	GRCopy = &GR3;					
	cout<<"The copied Golden Retriever's height is: "<<GRCopy->GoldenRetriever
			::getDogHeight()<<endl
		<<"The copied Golden Retriever's weight is: "<<GRCopy->GoldenRetriever
			::getDogWeight()<<endl
		<<"The copied Golden Retriever's name is: "<<GRCopy->GoldenRetriever
			::getDogName()<<endl
		<<"The copied Golden Retriever's tag reads: ";
	GRCopy->GoldenRetriever::getDogName(retrieveDogID);
	for ( int i = 0; i <= 16; ++i )
	{
		if ( retrieveDogID[i] != '\0' )
		cout<<retrieveDogID[i];
	}
	cout<<endl;
	
	//GoldenRetriever speaks
	GRCopy->GoldenRetriever::bark();

	//------------------ testing the deep copy of the golden retriever---


	cout<<"After altering the values of the copy a/k/a GRCopy\n"
		<<"and the values of the original a/k/a GR2: "<<endl;
	GRCopy->GoldenRetriever::setDogHeight(.800f);
	
	GRCopy->GoldenRetriever::setDogWeight(40.0f);
	GR2->setDogHeight(1.30000f);
	GR2->setDogWeight(80.0f);
	cout<<"GRCopy's height is: "<<GRCopy->getDogHeight()<<endl
		<<"GRCopy's weight is: "<<GRCopy->getDogWeight()<<endl
		<<"GRCopy's tag reads: ";
	GRCopy->getDogName(retrieveDogID);
	for ( int i = 0; i <= 16; ++i )
	{
		if ( retrieveDogID[i] != '\0' )
			cout<<retrieveDogID[i];
	}
	cout<<endl;
	cout<<"GR2's height is: "<<GR2->getDogHeight()<<endl
		<<"GR2's weight is: "<<GR2->getDogWeight()<<endl
		<<"GR2's tag reads: ";
	GR2->getDogName(retrieveDogID);
	for ( int i = 0; i <= 16; ++i )
	{
		if ( retrieveDogID[i] != '\0' )
			cout<<retrieveDogID[i];
	}
	cout<<endl;

	//------------------------- prairie dog's turn to copy -------------------

	//uses prairie dog copy constructor
	cout<<"----------"<<endl
		<<"For a copy of the prairie dog: "<<endl;
	PrairieDog PD3(*PD2);
	PDCopy = &PD3;
	cout<<"The copied Prairie Dog's height is: "<<PDCopy->PrairieDog
			::getDogHeight()<<endl
		<<"The copied Prairie Dog's weight is: "<<PDCopy->PrairieDog
			::getDogWeight()<<endl
		<<"The copied Prairie Dog's name is: "<<PDCopy->PrairieDog
			::getDogName()<<endl
		<<"The copied Prairie Dog's tag reads: ";
	PDCopy->PrairieDog::getDogName(retrieveDogID);
	for ( int i = 0; i <= 16; ++i )
	{
		if ( retrieveDogID[i] != '\0' )
		cout<<retrieveDogID[i];
	}
	cout<<endl;
	
	//PrairieDog speaks
	PDCopy->PrairieDog::bark();

	//summary of doggies

	doggiePtr[0] = GR1;
	doggiePtr[1] = GR2;
	doggiePtr[2] = GRCopy;
	doggiePtr[3] = PD1;
	doggiePtr[4] = PD2;
	doggiePtr[5] = PDCopy;
/*	doggiePtr[6] = Fido;
	doggiePtr[7] = Fidonew;
	doggiePtr[8] = FidoCopy;	
*/
//-----------behold a corus of virtual barks-----------------------------

	cout<<"----------Virtual Barking ----------"<<endl;
	for ( int i = 0; i <= 5; ++i )	/* change to 5 for pure virtual */
	{
		doggiePtr[i]->bark();
	}
	cout<<endl;
//-----------------------------------------------------------------------------
		
	//code designed to exit program after review
	
	system("PAUSE");
    //return EXIT_SUCCESS;

	return 0;
}


