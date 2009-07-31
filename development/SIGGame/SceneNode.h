#ifndef SceneNode_h
#define SceneNode_h
#include "SDL_opengl.h"
class SceneNode
{
	public:
	virtual void render() const = 0;
	virtual ~SceneNode(){}
};
#endif
