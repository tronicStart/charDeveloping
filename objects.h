#ifndef _COBJECTS_H
#define _COBJECTS_H

#include "ctipes.h"

typedef void * types;

#define V 50

struct limit {

    int X;
    int Y;

};

struct texture {

    int ID;
    int mode;
    char name[V];
    char nameFile[V];
    char content[1024];

};

struct asset{
    
    int ID;
    int color;
    char name[V];
    char data[V];
    
};

struct cpng{
    
    int X;
    int Y;
    int Top;
    int Down;
    int Letf;
    int Right;
    int ID;
    char Name[V];
    int color;
    char data[V];
    int range;
    
};

struct air_object
{
};

struct lava_object
{
    public name[V];
    public cpng[V];
    int animation;
    int rangeX;
    int rangeY;
    int damage;
    int speed;
};

struct water_object
{
    public name[V];
    public cpng1[V];
    public cpng2[V];
    public cpng3[V];
    public cpng4[V];
    public cpng5[V];
    public cpng6[V];
    public cpng7[V];
    public cpng8[V];
    public cpng9[V];
    public cpng10[V];
    public cpng11[V];
    public cpng12[V];
    public cpng13[V];
    public cpng14[V];
    public cpng15[V];
    public cpng16[V];
    public cpng17[V];
    public cpng18[V];
    public cpng19[V];
    public cpng20[V];
    int animation;
    int rangeInX;
    int rangeInY;
    int startPaintInX;
    int startPaintInY;
    int cpngActives;
    int time;
};

struct Object
{
    //Posiciones en X y Y del objeto
    int positionX;
    int positionY;
    //caja de colision
    int BOXTop;
    int BOXDown;
    int BOXLetf;
    int BOXright;
    //Otros
    int ID;
    int range;
    f gravity;
    //Para el nombre del objeto
    public Name[V];
};

struct newObject
{
    int positionX;
    int positionY;
    f gravity;
    int BOXTop, BOXDown, BOXLetf, BOXright;
    int ID;
    int range;
    int onX1;
    int onX2;
    int onY1;
    int onY2;
    public name[V];
};

struct box_collision
{
    struct Object posObject;
    struct newObject otherObject;
    int range;
    char name[V];
    int id;
    int condition;
};

struct _scenes_
{
    public name[V];
    int id;
    int actives;
    int fps;
    int calls;
    int time_calls;
    int limitX_left;
    int limitX_rigth;
    int limitY_top;
    int limitY_bottom;
    char cpng1[V], cpng2[V], cpng3[V], cpng4[V], cpng5[V], cpng6[V], cpng7[V], cpng8[V], cpng9[V], cpng10[V], cpng11[V], cpng12[V], cpng13[V], cpng14[V], cpng15[V], cpng16[V], cpng17[V], cpng18[V], cpng19[V], cpng20[V];
};

#endif