#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

float spin = 0.0;

void init()
{
    glClearColor(0.5f,0.5f,0.5f,0.0f);
    glOrtho(-100,100,-100,100,0,100);
}


void spinDisplay_left()
{
    spin = spin + .2;
    glutPostRedisplay();

}
void spinDisplay_right()
{
    spin = spin - .2;
    glutPostRedisplay();
}

void my_mouse(int button, int state, int x, int y)
{
    switch(button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_left);
        break;

    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_right);
        break;

    default:
        break;

    }
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    glRotatef(spin, 0.0,0.0,1.0);
    glColor3ub(25,255,255);
    glRectf(-25,-25,25,25);

    glPopMatrix();

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Rotation");
    init();
    glutDisplayFunc(myDisplay);
    glutMouseFunc(my_mouse);
    glutMainLoop();
    return 0;
}

