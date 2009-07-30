#include "Utils.h"

Utils::Utils(void)
{
}

Utils::~Utils(void)
{
}

int Utils::sumUp(int parameter) 
{
	if(parameter == 1)
	{
		return 1;
	}
	else
	{
		return ((sumUp(parameter - 1)) + parameter);
	}
}
