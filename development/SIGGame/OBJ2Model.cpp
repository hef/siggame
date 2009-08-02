#include "OBJ2Model.h"
#include <iostream>
ModelSceneNode OBJ2Model::file(std::string const filename)
{
	
	std::vector<Vector3f> positionVertex;
	std::vector<Vector3f> normalVertex;
	std::vector<Vector3f> textureVertex;

	std::vector< std::vector<int> > faces;

	std::set< std::string > vertexNames;
	std::string line;
	std::ifstream myfile(filename.c_str());
	assert(myfile.is_open());
	while( ! myfile.eof() )
	{
		std::getline(myfile,line);
		switch(line[0])
		{
			case 'v' :
				if(line[1]==' ')
				{
					std::vector<std::string> tokens;
					tokens = tokenize(line," ",2);
					float point0, point1, point2;
					(std::stringstream)tokens[0] >> point0;
					(std::stringstream)tokens[1] >> point1;
					(std::stringstream)tokens[2] >> point2;
					vertices.push_back(Vector3f(point0,point1,point2));
					break;
				}
			case 'f' :
				if(line[1]==' ')
				{
					std::vector<std::string> tokens = tokenize(line," ",2);	
					std::vector<int> face;
					
					std::vector<std::string>::const_iterator i;
					for( i = tokens.begin(); i!=tokens.end(); ++i)
					{
						vertexNames.insert((*i));
						/*
						std::vector<std::string> subtoken = tokenize((*i),"/",0);
						int iValue;
						(std::stringstream)subtoken[0] >> iValue;
						face.push_back(iValue-1);
						*/
					}
				}
			default :
				//std::cout << line << std::endl;
				break;
		}
	}//eof
	ModelSceneNode model = ModelSceneNode(vertices);
	model.addMesh(Vector3f(0.5f,0.5f,0.5f),faces);
	return model;
	/*
	//print verices
	std::vector<Vector3f>::const_iterator i;
	for( i=vertices.begin(); i!=vertices.end(); ++i)
	{
		std::cout << i->elementArray[0] << " " << i->elementArray[1] << " " << i->elementArray[2] << std::endl;
	}

	//print faces
	std::vector< std::vector<int> >::const_iterator j;
	for(j=faces.begin(); j!=faces.end(); ++j)
	{
		std::vector<int>::const_iterator k;
		for(k=j->begin(); k!=j->end(); ++k)
		{
			std::cout << (*k) << " ";
		}
		std::cout << std::endl;

	}*/
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
