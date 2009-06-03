#ifndef UTILITIES_H 
#define UTILITIES_H

class Utils
{
private:

public:
	Utils(){}
	~Utils(){}

	int sumUp(int numberToSum)
	{
		int finalNumber = 0;
		for( int i = 0; i <= numberToSum; ++i )
		{
			finalNumber += i;
		}
		return finalNumber;
	}
};

#endif /* UTILITIES_H */