#ifndef OBJ2Model_H
#define OBJ2Model_H
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include <vector>
#include "Vector3f.h"
#include "ModelSceneNode.h"
#include <sstream>
#include <map>
#include "Vertex.h"

class OBJ2Model
{
	private:
	static std::vector<std::string> tokenize(std::string string, std::string token, long unsigned int start);
	static std::map<std::string, Materials> mtl2materials(std::string filename);
	public:
	static ModelSceneNode file(std::string filename);
};
#endif
