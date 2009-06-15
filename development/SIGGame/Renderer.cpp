#include "Renderer.h"

Renderer* Renderer::instance = NULL;

Renderer::Renderer():windowWidth(500),windowHeight(500),cubeRotateX( 45.0f ),cubeRotateY ( 45.0f )
{
	if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		fprintf(stderr, "Unable to initialize SDL %s", SDL_GetError());
		exit(1);
	}
	if ( SDL_SetVideoMode(windowWidth, windowHeight, 0, SDL_OPENGL) == NULL)
	{
		fprintf(stderr, "Unable to create openGL scene %s", SDL_GetError());
		exit(2);
	}

	initGL(windowWidth, windowHeight);
}

Renderer::~Renderer()
{
	SDL_Quit();
}

const Renderer* Renderer::getInstanceOf()
{
	if(instance==NULL){
		instance=new Renderer;
	}

	return instance;
}


int Renderer::render( const World& gameWorld ) const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);

	
	

	const std::vector<Actor> actors = gameWorld.getActors();

	for(unsigned int i=0;i<actors.size();i++)
	{
		glLoadIdentity();

		//The following three lines have to implemented using the Actor class still
		glTranslatef(0, 0, -5.0f); // translate camera back -5
		glRotatef(cubeRotateX, 1, 0, 0); 
		glRotatef(cubeRotateY, 0, 1, 0);

		glBegin(GL_QUADS);
		const std::vector<Quad> q=actors[i].getQuads();
		for(unsigned int j = 0; j < q.size(); j++)
		{
			const float* color = q[j].getColor();
			glColor3f(color[0], color[1], color[2]);

			for(int k = 0; k < 4; k++ )
			{
				const float* pt = q[j].getPoint(k);
				glVertex3f( pt[0],pt[1],pt[2] );
			}
		}
		glEnd();
	}

	
	glFlush(); // free up stuff

	SDL_GL_SwapBuffers(); // switches buffer

	displayFPS();

	return 0;
}

void Renderer::establishProjectionMatrix(GLsizei width, GLsizei height)
{
	glViewport(0,0, width, height);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 200.0f);

}

void Renderer::initGL( GLsizei width, GLsizei height )
{
	establishProjectionMatrix(width, height);

	glShadeModel(GL_SMOOTH);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // nicest calculation possible
	glEnable(GL_PERSPECTIVE_CORRECTION_HINT); // enabled above

}

void Renderer::displayFPS( void ) const
{
	static long lastTime = SDL_GetTicks();
	static long loops = 0;
	static GLfloat fps = 0.0f;

	int newTime = SDL_GetTicks();

	if (newTime - lastTime > 100)
	{
		float newFPS = (float)loops / float(newTime - lastTime) * 1000.0f;

		fps = (fps + newFPS) / 2.0f;

		char title[80];
		sprintf(title, "SIGGame Demo - %.2f", fps);

		SDL_WM_SetCaption(title, NULL);

		lastTime = newTime;

		loops = 0;
	}
	loops++;
}