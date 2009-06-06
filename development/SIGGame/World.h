#ifndef WORLD_H
#define WORLD_H


#include <vector>
#include "Actor.h"

class World
{
public:
	const std::vector<Actor>& getActors() const;
	int addActor( Actor& actor );

private:
	std::vector<Actor> actors;
};

#endif