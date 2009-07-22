/*--------------------------------------------------------------------------*

// Implementation of class Utils
/* filename: Utils.cpp			*/

//included files
#include <iostream>
#include "Utils.h"

//only if the class is declared in a separate file
using std::cout;
using std::endl;
using std::cerr;


		//Default constructor:
		Utils::Utils(): digit(8), digitPub(9)
		{
		}

		//parameterized constructor:
		Utils::Utils(int initDigit): digit(initDigit), digitPub(9)
		{
		}

		//accessor methods
		int Utils::getDigit() const
		{
			return digit;
		}

		int Utils::getDigitPub() const
		{
			return digitPub;
		}

		//mutator methods
		void Utils::set(int newDigit)
		{
			digit = newDigit;
		}
		
		//static method that sums up numbers from 1 to the number entered
		int Utils::sumUp(int number) 
		{
			int sum = 0;
			if (number < 0)
			{
				cerr<<"Negative argument out of bounds"<<endl;
				return -1;
			}
			for (number; number > 0; number--)
			{
				sum += number;
			}
			return sum;
		}

		//Destructor:
		Utils::~Utils()
		{

		}

/*---------------------------------------------------------------------------*/