/** Input.cpp
Based off of input for spinning cube, current keyboard state is updated using
get input. Key states are set to true or false depending on if they are down or up.
Contains get methods to check that return true if key is pressed. To check for more keys,
add the keys to releaseKeys and setKeys.

*/

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

Input::Input() // All keys are up
{
	keys = NULL;
	shift = false;
	control = false;
	alt = false;
	key = false;
	kpKey = false;
	up = false;
	down = false;
	right = false;
	left = false;
}

Input::~Input()
{
	delete pInstance;
}

bool Input::getInput()
{
	SDL_Event keyevent;
	SDL_PollEvent( &keyevent );
	Input::keys = SDL_GetKeyState(NULL);
	//If escape is pressed, exit program
	if( keys[SDLK_ESCAPE] ) 
	{
		return false;
	}
	// Key pressed, update members
	if (keyevent.type == SDL_KEYDOWN)
	{
		Input::setKeys(keyevent);
}
	// Key released, update members
	if ( keyevent.type == SDL_KEYUP )
{
		Input::releaseKeys(keyevent);
	}
	return true;
}

bool Input::releaseKeys(SDL_Event keyevent)
{
	// Check status of keys, updated members accordingly
	switch(keyevent.key.keysym.sym)
	{
	  case SDLK_LEFT:
		left = false;
		break;
	  case SDLK_RIGHT:
		right = false;
		break;
	  case SDLK_UP:
		up = false;
		break;
	  case SDLK_DOWN:
		down = false;
		break;
	  case SDLK_RSHIFT:
	  case SDLK_LSHIFT:
		shift = false;
		break;
	  case SDLK_RALT:
	  case SDLK_LALT:
		alt = false;
		break;
	  case SDLK_RCTRL:
	  case SDLK_LCTRL:
		control = false;
		break;
	  default:
		break;
	}
	return true;
}

bool Input::setKeys(SDL_Event keyevent)
{
	// Check status of keys, updated members accordingly
	switch(keyevent.key.keysym.sym)
{
	  case SDLK_LEFT:
		left = true;
		break;
	  case SDLK_RIGHT:
		right = true;
		break;
	  case SDLK_UP:
		up = true;
		break;
	  case SDLK_DOWN:
		down = true;
		break;
	  case SDLK_RSHIFT:
	  case SDLK_LSHIFT:
		shift = true;
		break;
	  case SDLK_RALT:
	  case SDLK_LALT:
		alt = true;
		break;
	  case SDLK_RCTRL:
	  case SDLK_LCTRL:
		control = true;
		break;
	  default:
		break;
	}
	return true;
}

bool Input::shiftDown() { return shift; }
bool Input::controlDown() { return control; }
bool Input::altDown() { return alt; }
bool Input::leftDown() { return left; }
bool Input::rightDown() { return right; }
bool Input::upDown() { return up; }
bool Input::downDown() { return down; }
// The following two methods still need to be written
bool Input::keyDown(char aKey) 
{
	aKey = aKey;
	return key; 
}
bool Input::kpKeyDown(char aKey) 
{
	aKey = aKey;
	return kpKey; 
}