#ifndef Material_h
#define Material_h
#include "Vector3f.h"
class Material
{
	public:
		Material();
		Material(const Vector3f ambientColor, const Vector3f diffuseColor, const Vector3f specularColor, const float shininess);
		const Vector3f& getAmbientColor() const;
		void setAmbientColor( const Vector3f newAmbientColor);
		const Vector3f& getDiffuseColor() const;
		void setDiffuseColor( const Vector3f newDiffuseColor);
		const Vector3f& getSpecularColor() const;
		void setSpecularColor(const Vector3f newSpecularColor);
		const float&  getShininess() const;
		void setShininess(float const newShinieness);
	private:
		Vector3f ambientColor;
		Vector3f diffuseColor;
		Vector3f specularColor;
		float shininess;
};
#endif
