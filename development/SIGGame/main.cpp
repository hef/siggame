#include "Renderer.h"
#include "BoxActor.h"
#include "Input.h"
#include "AudioSystem.h"

int main(int argc, char **argv)
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
	BoxActor b;
	w.addActor(b);
	audio -> addSound( "Mac.wav" );
	audio -> playSound( "Mac.wav" );
	r -> render(w);

	//Start main loop, runs until esc is pressed
	while ( input -> getInput() )
	{
		//Rerender the world every iteration
		r -> render(w);
	}
	return 1;
}
