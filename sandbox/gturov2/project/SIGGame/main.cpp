#include "Utils.h"

int main()
{
	Utils stackUtil;
	Utils* heapUtil = new Utils;
	delete(heapUtil);
	return 0;
}