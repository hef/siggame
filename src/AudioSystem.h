#ifndef AUDIOSYS_H
#define AUDIOSYS_H
#include <string>
#include <assert.h>
#include <map>
#include "SDL_mixer.h"
using std::string;
using std::map;

class AudioSystem
{
public:
	/** Access the AudioSystem Instance **/
	static AudioSystem* getInstance();

	/** Destructor **/
	~AudioSystem();

	/** Destroy method **/
	void destroy();

	/** Adds a wave sound file to the map **/
	void addSound( const string& fileName );

	/** Adds a music file to the map. This can be a .ogg file **/
	void addMusic( const string& fileName );

	/** Removes a wave sound file from the map **/
	bool removeSound( const string& fileName );

	/** Removes a music file from the map **/
	bool removeMusic( const string& fileName );

	/** Plays a wave sound from the map **/
	bool playSound( const string& fileName );

	/** Plays a music file from the map **/
	bool playMusic( const string& fileName );

	/** Tick function **/
	void tick( double dt );

protected:
	AudioSystem();
	AudioSystem( const AudioSystem& other );
	AudioSystem& operator=( const AudioSystem& other );

private:
	/** Pointer to the sole instance **/
	static AudioSystem* pInstance;

	/** Map from string to sound **/
	map< string, Mix_Chunk* > sounds;

	/** Map from string to music **/
	map< string, Mix_Music* > music;

	// Constant values
	const static int AUDIO_RATE;
	const static Uint16 AUDIO_FORMAT;
	const static int AUDIO_CHANNELS;
	const static int AUDIO_BUFFERS;

	// Tick variable
	double tickTime;
};
#endif