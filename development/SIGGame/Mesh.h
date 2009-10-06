#ifndef Mesh_h
#define Mesh_h
#include "Vector3f.h"
#include <vector>
#include "Material.h"
/**
 * A Mesh is a Material and a collection of vertices.
 * A mesh really only makes sense if it is used in a modelSceneNode
 */
class Mesh
{
public:
	Mesh();
	Mesh( const Material& material, const std::vector< std::vector<int> >& vertexIndex );
	/**
	 * The material that is used for all vertexs contained within.
	 */
	const Material& getMaterial() const;
	/**
	 * index of the vertices contained in the parent modelSceneNode that
	* contains this object
	*/
	const std::vector< std::vector<int> >& getVertexIndex() const;
private:
	Material material;
	std::vector< std::vector<int> > vertexIndex;
};
#endif

