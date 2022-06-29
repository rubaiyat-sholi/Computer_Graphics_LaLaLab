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
    case GLUT_KEY_UP:
        ty = ty+.25;
        glutPostRedisplay();
        break;

    case GLUT_KEY_DOWN:
        ty = ty-.25;
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
    glVertex2f(30,0);
    glVertex2f(25,7.5);
    glVertex2f(20,0);
    glEnd();

    //2nd one
     //1st one
    glColor3f(1,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(22,0);
    glVertex2f(17,7.5);
    glVertex2f(12,0);
    glEnd();

    //Triangle right
    //TRIANGLES
    //1st
    glPushMatrix();
    glTranslatef(tx,ty,0);
    glColor3f(1,1,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(24,40);
    glVertex2f(30,40);
    glVertex2f(30,31);
    glEnd();

    //middle
    glColor3f(1,1,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(26,40);
    glVertex2f(21,32.5);
    glVertex2f(16,40);
    glEnd();

    //2nd
    glColor3f(1,1,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(18,40);
    glVertex2f(12,40);
    glVertex2f(12,31);
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
