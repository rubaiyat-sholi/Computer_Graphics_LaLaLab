#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

void init()
{
    glClearColor(0,1,1,0.0f);
    glOrtho(0,20,0,20,0,20);
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //QUADS Left
    glColor3ub(255,0,255);
    glBegin(GL_QUADS);
    glVertex2d(5,0);
    glVertex2d(10,0);
    glVertex2d(10,5);
    glVertex2d(5,5);
    glEnd();

    //TRIANGLES Left
    glColor3ub(0,255,0);
    glBegin(GL_TRIANGLES);
    glVertex2d(5,5);
    glVertex2d(10,5);
    glVertex2d(7.5,10);
    glEnd();

       //QUADS right
    glColor3ub(255,0,255);
    glBegin(GL_QUADS);
    glVertex2d(10,5);
    glVertex2d(15,5);
    glVertex2d(15,10);
    glVertex2d(10,10);
    glEnd();

    //TRIANGLES right
    glColor3ub(0,255,0);
    glBegin(GL_TRIANGLES);
    glVertex2d(10,0);
    glVertex2d(15,0);
    glVertex2d(12.5,5);
    glEnd();

    glFlush();

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(150,50);
    glutCreateWindow("DEMO");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
