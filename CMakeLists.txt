cmake_minimum_required(VERSION 3.6)
project( stPhysics )

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Src/main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/local/include")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa -framework OpenGL -framework IOKit")

add_executable(stPhysics ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
target_link_libraries(stPhysics ${OPENGL_LIBRARIES})

add_definitions( -DAPPLE )

find_package(GLEW REQUIRED)
include_directories($(GLEW_INCLUDE_DIRS))
target_link_libraries(stPhysics ${GLEW_LIBRARIES})

find_package(glfw3 3.2 REQUIRED)
include_directories($(glfw_INCLUDE_DIRS))
target_link_libraries(stPhysics ${glfw_LIBRARIES} glfw)

