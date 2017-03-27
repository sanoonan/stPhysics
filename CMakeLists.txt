cmake_minimum_required(VERSION 3.6)
project( stPhysics )

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Src/main.cpp
        Src/stGraphics/ApplicationWindow.cpp
        Src/stGraphics/ApplicationWindow.h
        Src/stUtils/NonCopyable.h
        Src/stUtils/ErrorHandling.h
        Src/stTypes/Types.h
        Src/stUtils/StaticClass.h
        Src/stUtils/Log.cpp
        Src/stUtils/Log.h
        Src/stMaths/Vec.h
        Src/stMaths/Vec2.cpp
        Src/stMaths/Vec2.h
        Src/stMaths/Vec.cpp
        Src/stUtils/Assertions.h
        Src/stMaths/VecDeclarations.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/local/include -fno-exceptions")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa -framework OpenGL -framework IOKit")

add_executable(stPhysics ${SOURCE_FILES})

include_directories( "Src/" )

find_package(OpenGL REQUIRED)
target_link_libraries(stPhysics ${OPENGL_LIBRARIES})

add_definitions( -DAPPLE )

find_package(GLEW REQUIRED)
include_directories($(GLEW_INCLUDE_DIRS))
target_link_libraries(stPhysics ${GLEW_LIBRARIES})

find_package(glfw3 3.2 REQUIRED)
include_directories($(glfw_INCLUDE_DIRS))
target_link_libraries(stPhysics ${glfw_LIBRARIES} glfw)

