#include "ModelSceneNode.cpp"
ModelSceneNode::ModelSceneNode()
{
}
void ModelSceneNode::Render() const
{
}
ModelSceneNode::Mesh::Mesh(Vector3f const color, Vector< Vector<int> > vertexIndex) :
	color(color),
	vertexIndex(vertexIndex)
{
}
