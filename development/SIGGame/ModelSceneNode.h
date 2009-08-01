#ifndef ModelSceneNode_h
#define ModelSceneNode_h
#include "SceneNode.h"
#include <vector>
#include "Vector3f.h"
class ModelSceneNode : public SceneNode
{
	private:
	class Mesh;
		std::vector<Vector3f> vertex;
		std::vector<Mesh> mesh;
	public:
		ModelSceneNode();
		ModelSceneNode(std::vector<Vector3f> vertices);
		void render() const;
		void addMesh(std::vector< std::vector<int> > newMesh);
		const std::vector<Vector3f>& getVertex() const;
	private:
	class Mesh
	{
		public:
			Mesh(std::vector< std::vector<int> > vertexIndex);
		//private:
		Vector3f ambientColor; // ka
		Vector3f diffuseColor;// kd
		Vector3f specularColor;// ks
		float shininess;  //ns
		std::vector< std::vector<int> > vertexIndex;
	};
};
#endif
