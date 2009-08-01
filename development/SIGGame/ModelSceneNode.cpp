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
		//glColor3fv(i->color.elementArray);
		glMaterialfv(GL_FRONT, GL_AMBIENT, i->ambientColor.elementArray);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, i->diffuseColor.elementArray);
		glMaterialfv(GL_FRONT, GL_SPECULAR, i->specularColor.elementArray);
		glMaterialf(GL_FRONT, GL_SHININESS, i->shininess);

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
void ModelSceneNode::addMesh(std::vector<std::vector<int> > newMesh)
{
	mesh.push_back(Mesh(newMesh));
}
ModelSceneNode::Mesh::Mesh(std::vector< std::vector<int> > vertexIndex) :
	vertexIndex(vertexIndex)
{
}
const std::vector<Vector3f>& ModelSceneNode::getVertex() const
{
	return vertex;
}
