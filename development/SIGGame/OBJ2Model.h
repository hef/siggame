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
#include "Material.h"

class OBJ2Model
{
	private:
	static std::vector<std::string> tokenize(const std::string& string, const std::string& token, const std::string::size_type& start);
	static std::map<std::string, Material> mtl2materials(const std::string& filename);
	public:
	static ModelSceneNode file(std::string const filename);
};
#endif
