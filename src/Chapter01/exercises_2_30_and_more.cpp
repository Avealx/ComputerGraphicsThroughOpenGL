// exercises_2_30_and_more
#include <cmath>
#include <cstdlib>
#include <iostream>

// clang-format off
#include <GL/glew.h>
#include <GL/freeglut.h>
// clang-format on

#define PI 3.14159265

void drawSine() {
  float scale = 8.0;
  float amplitude = scale / 2.0;
  float frequency = M_PI / scale; // Angle parameter.

  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0.0, 0.0);

  glBegin(GL_LINE_STRIP);
  for (float tt = -scale; tt <= scale; tt += scale / 20)
    glVertex3f(tt, amplitude * sin(frequency * tt), -10.0);
  glEnd();
}

// Drawing routine.
void drawScene(void) {
  // exercise 2.30
  drawSine();

  glFlush();
}

// Initialization routine.
void setup(void) { glClearColor(1.0, 1.0, 1.0, 0.0); }

// OpenGL window reshape routine.
void resize(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // glOrtho(-50.0, 50.0, -50.0, 50.0, 0.0, 100.0);
  glFrustum(-10.0, 10.0, -10.0, 10.0, 9.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y) {
  switch (key) {
  case 27:
    exit(0);
    break;
  default:
    break;
  }
}

// Main routine.
int main(int argc, char **argv) {
  glutInit(&argc, argv);

  glutInitContextVersion(4, 3);
  glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("exercises_2_30_and_more.cpp");
  glutDisplayFunc(drawScene);
  glutReshapeFunc(resize);
  glutKeyboardFunc(keyInput);

  glewExperimental = GL_TRUE;
  glewInit();

  setup();

  glutMainLoop();
}

