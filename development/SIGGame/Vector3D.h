#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D
{
public:
	//float* vector;
	float vector[4];

	Vector3D();

	Vector3D(float const x, float const y, float const z);

	Vector3D(const Vector3D& v1);

	~Vector3D()
	{
	}

	void setX(const float x);
	float getX() const;

	void setY(const float y);
	float getY() const;

	void setZ(const float z);
	float getZ() const;
	
	float dotProduct(const Vector3D& v1, const Vector3D& v2) const;		//v1 dot v2
	float dotProduct(const Vector3D& v1) const;							//vector dot v1

	Vector3D crossProduct( const Vector3D& v1,  const Vector3D& v2) const;	//v1 cross v2
	Vector3D crossProduct( const Vector3D& v1) const;						//vector cross v1

	Vector3D operator+(const Vector3D& v1) const;	//vector+v1

	Vector3D operator-(const Vector3D& v1) const;	//vector-v1


	//takes position, velocity, accelaration vectors and the tick (in that order) to returns the new position
	Vector3D translatePosition(const Vector3D& position, const Vector3D& velocity, const Vector3D& accelaration, const float& tick) const;


	//takes  velocity, accelaration vectors and the tick (in that order) to returns the new velocity
	//v1=vel, v2=acc, t=tick
	Vector3D translateVelocity(const Vector3D& velocity, const Vector3D& accelaration, const float& tick) const;	


};

#endif