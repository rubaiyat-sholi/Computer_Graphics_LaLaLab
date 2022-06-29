//translate Keyboard (SET- B - 1)

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

    //TRIANGLES Left
    //1st one
    glColor3f(1,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0,30);
    glVertex2f(7.5,25);
    glVertex2f(0,20);
    glEnd();

    //2nd one
     //1st one
    glColor3f(1,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0,22);
    glVertex2f(7.5,17);
    glVertex2f(0,12);
    glEnd();

    //Triangle right
    //TRIANGLES
    //1st
    glPushMatrix();
    glTranslatef(tx,ty,0);
    glColor3f(1,1,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(40,24);
    glVertex2f(40,30);
    glVertex2f(31,30);
    glEnd();

    //middle
    glColor3f(1,1,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(40,26);
    glVertex2f(32.5,21);
    glVertex2f(40,16);
    glEnd();

    //2nd
    glColor3f(1,1,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(40,18);
    glVertex2f(40,12);
    glVertex2f(31,12);
    glEnd();

    glPopMatrix();
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
    glutSpecialFunc(myKeyboard);
    glutMainLoop();
    return 0;
}
