#ifndef UTILITIES_H 
#define UTILITIES_H

class Utils
{
public:
	Utils(){}
	~Utils(){}
	unsigned int sumUp( const unsigned int numberToSum );

private:
	// using interceptors to prevent implicit conversions
	// http://www.devx.com/cplus/10MinuteSolution/37078/0/page/4
	unsigned int sumUp( const int numberToSum );
	unsigned int sumUp( const bool numberToSum );
	unsigned int sumUp( const float numberToSum );
	unsigned int sumUp( const short numberToSum );
};

#endif /* UTILITIES_H */