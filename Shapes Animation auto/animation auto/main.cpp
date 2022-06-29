//translate auto (SET - A - 2)

#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

float tx = 20.0;
float ty = 0.0;

void init()
{
    glClearColor(0,0,0,0);
    glOrtho(0,40,0,40,0,40);
}
void quad_move()
{
    tx-=.001;
    if(tx<-25)
        tx = 20.0;
    glutPostRedisplay();
}
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //left
    glColor3ub(255,0,0);
    glRectf(0,5,5,25);
    glRectf(5,20,10,25);
    glRectf(5,5,10,10);

    glPushMatrix();
    //right
    glTranslatef(tx,ty,0.0);
    glColor3ub(0,255,0);
    glRectf(35,20,30,10);
    glRectf(35,5,40,25);

    quad_move();

    glPopMatrix();
    glFlush();

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(700,600);
    glutInitWindowPosition(150,50);
    glutCreateWindow("DEMO");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
