#ifndef ACTOR_H
#define ACTOR_H
#include "Model.h"
#include "Vector3f.h"
class Actor
{
private:
	Model* model;
	/*float minX;
	float maxX;
	float minY;
	float maxY;*/
	float boundingBox[6];
protected:
	/** x, y, z */
	Vector3f position;
	/** delta position per tick */
	Vector3f dPosition;
	/** pitch, yaw, roll */
	Vector3f rotation;
	/** delta rotation per tick */
	Vector3f dRotation;
	/** current OpenGL matrix */
	float glMatrix[16];
public:
	/** Constructor. */
	Actor( Model* model, const Vector3f& position, const Vector3f& rotation );

	/** Constructor. */
	Actor( Model* model, const Vector3f& position, const Vector3f& dPosition,
	       const Vector3f& rotation, const Vector3f& dRotation );

	/** Copy constructor. */
	Actor( const Actor& actor );

	/** Destructor. */
	virtual ~Actor();

	/** Accessor. */
	const Model& getModel() const;

	/** Accessor. */
	const Vector3f& getPositionVector3f() const;

	/** Accessor. */
	const Vector3f& getRotationVector3f() const;

	virtual void tick( const double dt ) = 0;

	/** Sets the current OpenGL matrix for rendering/physics. */
	void setGLMatrix( float* mat );

	/** Accessor. */
	const float* getGLMatrix();

	/** Accessor. */
	const float* getBoundingBox();
};
#endif
