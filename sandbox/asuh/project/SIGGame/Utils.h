//Andrew Suh
//May 28, 2009

// #ifndef is a header guard that prevents errors from including 
// the same header multiple times

// Note: Utils is short for Utilities
#ifndef UTILS_H
#define UTILS_H

class Utils
{
public:
	Utils()
	{
		//Constructor
	}

	~Utils()
	{
		//Destructor
	}

	int sumUp(int x)
	{
		// http://www.curiousmath.com/index.php?name=News&file=article&sid=23
		return ( ( ( x * x ) + x ) / 2 );
	}
};

#endif //UTILS_H