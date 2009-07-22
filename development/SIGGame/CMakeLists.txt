cmake_minimum_required(VERSION 2.6)
Project(SIGGame)
set(SOURCES
#	SDLMain.m
	main.cpp
	Actor.cpp
	AsteroidActor.cpp
	AudioSystem.cpp
	Input.cpp
	Log.cpp
	Model.cpp
	PlayerActor.cpp
	Renderer.cpp
	Surface.cpp
	Vector3f.cpp
	World.cpp
	)
Find_Package(SDL REQUIRED)
Find_Package(SDL_mixer REQUIRED)
Find_Package(OpenGL REQUIRED)

INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${SDLMIXER_INCLUDE_DIR})
add_executable(
	siggame
	MACOSX_BUNDLE
	${SOURCES}
	)
target_link_libraries(
	siggame
	${SDL_LIBRARY}
	${SDLMIXER_LIBRARY}
	${OPENGL_LIBRARY}
	#SDLmain
	)
INSTALL(TARGETS siggame
	BUNDLE DESTINATION "/Applications"
	RUNTIME DESTINATION bin)
##cpack stuff
#SET(CPACK_GENERATOR "DragNDrop")
INCLUDE(CPack)
