#ifndef NON_INTER_ACT_H
#define NON_INTER_ACT_H
#include "Actor.h"

class NonInteractActor : public Actor
{
public:
	/** Constructor */
	NonInteractActor( Model* model, const Vector3f& position, const Vector3f& rotation );

	/** Constructor */
	NonInteractActor( Model* model, const Vector3f& position, const Vector3f& dPosition,
					const Vector3f& rotation, const Vector3f& dRotation );

	/** Copy Constructor */
	NonInteractActor( const NonInteractActor& other );

	/** Destructor */
	~NonInteractActor();

	/** Tick Function */
	void tick( const double dt );
};
#endif