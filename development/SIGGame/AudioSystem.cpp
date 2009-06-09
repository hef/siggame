#include "AudioSystem.h"
#include "SDL_mixer.h"
#include <iostream>
using std::cout;

AudioSystem* AudioSystem::pInstance = 0;

const int AudioSystem::AUDIO_RATE = 22050;
const Uint16 AudioSystem::AUDIO_FORMAT = AUDIO_S16;
const int AudioSystem::AUDIO_CHANNELS = 2;
const int AudioSystem::AUDIO_BUFFERS = 4096;

AudioSystem* AudioSystem::instance()
{
	if( pInstance == 0 )
	{
		pInstance = new AudioSystem;
	}
	return pInstance;
}

AudioSystem::AudioSystem()
: pMusic( 0 )
{
	// Fill in code...
	if( Mix_OpenAudio( AudioSystem::AUDIO_RATE, AudioSystem::AUDIO_FORMAT,
		AudioSystem::AUDIO_CHANNELS, AudioSystem::AUDIO_BUFFERS ) )
	{
		cout << "Unable to open audio!\n";
		exit(1);
	}
}

void AudioSystem::addSound( const string& name )
{
	sounds.push_back( name );
}

bool AudioSystem::removeSound( const string& name )
{
	for( unsigned i = 0; i < sounds.size(); ++i )
	{
		if( sounds[ i ] == name )
		{
			sounds.erase( sounds.begin() + i );
			return true;
		}

	}
	return false;
}

void AudioSystem::playSound( const string& name )
{
	
}
