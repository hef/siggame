cmake_minimum_required(VERSION 2.6)
Project(SIGGame)
set(SOURCES
	src/main.cpp
	src/Actor.cpp
	src/AIActor.cpp
	src/AsteroidActor.cpp
	src/AudioSystem.cpp
	src/Input.cpp
	src/Log.cpp
	src/Material.cpp
	src/Mesh.cpp
	src/ModelSceneNode.cpp
	src/OBJ2Model.cpp
	src/NonInteractActor.cpp
	src/PhysicsEngine.cpp
	src/PlayerActor.cpp
	src/Renderer.cpp
	src/Vector3f.cpp
	src/Vertex.cpp
	src/World.cpp
	)
file(GLOB_RECURSE DATA data)
IF(APPLE)
	set(SOURCES ${SOURCES} src/SDLMain.m)
ENDIF(APPLE)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Wconversion")
Find_Package(SDL REQUIRED)
Find_Package(SDL_mixer REQUIRED)
Find_Package(OpenGL REQUIRED)

INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${SDLMIXER_INCLUDE_DIR})
add_executable(
	siggame
	#MACOSX_BUNDLE
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
INSTALL(
	FILES ${DATA}
	)
add_custom_command(
		TARGET siggame
		POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/data ${PROJECT_BINARY_DIR}/data
)

##cpack stuff
set(CPACK_BUNDLE_NAME ${CMAKE_PROJECT_NAME})
set(CPACK_BUNDLE_PLIST ${PROJECT_SOURCE_DIR}/contrib/Info.plist)
set(CPACK_BUNDLE_ICON  ${PROJECT_SOURCE_DIR}/contrib/siggame.icns)
#SET(CPACK_GENERATOR "DragNDrop")
INCLUDE(CPack)
