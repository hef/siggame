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
		void addSound( const string& );
		bool removeSound( const string& );
		void playSound( const string& );
	protected:
		AudioSystem();
		AudioSystem( const AudioSystem& );
		AudioSystem& operator=( const AudioSystem& );
	private:
		static AudioSystem* pInstance;
		vector< string > sounds;
		const static int AUDIO_RATE;
		const static Uint16 AUDIO_FORMAT;
		const static int AUDIO_CHANNELS;
		const static int AUDIO_BUFFERS;
		Mix_Music* pMusic;
};
#endif