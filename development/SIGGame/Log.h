#ifndef LOG_H
#define LOG_H

#include <string>
using std::string;

#include <vector>
using std::vector;

typedef const unsigned int Destination;
typedef const unsigned int SourceSystem;

class Log
{
public:
	static Log* getInstanceOf();

	void setLogFile( const string& filePath );
	void log( const string& data, SourceSystem source, Destination dest );

	static Destination STDOUT		= 0x1;
	static Destination STDERR		= 0x2;
	static Destination LOG_FILE		= 0x4;

	enum system {	ACTOR		= 1,
					RENDERER	= 2,
					AUDIO		= 4,
					INPUT		= 8,
					PHYSICS		= 16,
					LOG			= 32,
					CONSOLE		= 64 
				};
private:
	Log();
	~Log();
	
	string logFilePath;
	vector<string> systems;
	static Log* pInstance;
};

#endif