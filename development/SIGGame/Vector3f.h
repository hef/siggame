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

	Vector3f operator+( const Vector3f& v1 ) const;
	Vector3f operator-( const Vector3f& v1 ) const;

	float dotProduct( const Vector3f& v1, const Vector3f& v2 ) const;
	float dotProduct( const Vector3f& v1 ) const;

	void scale( Vector3f& v1, const float scalar );
	void scale( const float scalar );


	Vector3f crossProduct( const Vector3f& v1, const Vector3f& v2 ) const;
	Vector3f crossProduct( const Vector3f& v1 ) const;

	Vector3f translatePosition( const Vector3f& position, const Vector3f& velocity, const Vector3f& accelaration, const float& tick ) const;
	Vector3f translateVelocity( const Vector3f& velocity, const Vector3f& accelaration, const float& tick ) const;
};
#endif
