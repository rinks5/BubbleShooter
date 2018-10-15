#ifndef BALL_H
#define BALL_H
#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
#include "game.h"


class ball
{
    public:
        float x,y,xa,ya,xc=400,yc=60;
        int r1=1,g1=0,b1=0;
        double _a;
        void body(float,float,float,float,float);
        void lbody(int,int);
        void move_ball(int,int,int ,int);
        void line(int,int);
        int check(float,float);
        void remove_ball(float ,float ,int r,int g,int b);
        void add_ball(float,float,int r,int g,int b);

    protected:

    private:
};

#endif // BALL_H
