#include "PlayerActor.h"
PlayerActor::PlayerActor( const string& name, const SceneNode* pSceneNode, const Vector3f& position, const Vector3f& rotation )
	: Actor( name, pSceneNode, position, rotation )
{
}

PlayerActor::PlayerActor( const string& name, const SceneNode *pSceneNode, const Vector3f& position, const Vector3f& dPosition, const Vector3f& rotation, const Vector3f& dRotation )
	: Actor( name, pSceneNode, position, dPosition, rotation, dRotation )
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
		const float PI = 3.14159265f;
		// TODO 10.0f is a magnitude of speed change. make it configureable
		// add the x vector componet of direction to x component of velocity
		dPosition[0] += -30.0f * sinf( rotation[2] * PI/180.0f ) * (float)dt;
		//add the y vector componet of rotation to y component of velocity
		dPosition[1] += 30.0f * cosf( rotation[2] * PI/180.0f ) * (float)dt;
	}

	if( input->altDown() )
	{
		World* w = World::getInstance();

		// THIS PROBABLY NEEDS TO CHANGE
		const float deltaPos = 5.0f;

		Vector3f tempPos( this->position[0], this->position[1], 0.0f );
		Vector3f tempDPos( this->dPosition[0] + deltaPos, this->dPosition[1] + deltaPos, 0.0f );
		Vector3f tempRotation( this->getRotationVector3f() );
		Vector3f tempDRotation( 0.0f, 0.0f, 0.0f );
		// Create a new actor. May want to use a Laser or Bullet Actor instead later
		AsteroidActor* laser = new AsteroidActor( "laser", new ModelSceneNode(OBJ2Model::file("spaceShip.obj")),
												  tempPos, tempDPos, tempRotation , tempDRotation);
		// Add to a temp vector in world to copy over at end of World::tick()
		w->addToActors( laser );
		
	}

	// TODO The numbers 7 and 14 need to be adjusted to fit veiwport size
	for ( int i = 0; i < 3 ; ++i )
	{
		position[ i ] += dPosition[ i ] * (float)dt;
		while ( position[ i ] > 100 )
		{
			position[ i ] += -200;
		}
		while ( position[ i ] < -100 )
		{
			position[ i ] += 200;
		}
	}

}
