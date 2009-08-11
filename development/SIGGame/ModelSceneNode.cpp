#include "ModelSceneNode.h"
#include <iostream>
ModelSceneNode::ModelSceneNode()
{
}
ModelSceneNode::ModelSceneNode( const std::vector<Vertex>& vertexVector, const std::vector<Mesh>& meshVector ) :
	vertex( vertexVector ),
	mesh( meshVector )
{
}
void ModelSceneNode::render() const
{
	std::vector<Mesh>::const_iterator i;
	for ( i = mesh.begin(); i != mesh.end(); ++i )
	{
		/*
		   std::cout << "ambient: ";
		   std::cout << i->getMaterial().getAmbientColor().elementArray[0] << " ";
		   std::cout << i->getMaterial().getAmbientColor().elementArray[1] << " ";
		   std::cout << i->getMaterial().getAmbientColor().elementArray[2] << std::endl;
		   std::cout << "diffuse: ";
		   std::cout << i->getMaterial().getDiffuseColor().elementArray[0] << " ";
		   std::cout << i->getMaterial().getDiffuseColor().elementArray[1] << " ";
		   std::cout << i->getMaterial().getDiffuseColor().elementArray[2] << std::endl;
		   std::cout << "specular: ";
		   std::cout << i->getMaterial().getSpecularColor().elementArray[0] << " ";
		   std::cout << i->getMaterial().getSpecularColor().elementArray[1] << " ";
		   std::cout << i->getMaterial().getSpecularColor().elementArray[2] << std::endl;
		   std::cout << "shininess: ";
		   std::cout << i->getMaterial().getShininess() << std::endl;
		 */
		glMaterialfv( GL_FRONT, GL_AMBIENT, i->getMaterial().getAmbientColor().elementArray );
		glMaterialfv( GL_FRONT, GL_DIFFUSE, i->getMaterial().getDiffuseColor().elementArray );
		glMaterialfv( GL_FRONT, GL_SPECULAR, i->getMaterial().getSpecularColor().elementArray );
		glMaterialf( GL_FRONT, GL_SHININESS, i->getMaterial().getShininess());

		std::vector< std::vector<int> >::const_iterator j;
		for ( j = i->getVertexIndex().begin(); j != i->getVertexIndex().end(); ++j )
		{
			glBegin( GL_TRIANGLE_FAN );
			std::vector<int>::const_iterator k;
			for ( k = j->begin(); k != j->end(); ++k )
			{
				/*
				   std::cout << "position: ";
				   std::cout << vertex[(*k)].getPosition().elementArray[0] <<  " ";
				   std::cout << vertex[(*k)].getPosition().elementArray[1] <<  " ";
				   std::cout << vertex[(*k)].getPosition().elementArray[2] <<  std::endl;
				   std::cout << "texture: ";
				   std::cout << vertex[(*k)].getTexture().elementArray[0] <<  " ";
				   std::cout << vertex[(*k)].getTexture().elementArray[1] <<  std::endl;
				   std::cout << "normal: ";
				   std::cout << vertex[(*k)].getNormal().elementArray[0] <<  " ";
				   std::cout << vertex[(*k)].getNormal().elementArray[1] <<  " ";
				   std::cout << vertex[(*k)].getNormal().elementArray[2] <<  std::endl;
				 */
				glNormal3fv( vertex[(*k)].getNormal().elementArray );
				glTexCoord2fv( vertex[(*k)].getTexture().elementArray );
				glVertex3fv( vertex[(*k)].getPosition().elementArray );
				//std::cout << "-----------------" << std::endl;
			}
			glEnd();
			//std::cout << "=================" << std::endl;
		}
	}
}
//TODO make this more efficient, also name it better
const std::vector<Vector3f> ModelSceneNode::getVertex() const
{
	std::vector<Vector3f> positionVertexVector;
	std::vector<Vertex>::const_iterator i;
	for ( i = vertex.begin(); i != vertex.end(); ++i )
	{
		positionVertexVector.push_back( i->getPosition() );
	}
	return positionVertexVector;
}

