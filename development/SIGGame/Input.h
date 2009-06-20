#include <stdlib.h>
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
	bool keyDown(char aKey);
	bool kpKeyDown(char aKey);
	bool leftDown();
	bool rightDown();
	bool upDown();
	bool downDown();

protected:
	Input();
	Input( const Input& );
	Input& operator= ( const Input& );

private:
	Uint8 *keys;
	bool releaseKeys( SDL_Event keyEvent );
	bool setKeys( SDL_Event keyEvent );
	// Current states of the keys, true if down, false if up
	bool shift;
	bool control;
	bool alt;
	bool key;
	bool kpKey;
	bool up;
	bool down;
	bool left;
	bool right;
	static Input* pInstance;
};

#endif