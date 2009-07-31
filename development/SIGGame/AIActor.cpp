#include "AIActor.h"

AIActor::AIActor( SceneNode* pSceneNode, const Vector3f& position, const Vector3f& rotation )
: Actor( pSceneNode, position, rotation )
{
}

AIActor::AIActor( SceneNode* pSceneNode, const Vector3f& position, const Vector3f& dPosition, const Vector3f& rotation, const Vector3f& dRotation )
: Actor( pSceneNode, position, dPosition, rotation, dRotation )
{
}

AIActor::AIActor( const AIActor& otherAIActor )
: Actor( otherAIActor )
{
}

AIActor::~AIActor()
{
}
