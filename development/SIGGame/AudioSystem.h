#ifndef AUDIOSYS_H
#define AUDIOSYS_H
#include <string>
#include <vector>
#include "SDL_mixer.h"
using std::string;
using std::vector;

class AudioSystem
{
	public:
		static AudioSystem* instance();
		void addSound( const string& fileName );
		bool removeSound( const string& fileName );
		void playSound( const string& fileName );
		void tick( double dt );
	protected:
		AudioSystem();
		AudioSystem( const AudioSystem& other );
		AudioSystem& operator=( const AudioSystem& other );
	private:
		static AudioSystem* pInstance;
		vector< string > sounds;

		// Constant values
		const static int AUDIO_RATE;
		const static Uint16 AUDIO_FORMAT;
		const static int AUDIO_CHANNELS;
		const static int AUDIO_BUFFERS;
		
		// Pointer to music
		Mix_Music* pMusic;
		// Tick variable
		double tickTime;
};
#endif