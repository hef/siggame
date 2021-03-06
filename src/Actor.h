#ifndef ACTOR_H
#define ACTOR_H
#include "SceneNode.h"
#include "ModelSceneNode.h"
#include "Vector3f.h"
#include <string>
using std::string;
class Actor
{
private:
	const SceneNode* pSceneNode;
	/** Actor Name */
	string name;
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
	/** radius of the bounding sphere */
	float boundingSphereRadius;
	/** center of the bounding sphere */
	Vector3f boundingSphereCenter;
public:
	Actor( const string& name, const SceneNode* pSceneNode, const Vector3f& position, const Vector3f& rotation );

	/** Constructor. */
	Actor( const string& name, const SceneNode* pSceneNode, const Vector3f& position, const Vector3f& dPosition,
	       const Vector3f& rotation, const Vector3f& dRotation );

	/** Copy constructor */
	Actor( const Actor& actor );

	/** Destructor */
	virtual ~Actor();

	/** Accessor. */
	const SceneNode& getSceneNode() const;

	/** Accessor */
	const string& getName() const;

	/** Accessor */
	const Vector3f& getPositionVector3f() const;

	/** Accessor */
	const Vector3f& getRotationVector3f() const;

	virtual void tick( const double dt ) = 0;

	/** Sets the current OpenGL matrix for rendering/physics */
	void setGLMatrix( float* mat );

	/** Accessor */
	const float* getGLMatrix() const;

	/** Accessor. */
	float getBoundingSphereRadius() const;

	/** Accessor */
	const Vector3f& getBoundingSphereCenter() const;

	/** Mutator */
	void setName( const string& name );

	/** Causes a bounce back from another actor */
	void bounceBackFrom( Actor& other, float distance );
};
#endif

