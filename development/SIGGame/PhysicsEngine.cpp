#include <stdlib.h>
#include "PhysicsEngine.h"
#include "World.h"
#include "Actor.h"
#include <iostream>
#include <time.h>
#include <math.h>

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

void PhysicsEngine::destroy()
{
	if( pInstance != NULL )
	{
		delete pInstance;
	}
}
int PhysicsEngine::applyPhysics( const World& gameWorld ) const
{
	const vector< Actor* >& actors = gameWorld.getActors();

	vector< Actor* >::const_iterator i,j;

	for( i = actors.begin(); i != actors.end(); ++i )
	{
		for(j = i+1; j != actors.end(); j++ )
		{
			float overlapDistance = PhysicsEngine::getBoundingSpheresOverlapDistance( *(*i),*(*j) );
			if( overlapDistance>0 ){
				std::cout << time(NULL) << ": Collision!" << std::endl;
				(*i)->bounceBackFrom(*(*j),overlapDistance);
			}
		}
	}
	return 0;
}

float PhysicsEngine::getBoundingSpheresOverlapDistance( const Actor& outer, Actor& inner ) 
{

	Vector3f otherBoundingSphereCenter = inner.getBoundingSphereCenter();
	Vector3f thisBoundingSphereCenter = outer.getBoundingSphereCenter();

	float distance = sqrt( (otherBoundingSphereCenter[0] - thisBoundingSphereCenter[0] ) * (otherBoundingSphereCenter[0]-thisBoundingSphereCenter[0]) +  (otherBoundingSphereCenter[1]-thisBoundingSphereCenter[1])*(otherBoundingSphereCenter[1]-thisBoundingSphereCenter[1]) + (otherBoundingSphereCenter[2]-thisBoundingSphereCenter[2])*(otherBoundingSphereCenter[2]-thisBoundingSphereCenter[2]));

	if(distance<=outer.getBoundingSphereRadius()){
		return outer.getBoundingSphereRadius()-distance;
	}

	return -1;
}

PhysicsEngine::~PhysicsEngine()
{
}