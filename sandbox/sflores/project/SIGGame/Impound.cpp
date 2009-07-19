#include "Impound.h"

Impound* Impound::pInstance = NULL;

Impound* Impound::getInstance()
{
	if( pInstance == NULL )
	{
		pInstance = new Impound;
	}
	return pInstance;
}

Impound::Impound()
{ }

Impound::~Impound()
{ }

void Impound::destroy()
{
	delete this;
}

RETURN_CODE Impound::addDog( const Dog* dog )
{
	const char* name = dog->getName();
	map< const char*, const Dog* >::iterator iter = cells.find( name );
	if( iter == cells.end() )
	{
		cells[ name ] = dog;
		return OK;
	}
	return FAIL;
}

bool Impound::findDog( const char* name )
{
	map< const char*, const Dog* >::iterator iter = cells.find( name );
	if( iter == cells.end() )
	{
		return false;
	}
	return true;
}

bool Impound::findDog( const string name )
{
	return findDog( name.c_str() );
}

bool Impound::findDog( const Dog* dog )
{
	return findDog( dog->getName() );
}

RETURN_CODE Impound::removeDog( const char* name )
{
	int erased = cells.erase( name );
	if( erased == OK )
	{
		return OK;
	}
	else return FAIL;
}

RETURN_CODE Impound::removeDog( const string name )
{
	return removeDog( name.c_str() );
}

RETURN_CODE Impound::removeDog( const Dog* dog )
{
	return removeDog( dog->getName() );
}

void Impound::visitImpound() const
{
	map< const char*, const Dog* >::const_iterator iter;
	for( iter = cells.begin(); iter != cells.end(); ++iter )
	{
		cout << "This is \"" << iter->second->getName() << "\"" << endl;
		iter->second->bark();
	}
}
