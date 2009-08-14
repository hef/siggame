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
/**
 * OBJ2Model reads an obj file from disk.  it the obj file refereneces a 
 * mtllib file (it should) that mtl file will also be read.
 * this supports a subset of all OBJ options, it will probably fail in the
 * following caes:
 * faces that do not contain 2 slashes (//)
 * faces that use negative indices.
 * this also does not yet support reading maps (e.g. texutre maps) from disk
 * yet.
 * */
class OBJ2Model
{
private:
	static std::vector<std::string> tokenize( const std::string& string, const std::string& token, const std::string::size_type& start );
	static std::map<std::string, Material> mtl2materials( const std::string& filename );
public:
	static ModelSceneNode file( std::string const filename );
};
#endif

