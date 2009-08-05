#ifndef ModelSceneNode_h
#define ModelSceneNode_h
#include "SceneNode.h"
#include <vector>
#include "Vector3f.h"
#include "Vertex.h"
#include "Mesh.h"
#include "Material.h"
class ModelSceneNode : public SceneNode
{
	private:
		std::vector<Vertex> vertex;
		std::vector<Mesh> mesh;
	public:
		ModelSceneNode();
		//ModelSceneNode(std::vector<Vector3f> vertices);
		void render() const;
		/// returns a position vertex vector
		const std::vector<Vector3f> getVertex() const;
};
#endif
