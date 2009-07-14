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
		int digit;
	public:

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
//#include "Utilities.h"
using namespace std;

int main()
{
	int ready;
	//Declaration of Objects
	Utilities *useful,
			  semiuseful;
	
	cout<<"Hello";
	cin>>ready;

	useful = new Utilities::Utilities();

	
	return 0;
}

