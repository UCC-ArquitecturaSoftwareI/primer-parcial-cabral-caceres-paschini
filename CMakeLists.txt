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



add_executable(${PROJECT_NAME} ${sources} ${sources_clases} clases/Character/Character.cpp clases/Character/Character.h clases/Map/Map.cpp clases/Map/Map.h clases/Renderer/Renderer.cpp clases/Renderer/Renderer.h "clases/Music Renderer/Sound_Render.cpp" "clases/Music Renderer/Sound_Render.h" clases/Animator/Animation.cpp clases/Animator/Animation.h clases/Input/Input_Handler.cpp clases/Input/Input_Handler.h clases/Game/Game.cpp clases/Game/Game.h clases/Colision/Collision.cpp clases/Colision/Collision.h clases/World/World.cpp clases/World/World.h clases/Entity/Entity.cpp clases/Entity/Entity.h clases/Fruits/Fruits.cpp clases/Fruits/Fruits.h clases/Animator/Image_Holder.cpp clases/Animator/Image_Holder.h clases/Animator/Animation_Creator.cpp clases/Animator/Animation_Creator.h  clases/Fruits/Fruit_Vector.cpp clases/Fruits/Fruit_Vector.h clases/Entity/All_entity.cpp clases/Entity/All_entity.h)

add_dependencies(${PROJECT_NAME} raylib)
target_link_libraries(${PROJECT_NAME} ${raylib_LDFLAGS})
target_include_directories(${PROJECT_NAME} PRIVATE ${raylib_INCLUDE_DIRS})

file(COPY "resources/"  DESTINATION "resources/")

include("cmake/raylib_web_post.cmake")