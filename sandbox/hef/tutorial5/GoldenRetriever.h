#ifndef GoldenRetriever_H
#define GoldenRetriever_H
#include "Dog.h"
#include <iostream>
class GoldenRetriever : public Dog
{
	public:
		GoldenRetriever(char const * const name, const int height, const int weight);
		virtual void bark();
};
#endif
