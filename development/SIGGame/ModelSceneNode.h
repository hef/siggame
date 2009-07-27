#ifndef ModelSceneNode_h
#define ModelSceneNode_h
#include "SceneNode.h"
#include <vector>
#include "Vector3f.h"
class ModelSceneNode : public SceneNode
{
	private:
	class Mesh
	{
		public:
			Mesh(Vector3f const color, std::vector< std::vector<int> > vertexIndex);
		private:
		Vector3f color;
		std::vector< std::vector<int> > vertexIndex;
	};
	public:
		ModelSceneNode();
		void render() const;
	private:
		std::vector<Vector3f> vertex;
		std::vector<Mesh> mesh;
};
#endif