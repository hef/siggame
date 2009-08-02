#ifndef ModelSceneNode_h
#define ModelSceneNode_h
#include "SceneNode.h"
#include <vector>
#include "Vector3f.h"
class ModelSceneNode : public SceneNode
{
	private:
		struct Mesh;
		struct Vertex;
		std::vector<Vertex> vertex;
		std::vector<Mesh> mesh;
	public:
		ModelSceneNode();
		//ModelSceneNode(std::vector<Vector3f> vertices);
		void render() const;
		/// returns a position vertex vector
		const std::vector<Vector3f> getVertex() const;
	private:
	struct Vertex
	{
		public:
			Vector3f position;
			Vector3f texture;
			Vector3f normal;
	};
	struct Mesh
	{
		public:
			Vector3f ambientColor; // ka
			Vector3f diffuseColor;// kd
			Vector3f specularColor;// ks
			float shininess;  //ns
			std::vector< std::vector<int> > vertexIndex;
	};
};
#endif
