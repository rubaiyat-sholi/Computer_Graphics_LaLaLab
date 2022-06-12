#include <math.h>
#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

void init()
{
    glClearColor(1,0.3,0.5,0.0f);
    glOrtho(-30,30,-30,30,-30,30);


}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    int x1=0, y1=0, x2=5, y2=5;
    for (int i=0; i<4; i++){
        if(i%2==0){
            glColor3ub(255,255,255);
        }else{
            glColor3ub(0,0,0);
        }
        glRectf(x1,y1,x2,y2);
        x1=x1+5;
        x2=x2+5;
    }

    glFlush();

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);
    glutCreateWindow("191-15-12486");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
