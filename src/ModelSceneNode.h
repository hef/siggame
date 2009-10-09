#ifndef ModelSceneNode_h
#define ModelSceneNode_h
#include "SceneNode.h"
#include <vector>
#include "Vector3f.h"
#include "Vertex.h"
#include "Mesh.h"
#include "Material.h"
/**
 * ModelSceneNode contains all the information neccesary to draw a model
 * ModelSceneNode should be considered render code.  Its most important function
 * is render().
 * */
class ModelSceneNode : public SceneNode
{
private:
	///The big list of vertices that mesh's will refer to by index
	std::vector<Vertex> vertex;
	///Meshs.  each mesh has a material to decied how the vertices in the mesh will be drawn
	std::vector<Mesh> mesh;
public:
	ModelSceneNode();
	ModelSceneNode( const std::vector<Vertex>& vertexVector, const std::vector<Mesh>& meshVector );
	void render() const;
	/// returns a position vertex vector
	const std::vector<Vector3f> getVertex() const;
};
#endif

