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
	Utils() {}

	~Utils() {}

	unsigned int sumUp( const unsigned int x );

private:
	// prevents types other than unsigned int from being called
	double sumUp( double d );
	float sumUp( float f);
	int sumUp( int i );
};

#endif //UTILS_H