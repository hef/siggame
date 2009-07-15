#ifndef PLAYACT_H
#define PLAYACT_H
#include "Actor.h"

class PlayerActor : public Actor
{
public:
	/** Constructor **/
	PlayerActor( Model* model, const Vector3f position, const Vector3f rotation );

	/** Constructor **/
	PlayerActor( Model* model, const Vector3f position, const Vector3f dPosition,
	             const Vector3f rotation, const Vector3f dRotation );

	/** Copy constructor **/
	PlayerActor( const PlayerActor& otherPlayer );

	/** Destructor **/
	~PlayerActor();
};
#endif