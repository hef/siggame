#ifndef Vertex_h
#define Vertex_h
#include "Vector3f.h"
class Vertex
{
	public:
		Vertex(const Vector3f position, const Vector3f texture, const Vector3f normal);
		const Vector3f& getPosition() const;
		const Vector3f& getTexture() const;
		const Vector3f& getNormal() const;
	private:
		Vector3f position;
		Vector3f texture;
		Vector3f normal;
};
#endif

