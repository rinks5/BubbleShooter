#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
#include "game.h"
int mx,my;
int _x,_y;
extern int q,g;
void time(int)
{

        glutTimerFunc(5,time,0);
        glutPostRedisplay();
}
void motion(int x,int y)
{
    mx=x;
    my=650-y;
}

void mouse(int b,int s,int x ,int y)
{
    if(b==GLUT_LEFT_BUTTON)
        {
            q=1;
            _x=x;
            _y=650-y;
    //        mx=x;
      //  my=y;
        }
        else
        if(b=GLUT_RIGHT_BUTTON)
        {
            g=1;
            _x=x;
            _y=650-y;
    //
        }

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    play(mx,my,_x,_y);

    glutSwapBuffers();
}
void reshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,800,0,650,0,1);
    glMatrixMode(GL_MODELVIEW);
}
void init()
{
    glClearColor(0.0,0.0,0.0,1.0);
}


int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(800,650);
    glutInitWindowPosition(250,40);
    glutCreateWindow("bubble_shooter");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,time,0);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(motion);
    glutMainLoop();
    return 0;
}

