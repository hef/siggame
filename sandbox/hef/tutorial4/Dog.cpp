#include "Dog.h"
Dog(std::string newName)
{
  name=newName;
}

int Dog::getHeight() const
{
	return height;
}
void Dog::setHeight(const int n)
{
	height=n;
        return;
}
int Dog::getWeight() const
{
	return weight;
}
void Dog::setWeight(const int n)
{
        height=n;
	return;
}
std::string Dog::getName() const
{
	return name;
}
