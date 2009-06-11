#ifndef _INPUT_H
#define _INPUT_H

class Input
{

public:
	static Input* Instance();
	~Input();

	int tick( int dl );
	bool shift();
	bool control();
	bool alt();
	bool key();
	bool kpKey();

protected:
	Input();
	Input( const Input& );
	Input& operator= ( const Input& );
private:
	static Input* pInstance;
};

#endif