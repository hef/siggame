#ifndef QUAD_H
#define QUAD_H

#include <assert.h>

class Quad
{
private:
	float point[4][3];
	float color[3];

public:
	Quad();

	void addPoint( unsigned int drawOrder, float x1, float x2, float x3 );
	const float* getPoint( unsigned int drawOrder ) const;
	const float* getColor() const;
	void setColor(float r, float g, float b);
};

#endif