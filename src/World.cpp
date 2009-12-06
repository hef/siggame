#include "World.h"

World* World::pInstance = NULL;

World* World::getInstance()
{
	if( pInstance == NULL )
	{
		pInstance = new World;
	}
	return pInstance;
}

World::World()
{
	pShipModel = new ModelSceneNode(OBJ2Model::file("spaceShip.obj"));
	Actor* pRock = new AsteroidActor
	(
		"Asteroid_1",
		pShipModel,
		Vector3f( -1, -3, 0 ),
		Vector3f( 1, 1.5, 0 ),
		Vector3f( 0, 0, 0 ),
		Vector3f( -1, 3, 15 )
	);
	addActor( pRock );

	pRock = new AsteroidActor
	(
		"Asteroid_2",
		pShipModel,
		Vector3f( -10, -30, 0 ),
		Vector3f( 5, -2.5, 0 ),
		Vector3f( 0, 0, 0 ),
		Vector3f( 105, -5, 5 )
	);

	addActor( pRock );

	pRock = new AsteroidActor
	(
		"Asteroid_3",
		pShipModel,
		Vector3f( 100, -30, 0 ),
		Vector3f( -3, .5, 0 ),
		Vector3f( 0, 0, 0 ),
		Vector3f( -12, 2, -6 )
	);

	addActor( pRock );

	Actor* pPlayer = new PlayerActor
	(
		"Player_1",
		pShipModel,
		Vector3f(0,0,0),
		Vector3f(0,0,0)
	);
	addActor( pPlayer );
}

World::~World()
{
	delete pShipModel;

	// Clean up the actors
	vector< Actor* >::iterator i;
	for( i = actors.begin(); i != actors.end(); ++i )
	{
		delete *i;
	}
	// Clean up the other actors that may still exist
	for( i = actorsToAdd.begin(); i != actorsToAdd.end(); ++i )
	{
		delete *i;
	}
}

{
	delete pInstance;
>>>>>>> p4/master
}

const vector< Actor* >& World::getActors() const
{
	return actors;
}

void World::addActor( Actor* actor )
{
	actors.push_back( actor );
}

void World::addToActors( Actor* actor )
{
	actorsToAdd.push_back( actor );
}

void World::tick( double dt )
{
	vector< Actor* >::iterator i;
	for( i = actors.begin(); i != actors.end(); ++i )
	{
		( *i )->tick( dt );
	}
	// Add actors to the vector of actors
	for( i = actorsToAdd.begin(); i != actorsToAdd.end(); ++i )
	{
		addActor( *i );
	}
	actorsToAdd.clear(); // Remove them from the temp vector when done
}
