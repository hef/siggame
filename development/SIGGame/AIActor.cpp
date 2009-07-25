#include "AIActor.h"

AIActor::AIActor( Model* model, const Vector3f& position, const Vector3f& rotation )
: Actor( model, position, rotation )
{
}

AIActor::AIActor( Model* model, const Vector3f& position, const Vector3f& dPosition, const Vector3f& rotation, const Vector3f& dRotation )
: Actor( model, position, dPosition, rotation, dRotation )
{
}

AIActor::AIActor( const AIActor& otherAIActor )
: Actor( otherAIActor )
{
}

AIActor::~AIActor()
{
}
