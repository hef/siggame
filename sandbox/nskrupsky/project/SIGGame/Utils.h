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
		unsigned int sumUp( const unsigned int );
	private:
		// overloaded and defined private to prevent calls to sumUp with doubles and floats as arguments
		unsigned int sumUp( const int );
		unsigned int sumUp( const double );
		unsigned int sumUp( const float );
};

#endif
