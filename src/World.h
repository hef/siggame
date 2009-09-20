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
	static World* pInstance;
	ModelSceneNode* pShipModel;
	ModelSceneNode* pCessnaModel;
	vector< Actor* > actors;
	/** Temporary vector used to add actors at the end of every tick */
	vector< Actor* > actorsToAdd;
public:
	static World* getInstance();
	/**
	   Responsible for deleting any created Model pointers and deletes all actors
	   in actors vector.
	 */
	~World();
	void destroy();
	const std::vector< Actor* >& getActors() const;
	void addActor( Actor* actor );
	/** This is used to add actors to the vector at the end of every tick */
	void addToActors( Actor* actor );
	void tick( const double dt );
private:
	World();
	World( const World& other );
	World& operator=( const World& other );
};

#endif
