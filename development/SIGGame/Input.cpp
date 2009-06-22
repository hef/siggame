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
	a = false;
	b = false;
	c = false;
	kPad1 = false;
	kPad2 = false;
	kPad3 = false;
	shift = false;
	control = false;
	alt = false;
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
	if( keys[SDLK_ESCAPE] || keyevent.type == SDL_QUIT ) 
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
		case SDLK_a:
			a = false;
			break;
		case SDLK_b:
			b = false;
			break;
		case SDLK_c:
			c = false;
			break;
		case SDLK_KP1:
			kPad1 = false;
			break;
		case SDLK_KP2:
			kPad2 = false;
			break;
		case SDLK_KP3:
			kPad3 = false;
			break;
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
		case SDLK_a:
			a = true;
			break;
		case SDLK_b:
			b = true;
			break;
		case SDLK_c:
			c = true;
			break;
		case SDLK_KP1:
			kPad1 = true;
			break;
		case SDLK_KP2:
			kPad2 = true;
			break;
		case SDLK_KP3:
			kPad3 = true;
			break;
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
bool Input::keyDown( char aKey ) 
{
	switch ( aKey )
	{
		case 'a':
			return a;
			break;
		case 'b':
			return b;
			break;
		case 'c':
			return c;
			break;
		default:
			return false;
	}

}
bool Input::kpKeyDown( char aKey ) 
{
	switch ( aKey )
	{
		case '1':
			return kPad1;
			break;
		case '2':
			return kPad2;
			break;
		case '3':
			return kPad3;
			break;
		default:
			return false;
	}
}

