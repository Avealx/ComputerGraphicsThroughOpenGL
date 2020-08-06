cmake_minimum_required (VERSION 3.10)
project(ComputerGraphicsThroughOpenGL)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)



add_subdirectory( src )

add_subdirectory( external )
include_directories(
    external/glm-0.9.7.1/
    external/glew-1.13.0/include/
)
