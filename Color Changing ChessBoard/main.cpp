#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

int a,b,c,e,g,f;

void fun()
{
    if(a==0)
    {
        a=255;
        b=255;
        c=255;
        e=0;
        f=0;
        g=0;
    }
    else{
        a=0;
        b=0;
        c=0;
        e=255;
        f=255;
        g=255;
    }

}

void init()
{
    glClearColor(1,0.3,0.5,0.0f);
    glOrtho(0,50,0,50,0,50);

}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);


    glPushMatrix();

    int x1=0,y1=0,x2=5,y2=5,i,j;

    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            if(i%2==0){
                if(j%2==0){
                    glColor3ub(a,b,c);
                }
                else{
                    glColor3ub(e,f,g);
                }
            }
            else{
                if(j%2==0){
                    glColor3ub(e,f,g);
                }
                else{

                    glColor3ub(a,b,c);
                }
            }
            glRectf(x1,y1,x2,y2);
            x1=x1+5;
            x2=x2+5;
        }
        y1=y1+5;
        y2=y2+5;

        x1=0;
        x2=5;

    }
    fun();
    glutPostRedisplay();

    glPopMatrix();

    glFlush();

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(150,50);
    glutCreateWindow("Chess Board");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
