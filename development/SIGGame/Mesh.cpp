#include "Mesh.h"
Mesh::Mesh() :
	material( Material())
{
}
Mesh::Mesh( const Material& material, const std::vector< std::vector<int> >& vertexIndex ) :
	material( material ),
	vertexIndex( vertexIndex )
{
}
const Material& Mesh::getMaterial() const
{
	return material;
}
const std::vector< std::vector<int> >& Mesh::getVertexIndex() const
{
	return vertexIndex;
}

