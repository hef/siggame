#ifndef Vertex.h
#define Vertex.h
#include "Vector3f.h"
class Vertex
{
	public:
		Vertex(const Vector3f position, const Vector3f texture, const Vector3f normal);
	private:
		Vector3f position;
		Vector3f texture;
		Vector3f normal;
};
#endif
