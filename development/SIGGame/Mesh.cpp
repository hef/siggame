#include "Mesh.h"
Mesh::Mesh() : 
	ambientColor(Vector3f(0.2f,0.2f,0.2f)),
	diffuseColor(Vector3f(0.8f,0.8f,0.8f)),
	specularColor(Vector3f(1.0f,1.0f,1.0f)),
	shininess(0.0f)
{
}
Mesh::Mesh(const std::vector< std:vector<int> > vertexIndex) :
	Mesh(),
	vertexIndex(vertexIndex)
{
}
Mesh::Mesh(const Vector3f ambientColor, const Vector3f diffuseColor; const specularColor, float shininess, const std::vector< std::vector<int> > vertexIndex) :
	ambientColor(ambientColor),
	diffuseColor(diffuseColor),
	specularColor(specularColor),
	shininess(shininess),
	vertexIndex(vertexIndex)
{
}
