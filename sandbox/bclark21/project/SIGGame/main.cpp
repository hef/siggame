/*****************************************************************************/
//header guards to prevent multiple compilation of definitions
#ifndef UTILITIES_H
#define UTILITIES_H

// Declaration of class Utilities
/* filename: Utilities.h			*/

#include <stdio.h>
//using namespace std;

class Utilities{
	private:
		
	public:
		int digit;
		//Default constructor:
		Utilities(){
			digit = 0;
		}

		//Destructor:
		~Utilities(){

		}
};
#endif /* UTILITIES_H */  //end of compiler directive ndef


/*****************************************************************************/

//  filename:  Utilities.cpp

#include <stdio.h>
#include <iostream>
#include <stack>
//#include "Utilities.h"  //used only when the class declaration is in 
//a separate headerfile
using namespace std;

int main()
{
	int ready;
	//Declaration of Objects 
	//a de-referenced pointer to useful for an instance on the heap
	//a variable for an instance on the stack
	Utilities *useful, semiuseful;

	
	cout<<"Hello"<<endl;


	useful = new Utilities();
	useful->digit = 3;

	cout<<useful->digit<<endl;

	cin>>ready;
	cout<<ready;
	return 0;
}

