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

add_executable( exercises_2_30_and_more
    ${CMAKE_CURRENT_SOURCE_DIR}/exercises_2_30_and_more.cpp
)
target_link_libraries( exercises_2_30_and_more 
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

add_executable( hemisphere
    ${CMAKE_CURRENT_SOURCE_DIR}/hemisphere.cpp
)
target_link_libraries( hemisphere 
    PRIVATE
    OpenGL::OpenGL
    GLUT::GLUT
    GLEW_1130
)

add_executable( moveSphere
    ${CMAKE_CURRENT_SOURCE_DIR}/moveSphere.cpp
)
target_link_libraries( moveSphere 
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

