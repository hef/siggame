#ifndef PrarieDog_H
#define PrarieDog_H
#include "Dog.h"
#include <iostream>
class PrairieDog : public Dog
{
	public:
		PrairieDog(const Dog&);
		virtual void bark();

};
#endif
