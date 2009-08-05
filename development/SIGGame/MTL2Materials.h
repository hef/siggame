#ifndef MTL2Materials_H
#define MTL2Materials_H
#include <iostream>
#include <fstream>
#include <string>
#include "Vector3f.h"
#include <sstream>
#include <map>
#include <vector>
#include "Material.h"

class MTL2Materials
{
	private:
	static std::vector<std::string> tokenize(std::string string, std::string token, long unsigned int start);
	public:
	static std::map<std::string, Material> file(std::string filename);
};
#endif
