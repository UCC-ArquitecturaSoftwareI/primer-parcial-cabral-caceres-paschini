cmake_minimum_required(VERSION 3.12)
project(raylibTemplate)

set(CMAKE_CXX_STANDARD 17)

set (GRAPHIC_API GRAPHICS_API_OPENGL_21 )

# Get the source toegher
file(GLOB sources *.cpp)

# Get the source  of classes toegher
file(GLOB sources_clases clases/*.cpp)


include("cmake/raylib_web.cmake")
include("cmake/raylib.cmake")


add_executable(${PROJECT_NAME} ${sources} ${sources_clases} clases/Personaje/Player.cpp clases/Personaje/Player.h clases/Map/Map.cpp clases/Map/Map.h clases/Renderer/Renderer.cpp clases/Renderer/Renderer.h "clases/Music Renderer/Sound_Render.cpp" "clases/Music Renderer/Sound_Render.h" clases/Animator/Animation.cpp clases/Animator/Animation.h clases/Input/Input_Handler.cpp clases/Input/Input_Handler.h clases/Game/Game.cpp clases/Game/Game.h clases/Colision/Collision.cpp clases/Colision/Collision.h)
add_dependencies(${PROJECT_NAME} raylib)
target_link_libraries(${PROJECT_NAME} ${raylib_LDFLAGS})
target_include_directories(${PROJECT_NAME} PRIVATE ${raylib_INCLUDE_DIRS})

file(COPY "resources/"  DESTINATION "resources/")

include("cmake/raylib_web_post.cmake")