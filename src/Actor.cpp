#include "Actor.h"
#include "Input.h"
#include <math.h>
#include <iostream>

Actor::Actor( const string& name, const SceneNode* pSceneNode, const Vector3f& position, const Vector3f& rotation ) :
	pSceneNode( pSceneNode ),
	position( position ),
	rotation( rotation ),
	boundingSphereRadius(0)
{
	dPosition.elementArray[ 0 ] = 0.0f;
	dPosition.elementArray[ 1 ] = 0.0f;
	dPosition.elementArray[ 2 ] = 0.0f;
	dRotation.elementArray[ 0 ] = 0.0f;
	dRotation.elementArray[ 1 ] = 0.0f;
	dRotation.elementArray[ 2 ] = 0.0f;

	this->name = name;
}

Actor::Actor( const string& name, const SceneNode* pSceneNode, const Vector3f& position, const Vector3f& dPosition, const Vector3f& rotation, const Vector3f& dRotation ) :
	pSceneNode( pSceneNode ),
	position( position ),
	dPosition( dPosition ),
	rotation( rotation ),
	dRotation( dRotation ),
	boundingSphereRadius(0)
{
	this->name = name;
}

Actor::Actor( const Actor& actor ) :
	pSceneNode( actor.pSceneNode ),
	position( actor.position ),
	dPosition( actor.dPosition ),
	rotation( actor.rotation ),
	dRotation( actor.dRotation ),
	boundingSphereRadius(0)
{
	this->name = actor.name + "_copy";
}

Actor::~Actor()
{
}

const SceneNode& Actor::getSceneNode() const
{
	return *pSceneNode;
}

const string& Actor::getName() const
{
	return name;
}

const Vector3f& Actor::getPositionVector3f() const
{
	return position;
}

const Vector3f& Actor::getRotationVector3f() const
{
	return rotation;
}

void Actor::setName( const string& name )
{
	this->name = name;
}

void Actor::setGLMatrix( float* mat )
{
	
	for ( int i = 0 ; i < 16 ; ++i )
	{
		glMatrix[i] = mat[i];
	}

	std::vector<Vector3f>::const_iterator j;
	const ModelSceneNode* pModelSceneNode= static_cast<const ModelSceneNode*>(pSceneNode);
	for( j=pModelSceneNode->getVertex().begin();j!=pModelSceneNode->getVertex().end();++j)
	{
			//Calculated vertex location will be stored here
			float temp[3];

			//Using a separate array to make the code easier to read
			float tempOrig[3];
			tempOrig[0] = ( *j ).elementArray[0];
			tempOrig[1] = ( *j ).elementArray[1];
			tempOrig[2] = ( *j ).elementArray[2];

			//Calculate the vertex's position on the screen
			temp[0] = tempOrig[0] * mat[0] + tempOrig[1] * mat[4] + tempOrig[2] * mat[8] + mat[12];
			temp[1] = tempOrig[0] * mat[1] + tempOrig[1] * mat[5] + tempOrig[2] * mat[9] + mat[13];
			temp[2] = tempOrig[0] * mat[2] + tempOrig[1] * mat[6] + tempOrig[2] * mat[10] + mat[14];

			//Get distance between vertex and center to get radius of bounding sphere
			float tempRadius = sqrtf( ( temp[0] - position[0] ) * ( temp[0] - position[0] ) +  ( temp[1] - position[1] ) * ( temp[1] - position[1] ) + ( temp[2] - position[2] ) * ( temp[2] - position[2] ) );

			if(boundingSphereRadius<tempRadius)
				boundingSphereRadius = tempRadius;
		}
}

	
const float* Actor::getGLMatrix() const
{
	return glMatrix;
}

float Actor::getBoundingSphereRadius() const
{
	return boundingSphereRadius;
}


const Vector3f& Actor::getBoundingSphereCenter() const
{
	return position;
}

void Actor::bounceBackFrom(Actor& other, float distance)
{
	distance = distance/2;

	Vector3f dpTemp;
	Vector3f drTemp;

	dpTemp[0] = dPosition[0];
	dpTemp[1] = dPosition[1];

	drTemp[0] = dRotation[0];
	drTemp[1] = dRotation[1];

	dPosition[0] = other.dPosition[0];
	dPosition[1] = other.dPosition[1];

	other.dPosition[0] = dpTemp[0];
	other.dPosition[1] = dpTemp[1];

	dRotation[0] = other.dRotation[0];
	dRotation[1] = other.dRotation[1];

	other.dRotation[0] = drTemp[0];
	other.dRotation[1] = drTemp[1];

	if(dPosition[0]!=0 && dPosition[1]!=0){
		double backTrackAmt = ( distance * distance ) / ( ( dPosition[0] * dPosition[0] ) + ( dPosition[1] * dPosition[1] ) );
		tick( backTrackAmt );
	}
	
	//if(position[0]<-14)
	std::cout << "    pos:" << position[0] << std::endl;

	if(other.dPosition[0]!=0 && other.dPosition[1]!=0){
		double backTrackAmt = ( distance * distance ) / ( ( other.dPosition[0] * other.dPosition[0] ) + ( other.dPosition[1] * other.dPosition[1] ) );
		other.tick( backTrackAmt );
	}
}
