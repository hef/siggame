#include "Actor.h"
#include "Input.h"
#include "Surface.h"
#include <vector>

Actor::Actor( Model* model, const Vector3f position, const Vector3f rotation ) :
	model( model ),
	position( position ),
	rotation( rotation )
{
	dPosition.elementArray[ 0 ] = 0.0f;
	dPosition.elementArray[ 1 ] = 0.0f;
	dPosition.elementArray[ 2 ] = 0.0f;
	dRotation.elementArray[ 0 ] = 0.0f;
	dRotation.elementArray[ 1 ] = 0.0f;
	dRotation.elementArray[ 2 ] = 0.0f;
}

Actor::Actor( Model* model, const Vector3f position, const Vector3f dPosition, const Vector3f rotation, const Vector3f dRotation ) :
	model( model ),
	position( position ),
	dPosition( dPosition ),
	rotation( rotation ),
	dRotation( dRotation )
{
}

Actor::Actor( const Actor& actor ) :
	model( actor.model ),
	position( actor.position ),
	dPosition( actor.dPosition ),
	rotation( actor.rotation ),
	dRotation( actor.dRotation )
{
}

Actor::~Actor()
{
}

const Model& Actor::getModel() const
{
	return *model;
}

const Vector3f& Actor::getPositionVector3f() const
{
	return position;
}

const Vector3f& Actor::getRotationVector3f() const
{
	return rotation;
}

void Actor::tick( double dt )
{
	position[ 0 ] += dPosition[ 0 ] * (float)dt;
	position[ 1 ] += dPosition[ 1 ] * (float)dt;
	position[ 2 ] += dPosition[ 2 ] * (float)dt;

	
}

void Actor::setGLMatrix( float* mat ){
	for(int i = 0 ; i < 16 ; i++){
		glMatrix[i] = mat[i];
	}

	const std::vector< Surface >& surfaces = model->getSurfaces();

	std::vector< Surface >::const_iterator j;

	for( j = surfaces.begin(); j != surfaces.end(); ++j )
	{
		
		for( int k = 0; k < 3; ++k )
		{
			
			//Calculated vertex location will be stored here
			float temp[3];

			//Using a separate array to make the code easier to read
			float tempOrig[3];
			tempOrig[0] = ( *j ).at( k ).elementArray[0];
			tempOrig[1] = ( *j ).at( k ).elementArray[1];
			tempOrig[2] = ( *j ).at( k ).elementArray[2];

			//Calculate the vertex's position on the screen
			temp[0] = tempOrig[0] * mat[0] + tempOrig[1] * mat[4] + tempOrig[2] * mat[8] + mat[12];
			temp[1] = tempOrig[0] * mat[1] + tempOrig[1] * mat[5] + tempOrig[2] * mat[9] + mat[13];
			temp[2] = tempOrig[0] * mat[2] + tempOrig[1] * mat[6] + tempOrig[2] * mat[10] + mat[14];

			if(j == surfaces.begin() && k == 0){
				boundingBox[0] = temp[0];
				boundingBox[1] = temp[0];
				boundingBox[2] = temp[1];
				boundingBox[3] = temp[1];
			}
			else{
				//Update min x
				if(boundingBox[0]>temp[0])
					boundingBox[0]=temp[0];
				//Update max x
				if(boundingBox[1]<temp[0])
					boundingBox[1]=temp[0];
				//Update min y
				if(boundingBox[2]>temp[1])
					boundingBox[2]=temp[1];
				//Update max y
				if(boundingBox[3]<temp[1])
					boundingBox[3]=temp[1];

				//Z coordinate shouldn't matter... but just in case
				//Update min z
				if(boundingBox[2]>temp[1])
					boundingBox[2]=temp[1];
				//Update max z
				if(boundingBox[3]<temp[1])
					boundingBox[3]=temp[1];
			}

		}

	}
}

	
const float* Actor::getGLMatrix()
{
	return glMatrix;
}

const float* Actor::getBoundingBox()
{
	return boundingBox;
}
