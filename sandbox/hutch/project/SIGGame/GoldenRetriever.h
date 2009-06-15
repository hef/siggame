#ifndef GOLDENRETRIEVER_H
#define GOLDENRETRIEVER_H

class GoldenRetriever : public Dog
{
public:
	virtual void bark() { std::cout << "Roof!" << std::endl; }
};

#endif