#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>
#include <math.h>
int x = 0;
int y = 30;
int z = 45;

void Timer(int );

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    //gluOrtho2D(-400, 400, -400, 400);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT |  GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();


    glEnd();

    glTranslatef(0, 0, -5.0);
    glColor3f(1, 0, 0);
    glRotatef(x, 1, 0, 0);
    glRotatef(y, 0, 1, 0);
    glRotatef(z, 0, 0, 1);
    glutWireCube(1.0);

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -10.0, 10.0);
    //gluPerspective(60, 1, 2.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D CUBE");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(1000,Timer,0);
    init();
    glutMainLoop();
    return 0;
}
void Timer(int t)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 200, Timer, 0);
    x++;
    y++;
    z++;
}