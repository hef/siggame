#include "World.h"
World::World()
{
	pGenericModel = new Model;
	Actor* pRock = new AsteroidActor
	               (
	        pGenericModel,
	        Vector3f( -1, -3, 0 ),
	        Vector3f( 1, 1.5, 0 ),
	        Vector3f( 0, 0, 0 ),
	        Vector3f( 0, 0, 0 )
	               );
	addActor( pRock );
}

World::~World()
{
	delete pGenericModel;

	///clean up the actors
	vector< Actor* >::iterator i;
	for( i = actors.begin(); i != actors.end(); ++i )
	{
		delete *i;
	}
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
		( *i )->tick( dt );
	}
}
