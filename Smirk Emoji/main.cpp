#include<windows.h>
#define PI   3.141592654
#include <GL/glut.h>
#include<math.h>
#include <stdlib.h>

void init()
{
    glClearColor(0,0,0,0);
    glOrtho(0,40,0,40,0,30);
}
void emoji(float x1, float y1, float x2, float y2)
{
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}

void circle(float x, float y, float r)
{
    int i;
    int amount = 100;
    float twicepi = 2*PI;

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x,y);
    for(i=0; i<=amount; i++){
        glVertex2f(
                x+(r*cos(i*twicepi/amount)),
                y+(r*sin(i*twicepi/amount))
                );
    }
    glEnd();
}
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(245,201,103);
    circle(20,15,5);
    glColor3ub(0,0,0);
    circle(17.5,17.5,1);
    glColor3ub(0,0,0);
    circle(22.5,17.5,1);

   //smile
    emoji(20,12.6,21.3,12.8);
    emoji(21.3,12.8,22.5,13.6);
    emoji(22.5,13.6,23.7,15);

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Emoji");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}

