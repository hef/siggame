/*****************************************************************************/
//header guards to prevent multiple compilation of definitions
#ifndef UTILITIES_H
#define UTILITIES_H

// Declaration of class Utils
/* filename: Utils.h			*/

//#include <stdio.h>
//using namespace std;		//only if the class is declared in a separate file

class Utils
{
	
	//private members
	private:
		//private data members
		int digit;
	
	//public members
	public:
		//public data
		int digitPub;

		//public function prototypes:
		//Default constructor:
		Utils();

		//Parameterized constructor:
		Utils(int initDigit);

		//accessor methods:
		int Utils::getDigit() const;
		int Utils::getDigitPub() const;

		//mutator methods
		void Utils::set(int newDigit);

		//static method that sums up numbers from 1 to the number entered
		static int Utils::sumUp(int number);

		//Destructor:
		~Utils();

};

#endif /* UTILITIES_H */  //end of compiler directive ndef

