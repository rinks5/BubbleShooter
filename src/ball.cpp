#include "ball.h"
int q=0,s=0,g=0,w=0,score=0;
int xp=0,XP=0;
float r_balls[300][2],color[5][3]={ 1,0,0,
                                    0,0,1,
                                    0,1,1,
                                    1,1,0,
                                    0,1,0
                                    };
float c_balls[300][3];
void ball::body(float x,float y,float r,float g,float b)
{
        double a;
        float p,q;
        int i;
glLineWidth(1.0);
    glBegin(GL_POLYGON);
    for(i=0;i<360;i++)
    {
         a=i*M_PI/180;
         p=x + 20*cos(a);
         q=y + 20*sin(a);

         //glColor3f(1.0,1.0,1.0);
        // glVertex2f(x,y);
         glColor3f(r,g,b);
         glVertex2f(p,q);

    }
    glEnd();
}
void ball::lbody(int x,int y)
{
    double a;
        float p,q;
        int i;

    glBegin(GL_POINTS);
    for(i=0;i<360;i++)
    {
         a=i*M_PI/180;
         p=x + 20*cos(a);
         q=y + 20*sin(a);

         //glColor3f(1.0,1.0,1.0);
        // glVertex2f(x,y);
         glColor3f(1,1,1);
         glVertex2f(p,q);

    }
    glEnd();
}
void ball::remove_ball(float x,float y,int r,int g,int b)
{
        unsigned char pixel[4];
        glReadPixels(x,y,1,1,GL_RGB,GL_UNSIGNED_BYTE,pixel);

        if((int)pixel[0]==r&&(int)pixel[1]==g&&(int)pixel[2]==b)
        {
         r_balls[xp][0]=x;
          r_balls[xp][1]=y;
          xp++;
          body(x,y,0,0,0);

            remove_ball(x+40,y,r,g,b);
            remove_ball(x-40,y,r,g,b);
            remove_ball(x,y+40,r,g,b);
            remove_ball(x,y-40,r,g,b);
        }
}

void ball::line(int mx,int my)
{
    int i,j;
    for(i=20;i<=740;i=i+40)
    {
        if(mx>=i&&mx<=i+40)
        {
            x=i+20;
            break;
        }
    }
    for(j=685;j>=385;j=j-40)
    {
        if(my<=j&&my>=j-40)
        {
            y=j-20;
            break;
        }
    }
    if(my>375&&check(x,y)==2)
    {

        lbody(x,y);
    glLineWidth(3.0);
    glPushAttrib(GL_ENABLE_BIT);
    glLineStipple(2,0x1111);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(400,60);
    glVertex2f(x,y);
    glEnd();
    glPopAttrib();
    }

}

int ball::check(float x ,float y)
{int q;
    unsigned char pixel1[4],pixel2[4],pixel3[4],pixel5[4];
    glReadPixels(x+22,y,1,1,GL_RGB,GL_UNSIGNED_BYTE,pixel1);

    glReadPixels(x-22,y,1,1,GL_RGB,GL_UNSIGNED_BYTE,pixel2);
    glReadPixels(x,y+22,1,1,GL_RGB,GL_UNSIGNED_BYTE,pixel3);
    if(((int)pixel1[0]==0&&(int)pixel1[1]==0&&(int)pixel1[2]==0)&&
       ((int)pixel2[0]==0&&(int)pixel2[1]==0&&(int)pixel2[2]==0)&&
       ((int)pixel3[0]==0&&(int)pixel3[1]==0&&(int)pixel3[2]==0))
        q=1;
    else
        q=2;

        return q;

}
void ball::move_ball(int mx,int my,int _x,int _y)
{


    int i,j;
    for(i=20;i<=740;i=i+40)
    {
        if(_x>=i&&_x<=i+40)
        {
            _x=i+20;
            break;
        }
    }
    for(j=685;j>=385;j=j-40)
    {
        if(_y<=j&&_y>=j-40)
        {
            _y=j-20;
            break;
        }
    }
    line(mx,my);

    if(q==0)
    {
        xc=400;
        yc=60;

        body(400,60,r1,g1,b1);
    }
    else if(q==1)
    {
        if(s==0)
        {
            float dx,dy,sloap;
            double a;
            dx=_x-400;
            dy=_y-60;
            sloap=dy/dx;
            if(sloap<0)
            {
                sloap=-1*sloap;
            }
            a=atan(sloap);
            if(dx<0)
                xa=-1*3*cos(a);
            else
                xa=3*cos(a);

            ya=3*sin(a);
            s=1;
        }
        else
        {
            if(check(_x,_y)==1)
            {

                q=0;
                s=0;
            }
            else if(yc<_y)
            {
                    xc=xc+xa;
                    yc=yc+ya;
                    body(xc,yc,r1,g1,b1);
            }
            else
            {
                 for(i=20;i<=740;i=i+40)
                    {
                        if(xc>=i&&xc<=i+40)
                        {
                            xc=i+20;
                            break;
                        }
                    }
                for(j=685;j>=385;j=j-40)
                {
                    if(yc<=j&&yc>=j-40)
                        {
                            yc=j-20;
                            break;
                        }
                }
                q=0;
                s=0;

                unsigned char pixel1[4];
                glReadPixels(xc,yc,1,1,GL_RGB,GL_UNSIGNED_BYTE,pixel1);
                if((int)pixel1[0]==0&&(int)pixel1[1]==0&&(int)pixel1[2]==0)
                {
                    body(xc,yc,r1,g1,b1);
                    unsigned char pixel[4];
                    glReadPixels(xc,yc,1,1,GL_RGB,GL_UNSIGNED_BYTE,pixel);
                    remove_ball(xc,yc,pixel[0],pixel[1],pixel[2]);
                    score++;

                }
                w=rand()%5;
                r1=color[w][0];
                g1=color[w][1];
                b1=color[w][2];
                g=0;

            }

        }

    }
}


