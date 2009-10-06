#include "Vertex.h"
Vertex::Vertex( const Vector3f position, const Vector3f texture, const Vector3f normal) :
	position(position),
	texture(texture),
	normal(normal)
{
}
const Vector3f& Vertex::getPosition() const
{
	return position;
}
const Vector3f& Vertex::getTexture() const
{
	return texture;
}
const Vector3f& Vertex::getNormal() const
{
	return normal;
}
