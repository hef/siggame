#ifndef DOG_H
#define DOG_H
#include <iostream> // for derived classes
class Dog
{
	public:
		// Constructors
		Dog();
		Dog( char* theName, const float theHeight, const float theWeight );
		~Dog();
		Dog( const Dog& dog );
		Dog& Dog::operator=( const Dog& dog );

		// Functions
		char const * const getName() const;
		float getHeight() const;
		float getWeight() const;

		void setHeight( const float newHeight );
		void setWeight( const float newWeight );
		
		virtual void bark() = 0; // Pure virtual for bark

	private:
		float height;
		float weight;
		char* name;

};

#endif

