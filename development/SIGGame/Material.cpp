#include "Material.h"
Material::Material() : 
	ambientColor(Vector3f(0.2f,0.2f,0.2f)),
	diffuseColor(Vector3f(0.8f,0.8f,0.8f)),
	specularColor(Vector3f(1.0f,1.0f,1.0f)),
	shininess(0.0f)
{
}
Material::Material(const Vector3f ambientColor, const Vector3f diffuseColor, const Vector3f specularColor, const float shininess) :
	ambientColor(ambientColor),
	diffuseColor(diffuseColor),
	specularColor(specularColor),
	shininess(shininess)
{
}
const Vector3f& Material::getAmbientColor() const
{
	return ambientColor;
}
const Vector3f& Material::getDiffuseColor() const
{
	return diffuseColor;
}
const Vector3f& Material::getSpecularColor() const
{
	return specularColor;
}
const float& Material::getShininess() const
{
    return shininess;
}
