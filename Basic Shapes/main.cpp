#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

void init()
{
    glClearColor(0,1,1,0.0f);
    glOrtho(-80,80,-80,80,-80,80);

}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //QUADS
    glColor3ub(255,0,255);
    glBegin(GL_QUADS);
    glVertex2d(0,0);
    glVertex2d(5,0);
    glVertex2d(5,5);
    glVertex2d(0,5);
    glEnd();

    //TRIANGLES
    glColor3ub(0,255,0);
    glBegin(GL_TRIANGLES);
    glVertex2d(20,0);
    glVertex2d(30,0);
    glVertex2d(25,10);
    glEnd();

    //QUADS using Rectf
    glColor3ub(0,0,255);
    glRectf(40,0,45,5);


    // STAR using Polygon
    glColor3ub(255,255,0);
    glBegin(GL_POLYGON);

    glVertex2f(62.5,5);
    glVertex2d(70,0);
    glVertex2d(67,8);
    glVertex2d(75,13);
    glVertex2f(65.5,13);
    glVertex2f(62.5,21);
    glVertex2f(59.5,13);
    glVertex2d(51,13);
    glVertex2d(58,8);
    glVertex2d(55,0);
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
