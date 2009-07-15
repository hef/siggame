#include "Renderer.h"
#include "Input.h"
#include "AudioSystem.h"
#include "World.h"
#include "Model.h"
#include "Vector3f.h"

int main( int argc, char **argv )
{
	if ( argc == 2 && strncmp( argv[1], "editor", 6 ) )
	{
		// Run the editor
	}

	//Initialize everything
	const Renderer* r = Renderer::getInstanceOf();
	AudioSystem* audio = AudioSystem::getInstance();

	Input* input = Input::Instance();
	World w;
	audio->addSound( "Mac.wav" );
	audio->playSound( "Mac.wav" );
	static unsigned int lastTime = SDL_GetTicks();
	static unsigned int currentTime = lastTime;
	///delta time
	static double dt = 0;
	r->render( w );

	//Start main loop, runs until esc is pressed
	while ( input->getInput() )
	{

		currentTime = SDL_GetTicks();
		dt = static_cast<double>( currentTime - lastTime ) / 1000;
		lastTime = currentTime;

		//process world logic
		w.tick( dt );

		//Rerender the world every iteration
		r->render( w );
	}
	return 1;
}
