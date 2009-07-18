#ifndef IMPOUND_H
#define IMPOUND_H
#include <vector>
#include <string>
#include "Dog.h"
enum dogEnum
{
	FAILED,
	SUCCESS
};
class Impound
{
public:
	static Impound* Instance();
	dogEnum addDog( Dog * pDog );
	dogEnum removeDog( Dog const * const pDog );
	dogEnum removeDog( std::string dogName );
	dogEnum removeDog( char const * const dogName );
	bool findDog( Dog const * const pDog );
	bool findDog( std::string dogName );
	bool findDog( char const * const dogName );
	void const visitImpound();
	void destroy();
protected:
	Impound();
	~Impound();
	Impound( const Impound& );
	Impound& operator= (const Impound& );
private:
	static Impound* pinstance;
	std::vector<Dog*> dogVector;
};

#endif

