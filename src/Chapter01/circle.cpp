// originally: circle.cpp by Sumanta Guha.
//
// see http://www.sumantaguha.com/downloads

#include <cstdlib>
#include <cmath>
#include <iostream>

// clang-format off
#include <GL/glew.h>
#include <GL/freeglut.h>
// clang-format on

#define PI 3.14159265358979324

// Globals.
static float R = 30.0; // Radius of circle.
static float X = 50.0; // X-coordinate of center of circle.
static float Y = 50.0; // Y-coordinate of center of circle.
static int numVertices = 5; // Number of vertices on circle.

void draw_circle() {
  float t = 0; // Angle parameter.
  int i;
  glBegin(GL_LINE_LOOP);
  for (i = 0; i < numVertices; ++i) {
    glColor3f((float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX,
              (float)rand() / (float)RAND_MAX);
    glVertex3f(X + R * cos(t), Y + R * sin(t), 0.0);
    t += 2 * PI / numVertices;
  }
  glEnd();
}

void exercise_2_19_spiral() {
  float t = 0; // Angle parameter.
  float R_offset = 0.3 / 3 * 2 * PI;
  int i;
  glBegin(GL_LINE_STRIP);
  for (i = 0; i < numVertices; ++i) {
    glColor3f((float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX,
              (float)rand() / (float)RAND_MAX);
    glVertex3f(X + (R + t * R_offset) * cos(t), Y + (R + t * R_offset) * sin(t),
               0.0);
    t += 3 * 2 * PI / (numVertices - 1);
  }
  glEnd();
}

void exercise_2_20_disc_polygon() {
  float t = 0; // Angle parameter.
  int i;
  glBegin(GL_POLYGON);
  for (i = 0; i < numVertices; ++i) {
    glColor3f((float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX,
              (float)rand() / (float)RAND_MAX);
    glVertex3f(X + R * cos(t), Y + R * sin(t), 0.0);
    t += 2 * PI / numVertices;
  }
  glEnd();
}

void exercise_2_20_disc_triangle_fan() {
  float t = 0; // Angle parameter.
  int i;
  glBegin(GL_TRIANGLE_FAN);
  for (i = 0; i < numVertices; ++i) {
    glColor3f((float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX,
              (float)rand() / (float)RAND_MAX);
    glVertex3f(X + R * cos(t), Y + R * sin(t), 0.0);
    t += 2 * PI / numVertices;
  }
  glEnd();
}

void exercise_2_22_circular_annylus() {
  float r = R / 2.0;
  float t = 0; // Angle parameter.
  int i;
  glBegin(GL_TRIANGLE_STRIP);
  for (i = 0; i <= numVertices; ++i) {
    glColor3f((float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX,
              (float)rand() / (float)RAND_MAX);
    glVertex3f(X + R * cos(t), Y + R * sin(t), 0.0);
    glVertex3f(X + r * cos(t), Y + r * sin(t), 0.0);
    t += 2 * PI / numVertices;
  }
  glEnd();
}

// Drawing routine.
void drawScene(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  // draw_circle();

  // exercise_2_19_spiral();

  // exercise_2_20_disc_polygon();

  // exercise_2_20_disc_triangle_fan();

  exercise_2_22_circular_annylus();

  glFlush();
}

// Initialization routine.
void setup(void) { glClearColor(1.0, 1.0, 1.0, 0.0); }

// OpenGL window reshape routine.
void resize(int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
  switch (key) {
  case 27:
    exit(0);
    break;
  case '+':
    numVertices++;
    glutPostRedisplay();
    break;
  case '-':
    if (numVertices > 3)
      numVertices--;
    glutPostRedisplay();
    break;
  default:
    break;
  }
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
  std::cout << "Interaction:" << std::endl;
  std::cout
      << "Press +/- to increase/decrease the number of vertices on the circle."
      << std::endl;
}

// Main routine.
int main(int argc, char **argv)
{
  printInteraction();
  glutInit(&argc, argv);

  glutInitContextVersion(4, 3);
  glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("circle.cpp");
  glutDisplayFunc(drawScene);
  glutReshapeFunc(resize);
  glutKeyboardFunc(keyInput);

  glewExperimental = GL_TRUE;
  glewInit();

  setup();

  glutMainLoop();
}

