///////////////////////////////////////////////////
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

const GLsizei windowWidth = 500;
const GLsizei windowHeight = 500;

GLfloat cubeRotateX = 45.0f;
GLfloat cubeRotateY = 45.0f;

Uint8 *keys = NULL;

//////////COPIED FROM GLUTDEMO.CPP///////////

GLvoid establishProjectionMatrix(GLsizei width, GLsizei height)
{
	glViewport(0,0, width, height);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 200.0f);

}

GLvoid initGL(GLsizei width, GLsizei height)
{
	establishProjectionMatrix(width, height);

	glShadeModel(GL_SMOOTH);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // nicest calculation possible
	glEnable(GL_PERSPECTIVE_CORRECTION_HINT); // enabled above

}

GLvoid displayFPS(GLvoid)
{
	static long lastTime = SDL_GetTicks();
	static long loops = 0;
	static GLfloat fps = 0.0f;

	int newTime = SDL_GetTicks();

	if (newTime - lastTime > 100)
	{
		float newFPS = (float)loops / float(newTime - lastTime) * 1000.0f;

		fps = (fps + newFPS) / 2.0f;

		char title[80];
		sprintf(title, "OpenGL Demo - %.2f", fps);

		SDL_WM_SetCaption(title, NULL);

		lastTime = newTime;

		loops = 0;
	}
	loops++;
}

GLvoid drawScene(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0, 0, -5.0f); // translate camera back -5
	glRotatef(cubeRotateX, 1, 0, 0); // rotate cube x, y,
	glRotatef(cubeRotateY, 0, 1, 0);

	// draw cube
	glBegin(GL_QUADS);
	// Top Face
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f( 1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f( 1.0f, 1.0f, 1.0f);

	// Bottom Face
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f( 1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f( 1.0f, -1.0f, 1.0f);

	// Front Face
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f( 1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f( 1.0f, -1.0f, 1.0f);

	// Back Face
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f( 1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f( 1.0f, -1.0f, -1.0f);

	//Left Face
	glColor3f(0.0f, 0.5f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	// Right Face
	glColor3f(1.0f, 0.5f, 1.0f);
	glVertex3f( 1.0f, 1.0f, 1.0f);
	glVertex3f( 1.0f, 1.0f, -1.0f);
	glVertex3f( 1.0f, -1.0f, -1.0f);
	glVertex3f( 1.0f, -1.0f, 1.0f);

	//
	glEnd();
	glFlush(); // free up stuff

	SDL_GL_SwapBuffers(); // switches buffer

	displayFPS();
}


GLboolean checkKeys(GLvoid)
{
	static long lastTime = SDL_GetTicks();
	const GLfloat speed = 1.0f;
	const long updateTime = 10;

	if ( keys[SDLK_ESCAPE] )
		return true;

	long newTime = SDL_GetTicks();

	if ( newTime - lastTime > updateTime )
	{
		if ( keys[SDLK_LEFT] )
			cubeRotateY -= speed;
		if ( keys[SDLK_RIGHT] )
			cubeRotateY += speed;
		if ( keys[SDLK_UP] )
			cubeRotateX -= speed;
		if ( keys[SDLK_DOWN] )
			cubeRotateX += speed;
	}
	return false;
}


//////////////////////////////////////

int main(int argc, char **argv)
{
	if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		fprintf(stderr, "Unable to initialize SDL %s", SDL_GetError());
		exit(1);
	}
	if ( SDL_SetVideoMode(windowWidth, windowHeight, 0, SDL_OPENGL) == NULL)
	{
		fprintf(stderr, "Unable to create openGL scene %s", SDL_GetError());
		exit(2);
	}

	initGL(windowWidth, windowHeight);

	int done = 0;
	while ( !done )
	{
		drawScene();

		SDL_Event event;
		while ( SDL_PollEvent(&event) )
		{
			if ( event.type == SDL_QUIT )
				done = 1;

			keys = SDL_GetKeyState(NULL);
		}
		if ( checkKeys() )
			done = 1;
	}

	SDL_Quit();

	return 1;
}
/////////////////////////////////////////////// 