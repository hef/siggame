#ifndef ASTERACT_H
#define ASTERACT_H
#include "Actor.h"

class AsteroidActor : public Actor
{
public:
	/** Constructor **/
	AsteroidActor( Model* model, const Vector3f position, const Vector3f rotation );

	/** Constructor **/
	AsteroidActor( Model* model, const Vector3f position, const Vector3f dPosition,
		   const Vector3f rotation, const Vector3f dRotation );

	/** Copy constructor **/
	AsteroidActor( const AsteroidActor& otherPlayer );

	/** Destructor **/
	~AsteroidActor();
};
#endif