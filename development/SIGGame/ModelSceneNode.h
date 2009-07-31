#ifndef ModelSceneNode_h
#define ModelSceneNode_h
#include "SceneNode.h"
#include <vector>
#include "Vector3f.h"
class ModelSceneNode : public SceneNode
{
	class Mesh;
	public:
		ModelSceneNode();
		ModelSceneNode(std::vector<Vector3f> vertices);
		void render() const;
		void addMesh(Vector3f newColor, std::vector< std::vector<int> > newMesh);
	private:
		std::vector<Vector3f> vertex;
		std::vector<Mesh> mesh;
	class Mesh
	{
		public:
			Mesh(Vector3f const color, std::vector< std::vector<int> > vertexIndex);
		//private:
		Vector3f color;
		std::vector< std::vector<int> > vertexIndex;
	};
};
#endif
