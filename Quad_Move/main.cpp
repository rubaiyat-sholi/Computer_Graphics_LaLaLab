#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

float tx = -90.0;
float ty = 0.0;

void init()
{
    glClearColor(0.5f,0.5f,0.5f,0.0f);
    glOrtho(-100,100,-100,100,-3,3);
}

void quad_move()
{
     tx+=.05;
    if(tx > 200)
    {
        tx = -90;
    }

    glutPostRedisplay();
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glColor3ub(25,255,255);
    glTranslatef(tx,ty,0);
    glRectf(-100,25,-75,0);
    quad_move();

    glPopMatrix();

    glFlush();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Object Translation");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
