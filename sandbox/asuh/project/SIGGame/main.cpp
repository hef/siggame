//Andrew Suh
//May 28, 2009

//Method 1: Using the "using" keyword
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
//End Method 1

#include <conio.h>
#include <stdio.h>
#include "Utils.h"

int main()
{
	Utils uForStack;
	Utils* uForHeap = new Utils;	// http://www.java2s.com/Tutorial/Cpp/0180__Class/Creatingobjectsontheheapusingnew.htm

	// 1+2+3+4+5 = 15
	// 1+2+3+4+5+6 = 21
	cout << uForStack.sumUp( 5 ) << endl;
	cout << uForHeap->sumUp( 6 ) << endl;	// http://www.java2s.com/Tutorial/Cpp/0180__Class/Accessingmembersofobjectsontheheap.htm

	// Should this function accomodate for decimals/negatives?
	// 4+3+2+1 = 10.  Decimals are cut off.
	// 8+7+6+5+4+3+2+1 = 36.  (signed)(-9) = 0111 = (unsigned)(+7) so I dunno.
	cout << uForStack.sumUp( 4.3 ) << endl;
	cout << uForHeap->sumUp( -9 ) << endl;

	_getch();

	delete uForHeap;	// http://msdn.microsoft.com/en-us/library/h6227113(VS.80).aspx
	return 0;
}