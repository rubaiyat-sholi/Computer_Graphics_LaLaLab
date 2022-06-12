#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

float tx = 1.0;
float ty = 0.0;

void init()
{
    glClearColor(1.0f,1.0f,1.0f,0.0f);
    glOrtho(0,70,0,70,0,70);
}

void quad_move()
{
     tx+=.01;
    if(tx > 80)
    {
        tx = 1.0;
    }

    glutPostRedisplay();
}
void boat()
{
    //boat base
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(4,24);
    glVertex2f(2,29);
    glVertex2f(34,29);
    glVertex2f(29.5,24);
    glEnd();

    // left pal
    glColor3ub(0,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(8,30);
    glVertex2f(14,46.5);
    glVertex2f(14,30);
    glEnd();

    // right pal
    glColor3ub(0,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(17,30);
    glVertex2f(17,51);
    glVertex2f(31,30);
    glEnd();

    // Middle
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(15,29);
    glVertex2f(16,29);
    glVertex2f(16,52);
    glVertex2f(15,52);
    glEnd();

}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // water
    glColor3ub(19,99,223);
    glBegin(GL_QUADS);
    glVertex2f(0,0);
    glVertex2f(0,27);
    glVertex2f(70,27);
    glVertex2f(70,0);
    glEnd();

    glPushMatrix();
    glTranslatef(tx,ty,0);
    boat();
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
    glutCreateWindow("Boat Project");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}

