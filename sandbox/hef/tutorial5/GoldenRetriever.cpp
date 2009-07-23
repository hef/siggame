#include "GoldenRetriever.h"
GoldenRetriever::GoldenRetriever( char const * const newName, int const weight, int const height ) : 
	Dog(newName, weight, height)
{
}
void GoldenRetriever::bark()
{
	std::cout << "Roof!" << std::endl;
}
