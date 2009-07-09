#include "World.h"
World::World()
{
	pGenericModel = new Model;
}

World::~World()
{
	delete pGenericModel;
}

const vector< Actor* >& World::getActors() const
{
	return actors;
}

void World::addActor( Actor* actor )
{
	actors.push_back( actor );
}

void World::tick( double dt )
{
	vector< Actor* >::iterator i;
	for( i = actors.begin(); i != actors.end(); ++i )
	{
		( *i ) -> tick( dt );
	}
}
