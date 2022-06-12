#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

float tx = 0.0;
float ty = 0.0;

void init()
{
    glClearColor(0.5f,0.5f,0.5f,0.0f);
    glOrtho(-100,100,-100,100,-3,3);
}



void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glColor3ub(25,255,255);
    glTranslatef(tx,ty,0);
    glRectf(-25,-25,25,25);

    glPopMatrix();

    glFlush();
}

void spe_key(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_LEFT:
        tx = tx-5;
        glutPostRedisplay();
        break;

    case GLUT_KEY_RIGHT:
        tx = tx+5;
        glutPostRedisplay();
        break;

    case GLUT_KEY_DOWN:
        ty = ty-5;
        glutPostRedisplay();
        break;

    case GLUT_KEY_UP:
        ty = ty+5;
        glutPostRedisplay();
        break;

    default:
        break;

    }
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
    glutSpecialFunc(spe_key);
    glutMainLoop();
    return 0;
}
