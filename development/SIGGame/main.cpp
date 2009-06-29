#include "Renderer.h"
#include "Input.h"
#include "AudioSystem.h"
#include "World.h"
#include "Model.h"
#include "Vector3f.h"

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
	Model* m = new Model();
	Actor b1(m,Vector3f(0.5,-0.75f,0),Vector3f(0,0,0));
	Actor b2(m,Vector3f(-0.5f,0.75,0),Vector3f(0,0,0));
	w.addActor(b1);
	w.addActor(b2);
	audio -> addSound( "Mac.wav" );
	audio -> playSound( "Mac.wav" );
	r -> render(w);

	//Start main loop, runs until esc is pressed
	
	while ( input -> getInput() )
	{
		//Rerender the world every iteration
		r -> render(w);
	}
	delete m;	
	return 1;
}
