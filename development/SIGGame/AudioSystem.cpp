#include "AudioSystem.h"
#include <iostream>
using std::cout;

AudioSystem* AudioSystem::pInstance = NULL;

const int AudioSystem::AUDIO_RATE = 22050;
const Uint16 AudioSystem::AUDIO_FORMAT = AUDIO_S16;
const int AudioSystem::AUDIO_CHANNELS = 2;
const int AudioSystem::AUDIO_BUFFERS = 4096;

/* Creates the sole instance and/or returns a pointer to it
 */
AudioSystem* AudioSystem::getInstance()
{
	if( pInstance == NULL )
	{
		pInstance = new AudioSystem;
	}
	return pInstance;
}

/* Initializes system and calls the Mix_OpenAudio routine
 */
AudioSystem::AudioSystem()
: tickTime( 0 )
{
	if( Mix_OpenAudio( AUDIO_RATE, AUDIO_FORMAT, AUDIO_CHANNELS, AUDIO_BUFFERS ) )
	{
		cout << "Unable to open audio!\n";
		exit(1);
	}
}

/* Adds a sound to the map. Could be a file name or relative path to file
 */
void AudioSystem::addSound( const string& fileName )
{
	sounds[ fileName ] = Mix_LoadWAV( fileName.c_str() );
}

/* Removes a sound file from the map
 */
bool AudioSystem::removeSound( const string& fileName )
{
	int succeeded = sounds.erase( fileName );
	if( succeeded )
		return true;
	else 
		return false;
}

/* Plays a sound from the map with the given file name
 */
bool AudioSystem::playSound( const string& fileName )
{
	// Play
	int nChannel = Mix_PlayChannel( -1, sounds[ fileName ], 0 );
	if( nChannel == -1 )
	{
		return false;	// Couldn't play file
	}
	return true;
}

/* Tick function
 */
void AudioSystem::tick( double dt )
{
	tickTime += dt;
}
