#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D
{
public:
	Vector3D()
	{
		//nothing
	}

	~Vector3D()
	{
		//nothing
	}
	
	float dotProduct(float *v1, float *v2);

	float* crossProduct(float *v1, float *v2);

	float* add(float *v1, float *v3);

	float* subtract(float *v1, float *v3);	//v1-v2
	
	//takes position, velocity, accelaration vectors and the tick (in that order) to returns the new position
	//v1=pos, v2=vel, v3=acc, t=tick
	float* translatePosition(float *v1, float *v2, float *v3, float t);

	//takes  velocity, accelaration vectors and the tick (in that order) to returns the new velocity
	//v1=vel, v2=acc, t=tick
	float* translateVelocity(float *v1, float *v2, float t);	
};

#endif