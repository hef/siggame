#include "Log.h"

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <fstream>
using std::fstream;

Log* Log::pInstance = NULL;

Log* Log::getInstanceOf()
{
	if( NULL == pInstance )
	{
		pInstance = new Log;
	}

	return pInstance;
}

Log::~Log()
{
}

void Log::destroy()
{
	if( pInstance != NULL )
	{
		delete pInstance;
	}
}

void Log::setLogFile( const string& filePath )
{
	logFilePath = filePath;
}

void Log::log( const string& data, SourceSystem source, Destination dest )
{
	string sys;

	switch( source )
	{
	case ACTOR:
	{
		sys = systems[0];
		break;
	}

	case RENDERER:
	{
		sys = systems[1];
		break;
	}

	case AUDIO:
	{
		sys = systems[2];
		break;
	}

	case INPUT:
	{
		sys = systems[3];
		break;
	}

	case PHYSICS:
	{
		sys = systems[4];
		break;
	}

	case LOG:
	{
		sys = systems[5];
		break;
	}

	case CONSOLE:
	{
		sys = systems[6];
		break;
	}
	}


	//TODO: Add source system to output.  Add time\date
	if( Log::STDOUT == ( dest & Log::STDOUT ) )
	{
		cout << "[" << sys << "] " << data << endl;
	}

	if( Log::STDERR == ( dest & Log::STDERR ) )
	{
		cerr << "[" << sys << "] " << data << endl;
	}

	if( Log::LOG_FILE == ( dest & Log::LOG_FILE ) )
	{
		std::fstream file( logFilePath.c_str(), std::ios::out | std::ios::app );

		if( file.good() )
		{
			file << "[" << sys << "] " << data << std::endl;

			file.flush();
			file.close();
		}
	}
}

Log::Log()
{
	logFilePath = "Log.txt";

	systems.push_back( "ACTOR" );
	systems.push_back( "RENDERER" );
	systems.push_back( "AUDIO" );
	systems.push_back( "INPUT" );
	systems.push_back( "PHYSICS" );
	systems.push_back( "LOG" );
	systems.push_back( "CONSOLE" );
}