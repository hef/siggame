#include "MTL2Materials.h"
std::map<std::string, Material> MTL2Materials::file(std::string const filename)
{

	std::map<std::string, Material> materialMap;
	std::string line;
	std::ifstream myfile(filename.c_str());
	assert(myfile.is_open());
	std::vector<std::string> tokens;
	while( ! myfile.eof() )
	{
		std::getline(myfile,line);
		tokens=tokenize(line," ",0);
		if(tokens[0]=="v" )
		{
		}
	}//eof


	return materialMap;
}
std::vector<std::string> MTL2Materials::tokenize(std::string string, std::string token, long unsigned int start)
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
