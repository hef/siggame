#include "Utils.h"

int main()
{
	Utils* utilHeap = new Utils; // heap implementation of Utilities
	Utils utilStack; // stack implementation of Utilities

	delete utilHeap;

	return 0;
}