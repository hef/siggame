#include "OBJ2Model.h"
ModelSceneNode OBJ2Model::file(std::string const filename)
{
	
	std::vector<Vector3f> positionVertexVector;
	std::vector<Vector3f> normalVertexVector;
	std::vector<Vector3f> textureVertexVector;

	std::vector< std::vector<int> > faces;

	std::set< std::string > vertexNames;
	std::string line;
	std::ifstream myfile(filename.c_str());
	assert(myfile.is_open());
	std::vector<std::string> tokens;
	float point0, point1, point2;
	while( ! myfile.eof() )
	{
		std::getline(myfile,line);
		tokens=tokenize(line," ",0);
		if(tokens[0]=="v" )
		{
			(std::stringstream)tokens[1] >> point0;
			(std::stringstream)tokens[2] >> point1;
			(std::stringstream)tokens[3] >> point2;
			positionVertexVector.push_back(Vector3f(point0,point1,point2));

		}
		else if (tokens[0]=="vn")
		{
			(std::stringstream)tokens[1] >> point0;
			(std::stringstream)tokens[2] >> point1;
			(std::stringstream)tokens[3] >> point2;
			normalVertexVector.push_back(Vector3f(point0,point1,point2));
		}
		else if (tokens[0]=="vt")
		{
			(std::stringstream)tokens[1] >> point0;
			(std::stringstream)tokens[2] >> point1;
			(std::stringstream)tokens[3] >> point2;
			textureVertexVector.push_back(Vector3f(point0,point1,point2));
		}
		else if (tokens[0]=="f")
		{
			std::vector<std::string>::const_iterator i;
			for( i = tokens.begin(); i!=tokens.end(); ++i)
			{
				vertexNames.insert((*i));
			}
		}
		else if (tokens[0]=="usemtl")
		{

		}
	}//eof
	ModelSceneNode model = ModelSceneNode();
	return model;
}
std::vector<std::string> OBJ2Model::tokenize(std::string string, std::string token, long unsigned int start)
{
	long unsigned int end=start;
	std::vector<std::string> tokens;
	while(end!=std::string::npos)
	{
		end = string.find(token,start);
		tokens.push_back(string.substr(start,end-start));
		start=end+token.size();
	}
	return tokens; 
}
