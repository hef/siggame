#include "ModelSceneNode.h"
ModelSceneNode::ModelSceneNode()
{
}
ModelSceneNode::ModelSceneNode(std::vector<Vector3f> vertices) :
	vertex(vertices)
{
}
void ModelSceneNode::render() const
{
	std::vector<Mesh>::const_iterator i;
	for( i=mesh.begin(); i!=mesh.end(); ++i)
	{
		glColor3fv(i->color.elementArray);
		std::vector< std::vector<int> >::const_iterator j;
		for( j=i->vertexIndex.begin(); j!=i->vertexIndex.end(); ++j  )
		{
			glBegin(GL_TRIANGLE_FAN);
			std::vector<int>::const_iterator k;
			for( k=j->begin(); k!=j->end(); ++k)
			{
				glVertex3fv( vertex[(*k)].elementArray );
			}
			glEnd();
		}
	}
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
const std::vector<Vector3f>& ModelSceneNode::getVertex() const
{
	return vertex;
}
