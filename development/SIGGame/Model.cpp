#include "Model.h"
Model::Model()
{
	//load a default model for no-arg constuctor
	surfaces.push_back
	(	Surface
		(
			Vector3f(0,0,0),
			Vector3f(1,0,0),
			Vector3f(1,1,1)
		)
	);
	surfaces.push_back
	(
		Surface
		(
			Vector3f(0,0,0),
			Vector3f(0,1,0),
			Vector3f(1,0,0)
		)
	);
	surfaces.push_back
	(
		Surface
		(
			Vector3f(1,0,0),
			Vector3f(1,1,1),
			Vector3f(0,1,0)
		)
	);
	surfaces.push_back
	(
		Surface
		(
			Vector3f(0,0,0),
			Vector3f(0,1,0),
			Vector3f(1,1,1)
		)
	);

}
Model::Model(const Model& model) :
	surfaces(model.surfaces)
{
}
Model::~Model()
{
}
const std::vector<Surface>& Model::getSurfaces() const
{
	return surfaces;
}
