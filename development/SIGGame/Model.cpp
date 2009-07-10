#include "Model.h"
Model::Model()
{
	//load a default model for no-arg constuctor
	surfaces.push_back
	(	Surface
		(
			Vector3f(-0.5,-0.5,-0.5),
			Vector3f(0.5,-0.5,-0.5),
			Vector3f(0.5,0.5,0.5)
		)
	);
	surfaces.push_back
	(
		Surface
		(
			Vector3f(-0.5,-0.5,-0.5),
			Vector3f(-0.5,0.5,-0.5),
			Vector3f(0.5,-0.5,-0.5)
		)
	);
	surfaces.push_back
	(
		Surface
		(
			Vector3f(0.5,-0.5,-0.5),
			Vector3f(0.5,0.5,0.5),
			Vector3f(-0.5,0.5,-0.5)
		)
	);
	surfaces.push_back
	(
		Surface
		(
			Vector3f(-0.5,-0.5,-0.5),
			Vector3f(-0.5,0.5,-0.5),
			Vector3f(0.5,0.5,0.5)
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
