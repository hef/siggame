#include "Actor.h"
Actor::Actor( Model* model, const Vector3f position, const Vector3f rotation ) :
	model( model ),
	position( position ),
	rotation( rotation )
{
	dPosition.elementArray[ 0 ] = 0.0f;
	dPosition.elementArray[ 1 ] = 0.0f;
	dPosition.elementArray[ 2 ] = 0.0f;
	dRotation.elementArray[ 0 ] = 0.0f;
	dRotation.elementArray[ 1 ] = 0.0f;
	dRotation.elementArray[ 2 ] = 0.0f;
}

Actor::Actor( Model* model, const Vector3f position, const Vector3f dPosition, const Vector3f rotation, const Vector3f dRotation ) :
	model( model ),
	position( position ),
	dPosition( dPosition ),
	rotation( rotation ),
	dRotation( dRotation )
{
}

Actor::Actor( const Actor& actor ) :
	model( actor.model ),
	position( actor.position ),
	dPosition( actor.dPosition ),
	rotation( actor.rotation ),
	dRotation( actor.dRotation )
{
}

Actor::~Actor()
{ }

const Model& Actor::getModel() const
{
	return *model;
}

const Vector3f& Actor::getPositionVector3f() const
{
	return position;
}

void Actor::tick( double dt )
{
	position[ 0 ] += dPosition[ 0 ] * (float)dt;
	position[ 1 ] += dPosition[ 1 ] * (float)dt;
	position[ 2 ] += dPosition[ 2 ] * (float)dt;
}
