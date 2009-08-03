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

class OBJ2Model
{
	private:
	static std::vector<std::string> tokenize(std::string string, std::string token, long unsigned int start);
	std::vector<Vector3f> positionVertexVector;
	std::vector<Vector3f> normalVertexVector;
	std::vector<Vector3f> textureVertexVector;
	std::map<std::string, int> vertexNames;
	vertexVector
	public:
	static ModelSceneNode file(std::string filename);
};
#endif
