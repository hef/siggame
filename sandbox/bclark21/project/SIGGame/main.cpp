

/*****************************************************************************/

//  filename:  Utils.cpp	//declares an executable source code

//#include <stdio.h>
#include <iostream>		//required for cin, cout, endl
#include <assert.h>		//required for assert
#include <math.h>		//required for abs()
#include "Dog.h"	//includes class Dog file
#include "GoldenRetriever.h"
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
	int ready = 0;

	//Declaration of Objects 
	//a de-referenced pointer to useful for an instance on the heap
	//a variable for an instance on the stack
	Utils* useful;
	
	Utils semiuseful;
	//Must declare a dereferenced pointer for an object on the heap
	Dog *Fido,*Fidonew, *FidoCopy;
	Dog dogOne, dogTwo, dogThree;
	char*  newDogID;
	char	retrieveDogID[17];
	
	float initDogHeight,
		  initDogWeight;

	GoldenRetriever GR1;

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


//-------------------------tut  -------------------------------------------


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

//-----------------------------------

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

//--------------------------tut 5----------------------------------

	cout<<"----------"<<endl;
	cout<<"For a default GoldenRetriever the results are as follows: "
		<<"GR1's height is: "<<GR1.GoldenRetriever::getDogHeight()<<endl
		<<"GR1's weight is: "<<GR1.GoldenRetriever::getDogWeight()<<endl
		<<"GR1's name is: "<<GR1.GoldenRetriever::getDogName()<<endl;

		
	//code designed to exit program after review
	
	system("PAUSE");
    //return EXIT_SUCCESS;

	return 0;
}


