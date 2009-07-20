# include <stdlib.h>
#include "SDL.h"

#ifndef _INPUT_H
#define _INPUT_H

class Input
{

public:
	static Input* Instance();
	~Input();

	// Functions

	bool getInput();

	bool shiftDown();

	bool controlDown();

	bool altDown();

	bool keyDown( char aKey );

	bool kpKeyDown( int aKey );

	bool leftArrowDown();

	bool rightArrowDown();

	bool upArrowDown();

	bool downArrowDown();

protected:
	Input();
	Input( const Input& );
	Input& operator= ( const Input& );

private:
	static const unsigned int SDL_KEYPAD_OFFSET = 256;
	static const unsigned int ASCII_TABLE_SIZE = 126;
	static const unsigned int KEYPAD_SIZE = 10;
	Uint8 *keys;
	bool releaseKeys( SDL_Event keyEvent );
	bool setKeys( SDL_Event keyEvent );
	// Current states of the keys, true if down, false if up
	bool keyArray[ASCII_TABLE_SIZE];
	bool kPadArray[KEYPAD_SIZE];
	bool shift;
	bool control;
	bool alt;
	bool upArrow;
	bool downArrow;
	bool leftArrow;
	bool rightArrow;
	static Input* pInstance;
};

#endif

