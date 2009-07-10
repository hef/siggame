#include "AsteroidActor.h"

AsteroidActor::AsteroidActor( Model* model, const Vector3f position, const Vector3f rotation )
: Actor( model, position, rotation )
{ }

AsteroidActor::AsteroidActor( Model* model, const Vector3f position, const Vector3f dPosition, const Vector3f rotation, const Vector3f dRotation )
: Actor( model, position, dPosition, rotation, dRotation )
{ }

AsteroidActor::AsteroidActor( const AsteroidActor& otherAsteroid )
: Actor( otherAsteroid )
{ }

AsteroidActor::~AsteroidActor()
{ }
