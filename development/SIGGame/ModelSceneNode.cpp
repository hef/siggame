#include "ModelSceneNode.h"
ModelSceneNode::ModelSceneNode()
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
				glNormal3fv(vertex[(*k)].normal.elementArray );
				glTexCoord2fv(vertex[(*k)].texture.elementArray );
				glVertex3fv( vertex[(*k)].position.elementArray );
			}
			glEnd();
		}
	}
}
//TODO make this more efficient, also name it better
const std::vector<Vector3f> ModelSceneNode::getVertex() const
{
	std::vector<Vector3f> positionVertexVector;
	std::vector<Vertex>::const_iterator i;
	for(i=vertex.begin(); i!=vertex.end(); ++i)
	{
		positionVertexVector.push_back( i->position );
	}
	return positionVertexVector;
}
