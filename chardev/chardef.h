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
#define GAME_TRUE 1
#define GAME_FALSE 0
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
#define _MAX_CPNG 1000

typedef char * String;
typedef String Texture;
typedef float matix4[4][4];
typedef int length_draws[_MAX_CPNG];

typedef struct texture{
    int id;
    int color;
    int mode_save;
    String file_texture;
    Texture texture;
}texture;

typedef struct {
    int posX;
    int posY;
    float positionX;
    float positionY;
    int id_cpng;
    int color;
    int mode_save;
    int var_i;
    float var_f;
    String name;
    String asset;
    String changes_x;
    String changes_y;
    String copy_asset;
    struct{
        int id_entity;
        int attack;
        int health;
        int hit_box;
    }entity;
    texture Texture;
} cpng;

typedef struct{
    char screen[100][100];
    int width, height;
    int ini_espace_x;
    int ini_espace_y;
    int limitX_1;
    int limitX_2;
    int limitY_1;
    int limitY_2;
    int limitX_r;
    int limitX_iz;
    int limitY_up;
    int limitY_down;
    int space_x;
    int space_y;
    char C[50];
    String name;
    int id;
    int color;
    String name_scene;
    Texture background;
    int (*addDraw)(cpng *);
    int (*clearScene)();
    float (*showFps)();
    void (*clearAscii)();
    void (*addPosXY)(int, int);
    void (*center_text)(const String);
    char (*genChar)();
    int (*genRandom)(int);
    int (*readFile)(const String);
    void (*showCoordDraw)(cpng *);
    int (*saveDraw)(cpng *);
    int (*readDraw)(cpng *);
    int (*movRandDraw)(cpng * , int, int, int, int, int);
    //int (*movRandPosOp)(cpng * , int, int, int, int, int, int, *(callback)());
    int (*movDrawFunc)(cpng * , const String, const String, const String, const String, const String, void (*callback)());
    int (*drawWait)(int);
    int (*deleteDraw_)(cpng *);
    int (*getDrawID)(cpng *);
    int (*movDraw)(cpng *, const String, const String, const String, const String);
    int (*movDraw_)(cpng * cpng, const String, const String, const String, const String, const String, const String, const String, const String);
    int (*movDrawPos)(cpng *, const String, const String, const String, const String);
    int (*duplicDraw)(cpng *, int, int);
    void (*addColor)(int);
    int (*addText)(const String, ...);
    void (*renderDraws)(cpng *);
    void (*rgba)(int, int, int, int);
    void (*addJumpsLines)(int);
    void (*hiddenCursor)(int);
    void (*addTitleConsole)(const String);
    char (*getKey)();
} Scene;

#endif
