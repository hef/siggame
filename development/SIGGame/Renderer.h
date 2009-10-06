#ifndef RENDERER_H
#define RENDERER_H
#include "World.h"
#include "ModelSceneNode.h"
#include <stdlib.h>
#include "SDL.h"
#include "SDL_opengl.h"
using std::vector;

class Renderer
{
public:
	static Renderer* getInstanceOf();
	void destroy();
	int render( const World& gameWorld ) const;

private:
	GLuint texture;
	SDL_Surface* surface;
	GLenum texture_format;
	GLint nOfColors;
	GLsizei windowWidth;
	GLsizei windowHeight;
	GLfloat cubeRotateX;
	GLfloat cubeRotateY;

	static Renderer* instance;
	Renderer();
	~Renderer();

	void establishProjectionMatrix( GLsizei width, GLsizei height );
	void initGL( GLsizei width, GLsizei height );
	void displayFPS( void ) const;
};
#endif

