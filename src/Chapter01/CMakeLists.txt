add_executable( circle
    ${CMAKE_CURRENT_SOURCE_DIR}/circle.cpp
)
target_link_libraries( circle 
    PRIVATE
    OpenGL::OpenGL
    GLUT::GLUT
    GLEW_1130
)

add_executable( circularAnnuluses
    ${CMAKE_CURRENT_SOURCE_DIR}/circularAnnuluses.cpp
)
target_link_libraries( circularAnnuluses 
    PRIVATE
    OpenGL::OpenGL
    GLUT::GLUT
    GLEW_1130
)

add_executable( helix
    ${CMAKE_CURRENT_SOURCE_DIR}/helix.cpp
)
target_link_libraries( helix 
    PRIVATE
    OpenGL::OpenGL
    GLUT::GLUT
    GLEW_1130
)

add_executable( parabola
    ${CMAKE_CURRENT_SOURCE_DIR}/parabola.cpp
)
target_link_libraries( parabola 
    PRIVATE
    OpenGL::OpenGL
    GLUT::GLUT
    GLEW_1130
)

add_executable( square
    ${CMAKE_CURRENT_SOURCE_DIR}/square.cpp
)
target_link_libraries( square 
    PRIVATE
    OpenGL::OpenGL
    GLUT::GLUT
    GLEW_1130
)

