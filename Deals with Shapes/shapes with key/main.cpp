//translate Keyboard (SET - A - 1)

#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

float tx = 0.0;
float ty = 0.0;

void init()
{
    glClearColor(0,0,0,0);
    glOrtho(0,40,0,40,0,40);
}
void  myKeyboard(int key, int x, int y)
{
     switch(key)
    {
    case GLUT_KEY_LEFT:
        tx = tx-.25;
        glutPostRedisplay();
        break;

    case GLUT_KEY_RIGHT:
        tx = tx+.25;
        glutPostRedisplay();
        break;

    default:
        break;

    }

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
    glutSpecialFunc(myKeyboard);
    glutMainLoop();
    return 0;
}
