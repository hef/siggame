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
		///delta position per tick
		Vector3f dPosition;
		//pitch, yaw, roll
		Vector3f rotation;
		///delta rotation per tick
		Vector3f dRotation;
	public:
		Actor(Model* model, Vector3f const position, Vector3f const rotation);
		Actor(Model* model, Vector3f const position, Vector3f const dPosition, Vector3f const rotation, Vector3f const dRotation);
		Actor(const Actor& actor);
		~Actor();
		const Model& getModel() const;
		const Vector3f& getPositionVector3f() const;
		///controls game logic and ai
		void tick(double dt);
};
#endif
