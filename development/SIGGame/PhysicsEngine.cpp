#include <stdlib.h>
#include "PhysicsEngine.h"
#include "World.h"
#include "Actor.h"
#include <Math.h>
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
			if( PhysicsEngine::containsAnyPartOf( *(*i),*(*j) ) ){
				PhysicsEngine::collision2D( *(*i),*(*j) );
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

void PhysicsEngine::collision2D(Actor& ball1, Actor& ball2)
{
	Vector3f velocity1 = ball1.getdPositionVector3f();
	Vector3f velocity2 = ball2.getdPositionVector3f();

	Vector3f position1 = ball1.getPositionVector3f();
	Vector3f position2 = ball2.getPositionVector3f();

	//since mass isn't a factor at the moment
	//float m1=1.0f;
	//float m2=1.0f;

	Vector3f normal(position1-position2);

	float mag=sqrt(pow(normal[0], 2)+pow(normal[1], 2));

	normal[0] = (normal[0]/mag);
	normal[1] = (normal[1]/mag);

	mag = velocity2.dotProduct(normal);
	Vector3f v2normal(sqrt(pow(mag,2)/(pow(normal[1]/normal[0],2)+1)), sqrt(pow(mag,2)/(pow(normal[0]/normal[1],2)+1)), 0); 

	normal = ((normal-normal)-normal);	//converts normal to negative

	mag = velocity2.dotProduct(normal);
	Vector3f v1normal(sqrt(pow(mag,2)/(pow(normal[1]/normal[0],2)+1)), sqrt(pow(mag,2)/(pow(normal[0]/normal[1],2)+1)), 0); 

	Vector3f v1tangent(v1normal - velocity1);
	Vector3f v2tangent(v2normal - velocity2);

	ball1.setdPositionVector3f(v1tangent + v2normal);
	ball2.setdPositionVector3f(v2tangent + v1normal);

	ball2.setPositionVector3f(ball2.getPositionVector3f+v1normal);
	ball1.setPositionVector3f(ball1.getPositionVector3f+v2normal);


	return;
}

PhysicsEngine::~PhysicsEngine()
{
}
