#include "Quad.h"

Quad::Quad()
{
	for( int i=0;i<4;i++ )
		addPoint( i, 0, 0, 0 );
}

void Quad::addPoint( unsigned int drawOrder, float x1, float x2, float x3 )
{
	assert( drawOrder<5 );
	point[drawOrder][0] = x1;
	point[drawOrder][1] = x2;
	point[drawOrder][2] = x3;
}

const float* Quad::getPoint( unsigned int drawOrder ) const
{
	assert( drawOrder<5 );
	return point[drawOrder];
}

const float* Quad::getColor() const
{
	return color;
}

void Quad::setColor(float r, float g, float b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
}