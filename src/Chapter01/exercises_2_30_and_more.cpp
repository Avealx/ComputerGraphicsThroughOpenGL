// exercises_2_30_and_more
#include <cmath>
#include <cstdlib>
#include <iostream>

// clang-format off
#include <GL/glew.h>
#include <GL/freeglut.h>
// clang-format on

#define PI 3.14159265
#define EPS 1e-5

static int N_SUBDIV = 7;

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

void drawEllipse(float axis1, float axis2) {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0.0, 0.0);

  glBegin(GL_LINE_STRIP);
  float period = 2.0 * M_PI;
  int n_steps = 100;
  for (float tt = 0.0; tt <= period + EPS; tt += period / n_steps)
    glVertex3f(axis1 * sin(tt), axis2 * cos(tt), -10.0);
  glEnd();
}

void drawRing() {
  //  int N_SUBDIV = 7;
  float radius = 5.0;
  float frequency = 2.0 * M_PI / N_SUBDIV;
  float z1 = -10.0, z2 = -12.0;

  glBegin(GL_TRIANGLE_STRIP);
  for (int ii = 0; ii <= N_SUBDIV; ++ii) {
    glVertex3f(radius * sin(frequency * ii), radius * cos(frequency * ii), z1);
    glVertex3f(radius * sin(frequency * ii), radius * cos(frequency * ii), z2);
  }
  glEnd();
}

// Drawing routine.
void drawScene(void) {
  glClearColor(0.2, 0.3, 0.4, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // exercise 2.30
  // drawSine();

  // exercise 2.31
  // float axis1 = 8.0, axis2 = 6.0;
  // drawEllipse(axis1, axis2);

  // exercise 2.34
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  drawRing();

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

void keyInput(unsigned char key, int x, int y) {
  switch (key) {
  case 'p':
    ++N_SUBDIV;
    glutPostRedisplay();
    break;
  case 'P':
    --N_SUBDIV;
    glutPostRedisplay();
    break;
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

