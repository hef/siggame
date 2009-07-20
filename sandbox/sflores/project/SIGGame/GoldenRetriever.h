#ifndef GOLD_RET
#define GOLD_RET
#include "Dog.h"

class GoldenRetriever : public Dog
{
public:
	GoldenRetriever( const char* name );
	~GoldenRetriever();

	// Memeber Function
	void bark() const;
};
#endif