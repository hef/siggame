/*****************************************************************************/
//header guards to prevent multiple compilation of definitions
#ifndef UTILITIES_H
#define UTILITIES_H

// Declaration of class Utilities
/* filename: Utilities.h			*/

//#include <stdio.h>
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
