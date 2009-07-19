#ifndef PRAIRIE_D
#define PRAIRIE_D
#include "Dog.h"

class PrairieDog : public Dog
{
public:
	PrairieDog( const char* name );
	~PrairieDog();

	// Member Function
	void bark() const;
};
#endif