#ifndef UTILS_H
#define UTILS_H

class Utils
{
	public:
		Utils() { }		// Default Constructor
		~Utils() { }	// Destructor
		
		// Calculates sum from 1 to nTop
		int sumUp( int nTop )
		{
			int nResult = 0;
			// Code enters for loop if nTop >= 1,
			// otherwise nResult = 0 is returned
			for( int i = 1; i <= nTop; ++i )
			{
				nResult += i;
			}
			return nResult;
		}
};

#endif
