#ifndef DOG_H
#define DOG_H


class Dog{
public:
	Dog();
	Dog(float height,float weight, char* name);
	~Dog();
	Dog(const Dog& oldDog);
	float getHeight() const;
	float getWeight() const;
	const char * const getName() const;
	void setHeight(float height);
	void setWeight(float weight);

private:
	float itsHeight;
	float itsWeight;
	char* itsName;

};

#endif //DOG_H