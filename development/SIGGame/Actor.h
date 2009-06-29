#ifndef ACTOR_H
#define ACTOR_H

#include <vector>
#include "Quad.h"

class Actor
{
public:
	virtual void addQuad(Quad& q);
	const std::vector<Quad>& getQuads() const;

protected:
	std::vector<Quad> quads; 
};


#endif