#ifndef PHYSENG_H
#define PHYSENG_H
#include "World.h"


class PhysicsEngine
{
private:
	static PhysicsEngine* pInstance;
protected:
	PhysicsEngine();
public:
	static PhysicsEngine* Instance();
	int applyPhysics( const World& gameWorld ) const;
	static bool containsAnyPartOf(Actor& outer, Actor& inner);
	~PhysicsEngine();
};
#endif