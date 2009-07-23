#include "Dog.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	Dog* Daisy = new Dog(4.0f, 15.0f, "Daisy");
	cout << "Daisy is " << Daisy->getHeight() << " meters high." << endl;
	cout << "Daisy is " << Daisy->getWeight() << " pounds." << endl;
	cout << "Sally's name really is " << Daisy->getName() << "." << endl;
	system("PAUSE"); //to see the output
	return 0;
};