#ifndef SURFACE_H
#define SURFACE_H
#include "Vector3f.h"
#include <assert.h>
/**
  A Surface is a triangle in 3d space.
  non-triangles are composed of triangles.
  this class should contain all properties that the renderer needs to apply to a triangle
  */
class Surface
{
	private:
		Vector3f corners[3];
	public:
		Surface(const Vector3f A, const Vector3f B, const Vector3f C);
		Surface(const Surface& surface);
		~Surface();
		Vector3f& operator[](const int i);

};
#endif
