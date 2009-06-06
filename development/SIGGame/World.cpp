#include "World.h"

const std::vector<Actor>& World::getActors() const
{
	return actors;
}

int World::addActor(Actor &actor)
{
	actors.push_back(actor);
	return 0;
}