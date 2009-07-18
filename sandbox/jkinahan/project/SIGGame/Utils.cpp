#include "Utils.h"

int Utils::sumUp(const int numberToSum)
{
	if (numberToSum > 0)
    {
		return numberToSum + sumUp(numberToSum - 1);
	}
	else
	{
		return 0;
	}
}