#include "game.h"
ball b;
extern int xp,XP,score;
extern float r_balls[300][2],a_balls[300][5];
void border()
{
    glLineWidth(5.0);
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(1,1);
    glVertex2f(1,649);
    glVertex2f(799,649);
    glVertex2f(799,1);
    glEnd();
}

void shooter()
{
    int i;
    double a;
    float x,y;
    glBegin(GL_POLYGON);
    glColor3f(0.2,0.2,0.2);
    glVertex2f(320,5);

    glVertex2f(365,55);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(435,55);
    glVertex2f(480,5);
    glEnd();

    for(i=180;i<360;i++)
    {
        a=M_PI*i/180;
        x=400 + 27*cos(a);
        y=60 + 27*sin(a);
        glBegin(GL_LINES);
        glColor3f(0.0,0.0,0.0);
        glVertex2f(400,60);
        glVertex2f(x,y);
        glEnd();
    }
}

void level()
{
    int i,j;
    float x=25;
    for(i=1;i<20;i++)
    {
        if(i%3==0)
             b.body(x*1.6*i,625,0,1,0);
        else if(i%2==0)
             b.body(x*1.6*i,625,1,0,0);
        else if(i%5==0)
             b.body(x*1.6*i,625,1,1,0);
        else
             b.body(x*1.6*i,625,0,0,1);
    }
    for(i=1;i<20;i++)
    {
        if(i==1 || i==19)
            continue;
        else if(i%4==0)
             b.body(x*1.6*i,585,0,0,1);
        else if(i%2==0)
             b.body(x*1.6*i,585,0,1,1);
        else if(i%5==0)
             b.body(x*1.6*i,585,1,1,0);
        else
             b.body(x*1.6*i,585,1,0,0);
    }
    for(i=1;i<20;i++)
    {
        if(i<3 || i>17)
            continue;
        else if(i%3==0)
            b.body(x*1.6*i,545,0,0,1);
        else if(i%5==0)
             b.body(x*1.6*i,545,1,0,0);
        else if(i%7==0)
             b.body(x*1.6*i,545,0,0,1);
        else
             b.body(x*1.6*i,545,0,1,0);
    }
    for(i=1;i<20;i++)
    {
        if(i<4 || i>16)
            continue;
            //b.body(x*1.6*i,505,0,0,0);
        else if(i%3==0)
            b.body(x*1.6*i,505,0,1,1);
        else if(i%5==0)
             b.body(x*1.6*i,505,0,0,1);
        else if(i%7==0)
             b.body(x*1.6*i,505,1,1,0);
        else
             b.body(x*1.6*i,505,1,0,0);
    }
    for(i=1;i<20;i++)
    {
        if(i<5 || i>15)
            continue;
            //b.body(x*1.6*i,465,0,0,0);
        else if(i%3==0)
            b.body(x*1.6*i,465,0,0,1);
        else if(i%5==0)
             b.body(x*1.6*i,465,1,1,0);
       // else if(i%7==0)
         //    b.body(x*1.6*i,465,1,0,1);
        else
             b.body(x*1.6*i,465,0,1,0);
    }
    for(i=1;i<20;i++)
    {
        if(i<6 || i>14)
            continue;
             //b.body(x*1.6*i,425,0,0,0);
        else if(i<8 || i>12)
             b.body(x*1.6*i,425,1,1,0);
        else
            b.body(x*1.6*i,425,1,0,0);
    }


    int p;
    p=xp;
    while(p>=0)
    {
        b.body(r_balls[p][0],r_balls[p][1],0,0,0);
        p--;
    }

}

void play(int mx,int my,int _x,int _y)
{
    int i,tscore;
    char buffer[200];
    tscore=xp-score;
     sprintf(buffer,"score = %d",tscore);
    glRasterPos2f(700,40);
    glColor3f(1,0,1);
    for(i=0;buffer[i]!='\0';i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,buffer[i]);
    }
    border();
    shooter();
    level();
   b.move_ball(mx,my,_x,_y);

}
