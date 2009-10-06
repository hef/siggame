#ifndef ASTERACT_H
#define ASTERACT_H
#include "AIActor.h"

class AsteroidActor : public AIActor
{
public:
	/** Constructor **/
	AsteroidActor( const string& name, const SceneNode* pSceneNode, const Vector3f& position, const Vector3f& rotation );

	/** Constructor **/
	AsteroidActor( const string& name, const SceneNode* pSceneNode, const Vector3f& position, const Vector3f& dPosition,
	               const Vector3f& rotation, const Vector3f& dRotation );

	/** Copy constructor **/
	AsteroidActor( const AsteroidActor& otherAsteroid );

	/** Destructor **/
	~AsteroidActor();

	/** Tick Function */
	void tick( const double dt );
};
#endif

