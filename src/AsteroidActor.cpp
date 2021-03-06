#include "AsteroidActor.h"

AsteroidActor::AsteroidActor( const string& name, const SceneNode* pSceneNode, const Vector3f& position, const Vector3f& rotation )
	: AIActor( name, pSceneNode, position, rotation )
{
}

AsteroidActor::AsteroidActor( const string& name, const SceneNode* pSceneNode, const Vector3f& position, const Vector3f& dPosition, const Vector3f& rotation, const Vector3f& dRotation )
	: AIActor( name, pSceneNode, position, dPosition, rotation, dRotation )
{
}

AsteroidActor::AsteroidActor( const AsteroidActor& otherAsteroid )
	: AIActor( otherAsteroid )
{
}

AsteroidActor::~AsteroidActor()
{
}

void AsteroidActor::tick( const double dt )
{
	// should handle wrapping movement
	// TODO The numbers 7 and 14 need to be adjusted to fit veiwport size
	for ( int i = 0; i < 3 ; ++i )
	{
		//handle 2d movement
		position[ i ] += dPosition[ i ] * (float)dt;
		//handle spinning
		rotation[ i ] += dRotation[ i ] * (float)dt;
		//handle wrapping
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
