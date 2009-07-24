#include "PlayerActor.h"
PlayerActor::PlayerActor( Model* model, const Vector3f& position, const Vector3f& rotation )
	: Actor( model, position, rotation )
{
}

PlayerActor::PlayerActor( Model *model, const Vector3f& position, const Vector3f& dPosition, const Vector3f& rotation, const Vector3f& dRotation )
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

	// TODO make 100.0f configureable
	if( input->leftArrowDown() ){
		rotation[2] += 100.0f * (float)dt;
	}
	else if( input->rightArrowDown() ){
		rotation[2] -= 100.0f * (float)dt;
	}
	if( input->upArrowDown() )
	{	
		const float PI = 3.14159265;
		// TODO 10.0f is a magnitude of speed change. make it configureable
		// add the x vector componet of direction to x component of velocity
		dPosition[0] += 10.0f * cos( rotation[2] * PI/180.0f ) * (float)dt;
		//add the y vector componet of rotation to y component of velocity
		dPosition[1] += 10.0f * sin( rotation[2] * PI/180.0f ) * (float)dt;
	}

	// TODO The numbers 7 and 14 need to be adjusted to fit veiwport size
	for ( int i = 0; i < 3 ; ++i )
	{
		position[ i ] += dPosition[ i ] * (float)dt;
		while ( position[ i ] > 7 )
		{
			position[ i ] += -14;
		}
		while ( position[ i ] < -7 )
		{
			position[ i ] += 14;
		}
	}

}
