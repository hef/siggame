#include "Actor.h"

void Actor::addQuad(Quad& q)
{
	quads.push_back(q);
}

const std::vector<Quad>& Actor::getQuads() const
{
	return quads;
}