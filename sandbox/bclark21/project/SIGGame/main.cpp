/*****************************************************************************/
//header guards to prevent multiple compilation of definitions
#ifndef UTILITIES_H
#define UTILITIES_H

// Declaration of class Utilities
/* filename: Utilities.h			*/

#include <stdio.h>
//using namespace std;		//only if the class is declared in a separate file

class Utilities{
	
	//private members
	private:
		//private data members
		int digit;
	
	//public members
	public:
		//public data
		int digitPub;

		//Default constructor:
		Utilities(){
			digit = 8;
			digitPub = 9;
		}

		//parameterized constructor:
		Utilities(int initDigit){
			digit = initDigit;
			digitPub = 9;
		}

		//accessor methods
		int Utilities::getDigit(){
			return digit;
		}

		int Utilities::getDigitPub(){
			return digitPub;
		}

		//mutator method
		void Utilities::set(int newDigit){
			digit = newDigit;
		}

		//Destructor:
		~Utilities(){

		}
};
#endif /* UTILITIES_H */  //end of compiler directive ndef


/*****************************************************************************/

//  filename:  Utilities.cpp	//declares an executable source code

#include <stdio.h>
#include <iostream>
//#include "Utilities.h"  //used only when the class declaration is in 
//a separate headerfile

using namespace std;

int main()
{
	int ready (0);

	//Declaration of Objects 
	//a de-referenced pointer to useful for an instance on the heap
	//a variable for an instance on the stack
	Utilities *useful, semiuseful;

	//std output of instance on the stack, declaration uses constructor
	//private data requires accessor method, public data uses . operator
	cout<<"private data on the stack: "<<semiuseful.getDigit()<<endl
		<<"public data on the stack: "<<semiuseful.digitPub<<endl;

	//instantiate object on the heap
	useful = new Utilities(5);

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

	cout<<"Enter number when ready: ";
	cin>>ready;
	cout<<ready;
	return 0;
}

