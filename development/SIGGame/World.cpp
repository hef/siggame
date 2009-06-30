#include "World.h"
World::World()
{
	pGenericModel=new Model();
	Actor b1(pGenericModel,Vector3f(0.5,-0.75f,0),Vector3f(0,0,0));
	Actor b2(pGenericModel,Vector3f(-0.5f,0.75,0),Vector3f(0,0,0));
	addActor(b1);
	addActor(b2);

}
World::~World()
{
	delete pGenericModel;
}
const std::vector<Actor>& World::getActors() const
{
	return actors;
}

void World::addActor(Actor &actor)
{
	actors.push_back(actor);
	return;
}
