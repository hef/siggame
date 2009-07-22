#ifndef Vector3f_H
#define Vector3f_H
#include <assert.h>
class Vector3f
{
public:
	float elementArray[ 3 ];
	Vector3f();
	Vector3f( const float x, const float y, const float z );
	Vector3f( const Vector3f& vector3f );
	float& operator[]( const int i );
	float operator[]( const int i ) const;
	float at( const int i ) const;
};
#endif
