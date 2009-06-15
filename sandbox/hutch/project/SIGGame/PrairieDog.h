#ifndef PRAIRIEDOG_H
#define PRAIRIEDOG_H

class PrairieDog : public Dog
{
public:
	virtual void bark() { std::cout << "Yelp!" << std::endl; }
};

#endif