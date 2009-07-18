#ifndef GOLDENRETRIEVER_H
#define GOLDENRETRIEVER_H

class GoldenRetriever : public Dog
{
public:
	GoldenRetriever( char* theName, const float theHeight, const float theWeight )
{
	name = new char[17];
	strncpy( name, theName, 16 );
	name[16] = '\0';
	height = theHeight;
	weight = theWeight;
}
	virtual void bark() { std::cout << "Roof!" << std::endl; }
};

#endif