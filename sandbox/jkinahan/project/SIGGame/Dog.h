#ifndef DOG_H
#define DOG_H

class Dog
{
public:
	Dog();
	Dog( const Dog &thisDog );
	Dog( float height, float weight, const char* tagID );
	~Dog();
	float getHeight();
	float getWeight();
	const char* getTagID() const;
	void setHeight( float height );
	void setWeight( float weight );

private:
	float dogHeight;
	float dogWeight;
	const char* dogTagID;
};

#endif /* DOG_H */