#include "Vector3D.h"

float Vector3D::dotProduct( float *v1, float *v2 )
{
	float result=0.0f;
	for( int dimensions=3; dimensions; --dimensions )
	{
		result += (*(v1++) * *(v2++));
	}
	return result;
};

float* Vector3D::crossProduct( float *v1, float *v2 )
{

	float* result = new float[4];

	for( int i=0; i!=3; ++i )
	{
		result[i] = ((*(v1+(i+1)%3)) * (*(v2+(i+2)%3))) - ((*(v1+(i+2)%3)) * (*(v2+(i+1)%3)));
	}
	return result;
};

float* Vector3D::add( float *v1, float *v2 )
{
	float* result = new float[4];

	for( int dimensions=0; dimensions!=3; ++dimensions )
	{
		result[dimensions] = (*(v1++) + *(v2++));
	}
	return result;
};

float* Vector3D::subtract( float *v1, float *v2 )
{
	float* result = new float[4];

	for( int dimensions=0; dimensions!=3; ++dimensions )
	{
		result[dimensions] = (*(v1++) - *(v2++));
	}
	return result;
};

float* Vector3D::translatePosition( float *v1, float *v2, float *v3, float t )
{       //X = Xini + Vini*t + 1/2*Acc*(t^2)
	float* result = new float[4];

	for( int i=0; i!=3; ++i )
	{
		result[i] = *(v1+i) + (*(v2+i))*t + (0.5f)*(*(v3+i))*(t*t);
	}

	return result;
};

float* Vector3D::translateVelocity( float *v1, float *v2, float t )
{       //V = Vini + Acc*t
	float* result = new float[4];

	for( int i=0; i!=3; ++i )
	{
		result[i] = *(v1+i) + (*(v2+i))*t;
	}

	return result;
};