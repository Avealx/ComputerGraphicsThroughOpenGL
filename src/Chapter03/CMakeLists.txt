add_executable( hemisphere03
    ${CMAKE_CURRENT_SOURCE_DIR}/hemisphere.cpp
)
target_link_libraries( hemisphere03 
    PRIVATE
    OpenGL::OpenGL
    GLUT::GLUT
    GLEW_1130
)

add_executable( hemisphereMultidraw
    ${CMAKE_CURRENT_SOURCE_DIR}/hemisphereMultidraw.cpp
)
target_link_libraries( hemisphereMultidraw
    PRIVATE
    OpenGL::OpenGL
    GLUT::GLUT
    GLEW_1130
)

add_executable( squareAnnulus1
    ${CMAKE_CURRENT_SOURCE_DIR}/squareAnnulus1.cpp
)
target_link_libraries( squareAnnulus1 
    PRIVATE
    OpenGL::OpenGL
    GLUT::GLUT
    GLEW_1130
)

add_executable( squareAnnulus2
    ${CMAKE_CURRENT_SOURCE_DIR}/squareAnnulus2.cpp
)
target_link_libraries( squareAnnulus2 
    PRIVATE
    OpenGL::OpenGL
    GLUT::GLUT
    GLEW_1130
)

add_executable( squareAnnulus3
    ${CMAKE_CURRENT_SOURCE_DIR}/squareAnnulus3.cpp
)
target_link_libraries( squareAnnulus3 
    PRIVATE
    OpenGL::OpenGL
    GLUT::GLUT
    GLEW_1130
)

add_executable( squareAnnulus4
    ${CMAKE_CURRENT_SOURCE_DIR}/squareAnnulus4.cpp
)
target_link_libraries( squareAnnulus4 
    PRIVATE
    OpenGL::OpenGL
    GLUT::GLUT
    GLEW_1130
)

add_executable( squareAnnulusAndTriangle
    ${CMAKE_CURRENT_SOURCE_DIR}/squareAnnulusAndTriangle.cpp
)
target_link_libraries( squareAnnulusAndTriangle 
    PRIVATE
    OpenGL::OpenGL
    GLUT::GLUT
    GLEW_1130
)

