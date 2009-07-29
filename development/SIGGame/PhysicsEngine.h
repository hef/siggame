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
	void destroy();
	int applyPhysics( const World& gameWorld ) const;
	static bool containsAnyPartOf(Actor& outer, Actor& inner);

	static void collision2D(Actor& ball1, Actor& ball2);

	~PhysicsEngine();
};
#endif
