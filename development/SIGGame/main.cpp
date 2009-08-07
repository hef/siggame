#include "Renderer.h"
#include "Input.h"
#include "AudioSystem.h"
#include "PhysicsEngine.h"
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
	Renderer* r = Renderer::getInstanceOf();
	AudioSystem* audio = AudioSystem::getInstance();
	PhysicsEngine* p = PhysicsEngine::Instance();
	Input* input = Input::Instance();
	World w;
	audio->addSound( "Mac.wav" );
	audio->addSound( "doh.wav" );
	audio->playSound( "Mac.wav" );
	static unsigned int lastTime = SDL_GetTicks();
	static unsigned int currentTime = lastTime;
	static double dt = 0;
	bool bShouldExit = false;
	//Start main loop, runs until esc is pressed
	do
	{
		currentTime = SDL_GetTicks();
		dt = static_cast<double>( currentTime - lastTime ) / 1000;
		lastTime = currentTime;
		//Update keyboard state
		input->tick( dt );
		bShouldExit = input->escKeyDown();
		//process world logic
		w.tick( dt );
		p->applyPhysics( w );
		//Rerender the world every iteration
		r->render( w );
	}
	while( !bShouldExit);
	//delete the instances
	audio->destroy();
	p->destroy();
	input->destroy();
	r->destroy();
	return EXIT_SUCCESS;
}

