// clang-format off
#include <GL/glew.h>
#include <GL/freeglut.h>
// clang-format on

#include <iostream>

using namespace std;

// int main() {
//    cout << "Hello World!" << endl;
//    return 0;
//}

void draw_cube_in_cube() {
  glColor3f(0.3, 0.1, 0.1);
  glBegin(GL_POLYGON);
  glVertex3f(20.0, 20.0, 0.0);
  glVertex3f(80.0, 20.0, 0.0);
  glVertex3f(80.0, 80.0, 0.0);
  glVertex3f(20.0, 80.0, 0.0);
  glEnd();

  glColor3f(0.3, 0.4, 0.5);
  glBegin(GL_POLYGON);
  glVertex3f(40.0, 40.0, 0.0);
  glVertex3f(60.0, 40.0, 0.0);
  glVertex3f(60.0, 60.0, 0.0);
  glVertex3f(40.0, 60.0, 0.0);
  glEnd();
}

void draw_cube_color_interpolation() {
  glBegin(GL_POLYGON);
  glPointSize(5.0);
  glBegin(GL_POINTS);
  glBegin(GL_LINES);
  glLineWidth(5.0);
  glBegin(GL_LINE_LOOP);
  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(20.0, 20.0, 0.0);
  glColor3f(0.0, 1.0, 0.0);
  glVertex3f(80.0, 20.0, 0.0);
  glColor3f(0.0, 0.0, 1.0);
  glVertex3f(80.0, 80.0, 0.0);
  glColor3f(1.0, 1.0, 0.0);
  glVertex3f(20.0, 80.0, 0.0);
  glEnd();
}

void line_color_interpolation() {
  glLineWidth(5.0);
  glBegin(GL_LINES);
  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(20.0, 20.0, 0.0);
  glColor3f(0.0, 1.0, 0.0);
  glVertex3f(80.0, 20.0, 0.0);
  glEnd();

  glPointSize(5.0);
  glBegin(GL_POINTS);
  glColor3f(0.5, 0.5, 0.0);
  glVertex3f(50.0, 21.0, 0.0);
  glEnd();
}

void different_polygon_modes() {
  glPolygonMode(GL_FRONT, GL_FILL);
  glPolygonMode(GL_BACK, GL_LINE);

  glBegin(GL_TRIANGLES);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(50.0, 50.0, 0.0);
  glVertex3f(00.0, 50.0, 0.0);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(50.0, 50.0, 0.0);
  glVertex3f(50.0, 00.0, 0.0);
  glEnd();
}

void exercise_2_13_annulus() {
  glPolygonMode(GL_BACK, GL_LINE);
  glPolygonMode(GL_FRONT, GL_FILL);
  glBegin(GL_TRIANGLE_STRIP);
  glVertex3f(20.0, 80.0, 0.0);
  glVertex3f(30.0, 70.0, 0.0);
  glVertex3f(20.0, 20.0, 0.0);
  glVertex3f(30.0, 30.0, 0.0);
  glVertex3f(80.0, 20.0, 0.0);
  glVertex3f(70.0, 30.0, 0.0);
  glVertex3f(80.0, 80.0, 0.0);
  glVertex3f(70.0, 70.0, 0.0);
  glVertex3f(20.0, 80.0, 0.0);
  glVertex3f(30.0, 70.0, 0.0);
  glEnd();
}

void exercise_2_14_u_shape() {
  // Ex 2.14
  glPolygonMode(GL_BACK, GL_LINE);
  glPolygonMode(GL_FRONT, GL_FILL);
  glBegin(GL_TRIANGLE_STRIP);
  glVertex3f(20.0, 70.0, 0.0);
  glVertex3f(20.0, 80.0, 0.0);
  glVertex3f(30.0, 70.0, 0.0);
  glVertex3f(40.0, 80.0, 0.0);
  glVertex3f(30.0, 20.0, 0.0);
  glVertex3f(40.0, 30.0, 0.0);
  glVertex3f(60.0, 20.0, 0.0);
  glVertex3f(50.0, 30.0, 0.0);
  glVertex3f(60.0, 70.0, 0.0);
  glVertex3f(50.0, 80.0, 0.0);
  glVertex3f(70.0, 70.0, 0.0);
  glVertex3f(70.0, 80.0, 0.0);
  glEnd();
}

void experiment_2_15_triangle_fan() {
  // Experiment 2.15
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(10.0, 10.0, 0.0);
  glVertex3f(15.0, 90.0, 0.0);
  glVertex3f(55.0, 75.0, 0.0);
  glVertex3f(80.0, 30.0, 0.0);
  glVertex3f(90.0, 10.0, 0.0);
  glEnd();
}

void exercise_2_15_annulus_triangle_fans() {
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(20.0, 20.0, 0.0);
  glVertex3f(20.0, 80.0, 0.0);
  glVertex3f(30.0, 70.0, 0.0);
  glVertex3f(30.0, 30.0, 0.0);
  glVertex3f(70.0, 30.0, 0.0);
  glVertex3f(80.0, 20.0, 0.0);
  glEnd();
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(80.0, 80.0, 0.0);
  glVertex3f(20.0, 80.0, 0.0);
  glVertex3f(30.0, 70.0, 0.0);
  glVertex3f(70.0, 70.0, 0.0);
  glVertex3f(70.0, 30.0, 0.0);
  glVertex3f(80.0, 20.0, 0.0);
  glEnd();
}

void experiment_2_16_rect() { glRectf(20.0, 20.0, 80.0, 80.0); }

void exercise_2_18_double_annulus_triangle_strip() {
  glPolygonMode(GL_BACK, GL_LINE);
  glPolygonMode(GL_FRONT, GL_FILL);
  glBegin(GL_TRIANGLE_STRIP);
  glVertex3f(40.0, 30.0, 0.0);
  glVertex3f(50.0, 30.0, 0.0);
  glVertex3f(40.0, 40.0, 0.0);
  glVertex3f(50.0, 50.0, 0.0);
  glVertex3f(30.0, 40.0, 0.0);
  glVertex3f(20.0, 50.0, 0.0);
  glVertex3f(30.0, 30.0, 0.0);
  glVertex3f(20.0, 20.0, 0.0);
  glVertex3f(60.0, 30.0, 0.0);
  glVertex3f(70.0, 20.0, 0.0);
  glVertex3f(60.0, 40.0, 0.0);
  glVertex3f(70.0, 50.0, 0.0);
  glVertex3f(50.0, 40.0, 0.0);
  glVertex3f(50.0, 50.0, 0.0);
  glEnd();
}

// Drawing routine.
void drawScene(void) {
  glClear(GL_COLOR_BUFFER_BIT);

  // draw_cube_in_cube();
  // draw_cube_color_interpolation();
  // line_color_interpolation();
  // different_polygon_modes();
  // exercise_2_13_annulus();
  // exercise_2_14_u_shape();
  // experiment_2_15_triangle_fan();
  // exercise_2_15_annulus_triangle_fans();
  // experiment_2_16_rect();
  exercise_2_18_double_annulus_triangle_strip();

  glFlush();
}

// Initialization routine.
void setup(void) { glClearColor(0.3, 0.4, 0.5, 0.0); }

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

  glutCreateWindow("square.cpp");

  glutDisplayFunc(drawScene);
  glutReshapeFunc(resize);
  glutKeyboardFunc(keyInput);

  glewExperimental = GL_TRUE;
  glewInit();

  setup();

  glutMainLoop();
}
