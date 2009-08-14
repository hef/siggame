#include "NonInteractActor.h"

NonInteractActor::NonInteractActor( const string& name, const SceneNode* pSceneNode, const Vector3f& position, const Vector3f& rotation )
: Actor( name, pSceneNode, position, rotation )
{
}

NonInteractActor::NonInteractActor( const string& name, const SceneNode* pSceneNode, const Vector3f& position, const Vector3f& dPosition, const Vector3f& rotation, const Vector3f& dRotation )
: Actor( name, pSceneNode, position, dPosition, rotation, dRotation )
{
}

NonInteractActor::NonInteractActor( const NonInteractActor& other )
: Actor( other )
{
}

NonInteractActor::~NonInteractActor()
{
}
									
void NonInteractActor::tick( const double dt )
{
	for( int i = 0; i < 3; ++i )
	{
		position[ i ] += dPosition[ i ] * (float)dt;
	}
}
