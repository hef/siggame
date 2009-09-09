#ifndef UTILS_H
#define UTILS_H

#include <iostream>

using namespace std;

class Utils //Sample Class for the C++ Tutorial 
   {
         public: 
         Utils() //Constructor for the C++ tutorial 
         { 
             cout<< "Constructor" << endl;
         }
       ~Utils() //destructor for the C++ Tutorial 
       { cout<< "Constructor" << endl; } 

	   int sumUp(int n)
	   {
		   int sum=0;
		   for(int i=1;i<=n;i++)
			   sum = sum+i;
		   return sum;
	   }
      
}; 

#endif
