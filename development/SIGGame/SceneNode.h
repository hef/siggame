#ifndef SceneNode_h
#define SceneNode_h
#include "SDL_opengl.h"
class SceneNode
{
	public:
	virtual void render() = 0;
};
#endif
