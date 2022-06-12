#include<windows.h>
#include<math.h>
#include <GL/glut.h>
#define PI   3.141592654
#include <stdlib.h>

void init()
{
    glClearColor(0.10f,0.74f,0.87f,0.0f);
    glOrtho(0,50,0,50,0,50);
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    int i;
    int amount = 100;
    float twicepi = 2*PI;
    float x = 25;
    float y = 25;
    float r = 5;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245,201,103);
    glVertex2f(x,y);
    for(i=0; i<=amount; i++){
        glVertex2f(
                x+(r*cos(i*twicepi/amount)),
                y+(r*sin(i*twicepi/amount))
                );
    }
    glEnd();
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Circle");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
