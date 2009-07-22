#include "Surface.h"
Surface::Surface( const Vector3f A, const Vector3f B, const Vector3f C )
{
	corners[ 0 ] = A;
	corners[ 1 ] = B;
	corners[ 2 ] = C;
	color = Vector3f( 1.0f, 1.0f, 1.0f );
}
Surface::Surface( const Vector3f A, const Vector3f B, const Vector3f C, const Vector3f rgb )
{
	corners[ 0 ] = A;
	corners[ 1 ] = B;
	corners[ 2 ] = C;
	color = rgb;
}
Surface::Surface( const Surface& surface )
{
	corners[ 0 ] = surface.corners[ 0 ];
	corners[ 1 ] = surface.corners[ 1 ];
	corners[ 2 ] = surface.corners[ 2 ];
	color = surface.getColor();
}
Surface::~Surface()
{
}
Vector3f& Surface::operator[]( const int i )
{
	assert( i >= 0 && i < 3 && "Surface::Operator[] out of bounds assert" );
	return corners[ i ];
}
const Vector3f& Surface::operator []( const int i ) const
{
	assert( i >= 0 && i < 3 && "Surface::Operator[] out of bounds assert" );
	return corners[ i ];
}
const Vector3f& Surface::at( const int i ) const
{
	return operator[]( i );
}
const Vector3f Surface::getColor() const
{
	return color;
}
