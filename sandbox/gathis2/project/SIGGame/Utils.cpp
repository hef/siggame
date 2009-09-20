#include "Utils.h"
#include <iostream>


using namespace std;

Utils::Utils()
{
	cout<< "Constructor" << endl;
}

Utils::~Utils()
{ cout<< "Constructor" << endl; }

int Utils::sumUp(int n)
{
		   int sum=0;
		   if(n<0)
		   {
			   return 0;
		   }
		   for(int i=1;i<=n;i++)
			   sum = sum+i;
		   return sum;
}

Dog::Dog(const Dog& x) {
    height = x.height;
    weight = x.weight;
	strcpy(name,x.name);
}

Dog::Dog()
{
	name= new char[16];
	height=0.0;
	weight=0.0;
}

Dog::Dog(char* n)
{
	name= new char[16];
	height=0.0;
	weight=0.0;
	strcpy(name,n);
}

Dog::~Dog()
{
    delete [] name;
}

const Dog& Dog :: operator=(const Dog& x){
	strcpy(name, x.name);
	height = x.height;
	weight = x.weight;
	return *this;	
}


float Dog::getHeight()
{
	return height;
}

float Dog::getWeight()
{
	return weight;
}

char* Dog::getName()
{
	char* namecopy= new char[16];
	strcpy(namecopy,name);
	return namecopy;
}

void Dog::setHeight(float h)
{
	height = h;
}

void Dog::setWeight(float w)
{
	weight = w;
}
