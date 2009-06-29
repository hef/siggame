#ifndef RENDERER_H
#define RENDERER_H

#include "World.h"

#include <stdlib.h>
#include "SDL.h"
#include "SDL_opengl.h"
class Renderer
{
public:
	static const Renderer* getInstanceOf();
	int render( const World& gameWorld ) const;

private:
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

