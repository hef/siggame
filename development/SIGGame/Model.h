#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "Surface.h"
#include "Vector3f.h"
/**
   A model has a std::vector of surfaces
   All models are composed of triangles
 */
class Model
{
private:
	std::vector<Surface> surfaces;
public:
	///loads a sample model
	Model();
	Model( const Model& model );
	~Model();
	const std::vector<Surface>& getSurfaces() const;
};
#endif
