#include <vector>
#include "Input.h"

Input* Input::pInstance = NULL;
Input* Input::Instance()
{
	if( pInstance == NULL )
	{
		pInstance = new Input;
	}
	return pInstance;
}

Input::Input()
{

}

Input::~Input()
{
}

int tick( int dl )
{
	return 0;
}
bool shift()
{
	return false;
}
bool control()
{
	return false;
}
bool alt()
{
	return false;
}
bool key()
{
	return false;
}
bool kpKey()
{
	return false;
}