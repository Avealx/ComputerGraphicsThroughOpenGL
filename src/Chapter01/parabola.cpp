// originally: parabola.cpp by Sumanta Guha.
//
// see http://www.sumantaguha.com/downloads

#include <cmath>
#include <cstdlib>
#include <iostream>

// clang-format off
#include <GL/glew.h>
#include <GL/freeglut.h>
// clang-format on

// Globals.
static int M = 3; // Number of vertices on one half of the parabola.

// Drawing routine.
void drawScene(void) {
  int i;
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(0.0, 0.0, 0.0);

  // The 2M+1 vertices on the parabola are equally spaced in x-coordinates.
  // The parabola is translated and scaled to center it in the window.
  glBegin(GL_LINE_STRIP);
  for (i = -M; i <= M; ++i) {
    glVertex3f(50.0 + 50.0 * (float)i / M, 100.0 * (float)(i * i) / (M * M),
               0.0);
  }
  glEnd();

  glFlush();
}

// Initialization routine.
void setup(void) { glClearColor(1.0, 1.0, 1.0, 0.0); }

// OpenGL window reshape routine.
void resize(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y) {
  switch (key) {
  case 27:
    exit(0);
    break;
  case '+':
    M++;
    glutPostRedisplay();
    break;
  case '-':
    if (M > 2)
      M--;
    glutPostRedisplay();
    break;
  default:
    break;
  }
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void) {
  std::cout << "Interaction:" << std::endl;
  std::cout << "Press +/- to increase/decrease the number of vertices on the "
               "parabola."
            << std::endl;
}

// Main routine.
int main(int argc, char **argv) {
  printInteraction();
  glutInit(&argc, argv);

  glutInitContextVersion(4, 3);
  glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("parabola.cpp");
  glutDisplayFunc(drawScene);
  glutReshapeFunc(resize);
  glutKeyboardFunc(keyInput);

  glewExperimental = GL_TRUE;
  glewInit();

  setup();

  glutMainLoop();
}

