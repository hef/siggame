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
