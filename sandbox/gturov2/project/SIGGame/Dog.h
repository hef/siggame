class Dog
{
protected:
	float height;
	float weight;
	char* name;

public:
	Dog( const char* dogName );
	Dog( Dog& oldDog );
	~Dog();
	float getHeight() const;
	void setHeight( float newHeight );
	float getWeight() const;
	void setWeight( float newWeight );
	const char* getName() const;
	
};
