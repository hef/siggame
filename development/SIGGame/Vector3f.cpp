#include "Vector3f.h"
Vector3f::Vector3f() :
	x(0),
	y(0),
	z(0)
{
}
Vector3f::Vector3f( const float x, const float y, const float z) :
	x(x),
	y(y),
	z(z)
{
}
Vector3f::Vector3f(const Vector3f& vector3f ) :
	x(vector3f.x),
	y(vector3f.y),
	z(vector3f.z)
{
}
float Vector3f::operator[](int i)
{
	assert(i >= 0 && i<3 && "Operator[] out of bounds assert");
	return elementArray[i];
}
