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
    float twicepi = PI;
    float x = 20;
    float y = 10;
    float r = 5;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245,201,103);
    glVertex2f(x,y);
    for(i=0; i<=amount; i++){
        glVertex2f(
                x-(r*cos(i*twicepi/amount)),
                y-(r*sin(i*twicepi/amount))
                );
    }
    glEnd();

    //2nd circle

    float twicepi2 = 2*PI;
    float x1 = 17.5;
    float y1 = 10;
    float r1 = 2.5;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245,201,103);
    glVertex2f(x1,y1);
    for(i=0; i<=amount; i++){
        glVertex2f(
                x1+(r1*cos(i*twicepi2/amount)),
                y1+(r1*sin(i*twicepi2/amount))
                );
    }
    glEnd();
    //circle 3
     //2nd circle

    float twicepi3 = 2*PI;
    float x2 = 17.5;
    float y2 = 10;
    float r2 = 1;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0);
    glVertex2f(x2,y2);
    for(i=0; i<=amount; i++){
        glVertex2f(
                x2+(r2*cos(i*twicepi3/amount)),
                y2+(r2*sin(i*twicepi3/amount))
                );
    }
    glEnd();

    //circle 3
    //2nd circle

    float twicepi4 = 2*PI;
    float x3 = 17.5;
    float y3 = 10;
    float r3 = 0.5;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255);
    glVertex2f(x3,y3);
    for(i=0; i<=amount; i++){
        glVertex2f(
                x3+(r3*cos(i*twicepi4/amount)),
                y3+(r3*sin(i*twicepi4/amount))
                );
    }
    glEnd();


    //TRIANGLES 1 lej
    glColor3ub(245,201,103);
    glBegin(GL_TRIANGLES);
    glVertex2d(25,10);
    glVertex2d(30,10);
    glVertex2d(30,14);
    glEnd();

    //tri 2 mukh

    //TRIANGLES
    glColor3ub(0,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2d(15,11);
    glVertex2d(13,11);
    glVertex2d(15,10);
    glEnd();

    //tri 3
    glColor3ub(0,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2d(15,10);
    glVertex2d(13,9);
    glVertex2d(15,9);
    glEnd();

    //pakhna
       // STAR using Polygon
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);

    glVertex2f(25-1,6.5);
    glVertex2d(30-1,5.5);
    glVertex2d(30-1,5.3);
    glVertex2d(25-1,6);
    glVertex2f(22-1,6.8);
    glVertex2f(22-1,7);

    glEnd();


    //paa 1
    //line 1
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(17.5,6);
    glVertex2f(18,5);
    //line 2

    glVertex2f(18,5);
    glVertex2f(17.5,4);

    //line3

    glVertex2f(17.5,4);
    glVertex2f(17.7,3);
    //line 4

    glVertex2f(17.5,4);
    glVertex2f(17,3);
    //line 5

    glVertex2f(17.5,4);
    glVertex2f(16.5,3.5);


    glEnd();

    //paa 2
    //line 1
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(17.5+2,6);
    glVertex2f(18+2,5);
    //line 2

    glVertex2f(18+2,5);
    glVertex2f(17.5+2,4);

    //line3

    glVertex2f(17.5+2,4);
    glVertex2f(17.7+2,3);
    //line 4

    glVertex2f(17.5+2,4);
    glVertex2f(17+2,3);
    //line 5

    glVertex2f(17.5+2,4);
    glVertex2f(16.5+2,3.5);


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
