#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include "Actor.h"
#include "AsteroidActor.h"
#include "PlayerActor.h"
#include "Model.h"
using std::vector;

class World
{
private:
	Model* pGenericModel;
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
