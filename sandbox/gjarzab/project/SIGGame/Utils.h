#ifndef UTILITIES_H
#define UTILITIES_H

class Utils
{
	public:
		unsigned int sumUp( const unsigned int upTo );

		Utils(){};		//Define empty constructor
		~Utils(){};		//Define empty destructor

		// Prevent calling with parameters of types other than unsigned int
	private:
		unsigned int sumUp( const int upTo );
		unsigned int sumUp( const float upTo );
		unsigned int sumUp( const double upTo );
};

#endif