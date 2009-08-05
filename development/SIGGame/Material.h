#ifndef Material_h
#define Material_h
#include "Vector3f.h"
class Material
{
	public:
		Material();
		Material(const Vector3f ambientColor, const Vector3f diffuseColor, const Vector3f specularColor, const float shininess);
		const Vector3f& getAmbientColor() const;
		const Vector3f& getDiffuseColor() const;
		const Vector3f& getSpecularColor() const;
		const float&  getShininess() const;
	private:
		Vector3f ambientColor;
		Vector3f diffuseColor;
		Vector3f specularColor;
		float shininess;
};
#endif
