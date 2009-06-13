#include "AudioSystem.h"
#include "SDL_mixer.h"
#include <iostream>
using std::cout;

AudioSystem* AudioSystem::pInstance = NULL;

const int AudioSystem::AUDIO_RATE = 22050;
const Uint16 AudioSystem::AUDIO_FORMAT = AUDIO_S16;
const int AudioSystem::AUDIO_CHANNELS = 2;
const int AudioSystem::AUDIO_BUFFERS = 4096;

/* Creates the sole instance and/or returns a pointer to it
 */
AudioSystem* AudioSystem::instance()
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
: pMusic( NULL ), tickTime( 0 )
{
	if( Mix_OpenAudio( AudioSystem::AUDIO_RATE, AudioSystem::AUDIO_FORMAT,
		AudioSystem::AUDIO_CHANNELS, AudioSystem::AUDIO_BUFFERS ) )
	{
		cout << "Unable to open audio!\n";
		exit(1);
	}
}

/* Adds a sound to the list. Could be a file name or relative path to file
 */
void AudioSystem::addSound( const string& fileName )
{
	sounds.push_back( fileName );
}

/* Removes a sound file from the list. The file name
   should be the same as when added to the list
 */
bool AudioSystem::removeSound( const string& fileName )
{
	for( unsigned int i = 0; i < sounds.size(); ++i )
	{
		if( sounds[ i ] == fileName )
		{
			sounds.erase( sounds.begin() + i );
			return true;
		}

	}
	return false;
}

/* Plays a sound from the given file name or relative path to file
 */
void AudioSystem::playSound( const string& fileName )
{
	// Load up the music (or sound)
	pMusic = Mix_LoadMUS( fileName.c_str() );
	// Play
	Mix_PlayMusic( pMusic, 0 );
	// When finished, clean up
	Mix_HookMusicFinished( NULL );
	Mix_HaltMusic();
	Mix_FreeMusic( pMusic );	// Free memory
	pMusic = NULL;					// Set pointer to null
}

/* Tick function
 */
void AudioSystem::tick( double dt )
{
	tickTime += dt;
}