#ifndef IMPND_H
#define IMPND_H
#include "Dog.h"
#include <map>
#include <string>
#include <iostream>
using std::string;
using std::map;
using std::cout;
using std::endl;

enum RETURN_CODE {
	FAIL,
	OK
};

class Impound
{
public:
	~Impound();
	void destroy();
	static Impound* getInstance();
	RETURN_CODE addDog( const Dog* dog );
	RETURN_CODE removeDog( const Dog* dog );
	RETURN_CODE removeDog( const char* name );
	RETURN_CODE removeDog( const string name );
	bool findDog( const Dog* dog );
	bool findDog( const char* name );
	bool findDog( const string name );
	void visitImpound() const;
protected:
	Impound();
	Impound( const Impound& other );
	Impound& operator=( const Impound& rhs );
private:
	static Impound* pInstance;
	map< const char*, const Dog* > cells;
};
#endif