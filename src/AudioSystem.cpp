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
	int success = Mix_OpenAudio( AUDIO_RATE, AUDIO_FORMAT, AUDIO_CHANNELS, AUDIO_BUFFERS );
	assert( success == 0 && "Unable to open audio!" );
}

/* Destructor
 */
AudioSystem::~AudioSystem()
{
	map< string, Mix_Chunk* >::iterator i;
	for( i = sounds.begin(); i != sounds.end(); ++i )
	{
		Mix_FreeChunk( i->second );   // Free memory
	}
	sounds.clear();

	map< string, Mix_Music* >::iterator j;
	for( j = music.begin(); j != music.end(); ++j )
	{
		Mix_FreeMusic( j->second );   // Free memory
	}
	music.clear();
}

/* Destroy method
 */
void AudioSystem::destroy()
{
	if( pInstance != NULL )
	{
		delete pInstance;
	}
}
/* Adds a sound to the map. Could be a file name or relative path to file
 */
void AudioSystem::addSound( const string& fileName )
{
	sounds[ fileName ] = Mix_LoadWAV( fileName.c_str() );
}

/* Adds a music file to the map. Could be a file name or relative path to file
 */
void AudioSystem::addMusic( const string& fileName )
{
	music[ fileName ] = Mix_LoadMUS( fileName.c_str() );
}

/* Removes a sound file from the map
 */
bool AudioSystem::removeSound( const string& fileName )
{
	// Free memory
	Mix_FreeChunk( sounds[ fileName ] );
	// Remove from map
	int succeeded = sounds.erase( fileName );
	if( succeeded )
		return true;
	else
		return false;
}

/* Removes a music file from the map
 */
bool AudioSystem::removeMusic( const string& fileName )
{
	// Free memory
	Mix_FreeMusic( music[ fileName ] );
	// Remove from map
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
		return false;   // Couldn't play file
	}
	return true;
}

/* Plays a music file from the map with the given file name
 */
bool AudioSystem::playMusic( const string& fileName )
{
	int retVal = Mix_PlayMusic( music[ fileName ], -1 );
	if( retVal == -1 )
	{
		return false;   // Couldn't play file
	}
	return true;
}

/* Tick function
 */
void AudioSystem::tick( double dt )
{
	tickTime += dt;
}
