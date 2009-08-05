#ifndef Mesh_h
#define Mesh_h
#include "Vector3f.h"
#include <vector>
#include "Material.h"
class Mesh
{
	public:
		Mesh();
		Mesh(const Material material, const std::vector< std::vector<int> > vertexIndex);
		const Material& getMaterial() const;
		const std::vector< std::vector<int> >& getVertexIndex() const;
	private:
		Material material;
		std::vector< std::vector<int> > vertexIndex;
};
#endif
