#ifndef Vertex_h
#define Vertex_h
#include "Vector3f.h"
/**
 * A vertex is a point in space.
 * A vertex is composed of 3 types of grid points:  position, texture, and
 * normal.  A position is a point in 3dspace.  A texture coordinate is an X,Y
 * Cooridinate that should be mapped to texturedata.  A normal vertex should be
 * unit (magnitude 1) from an origin. The normal vector describes which
 * light bounces off a surface.  if the normals that defince a surface are not
 * all in the same direction, the normal is interpolated by OpenGL
 * */
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

