#include "Vector3f.h"
#include <math.h>
#include <iostream>
Vector3f::Vector3f()
{
	elementArray[ 0 ] = 0;
	elementArray[ 1 ] = 1;
	elementArray[ 2 ] = 2;

}
Vector3f::Vector3f( const float x, const float y, const float z )
{
	elementArray[ 0 ] = x;
	elementArray[ 1 ] = y;
	elementArray[ 2 ] = z;
}
Vector3f::Vector3f( const Vector3f& vector3f )
{
	elementArray[ 0 ] = vector3f.elementArray[ 0 ];
	elementArray[ 1 ] = vector3f.elementArray[ 1 ];
	elementArray[ 2 ] = vector3f.elementArray[ 2 ];
}
float& Vector3f::operator[]( const int i )
{
	assert( i >= 0 && i < 3 && "Vector3f::Operator[] out of bounds assert" );
	return elementArray[ i ];
}
float Vector3f::operator []( const int i ) const
{
	assert( i >= 0 && i < 3 && "Vector3f::Operator[] out of bounds assert" );
	return elementArray[ i ];
}
float Vector3f::at( const int i ) const
{
	return operator[]( i );
}

Vector3f Vector3f::operator +( const Vector3f& v1 ) const
{
	Vector3f result;
	for( int dimensions = 0; dimensions != 3; ++dimensions )
	{
		result.elementArray[ dimensions ] = this->elementArray[ dimensions ] + v1.elementArray[ dimensions ];
	}
	return result;
}

Vector3f Vector3f::operator -( const Vector3f& v1 ) const
{
	Vector3f result;
	for( int dimensions = 0; dimensions != 3; ++dimensions )
	{
		result.elementArray[ dimensions ] = this->elementArray[ dimensions ] - v1.elementArray[ dimensions ];
	}
	return result;
}

float Vector3f::dotProduct( const Vector3f& v1, const Vector3f& v2 ) const
{
	float result = 0.0f;
	for( int dimensions = 0; dimensions != 3; ++dimensions )
	{
		result += ( ( v1.elementArray[ dimensions ] ) * ( v2.elementArray[ dimensions ] ) );
	}
	return result;
}

float Vector3f::dotProduct( const Vector3f& v1 ) const
{
	return dotProduct( *this, v1 );
}

Vector3f Vector3f::crossProduct( const Vector3f& v1, const Vector3f& v2 ) const
{
	Vector3f result;
	for( int i = 0; i != 3; ++i )
	{
		result.elementArray[ i ] = ( v1.elementArray[ (i+1)%3 ] * v2.elementArray[ (i+2)%3 ] ) - ( v1.elementArray[ (i+2)%3 ] * v2.elementArray[ (i+1)%3 ] );
	}
	return result;
}

Vector3f Vector3f::crossProduct( const Vector3f& v1 ) const
{
	return crossProduct( *this, v1 );
}

Vector3f Vector3f::translatePosition( const Vector3f& position, const Vector3f& velocity, const Vector3f& accelaration, const float& tick ) const
{	
	//X = Xini + Vini*t + 1/2*Acc*(t^2)
	Vector3f result;
	for( int i = 0; i != 3; ++i)
	{
		result.elementArray[ i ] = position.elementArray[ i ] + ( velocity.elementArray[ i ] ) * tick + ( 0.5f ) * ( accelaration.elementArray[i] ) * ( tick * tick );
	}
	return result;
}

Vector3f Vector3f::translateVelocity( const Vector3f& velocity, const Vector3f& accelaration, const float& tick ) const
{	
	//V = Vini + Acc*t
	Vector3f result;
	for( int i = 0; i != 3; ++i )
	{
		result.elementArray[ i ] = velocity.elementArray[ i ] + ( accelaration.elementArray[ i ] ) * tick;
	}
	return result;
}


void Vector3f::scale( Vector3f& v1, const float scalar )
{
	float mag = 0.0f;
	for( int i = 0; i != 3; ++i )
	{
		mag += ( v1.elementArray[ i ] * v1.elementArray[ i ] );
	}

	mag = sqrt( mag );

	if( mag == 0 )
	{
		std::cout<<"The vector passed in is broken.";
	}

	for( int i = 0; i != 3; ++i )
	{
		v1[ i ] = ( v1[ i ] / mag );	//makes it a unit vector
	}

	for( int i = 0; i != 3; ++i )
	{
		v1[ i ] = ( v1[ i ] * scalar );		//scales the unit vector
	}
	
	return;
}

void Vector3f::scale( const float scalar )
{
	return scale( *this, scalar );
}
