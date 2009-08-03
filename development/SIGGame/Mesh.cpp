#include "Mesh.h"
Mesh::Mesh() : 
	ambientColor(Vector3f(0.2f,0.2f,0.2f)),
	diffuseColor(Vector3f(0.8f,0.8f,0.8f)),
	specularColor(Vector3f(1.0f,1.0f,1.0f)),
	shininess(0.0f)
{
}
Mesh::Mesh(const std::vector< std::vector<int> > vertexIndex) :
	ambientColor(Vector3f(0.2f,0.2f,0.2f)),
	diffuseColor(Vector3f(0.8f,0.8f,0.8f)),
	specularColor(Vector3f(1.0f,1.0f,1.0f)),
	shininess(0.0f),
	vertexIndex(vertexIndex)
{
}
Mesh::Mesh(const Vector3f ambientColor, const Vector3f diffuseColor, const Vector3f specularColor, const float shininess, const std::vector< std::vector<int> > vertexIndex) :
	ambientColor(ambientColor),
	diffuseColor(diffuseColor),
	specularColor(specularColor),
	shininess(shininess),
	vertexIndex(vertexIndex)
{
}
const Vector3f& Mesh::getAmbientColor() const
{
	return ambientColor;
}
const Vector3f& Mesh::getDiffuseColor() const
{
	return diffuseColor;
}
const Vector3f& Mesh::getSpecularColor() const
{
	return specularColor;
}
const float& Mesh::getShininess() const
{
    return shininess;
}
const std::vector< std::vector<int> >& Mesh::getVertexIndex() const
{
    return vertexIndex;
}
