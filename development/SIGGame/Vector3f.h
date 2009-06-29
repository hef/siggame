#ifndef Vector3f_H
#define Vector3f_H
#include <assert.h>
class Vector3f
{
	private:
	public:
		union
		{
			float elementArray[3];
			struct
			{
				float x;
				float y;
				float z;
			};
		};
		Vector3f();
		Vector3f( const float x, const float y, const float z );
		Vector3f( const  Vector3f& vector3f );
		float operator[](const int i);

};
#endif
