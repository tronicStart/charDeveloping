#ifndef ASSETS_H
#define ASSETS_H

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#include "strtypes.h"
#include "strfiles.h"

void draw_square(int size, const char * c) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                printf("%s ",c);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int createImg (char nombre[1024], const char *Contenido){
    
    char cat[1024] = ".img";
	char nose[1024];

	FILE *file;

	strcpy(nose, nombre);

	strcat(nose, cat);

	file = fopen(nose, "w");

	if (file == NULL)
	{
		perror("Escrity ");
		return -1;
	}

	fprintf(file, "%s", Contenido);
	printf("Se ha guardado\n");
    
}

void readImg(char nombre[1024]){
    
    char cat[1024] = ".img";
	char nose[1024];

	FILE *file;

	strcpy(nose, nombre);

	strcat(nose, cat);

	file = fopen(nose, "r");

	if (file == NULL)
	{
		perror("Escrity ");
		return;
	}
    StringReadFileModeRB(nose);
    
}

void readAsset(char nombre[1024]){
    
    char cat[1024] = ".asset";
	char nose[1024];

	FILE *file;

	strcpy(nose, nombre);

	strcat(nose, cat);

	file = fopen(nose, "r");

	if (file == NULL)
	{
		perror("Escrity ");
		return;
	}
    StringReadFileModeRB(nose);
    
}

void screen_flash(const char * color){
    
    char str[9]="color   ";
    char sym[17]="0123456789ABCDEF";
    str[6]=sym[rand()%17];
    str[7]=sym[rand()%17];
    system(str);
    Sleep(3);
    str[6]=sym[rand()%17];
    str[7]=sym[rand()%17];
    system(str);
    Sleep(3);
    str[6]=sym[rand()%17];
    str[7]=sym[rand()%17];
    system(str);
    Sleep(3);
    system(color);
    
}

void move_char (let X , let Y , String player , String key1 , String key2 , String key3 , String key4){
    
    char Keey;

    HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = X;
	dwPos.Y = Y;

	SetConsoleCursorPosition(hCon, dwPos);
	printf("%s\n",player);

	Keey = getch();

	//Movimiento en X
	if(Keey == key1){

	   if(key1 == NULL){
	       return;
	   }

	   X--;
	}

	if(Keey == key2){

	   if(key2 == NULL){
	       return;
	   }

	   X++;
	}

	if(Keey == key3){

	   if(key3 == NULL){
	       return;
	   }

	   Y++;
	}

	if(Keey == key4){

	   if(key4 == NULL){
	       return;
	   }

	   Y--;
	}
    
}

void draw_triangle(int size, const char * c) {
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("%s",c);
        }
        printf("\n");
    }
}

void return_circle(int size, int x_center, int y_center) {
    int x = 0, y = size;
    int d = 3 - 2 * size;

    while (y >= x) {
        // imprimir los puntos en los octantes
        printf("%d, %d\n", x_center + x, y_center + y);
        printf("%d, %d\n", x_center + y, y_center + x);
        printf("%d, %d\n", x_center - x, y_center + y);
        printf("%d, %d\n", x_center - y, y_center + x);
        printf("%d, %d\n", x_center + x, y_center - y);
        printf("%d, %d\n", x_center + y, y_center - x);
        printf("%d, %d\n", x_center - x, y_center - y);
        printf("%d, %d\n", x_center - y, y_center - x);

        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void file_scene_(const char nameAsset[1024]){
    
    char cat[1024] = ".sce";
    char nose[1024];

    FILE *file;

    strcpy(nose, nameAsset);

    strcat(nose, cat);

    file = fopen(nose, "r");

    StringReadFileModeRB(nose);
    
}

void colorRGBA(int R, int G, int B, int A){
    
    if (A == 0){
        if (R && G && B == 1){ //Red , Green and blue on
            HANDLE out;
            out = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(out, 7);
            return;
        }
        if (R == 1){ //Red on
            HANDLE out;
            out = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(out, 4);
            if (R && G == 1){ //Red and Green on / Yellow
                HANDLE out;
                out = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(out, 6);
                return;
            }
            if (R && B == 1){ //Red and Blue / Pink
                HANDLE out;
                out = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(out, 5);
                return;
            }
            return;
        }
        if (G == 1){ //Green on
            HANDLE out;
            out = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(out, 2);
            if (G && R == 1){ //Green and Red on / Yellow
                HANDLE out;
                out = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(out, 6);
                return;
            }
            if (G && B == 1){ //Green and Blue on / Cyan
                HANDLE out;
                out = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(out, 11);
                return;
            }
            return;
        }
        if (B == 1){ //Blue on
            HANDLE out;
            out = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(out, 1);
            if (B && R == 1){ //Blue and Red on / Pink
                HANDLE out;
                out = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(out, 5);
                return;
            }
            if (B && G == 1){ //Blue and Green on / Cyan
                HANDLE out;
                out = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(out, 11);
                return;
            }
            return;
        }
        else
        {
            HANDLE out;
            out = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(out, 0);
        }
    }
    //Colores mas intensos
    else if (A == 1){
        if (R && G && B == 1){ //Red , Green and blue on
            HANDLE out;
            out = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(out, 7);
            return;
        }
        if (R == 1){ //Red on
            HANDLE out;
            out = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(out, 68);
            if (R && G == 1){ //Red and Green on / Yellow
                HANDLE out;
                out = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(out, 102);
                return;
            }
            if (R && B == 1){ //Red and Blue / Pink
                HANDLE out;
                out = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(out, 85);
                return;
            }
            return;
        }
        if (G == 1){ //Green on
            HANDLE out;
            out = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(out, 34);
            if (G && R == 1){ //Green and Red on / Yellow
                HANDLE out;
                out = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(out, 102);
                return;
            }
            if (G && B == 1){ //Green and Blue on / Cyan
                HANDLE out;
                out = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(out, 51);
                return;
            }
            return;
        }
        if (B == 1){ //Blue on
            HANDLE out;
            out = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(out, 17);
            if (B && R == 1){ //Blue and Red on / Pink
                HANDLE out;
                out = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(out, 85);
                return;
            }
            if (B && G == 1){ //Blue and Green on / Cyan
                HANDLE out;
                out = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(out, 51);
                return;
            }
            return;
        }
        else
        {
            HANDLE out;
            out = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(out, 0);
        }
    }
}

void colorRGB(int R , int G , int B){
    
    if(R&&G&&B == 1){//Red , Green and blue on
        HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(out,7);
    	return;
    }
    if(R == 1){//Red on
        HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(out,4);
    	if(R&&G == 1){//Red and Green on / Yellow
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,6);
        	return;
        }
        if(R&&B == 1){//Red and Blue / Pink
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,5);
        	return;
        }
    	return;
    }
    if(G == 1){//Green on
        HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(out,2);
    	if(G&&R == 1){//Green and Red on / Yellow
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,6);
        	return;
        }
        if(G&&B == 1){//Green and Blue on / Cyan
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,11);
        	return;
        }
    	return;
    }
    if(B == 1){//Blue on
        HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(out,1);
    	if(B&&R == 1){//Blue and Red on / Pink
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,5);
        	return;
        }
        if(B&&G == 1){//Blue and Green on / Cyan
            HANDLE out;
            out=GetStdHandle(STD_OUTPUT_HANDLE);
        	SetConsoleTextAttribute(out,11);
        	return;
        }
    	return;
    }
    else{
        HANDLE out;
        out=GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(out,0);
    }
    
}

#endif
