#include "Model.h"
Model::Model()
{
	//load a default model for no-arg constuctor

	//TOP
	surfaces.push_back
	(
	        Surface
	        (
	                Vector3f( -.5, -.5, .5 ),
	                Vector3f( .5, -.5, .5 ),
	                Vector3f( -.5, .5, .5 ),
					Vector3f( 1, 0, 0 )
	        )
	);

	surfaces.push_back
	(
	        Surface
	        (
	                Vector3f( .5, .5, .5 ),
	                Vector3f( .5, -.5, .5 ),
	                Vector3f( -.5, .5, .5 ),
					Vector3f( 1, 0, 0 )
	        )
	);

	//BOTTOM
	surfaces.push_back
	(
	        Surface
	        (
	                Vector3f( -.5, -.5, -.5 ),
	                Vector3f( .5, -.5, -.5 ),
	                Vector3f( -.5, .5, -.5 ),
					Vector3f( 0, 0, 1 )
	        )
	);
	surfaces.push_back
	(
	        Surface
	        (
	                Vector3f( .5, .5, -.5 ),
	                Vector3f( .5, -.5, -.5 ),
	                Vector3f( -.5, .5, -.5 ),
					Vector3f( 0, 0, 1 )
	        )
	);

	//FRONT
	surfaces.push_back
	(
	        Surface
	        (
	                Vector3f( -.5, -.5, .5 ),
	                Vector3f( .5, -.5, -.5 ),
	                Vector3f( -.5, -.5, -.5 ),
					Vector3f( 0, 1, 0 )
	        )
	);

	surfaces.push_back
	(
	        Surface
	        (
	                Vector3f( .5, -.5, -.5 ),
	                Vector3f( .5, -.5, .5 ),
	                Vector3f( -.5, -.5, .5 ),
					Vector3f( 0, 1, 0 )
	        )
	);

	//BACK
	surfaces.push_back
	(
	        Surface
	        (
	                Vector3f( -.5, .5, .5 ),
	                Vector3f( .5, .5, -.5 ),
	                Vector3f( -.5, .5, -.5 ),
					Vector3f( 1, 1, 0 )
	        )
	);
	surfaces.push_back
	(
	        Surface
	        (
	                Vector3f( .5, .5, -.5 ),
	                Vector3f( .5, .5, .5 ),
	                Vector3f( -.5, .5, .5 ),
					Vector3f( 1, 1, 0 )
	        )
	);

	//LEFT
	surfaces.push_back
	(
	        Surface
	        (
	                Vector3f( -.5, -.5, .5 ),
	                Vector3f( -.5, .5, .5 ),
	                Vector3f( -.5, .5, -.5 ),
					Vector3f( 1, 1, 1 )
	        )
	);

	surfaces.push_back
	(
	        Surface
	        (
	                Vector3f( -.5, -.5, -.5 ),
	                Vector3f( -.5, .5, -.5 ),
	                Vector3f( -.5, -.5, .5 ),
					Vector3f( 1, 1, 1 )
	        )
	);

	//RIGHT
	surfaces.push_back
	(
	        Surface
	        (
	                Vector3f( .5, -.5, .5 ),
	                Vector3f( .5, .5, .5 ),
	                Vector3f( .5, .5, -.5 ),
					Vector3f( .5, 1, 1 )
	        )
	);

	surfaces.push_back
	(
	        Surface
	        (
	                Vector3f( .5, -.5, -.5 ),
	                Vector3f( .5, .5, -.5 ),
	                Vector3f( .5, -.5, .5 ),
					Vector3f( .5, 1, 1 )
	        )
	);

}
Model::Model( const Model& model ) :
	surfaces( model.surfaces )
{
}
Model::~Model()
{
}
const std::vector<Surface>& Model::getSurfaces() const
{
	return surfaces;
}
