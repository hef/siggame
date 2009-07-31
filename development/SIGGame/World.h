#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include "Actor.h"
#include "AsteroidActor.h"
#include "PlayerActor.h"
#include "ModelSceneNode.h"
#include "OBJ2Model.h"
#include <string>
using std::vector;

class World
{
private:
	ModelSceneNode* pShipModel;
	vector< Actor* > actors;
public:
	World();
	/**
	   Responsible for deleting any created Model pointers and deletes all actors
	   in actors vector.
	 */
	~World();
	const std::vector< Actor* >& getActors() const;
	void addActor( Actor* actor );
	void tick( double dt );
};

#endif
