#include "Vector3D.h"

Vector3D::Vector3D()
{
	for(int i=0; i!=3; ++i)
	{
		vector[i] = 0;
	}
}

Vector3D::Vector3D(float const x, float const y, float const z)
{
	vector[0] = x;

	vector[1] = y;

	vector[2] = z;
};

Vector3D::Vector3D(const Vector3D& v1)
{
	for(int i=0; i!=3; ++i)
	{
		vector[i] = v1.vector[i];
	}
}





void Vector3D::setX(const float x)
{
	vector[0] = x;
};

float Vector3D::getX() const
{
	return vector[0];
};






void Vector3D::setY(const float y)
{
	vector[1] = y;
};

float Vector3D::getY() const
{
	return vector[1];
};





void Vector3D::setZ(const float z)
{
	vector[2] = z;
};

float Vector3D::getZ() const
{
	return vector[2];
};






float Vector3D::dotProduct(const Vector3D& v1, const Vector3D& v2) const
{
	float result = 0.0f;
	for(int dimensions=0; dimensions!=3; ++dimensions)
	{
		result += ((v1.vector[dimensions]) * (v2.vector[dimensions]));
	}
	return result;
};

float Vector3D::dotProduct(const Vector3D& v1) const
{
	return dotProduct(*this, v1);
};





Vector3D Vector3D::crossProduct(const Vector3D& v1, const Vector3D& v2) const
{

	Vector3D result;

	for(int i=0; i!=3; ++i)
	{
		result.vector[i] = (v1.vector[(i+1)%3] * v2.vector[(i+2)%3]) - (v1.vector[(i+2)%3] * v2.vector[(i+1)%3]);
	}
	return result;
};

Vector3D Vector3D::crossProduct(const Vector3D& v1) const
{
	return crossProduct(*this, v1);
};






Vector3D Vector3D::operator+(const Vector3D& v1) const
{
	Vector3D result;

	for(int dimensions=0; dimensions!=3; ++dimensions)
	{
		result.vector[dimensions] = this->vector[dimensions] + v1.vector[dimensions];
	}
	return result;
};





Vector3D Vector3D::operator-(const Vector3D& v1) const
{
	Vector3D result;

	for(int dimensions=0; dimensions!=3; ++dimensions)
	{
		result.vector[dimensions] = this->vector[dimensions] - v1.vector[dimensions];
	}
	return result;
};






Vector3D Vector3D::translatePosition(const Vector3D& position, const Vector3D& velocity, const Vector3D& accelaration, const float& tick) const
{	
	//X = Xini + Vini*t + 1/2*Acc*(t^2)
	Vector3D result;

	for(int i=0; i!=3; ++i)
	{
		result.vector[i] = position.vector[i] + (velocity.vector[i])*tick + (0.5f)*(accelaration.vector[i])*(tick*tick);
	}

	return result;
};





Vector3D Vector3D::translateVelocity(const Vector3D& velocity, const Vector3D& accelaration, const float& tick) const
{	
	//V = Vini + Acc*t
	Vector3D result;

	for(int i=0; i!=3; ++i)
	{
		result.vector[i] = velocity.vector[i] + (accelaration.vector[i])*tick;
	}

	return result;
};