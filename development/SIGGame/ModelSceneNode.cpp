#include "ModelSceneNode.h"
ModelSceneNode::ModelSceneNode()
{
}
void ModelSceneNode::render() const
{
}
void ModelSceneNode::addMesh(Vector3f newColor, std::vector<std::vector<int> > newMesh)
{
	mesh.push_back(Mesh(newColor, newMesh));
}
ModelSceneNode::Mesh::Mesh(Vector3f const color, std::vector< std::vector<int> > vertexIndex) :
	color(color),
	vertexIndex(vertexIndex)
{
}
