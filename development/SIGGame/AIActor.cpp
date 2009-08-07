#include "AIActor.h"

AIActor::AIActor( const string& name, SceneNode* pSceneNode, const Vector3f& position, const Vector3f& rotation )
: Actor( name, pSceneNode, position, rotation )
{
}

AIActor::AIActor( const string& name, SceneNode* pSceneNode, const Vector3f& position, const Vector3f& dPosition, const Vector3f& rotation, const Vector3f& dRotation )
: Actor( name, pSceneNode, position, dPosition, rotation, dRotation )
{
}

AIActor::AIActor( const AIActor& otherAIActor )
: Actor( otherAIActor )
{
}

AIActor::~AIActor()
{
}
