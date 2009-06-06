#ifndef RENDERER_H
#define RENDERER_H

#include "World.h"

#include <stdlib.h>
#include "SDL.h"

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#if defined(__APPLE__) && defined(__MACH__)
#include <openGL/gl.h>
#include <openGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

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

	GLvoid establishProjectionMatrix( GLsizei width, GLsizei height );
	GLvoid initGL( GLsizei width, GLsizei height );
	GLvoid displayFPS( GLvoid ) const;
};
#endif

