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
	for ( unsigned int c = 0; c < ASCII_TABLE_SIZE; c++ )
	{
		keyArray[c] = false;
	}
	for ( unsigned int c = 0; c < KEYPAD_SIZE; c++ )
	{
		kPadArray[c] = false;
	}
	keys = NULL;
	shift = false;
	control = false;
	alt = false;
	upArrow = false;
	downArrow = false;
	rightArrow = false;
	leftArrow = false;
}

Input::~Input()
{
	delete pInstance;
}

bool Input::getInput()
{
	SDL_Event keyevent;
	SDL_PollEvent( &keyevent );
	Input::keys = SDL_GetKeyState( NULL );
	//If escape is pressed, exit program
	if( keys[SDLK_ESCAPE] || keyevent.type == SDL_QUIT )
	{
		return false;
	}
	// Key pressed, update members
	if ( keyevent.type == SDL_KEYDOWN )
	{
		Input::setKeys( keyevent );
	}
	// Key released, update members
	if ( keyevent.type == SDL_KEYUP )
	{
		Input::releaseKeys( keyevent );
	}
	return true;
}

bool Input::releaseKeys( SDL_Event keyevent )
{
	unsigned int key = keyevent.key.keysym.sym; // to clean up code
	// Check status of single character keys, update members accordingly
	if ( key <= ASCII_TABLE_SIZE )
	{
		keyArray[ key ] = false;
	}
	// Check status of keypad numbers, update members accordingly
	else if ( key >= ASCII_TABLE_SIZE && key <= SDL_KEYPAD_OFFSET + KEYPAD_SIZE )
	{
		kPadArray[ key - SDL_KEYPAD_OFFSET ] = false;
	}
	// Check status rest of keys, updated members accordingly
	switch( key )
	{
	case SDLK_LEFT:
		leftArrow = false;
		break;
	case SDLK_RIGHT:
		rightArrow = false;
		break;
	case SDLK_UP:
		upArrow = false;
		break;
	case SDLK_DOWN:
		downArrow = false;
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

bool Input::setKeys( SDL_Event keyevent )
{
	unsigned int key = keyevent.key.keysym.sym; // To make the code cleaner
	// Check status of single character keys, update members accordingly
	if ( key <= ASCII_TABLE_SIZE )
	{
		keyArray[ key ] = true;
	}
	// Check status of keypad numbers, update members accordingly
	else if ( key >= ASCII_TABLE_SIZE && key <= SDL_KEYPAD_OFFSET + 10 )
	{
		kPadArray[ key - SDL_KEYPAD_OFFSET ] = true;
	}
	// Check status of rest of keys, update members accordingly
	else switch( key )
		{
		case SDLK_LEFT:
			leftArrow = true;
			break;
		case SDLK_RIGHT:
			rightArrow = true;
			break;
		case SDLK_UP:
			upArrow = true;
			break;
		case SDLK_DOWN:
			downArrow = true;
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
bool Input::leftArrowDown() { return leftArrow; }
bool Input::rightArrowDown() { return rightArrow; }
bool Input::upArrowDown() { return upArrow; }
bool Input::downArrowDown() { return downArrow; }
bool Input::keyDown( char aKey ) { return keyArray[ static_cast<int>(aKey) ]; }
bool Input::kpKeyDown( int aKey ) { return kPadArray[ aKey ]; }

