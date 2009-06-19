#include "Renderer.h"
#include "BoxActor.h"

Uint8 *keys = NULL;

// Following section is to be implemented by the input coders
/*GLboolean checkKeys(void)
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
}*/


int main(int argc, char **argv)
{
	if ( argc == 2 && strncmp(argv[1], "editor", 6 ) )
	{
		// Run the editor 
	}

	const Renderer* r=Renderer::getInstanceOf();
	World w;
	BoxActor b;
	w.addActor(b);

	int done = 0;
	while ( !done )
	{
		(*r).render(w);

		SDL_Event event;
		while ( SDL_PollEvent(&event) )
		{
			if ( event.type == SDL_QUIT )
				done = 1;

			keys = SDL_GetKeyState(NULL);
		}
		// To be implemented by input coders
		/*if ( checkKeys() )
			done = 1;*/
	}

	return 1;
}
