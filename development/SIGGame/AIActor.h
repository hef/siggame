#ifndef AIACTOR_H
#define AIACTOR_H
#include "Actor.h"

class AIActor : public Actor
{
public:
	/** Constructor */
	AIActor( const string& name, const SceneNode* pSceneNode, const Vector3f& position, const Vector3f& rotation );

	/** Constructor */
	AIActor( const string& name, const SceneNode* pSceneNode, const Vector3f& position, const Vector3f& dPosition,
			const Vector3f& rotation, const Vector3f& dRotation );

	/** Copy Constructor */
	AIActor( const AIActor& otherAIActor );

	/** Destructor */
	virtual ~AIActor();

	/** Tick Function */
	virtual void tick( const double dt ) = 0;

};
#endif
