#ifndef AUDIOSYS_H
#define AUDIOSYS_H
#include <string>
#include <map>
#include "SDL_mixer.h"
using std::string;
using std::map;

class AudioSystem
{
	public:
		static AudioSystem* getInstance();
		void addSound( const string& fileName );
		bool removeSound( const string& fileName );
		bool playSound( const string& fileName );
		void tick( double dt );
	protected:
		AudioSystem();
		AudioSystem( const AudioSystem& other );
		AudioSystem& operator=( const AudioSystem& other );
	private:
		static AudioSystem* pInstance;
		// Map from string to "sound object"
		map< string, Mix_Chunk* > sounds;

		// Constant values
		const static int AUDIO_RATE;
		const static Uint16 AUDIO_FORMAT;
		const static int AUDIO_CHANNELS;
		const static int AUDIO_BUFFERS;
		
		// Tick variable
		double tickTime;
};
#endif