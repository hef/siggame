cmake_minimum_required(VERSION 2.6)
Project(SIGGame)
set(SOURCES
	main.cpp
	Actor.cpp
	AIActor.cpp
	AsteroidActor.cpp
	AudioSystem.cpp
	Input.cpp
	Log.cpp
	Mesh.cpp
	Model.cpp
	ModelSceneNode.cpp
	OBJ2Model.cpp
	PhysicsEngine.cpp
	PlayerActor.cpp
	Renderer.cpp
	Surface.cpp
	Vector3f.cpp
	Vertex.cpp
	World.cpp
	)
IF(APPLE)
	set(SOURCES ${SOURCES} SDLMain.m)
ENDIF(APPLE)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Wconversion")
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
	RUNTIME DESTINATION bin
	)
##cpack stuff
SET(CPACK_GENERATOR "DragNDrop")
INCLUDE(CPack)
