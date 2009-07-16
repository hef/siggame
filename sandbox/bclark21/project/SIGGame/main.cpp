

/*****************************************************************************/

//  filename:  Utils.cpp	//declares an executable source code

//#include <stdio.h>
#include <iostream>		//required for cin, cout, endl
#include "Dog.h"	//includes class Dog file
#include "Utils.h"  //used only when the class declaration is in 
//a separate headerfile

using namespace std;

//function prototype unnecessary when function included in header file
//Utils::sumUp(int);	

int main()
{
	int ready (0);

	//Declaration of Objects 
	//a de-referenced pointer to useful for an instance on the heap
	//a variable for an instance on the stack
	Utils *useful, semiuseful;
	//Must declare a dereferenced pointer for an object on the heap
	Dog *Fido,*Fidonew;
	char newDogID [16],
		 retreivedDogID[16];
	
	float initDogHeight_M,
		  initDogWeight;

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

	//enter a non-negative number and test it
	int numberSum, num (-1);
	do
	{
		cout<<"Enter non negative integer to be summed: ";
		cin>>num;
		if(num<0)
			cout<<"Please re-enter a non-negative number."<<endl;
	}while(num<0);

	//function called with scope operator
	//if sum is negative, then exit
	if(Utils::sumUp(num)<0)		
		exit(-1);				
	numberSum = Utils::sumUp(num); 

	//stream result to std output
	cout<<"The sum of num is: "<<numberSum<<endl;
	
	//testing for tutorial 4 on classes
	Fido = new Dog();
	cout<<"Dog's height is: "<<Fido->getDogHeight_M()<<endl
		<<"Dog's weight is: "<<Fido->getDogWeight()<<endl;
	cout<<"Dog's tag is: ";
		Fido->getDogName();
		//<<Fido->getDogName()<<endl;
		
	cout<<"Enter the dog's height in meters: ";
	cin>>initDogHeight_M;
	cout<<"Enter the dog's weight: ";
	cin>>initDogWeight;
	cout<<"Enter the dog's tag (16 characters): ";
	cin>>newDogID;
	cout<<newDogID<<endl;
		
	
	Fidonew = new Dog(initDogHeight_M, initDogWeight, newDogID);
	cout<<"Dog's height is: "<<Fidonew->getDogHeight_M()<<endl
		<<"Dog's weight is: "<<Fidonew->getDogWeight()<<endl;
	Fidonew->getDogName();
		
	//code designed to exit program after review
	cout<<"Enter number when ready: ";
	cin>>ready;
	cout<<ready;
	return 0;
}

