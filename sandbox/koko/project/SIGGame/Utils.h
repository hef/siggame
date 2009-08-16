//Utils.h
#ifndef UTILS_H
#define UTILS_H

class Utils
{
	public:
		Utils();

		~Utils();

	unsigned int sumUp( unsigned int n );

	private:
		int sumUp( int n );
		int sumUp( float n );
		int sumUp( double n );
		int sumUp( long n );
};

#endif //UTILS_H