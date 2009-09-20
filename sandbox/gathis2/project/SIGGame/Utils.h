#ifndef UTILS_H
#define UTILS_H

class Utils //Sample Class for the C++ Tutorial 
{
	public: 
		Utils(); //Constructor for the C++ tutorial 
		~Utils(); //destructor for the C++ Tutorial 
		int sumUp(int n);
}; 

class Dog
{
public:
	float height;
	float weight;
	char* name;

	float getHeight();
	float getWeight();
	char* getName();
	void setHeight(float);
	void setWeight(float);
	void setName(char*);
	Dog(const Dog& x);
	const Dog& operator=(const Dog& );
	Dog();
	Dog(char* n);
	~Dog();

};

#endif
