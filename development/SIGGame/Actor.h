#ifndef ACTOR_H
#define ACTOR_H
#include "Model.h"
#include "Vector3f.h"
class Actor
{
	private:
		Model* model;
		///x, y, z
		Vector3f position;
		//pitch, yaw, roll
		Vector3f rotation;
	public:
		Actor(Model* model, Vector3f const position, Vector3f const rotation);
		Actor(const Actor& actor);
		~Actor();
		const Model& getModel() const;
		const Vector3f& getPositionVector3f() const;
};
#endif
