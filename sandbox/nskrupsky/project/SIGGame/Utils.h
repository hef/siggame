#ifndef __UTILS_H
#define __UTILS_H

class Utils
{
	public:
		Utils()
		{
			// constructor
		}
		Utils( const Utils& rParm )
		{
			// copy constructor
		}
		virtual ~Utils()
		{
			// destructor
		}
		const Utils& operator= ( const Utils& rParm )
		{
			if( this != &rParm )
			{
				// copy
			}
			return *this;
		}
};

#endif
