#ifndef OBJ2Model_H
#define OBJ2Model_H
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include <vector>
#include "Vector3f.h"
#include "Surface.h"
#include <sstream>
#include "Model.h"

class OBJ2Model
{
	private:
	public:
	static Model file(std::string filename);
};
#endif
