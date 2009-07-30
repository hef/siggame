#include "OBJ2Model.h"
#include <iostream>
Model OBJ2Model::file(std::string filename)
{
	std::vector<Vector3f> vertices;
	std::vector<int> face;
	std::vector< std::vector<int> > faces;
	std::string line;
	std::ifstream myfile(filename.data());
	std::vector<Surface> surfaces;
	assert(myfile.is_open());
	size_t start=0;
	size_t end;
	int count = 0;
	while( ! myfile.eof() )
	{
		std::getline(myfile,line);
		std::cout << line << std::endl;
		switch(line[0])
		{
			case 'v' :
				if(line[1]==' ')
				{	
					start = 2;// skip 2 letters, we know what they are.
					end = start;
					count = 0;
					float point;
					vertices.push_back(Vector3f(0.0f, 0.0f, 0.0f));
					while(end!=std::string::npos)
					{
						end = line.find(' ',start);
						(std::stringstream)line.substr(start,end-start) >> point;
						vertices.back()[count]=point;
						++count;
						start = end+1;

					}
					break;
				}
			case 'f' :
				if(line[1]==' ')
				{
					start = 2;
					end = start;
					int firstIndex;
					int secondIndex;
					int thirdIndex;
					end = line.find(' ',start);
					(std::stringstream)line.substr(start,end-start) >> firstIndex;
					end = line.find(' ',start);
					(std::stringstream)line.substr(start,end-start) >> secondIndex;
					while(end!=std::string::npos)
					{
						end = line.find(' ',start);
						(std::stringstream)line.substr(start,end-start) >> thirdIndex;
						start = end+1;
						face.clear();
						face.push_back(firstIndex);
						face.push_back(secondIndex);
						face.push_back(thirdIndex);
						faces.push_back(face);
						secondIndex=thirdIndex;

					}
					break;
				}


			default :
				//std::cout << line << std::endl;
				break;
		}
	}//eof

	std::vector< std::vector<int> >::const_iterator i;
	for( i = faces.begin(); i != faces.end(); ++i)
	{
		surfaces.push_back
		(
			Surface
			(
				Vector3f
				(
					vertices.at(i->at(0)-1).at(0),
					vertices.at(i->at(0)-1).at(1),
					vertices.at(i->at(0)-1).at(2)
				),
				Vector3f
				(
					vertices.at(i->at(1)-1).at(0),
					vertices.at(i->at(1)-1).at(1),
					vertices.at(i->at(1)-1).at(2)
				),
				Vector3f
				(
					vertices.at(i->at(2)-1).at(0),
					vertices.at(i->at(2)-1).at(1),
					vertices.at(i->at(2)-1).at(2)
				),
				//color red for now
				Vector3f(1,0,0)
			)
		);
	}
	return Model(surfaces);
	
}
