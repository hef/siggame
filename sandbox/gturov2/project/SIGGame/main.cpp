#include "Utilities.h"

int main()
{
	Utilities stackUtil;
	Utilities* heapUtil = new Utilities;
	delete(heapUtil);
	return 0;
}