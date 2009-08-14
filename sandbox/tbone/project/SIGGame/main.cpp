#include "Utils.h"

int main()
{
	// Calls the default constructor, allocates space on the stack
	Utils utilStackVersion;

	// Creates a pointer to a new Utils allocated on the heap
	Utils* utilHeapVersion = new Utils;

	// Delete it for good measure
	delete utilHeapVersion;

	return 0;
}