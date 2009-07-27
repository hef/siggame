#ifndef ModelSceneNode_h
#define ModelSceneNode_h
#include "SceneNode.h"
#include <vector>
class ModelSceneNode : SceneNode
{
	public:
		ModelSceneNode();
		void render() const;
	private:
		vector<vector3f> vertex;
		vector<Mesh> mesh;
	class Mesh
	{
		vector3f color;
		vector< Vector<int> > vertexIndex;
	};
};
#endif
