#include "BoxActor.h"

BoxActor::BoxActor()
{
	// Top Face
	Quad* curr=new Quad;
	curr->setColor(1.0f, 0.5f, 0.0f);
	curr->addPoint(0, 1.0f, 1.0f, -1.0f);
	curr->addPoint(1,-1.0f, 1.0f, -1.0f);
	curr->addPoint(2,-1.0f, 1.0f, 1.0f);
	curr->addPoint(3, 1.0f, 1.0f, 1.0f);
	
	quads.push_back(*curr);

	// Bottom Face
	curr=new Quad;
	curr->setColor(1.0f, 1.0f, 0.0f);
	curr->addPoint(0, 1.0f, -1.0f, -1.0f);
	curr->addPoint(1,-1.0f, -1.0f, -1.0f);
	curr->addPoint(2,-1.0f, -1.0f, 1.0f);
	curr->addPoint(3, 1.0f, -1.0f, 1.0f);

	quads.push_back(*curr);

	// Front Face
	curr=new Quad;
	curr->setColor(1.0f, 0.5f, 0.0f);
	curr->addPoint(0, 1.0f, 1.0f, 1.0f);
	curr->addPoint(1,-1.0f, 1.0f, 1.0f);
	curr->addPoint(2,-1.0f, -1.0f, 1.0f);
	curr->addPoint(3, 1.0f, -1.0f, 1.0f);

	quads.push_back(*curr);

	// Back Face
	curr=new Quad;
	curr->setColor(1.0f, 0.0f, 0.0f);
	curr->addPoint(0, 1.0f, 1.0f, -1.0f);
	curr->addPoint(1,-1.0f, 1.0f, -1.0f);
	curr->addPoint(2,-1.0f, -1.0f, 1.0f);
	curr->addPoint(3, 1.0f, -1.0f, 1.0f);

	quads.push_back(*curr);

	// Left Face
	curr=new Quad;
	curr->setColor(0.0f, 0.5f, 1.0f);
	curr->addPoint(0,-1.0f, 1.0f, 1.0f);
	curr->addPoint(1,-1.0f, 1.0f, -1.0f);
	curr->addPoint(2,-1.0f, -1.0f, -1.0f);
	curr->addPoint(3,-1.0f, -1.0f, 1.0f);

	quads.push_back(*curr);

	// Right Face
	curr=new Quad;
	curr->setColor(1.0f, 0.5f, 1.0f);
	curr->addPoint(0, 1.0f, 1.0f, 1.0f);
	curr->addPoint(1, 1.0f, 1.0f, -1.0f);
	curr->addPoint(2, 1.0f, -1.0f, -1.0f);
	curr->addPoint(3, 1.0f, -1.0f, 1.0f);

	quads.push_back(*curr);

	
}