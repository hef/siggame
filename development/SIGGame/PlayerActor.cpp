#include "PlayerActor.h"

PlayerActor::PlayerActor( Model* model, const Vector3f position, const Vector3f rotation )
	: Actor( model, position, rotation )
{
}

PlayerActor::PlayerActor( Model *model, const Vector3f position, const Vector3f dPosition, const Vector3f rotation, const Vector3f dRotation )
	: Actor( model, position, dPosition, rotation, dRotation )
{
}

PlayerActor::PlayerActor( const PlayerActor& otherPlayer )
	: Actor( otherPlayer )
{
}

PlayerActor::~PlayerActor()
{
}
void PlayerActor::tick( const double dt )
{
	Input* input = Input::Instance();
	input->getInput();

	if(input->leftDown()){
		rotation[2] += 100.0f * (float)dt;
	}
	else if(input->rightDown()){
		rotation[2] -= 100.0f * (float)dt;
	}

	/* TODO read up on math to fill this in
	   the concept is:
	   take the rotation[2] x component,
	   add it to dPosition[0]
	   take the rotation[2] y component, 
	   add it to dPosition[1]
	   then apply normal vector movement(pos+=dpos*dt)
	   
	   remember, sin/cos methods suck cycles fast, there is probably a 
	   vector/matrix method that is faster and better

	if(input->upDown()){
		rotation[0] += dRotation[0];
	}
	else if(input->downDown()){
		rotation[0] -= dRotation[0];
	}
	*/

}
