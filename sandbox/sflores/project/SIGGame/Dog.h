#ifndef DOG_H
#define DOG_H

class Dog
{
public:
	// Constructors
	Dog( const char* name );
	Dog( const Dog& otherDog );
	// Destructor
	~Dog();
	// Assignment 
	const Dog& operator=( const Dog& otherDog );
	
	// Accessors
	float getHeight() const;
	float getWeight() const;
	const char* getName() const;

	// Mutators
	void setHeight( const float newHeight );
	void setWeight( const float newWeight );

private:
	// Constant
	const static int MAXSIZE = 16;

	// Prohibited methods
	void setHeight( const double );
	void setHeight( const int );
	void setHeight( const unsigned int );
	void setHeight( const long );

	void setWeight( const double );
	void setWeight( const int );
	void setWeight( const unsigned int );
	void setWeight( const long );
	explicit Dog();

	// Class variables
	char* NAME;
	float height;		// In meters
	float weight;		// In Lbs??
};
#endif