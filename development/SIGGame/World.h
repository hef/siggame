#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include "Actor.h"
#include "Model.h"
using std::vector;

class World
{
private:
	Model* pGenericModel;
	vector< Actor* > actors;
public:
	World();
	~World();
	const std::vector< Actor* >& getActors() const;
	void addActor( Actor* actor );
	void tick( double dt );
};

#endif
