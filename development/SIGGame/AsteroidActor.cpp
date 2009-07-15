#include "AsteroidActor.h"

AsteroidActor::AsteroidActor( Model* model, const Vector3f position, const Vector3f rotation )
	: Actor( model, position, rotation )
{
}

AsteroidActor::AsteroidActor( Model* model, const Vector3f position, const Vector3f dPosition, const Vector3f rotation, const Vector3f dRotation )
	: Actor( model, position, dPosition, rotation, dRotation )
{
}

AsteroidActor::AsteroidActor( const AsteroidActor& otherAsteroid )
	: Actor( otherAsteroid )
{
}

AsteroidActor::~AsteroidActor()
{
}
void AsteroidActor::tick( const double dt )
{
	//should handle wrapping movement
	//TODO The numbers 7 and 14 need to be adjusted to fit veiwport size
	for ( int i=0; i<3 ; ++i )
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
