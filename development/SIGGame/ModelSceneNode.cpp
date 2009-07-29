#include "ModelSceneNode.h"
ModelSceneNode::ModelSceneNode()
{
}
void ModelSceneNode::render() const
{
	std::vector<Mesh>::const_iterator i;
	for( i=mesh.begin(); i!=mesh.end(); ++i)
	{
		std::vector< std::vector<int> >::const_iterator j;
		for( j=i->begin; i!=i->end(); ++i  )
		{
			std::vector<int>::const_iterator k;
			for( k=i)

			//glBegin(GL_TRIANGLE_FAN);
			//glEnd();

			
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
