#ifndef __UTILITIES_H
#define __UTILITIES_H

class Utilities
{
	public:
		Utilities()
		{
			// constructor
		}
		Utilities( const Utilities& rParm )
		{
			// copy constructor
		}
		virtual ~Utilities()
		{
			// destructor
		}
		const Utilities& operator= ( const Utilities& rParm )
		{
			if( this != &rParm )
			{
				// copy
			}
			return *this;
		}
};

#endif
