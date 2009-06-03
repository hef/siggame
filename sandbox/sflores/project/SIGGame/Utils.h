#ifndef UTILS_H
#define UTILS_H

class Utils
{
	public:
		Utils() { }		// Default Constructor
		~Utils() { }	// Destructor
		unsigned int sumUp( unsigned int n );
	private:
		unsigned int sumUp( short n );
		unsigned int sumUp( int n );
		unsigned int sumUp( long n );
		unsigned int sumUp( long long n );
		unsigned int sumUp( float n );
		unsigned int sumUp( double n );
};

#endif
