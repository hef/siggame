#include "Renderer.h"
#include <iostream>

Renderer* Renderer::instance = NULL;

Renderer::Renderer()
	: windowWidth( 500 ), windowHeight( 500 ), cubeRotateX( 45.0f ), cubeRotateY ( 45.0f )
{
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		fprintf( stderr, "Unable to initialize SDL %s", SDL_GetError() );
		exit( 1 );
	}
	if ( SDL_SetVideoMode( windowWidth, windowHeight, 0, SDL_OPENGL ) == NULL )
	{
		fprintf( stderr, "Unable to create openGL scene %s", SDL_GetError() );
		exit( 2 );
	}

	initGL( windowWidth, windowHeight );
}

Renderer::~Renderer()
{
	SDL_Quit();
}

Renderer* Renderer::getInstanceOf()
{
	if( instance == NULL )
	{
		instance = new Renderer;
	}
	return instance;
}

void Renderer::destroy()
{
	if( instance != NULL )
	{
		delete instance;
	}
}

int Renderer::render( const World& gameWorld ) const
{
	glEnable( GL_TEXTURE_2D );

	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );



	glMatrixMode( GL_MODELVIEW );


	const vector< Actor* >& actors = gameWorld.getActors();

	vector< Actor* >::const_iterator i;

	glLoadIdentity();

	// camera translation
	// you can pretend this is the camera location
	//	glTranslatef( 0.0f, 0.0f, -15.0f );

	for( i = actors.begin(); i != actors.end(); ++i )
	{
		glLoadIdentity();

		// shift according to actor position
		const Vector3f& actorPosition = ( *i )->getPositionVector3f();
		glTranslatef( actorPosition[ 0 ], actorPosition[ 1 ], actorPosition[ 2 ] );

		
		const Vector3f& actorRotation = ( *i )->getRotationVector3f();

		if( actorRotation[ 0 ] != 0.0f )
			glRotatef( actorRotation[ 0 ], 1.0f, 0.0f, 0.0f ); //rotate on the x axis

		if( actorRotation[ 1 ] != 0.0f )
			glRotatef( actorRotation[ 1 ], 0.0f, 1.0f, 0.0f ); //rotate on the y axis

		if( actorRotation[ 2 ] != 0.0f )
			glRotatef( actorRotation[ 2 ], 0.0f, 0.0f, 1.0f ); //rotate on the z axis
		(*i)->getSceneNode().render();
		
	}


	glFlush(); // free up stuff

	SDL_GL_SwapBuffers(); // switches buffer

	displayFPS();

	return 0;
}

void Renderer::establishProjectionMatrix( GLsizei width, GLsizei height )
{
	glViewport( 0, 0, width, height );

	glMatrixMode( GL_PROJECTION );

	glLoadIdentity();

	glOrtho(-100.0f, 100.0f, -100.0f, 100.0f, -100.0f, 100.0f);
	


}

void Renderer::initGL( GLsizei width, GLsizei height )
{
	establishProjectionMatrix( width, height );

	glShadeModel( GL_SMOOTH );

	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

	glEnable( GL_DEPTH_TEST );
	glDepthFunc( GL_LEQUAL );

	//glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST ); // nicest calculation possible
	//glEnable( GL_PERSPECTIVE_CORRECTION_HINT ); // enabled above
	
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);

	// Create light components
	float ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	float diffuseLight[] = { 1.0f, 0.3f, 0.0f, 1.0f };
	float specularLight[] = { 0.0f, 0.0f, 0.8f, 1.0f };
	float position[] = { 0.0f, 0.0f, -100.0f, 1.0f };
	//
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

}

void Renderer::displayFPS( void ) const
{
	static long lastTime = SDL_GetTicks();
	static long loops = 0;
	static GLfloat fps = 0.0f;

	int newTime = SDL_GetTicks();

	if( newTime - lastTime > 100 )
	{
		float newFPS = (float)loops / float( newTime - lastTime ) * 1000.0f;

		fps = ( fps + newFPS ) / 2.0f;

		char title[80];
		sprintf( title, "SIGGame Demo - %.2f", fps );

		SDL_WM_SetCaption( title, NULL );

		lastTime = newTime;

		loops = 0;
	}
	loops++;
}
