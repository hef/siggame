#include "World.h"
World::World()
{
	pGenericModel = new Model;
	Actor* pRock = new AsteroidActor
	               (
			"Asteroid_1",
	        pGenericModel,
	        Vector3f( -1, -3, 0 ),
	        Vector3f( 1, 1.5, 0 ),
	        Vector3f( 0, 0, 0 ),
	        Vector3f( -1, 3, 15 )
	               );
	addActor( pRock );

	pRock = new AsteroidActor
	               (
			"Asteroid_2",
	        pGenericModel,
	        Vector3f( -10, -30, 0 ),
	        Vector3f( 5, -2.5, 0 ),
	        Vector3f( 0, 0, 0 ),
	        Vector3f( 105, -5, 5 )
			);

	addActor( pRock );

	pRock = new AsteroidActor
	               (
			"Asteroid_3",
	        pGenericModel,
	        Vector3f( 100, -30, 0 ),
	        Vector3f( -3, .5, 0 ),
	        Vector3f( 0, 0, 0 ),
	        Vector3f( -12, 2, -6 )
			);

	addActor( pRock );

	Actor* pPlayer = new PlayerActor
	(
		"Player_1",
		pGenericModel,
		Vector3f(0,0,0),
		Vector3f(0,0,0)
	);
	addActor( pPlayer );
}

World::~World()
{
	delete pGenericModel;

	//clean up the actors
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
