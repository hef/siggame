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
		glMaterialfv(GL_FRONT, GL_AMBIENT, i->getAmbientColor().elementArray);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, i->getDiffuseColor().elementArray);
		glMaterialfv(GL_FRONT, GL_SPECULAR, i->getSpecularColor().elementArray);
		glMaterialf(GL_FRONT, GL_SHININESS, i->getShininess());

		std::vector< std::vector<int> >::const_iterator j;
		for( j=i->getVertexIndex().begin(); j!=i->getVertexIndex().end(); ++j  )
		{
			glBegin(GL_TRIANGLE_FAN);
			std::vector<int>::const_iterator k;
			for( k=j->begin(); k!=j->end(); ++k)
			{
				glNormal3fv(vertex[(*k)].getNormal().elementArray );
				glTexCoord2fv(vertex[(*k)].getTexture().elementArray );
				glVertex3fv( vertex[(*k)].getPosition().elementArray );
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
		positionVertexVector.push_back( i->getPosition() );
	}
	return positionVertexVector;
}
