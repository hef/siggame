#include <stdlib.h>
#include "PhysicsEngine.h"
#include "World.h"
#include "Actor.h"
#include <iostream>
#include <time.h>

PhysicsEngine* PhysicsEngine::pInstance = NULL;
PhysicsEngine* PhysicsEngine::Instance()
{
	if( pInstance == NULL )
	{
		pInstance = new PhysicsEngine;
	}
	return pInstance;
}

PhysicsEngine::PhysicsEngine()
{
}

int PhysicsEngine::applyPhysics( const World& gameWorld ) const
{
	const vector< Actor* >& actors = gameWorld.getActors();

	vector< Actor* >::const_iterator i,j;

	for( i = actors.begin(); i != actors.end(); ++i )
	{
		for(j = i+1; j != actors.end(); j++ )
		{
			if( PhysicsEngine::containsAnyPartOf( *(*i),*(*j) ) ){
				std::cout << time(NULL) << ": Collision!" << std::endl;
			}
		}
	}
	return 0;
}

bool PhysicsEngine::containsAnyPartOf(Actor& outer, Actor& inner)
{
	const float* otherBoundingBox = inner.getBoundingBox();
	const float* boundingBox = outer.getBoundingBox();

	bool xIntersect=false;

	if(otherBoundingBox[0]>=boundingBox[0] && otherBoundingBox[0]<=boundingBox[1])
		xIntersect=true;
	else if(otherBoundingBox[1]>=boundingBox[0] && otherBoundingBox[1]<=boundingBox[1])
		xIntersect=true;

	if(xIntersect)
	{
		if(otherBoundingBox[2]>=boundingBox[2] && otherBoundingBox[2]<=boundingBox[3])
			return true;
		else if(otherBoundingBox[3]>=boundingBox[2] && otherBoundingBox[3]<=boundingBox[3])
			return true;
	}

	return false;
}

PhysicsEngine::~PhysicsEngine()
{
	delete pInstance;
}