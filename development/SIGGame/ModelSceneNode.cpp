#include "ModelSceneNode.h"
ModelSceneNode::ModelSceneNode()
{
}
void ModelSceneNode::render() const
{
}
ModelSceneNode::Mesh::Mesh(Vector3f const color, std::vector< std::vector<int> > vertexIndex) :
	color(color),
	vertexIndex(vertexIndex)
{
}
