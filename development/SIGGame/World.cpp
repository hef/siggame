#include "World.h"
World::World()
{
	pShipModel = new ModelSceneNode(OBJ2Model::file("spaceShip.obj"));
	pCessnaModel = new ModelSceneNode(OBJ2Model::file("cessna.obj"));
	Actor* pPlayer = new PlayerActor
	(
		pShipModel,
		//pCessnaModel,
		Vector3f(0,0,0),
		Vector3f(0,0,0)
	);
	addActor( pPlayer );
}

World::~World()
{
	delete pShipModel;
	delete pCessnaModel;

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
