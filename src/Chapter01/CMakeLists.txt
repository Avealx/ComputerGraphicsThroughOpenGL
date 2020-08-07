add_executable( square
    ${CMAKE_CURRENT_SOURCE_DIR}/square.cpp
)
target_link_libraries( square 
    PRIVATE
    OpenGL::OpenGL
    GLUT::GLUT
    GLEW_1130
)

