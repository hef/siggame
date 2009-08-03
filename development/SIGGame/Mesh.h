#ifndef Mesh.h
#define Mesh.h
#include "Vector3f.h"
#include "Vertex.h"
class Mesh
{
	public:
		Mesh()
		Mesh(const Vector3f ambientColor, const Vector3f diffuseColor; const specularColor, float shininess, const std::vector< std::vector<int> > vertexIndex)
	private:
		Vector3f ambientColor;
		Vector3f diffuseColor;
		Vector3f specularColor;
		float shininess;
		std::vector< std::vector<int> > vertexIndex;
};
#endif
