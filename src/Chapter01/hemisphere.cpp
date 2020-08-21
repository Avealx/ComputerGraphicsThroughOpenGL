// original: hemisphere.cpp by Sumanta Guha.
//
// see http://www.sumantaguha.com/downloads
///////////////////////////////////////////////////////////////////////////////////////
#include <cmath>
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

#define PI 3.14159265

// Globals.
static float R = 5.0; // Radius of hemisphere.
static int pp = 6;    // Number of longitudinal slices.
static int qq = 4;    // Number of latitudinal slices.
static float Xangle = 0.0, Yangle = 0.0, Zangle = 0.0; // Angles to rotate hemisphere.

// Initialization routine.
void setup(void) { glClearColor(1.0, 1.0, 1.0, 0.0); }

void _drawHemispherePart(float qq_ratio, float pp_qq_ratio = 1.0) {
  // Array of latitudinal triangle strips, each parallel to the equator,
  // stacked one above the other from the equator to the north pole.
  for (int j = 0; j < qq_ratio * qq; j++) {
    // One latitudinal triangle strip.
    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= pp * pp_qq_ratio; i++) {
      glVertex3f(R * cos((float)(j + 1) / qq * PI / 2.0) *
                     cos(2.0 * (float)i / pp * PI),
                 R * sin((float)(j + 1) / qq * PI / 2.0),
                 -R * cos((float)(j + 1) / qq * PI / 2.0) *
                     sin(2.0 * (float)i / pp * PI));
      glVertex3f(
          R * cos((float)j / qq * PI / 2.0) * cos(2.0 * (float)i / pp * PI),
          R * sin((float)j / qq * PI / 2.0),
          -R * cos((float)j / qq * PI / 2.0) * sin(2.0 * (float)i / pp * PI));
    }
    glEnd();
  }
}

void _drawHemisphereSliceSide(float qq_ratio, float pp_ratio) {
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(0.0, 0.0, 0.0);
  for (int j = 0; j <= qq * qq_ratio; j++) {
    glVertex3f(R * cos((float)(j) / qq * PI / 2.0) *
                   cos(2.0 * (int)(pp * pp_ratio) / pp * PI),
               R * sin((float)(j) / qq * PI / 2.0),
               -R * cos((float)(j) / qq * PI / 2.0) *
                   sin(2.0 * (int)(pp * pp_ratio) / pp * PI));
  }
  glEnd();
}

void _drawHemisphereSliceBottom(float qq_ratio, float pp_ratio) {
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(0.0, 0.0, 0.0);
  for (int i = 0; i <= pp * pp_ratio; i++) {
    glVertex3f(
        R * cos((float)(0) / qq * PI / 2.0) * cos(2.0 * (float)i / pp * PI),
        R * sin((float)(0) / qq * PI / 2.0),
        -R * cos((float)(0) / qq * PI / 2.0) * sin(2.0 * (float)i / pp * PI));
  }
  glEnd();
}

void drawHemisphere() { _drawHemispherePart(1.0); }

void drawBottomHalfHemisphere() { _drawHemispherePart(0.5); }

void drawSliceOfHemisphere() {
  float qq_ratio = 1.0, pp_ratio = 0.3;
  _drawHemispherePart(qq_ratio, pp_ratio);
  _drawHemisphereSliceSide(qq_ratio, 0.0);
  _drawHemisphereSliceSide(qq_ratio, pp_ratio);
  _drawHemisphereSliceBottom(qq_ratio, pp_ratio);
}

// Drawing routine.
void drawScene(void) {
  glClear(GL_COLOR_BUFFER_BIT);

  glLoadIdentity();

  // Command to push the hemisphere, which is drawn centered at the origin,
  // into the viewing frustum.
  glTranslatef(0.0, 0.0, -10.0);

  // Commands to turn the hemisphere.
  glRotatef(Zangle, 0.0, 0.0, 1.0);
  glRotatef(Yangle, 0.0, 1.0, 0.0);
  glRotatef(Xangle, 1.0, 0.0, 0.0);

  // Hemisphere properties.
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glColor3f(0.0, 0.0, 0.0);

  // drawHemisphere();

  // exercise 2.39 a)
  //  drawBottomHalfHemisphere();
  // exercise 2.39 b)
  drawSliceOfHemisphere();

  glFlush();
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
  glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
  switch (key) {
  case 27:
    exit(0);
    break;
  case 'P':
    pp += 1;
    glutPostRedisplay();
    break;
  case 'p':
    if (pp > 3)
      pp -= 1;
    glutPostRedisplay();
    break;
  case 'Q':
    qq += 1;
    glutPostRedisplay();
    break;
  case 'q':
    if (qq > 3)
      qq -= 1;
    glutPostRedisplay();
    break;
  case 'x':
    Xangle += 5.0;
    if (Xangle > 360.0)
      Xangle -= 360.0;
    glutPostRedisplay();
    break;
  case 'X':
    Xangle -= 5.0;
    if (Xangle < 0.0)
      Xangle += 360.0;
    glutPostRedisplay();
    break;
  case 'y':
    Yangle += 5.0;
    if (Yangle > 360.0)
      Yangle -= 360.0;
    glutPostRedisplay();
    break;
  case 'Y':
    Yangle -= 5.0;
    if (Yangle < 0.0)
      Yangle += 360.0;
    glutPostRedisplay();
    break;
  case 'z':
    Zangle += 5.0;
    if (Zangle > 360.0)
      Zangle -= 360.0;
    glutPostRedisplay();
    break;
  case 'Z':
    Zangle -= 5.0;
    if (Zangle < 0.0)
      Zangle += 360.0;
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
      << "Press P/pp to increase/decrease the number of longitudinal slices."
      << std::endl
      << "Press Q/qq to increase/decrease the number of latitudinal slices."
      << std::endl
      << "Press x, X, y, Y, z, Z to turn the hemisphere." << std::endl;
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
  glutCreateWindow("hemisphere.cpp");
  glutDisplayFunc(drawScene);
  glutReshapeFunc(resize);
  glutKeyboardFunc(keyInput);

  glewExperimental = GL_TRUE;
  glewInit();

  setup();

  glutMainLoop();
}

