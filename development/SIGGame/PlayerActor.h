#ifndef PLAYACT_H
#define PLAYACT_H
#include "Actor.h"
#include "Input.h"
#include "World.h"
#include "AsteroidActor.h"
#include <math.h>

class PlayerActor : public Actor
{
public:
	/** Constructor **/
	PlayerActor( const string& name, const SceneNode* pSceneNode, const Vector3f& position, const Vector3f& rotation );

	/** Constructor **/
	PlayerActor( const string& name, const SceneNode* pSceneNode, const Vector3f& position, const Vector3f& dPosition,
	             const Vector3f& rotation, const Vector3f& dRotation );

	/** Copy constructor **/
	PlayerActor( const PlayerActor& otherPlayer );

	/** Tick Function **/
	void tick( const double dt );

	/** Destructor **/
	~PlayerActor();
};
#endif

