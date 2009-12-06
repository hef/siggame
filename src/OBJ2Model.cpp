#include "OBJ2Model.h"
ModelSceneNode OBJ2Model::file( std::string const filename )
{

	std::vector<Vector3f> positionVertexVector;
	std::vector<Vector3f> normalVertexVector;
	std::vector<Vector3f> textureVertexVector;
	std::map<std::string, int> vertexNames;
	int vertexNamesIndex = 0;
	std::vector<Vertex> vertexVector;
	std::map<std::string, Material> materialMap;
	std::vector<Mesh> meshVector;
	std::string previousMaterial = "";

	std::vector< std::vector<int> > faces;
	std::string line;
	std::ifstream myfile( ("data/models/" + filename).c_str());
	assert( myfile.is_open());
	std::vector<std::string> tokens;
	float point0, point1, point2;
	int index0, index1, index2;
	while ( !myfile.eof() )
	{
		std::getline( myfile, line );
		tokens = tokenize( line, " ", 0 );
		if ( tokens.empty())
			continue;
		if ( tokens[0] == "v" )
		{
			(std::stringstream)tokens[1] >> point0;
			(std::stringstream)tokens[2] >> point1;
			(std::stringstream)tokens[3] >> point2;
			positionVertexVector.push_back( Vector3f( point0, point1, point2 ));

		}
		else if ( tokens[0] == "vn" )
		{
			(std::stringstream)tokens[1] >> point0;
			(std::stringstream)tokens[2] >> point1;
			(std::stringstream)tokens[3] >> point2;
			//it seems that normals point inward on obj files. invert it
			normalVertexVector.push_back( Vector3f( point0 * -1, point1 * -1, point2 * -1 ));
		}
		else if ( tokens[0] == "vt" )
		{
			(std::stringstream)tokens[1] >> point0;
			(std::stringstream)tokens[2] >> point1;
			//(std::stringstream)tokens[3] >> point2;
			textureVertexVector.push_back( Vector3f( point0, point1, 0.0f ));
		}
		else if ( tokens[0] == "f" )
		{
			std::vector<int> face;
			std::vector<std::string>::const_iterator i;
			for ( i = tokens.begin()+1; i != tokens.end(); ++i )
			{
				if ( vertexNames.find( (*i) ) == vertexNames.end() ) // if (*i) not found
				{

					vertexNames[ (*i) ] = static_cast<int>(++vertexNamesIndex);
					std::vector<std::string> faceToken;
					faceToken = moreTokenize( (*i), "/", 0 );
					(std::stringstream)faceToken[0] >> index0;
					(std::stringstream)faceToken[1] >> index1;
					(std::stringstream)faceToken[2] >> index2;
					//TODO this is to make textureless blender exports work.
					//there is probably a better way
					if( textureVertexVector.empty() )
					{
						textureVertexVector.push_back(Vector3f(0.0f,0.0f,0.0f));
					}
					if(faceToken[1]=="")
					{
						index1=1;
					}

					vertexVector.push_back
					(
					        Vertex
					        (
					                positionVertexVector[ index0-1 ],
					                textureVertexVector[ index1-1 ],
					                normalVertexVector[ index2-1 ]
					        )
					);
				}
				face.push_back( vertexNames[ (*i) ] -1 );
			}
			faces.push_back( face );

		}
		else if ( tokens[0] == "usemtl" )
		{
			//close off previous material group
			if ( faces.size() > 0 )
			{
				meshVector.push_back
				                    ( Mesh( materialMap[previousMaterial], faces ));
				faces.clear();
			}
			previousMaterial = tokens[1];


		}
		else if ( tokens[0] == "mtllib" )
		{
			materialMap = mtl2materials( "data/models/" + tokens[1] );
		}
	} //eof
	meshVector.push_back( Mesh( materialMap[previousMaterial], faces ));
	ModelSceneNode model = ModelSceneNode( vertexVector, meshVector );
	return model;
}
std::map<std::string, Material> OBJ2Model::mtl2materials( const std::string& filename )
{
	std::map<std::string, Material> materialMap;
	std::string line;
	std::ifstream myfile( filename.c_str());
	assert( myfile.is_open());
	std::vector<std::string> tokens;
	//tokens = tokenize(line," ",0);
	std::string currentMaterial = "";
	float point0, point1, point2;

	while ( !myfile.eof() )
	{
		std::getline( myfile, line );
		tokens = tokenize( line, " ", 0 );
		if ( tokens.empty())
			continue;
		if ( tokens[0] == "newmtl" )
		{
			materialMap[tokens[1]] = Material();
			currentMaterial = tokens[1];
		}
		else if ( tokens[0] == "Ka" )
		{
			(std::stringstream)tokens[1] >> point0;
			(std::stringstream)tokens[2] >> point1;
			(std::stringstream)tokens[3] >> point2;
			materialMap[currentMaterial].setAmbientColor( Vector3f( point0, point1, point2 ));
		}
		else if ( tokens[0] == "Kd" )
		{
			(std::stringstream)tokens[1] >> point0;
			(std::stringstream)tokens[2] >> point1;
			(std::stringstream)tokens[3] >> point2;
			materialMap[currentMaterial].setDiffuseColor( Vector3f( point0, point1, point2 ));
		}
		else if ( tokens[0] == "Ks" )
		{
			(std::stringstream)tokens[1] >> point0;
			(std::stringstream)tokens[2] >> point1;
			(std::stringstream)tokens[3] >> point2;
			materialMap[currentMaterial].setSpecularColor( Vector3f( point0, point1, point2 ));
		}
		else if ( tokens[0] == "Ns" )
		{
			(std::stringstream)tokens[1] >> point0;
			materialMap[currentMaterial].setShininess( point0 );
		}
	} //eof
	return materialMap;

}
//this version of tokenize will skip repeated delimiters
std::vector<std::string> OBJ2Model::tokenize( const std::string& string, const std::string& delimiters, const std::string::size_type& startingPoint )
{
	std::vector<std::string> tokens;
	std::string::size_type start = string.find_first_not_of( delimiters, startingPoint );
	std::string::size_type end = string.find_first_of( delimiters, start );
	while ( end != std::string::npos || std::string::npos != start )
	{
		tokens.push_back( string.substr( start, end-start ));
		start = string.find_first_not_of( delimiters, end );
		end = string.find_first_of( delimiters, start );
	}
	return tokens;
}
/** This version will create empty nodes in the vector for repated delimiters
 *  this one was created to handle faces that sometimes don't have textures
 *
 */
std::vector<std::string> OBJ2Model::moreTokenize(const std::string& string, const std::string& delimiters, const std::string::size_type& startingPoint)
{
	std::vector<std::string> tokens;
	std::string::size_type start = startingPoint;
	std::string::size_type end = string.find_first_of( delimiters, start );
	while (end != std::string::npos)
	{
		end=string.find_first_of( delimiters, start );
		tokens.push_back( string.substr( start, end-start ));
		start=end+1;
	}
	return tokens;
}
