#ifndef CHARDEF_H
#define CHARDEF_H

#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define READKEY() getch()
#define READLINE() getche()
#define NAMES_LONG 50
#define CPNG_ERROR_FILE -10
#define CPNG_ERROR -2
#define TEXTURE_ERROR -5
#define ERROR -1
#define KEY_A 'a'
#define KEY_B 'b'
#define KEY_C 'c'
#define KEY_D 'd'
#define KEY_E 'e'
#define KEY_F 'f'
#define KEY_G 'g'
#define KEY_H 'h'
#define KEY_I 'i'
#define KEY_J 'j'
#define KEY_K 'k'
#define KEY_L 'l'
#define KEY_N 'n'
#define KEY_M 'm'
#define KEY_O 'o'
#define KEY_P 'p'
#define KEY_Q 'q'
#define KEY_R 'r'
#define KEY_S 's'
#define KEY_T 't'
#define KEY_U 'u'
#define KEY_V 'v'
#define KEY_W 'w'
#define KEY_X 'x'
#define KEY_Y 'y'
#define KEY_Z 'z'
#define KEY_NULL NULL
#define KEY_0 '0'
#define KEY_1 '1'
#define KEY_2 '2'
#define KEY_3 '3'
#define KEY_4 '4'
#define KEY_5 '5'
#define KEY_6 '6'
#define KEY_7 '7'
#define KEY_8 '8'
#define KEY_9 '9'
#define KEY_10 '10'
#define KEY_POINT '.'
#define KEY_ ','
#define XE6 ';'
#define _KEY_UP 0x48
#define _KEY_DOWN 0x50
#define _KEY_LEFT  0x4b
#define _KEY_RIGHT 0x4d
#define _KEY_ESCAPE 0x1b
#define _KEY_RETURN 0x0d
#define OK 1
#define CANCEL 0
#define _PI                   3.14159265358979323846f
#define ARRAYSIZE(_ARR)      ((int)(sizeof(_ARR)/sizeof(*_ARR)))

enum gamebool {
    GAMEFALSE,
    GAMETRUE
};

enum colorsgame {
    blue = 1,
    green_1,
    cyan_1,
    red_1,
    pink_1,
    yellow_1,
    white,
    gris,
    morado_1,
    green_2,
    cyan_2,
    red_2,
    pink_2,
    yellow_2
};

typedef int pos;
typedef char * String;

struct Entity{
    int id;
    String name;
    int attack;
    int healt;
    int boxCollision;
    int range;
};

typedef struct {
    pos X;
    pos Y;
    int id;
    int color;
    int aux;
    int files;
    int columns;
    String name;
    String asset;
    String url;
    string lecture_file;
    struct Entity entity;
}cpng;

typedef struct {
    int id;
    String name;
    int limit_right;
    int limit_left;
    int limit_up;
    int limit_down;
    int color;
    cpng object;
    int sizeConsole[2];
    int fps_;
    float fps;
    void (*addCpng)(cpng * );
    void (*addCpngOnly)(cpng *);
    void (*coordCpng)(cpng * );
    void (*addCpngFile)(cpng * );
    void (*addCpngFileOnly)(cpng *);
    void (*setColor)(int);
    int (*addText)(const String, ...);
    void (*rgba)(int,int,int,int);
    void (*addJumpLine)(int);
    void (*addJumpLineColor)(int,int);
    void (*duplicCpng)(cpng *, int, int);
    void (*duplicChar)(const String , int,int);
    void (*duplicCpngFile)(cpng *, int,int);
    void (*saveCpngFile)(cpng *);
    void (*gotoXY)(int, int);
    void (*centerText)(const String);
    int (*getRandomInt)(int);
    char (*getRandomChar)();
    void (*readLine)();
    int (*readKey)();
    void (*hiddenCursor)();
    void (*addTitleConsole)();
    void (*clearConsole)();
    float (*showFps)();
    void (*printChar)(int, ...);
    int (*getSizeConsoleX)();
    int (*getSizeConsoleY)();
    struct{
        void (*moveCpng)(cpng *, const String,const String,const String,const String);
        void (*moveCpngDiagonal)(cpng *, const String,const String,const String,const String,const String,const String,const String,const String);
        void (*moveCpngFunc)(cpng * ,const String,const String,const String,const String,const String,void (*callback)());
        void (*moveCpngDiagonalFunc)(cpng *, const String, const String, const String, const String, const String, const String, const String, const String, const String, void (*callback)());
        void (*moveCpngOnly)(cpng *, int,int, int, int, int);
        void (*moveCpngOnlyDiagonal)(cpng *, int,int,int,int,int,int,int,int,int);
        void (*moveCpngOnlyFunc)(cpng *, int, int,int,int,int, int, void (*callback)());
        void (*moveCpngOnlyDiagonalFunc)(cpng *, int, int,int,int,int,int,int,int,int, int, void (*callback)());
        void (*setLimitCpng)(cpng *, int, int, int, int);
        void (*setLimitCpng_)();
    }mov;
    struct{
        int (*createFile)(const String, const String, const String);
        int (*readFile)(const String);
        int (*extractDataFileCpng)(char matriz[][1024], cpng *);
        int (*extractDataFile)(char matriz[][1024], const String, int, int);
        int (*saveCpng)(cpng *);
    }Files;
    struct{
        int datos_xd;
    }vec;
}scene;

#endif
