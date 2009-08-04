#include "Utilities.h"

int main()
{
	// Calls the default constructor, allocates space on the stack
	Utilities utilStackVersion;

	// Creates a pointer to a new Utilities allocated on the heap
	Utilities* utilHeapVersion = new Utilities;

	// Delete it for good measure
	delete utilHeapVersion;

	return 0;
}