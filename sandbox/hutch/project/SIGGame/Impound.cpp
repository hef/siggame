#include "Impound.h"

Impound* Impound::pinstance = 0;
Impound* Impound::Instance()
{
	if ( pinstance == 0 )
	{
		pinstance = new Impound;
	}
	return pinstance;
}
Impound::Impound()
{
}

Impound::~Impound(){}

void Impound::destroy()
{
	if ( pinstance != 0 )
	{
		delete pinstance;
	}
}

dogEnum Impound::addDog( Dog* pDog )
{
	for( std::vector<Dog* >::iterator it = dogVector.begin(); it != dogVector.end(); ++it )
	{
		if( !strcmp( ( *it )->getName(), pDog->getName() ) )
		{
			return FAILED;
		}
	}
	dogVector.push_back( pDog );
	return SUCCESS;
}

dogEnum Impound::removeDog( Dog const * const pDog )
{
	std::string dogName = pDog->getName();
	return removeDog( dogName );
}

dogEnum Impound::removeDog( std::string dogName )
{
	for( std::vector<Dog* >::iterator it = dogVector.begin(); it != dogVector.end(); ++it )
	{
		std::string theName = ( *it )->getName();
		if( theName == dogName )
		{
			dogVector.erase( it );
			return SUCCESS;
		}
	}
	return FAILED;
}

dogEnum Impound::removeDog( char const * const dogName )
{
	std::string theName = dogName;
	return removeDog( theName );
}

bool Impound::findDog( Dog const * const pDog )
{
	std::string theName = pDog->getName();
	return findDog( theName );
}

bool Impound::findDog( std::string dogName )
{
	for( std::vector<Dog* >::iterator it = dogVector.begin(); it != dogVector.end(); ++it )
	{
		std::string theName = ( *it )->getName();
		if( theName == dogName )
		{
			return true;
		}
	}
	return false;
}

bool Impound::findDog( char const * const dogName )
{
	std::string theName = dogName;
	return findDog( theName );
}

void const Impound::visitImpound()
{
	for( std::vector<Dog*>::iterator it = dogVector.begin(); it != dogVector.end(); ++it )
	{
		std::cout << "This is \"" << it[0]->getName() << "\"" << std::endl;
		( *it )->bark();
	}
}

