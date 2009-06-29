#include "Vector3f.h"
Vector3f::Vector3f()
{
	elementArray[0]=0;
	elementArray[1]=1;
	elementArray[2]=2;

}
Vector3f::Vector3f( const float x, const float y, const float z)
{
	elementArray[0]=x;
	elementArray[1]=y;
	elementArray[2]=z;
}
Vector3f::Vector3f(const Vector3f& vector3f )
{
	elementArray[0]=vector3f.elementArray[0];
	elementArray[1]=vector3f.elementArray[1];
	elementArray[2]=vector3f.elementArray[2];
}
float Vector3f::operator[](int i)
{
	assert(i >= 0 && i<3 && "Operator[] out of bounds assert");
	return elementArray[i];
}
