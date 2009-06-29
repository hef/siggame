#include "Actor.h"
Actor::Actor(Model* model, Vector3f const position, Vector3f const rotation) :
	model(model),
	position(position),
	rotation(rotation)
{
}
Actor::Actor(const Actor& actor) :
	model(actor.model),
	position(actor.position),
	rotation(actor.rotation)
{
}
Actor::~Actor()
{
}
const Model& Actor::getModel() const
{
	return *model;
}
const Vector3f& Actor::getPositionVector3f() const
{
	return position;
}
