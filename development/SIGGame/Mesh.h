#ifndef Mesh_h
#define Mesh_h
#include "Vector3f.h"
#include <vector>
class Mesh
{
	public:
		Mesh();
		Mesh(const Vector3f ambientColor, const Vector3f diffuseColor, const Vector3f specularColor, const float shininess, const std::vector< std::vector<int> > vertexIndex);
		Mesh(const std::vector< std::vector<int> > vertexIndex);
		const Vector3f& getAmbientColor() const;
		const Vector3f& getDiffuseColor() const;
		const Vector3f& getSpecularColor() const;
		const float&  getShininess() const;
		const std::vector< std::vector<int> >& getVertexIndex() const;
	private:
		Vector3f ambientColor;
		Vector3f diffuseColor;
		Vector3f specularColor;
		float shininess;
		std::vector< std::vector<int> > vertexIndex;
};
#endif
