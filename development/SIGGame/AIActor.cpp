#include "AIActor.h"

AIActor::AIActor( const string& name, Model* model, const Vector3f& position, const Vector3f& rotation )
: Actor( name, model, position, rotation )
{
}

AIActor::AIActor( const string& name, Model* model, const Vector3f& position, const Vector3f& dPosition, const Vector3f& rotation, const Vector3f& dRotation )
: Actor( name, model, position, dPosition, rotation, dRotation )
{
}

AIActor::AIActor( const AIActor& otherAIActor )
: Actor( otherAIActor )
{
}

AIActor::~AIActor()
{
}
