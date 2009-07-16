#ifndef ACTOR_H
#define ACTOR_H
#include "Model.h"
#include "Vector3f.h"
class Actor
{
private:
	Model* model;
protected:
	///x, y, z
	Vector3f position;
	///delta position per tick
	Vector3f dPosition;
	//pitch, yaw, roll
	Vector3f rotation;
	///delta rotation per tick
	Vector3f dRotation;
public:
	/** Constructor **/
	Actor( Model* model, const Vector3f position, const Vector3f rotation );

	/** Constructor **/
	Actor( Model* model, const Vector3f position, const Vector3f dPosition,
	       const Vector3f rotation, const Vector3f dRotation );

	/** Copy constructor **/
	Actor( const Actor& actor );

	/** Destructor **/
	~Actor();

	/** Accessor **/
	const Model& getModel() const;

	/** Accessor **/
	const Vector3f& getPositionVector3f() const;

	/** Accessor **/
	const Vector3f& getRotationVector3f() const;

	/// Controls game logic and ai
	virtual void tick( const double dt ) = 0;
};
#endif
