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

class OBJ2Model
{
	private:
	static std::vector<std::string> tokenize(std::string string, std::string token, unsigned int start);
	public:
	static ModelSceneNode file(std::string filename);
};
#endif
