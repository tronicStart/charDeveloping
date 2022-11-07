#ifndef _COBJS_H
#define _COBJS_H

#include "objects.h"
#include "cfile.h"
#include "cdef.h"
#include "ctipes.h"
#include <windows.h>

struct Scene{
    //Limites de la esena
    int limitX;
    int limitX2;
    int limitY;
    int limitY2;

    int ID;
    public name[V];

    int Gravity;
    f ObjectInSceneGravity;
    int ObjectInSceneGravityDX;
    
    int color , blocks;

};

void createImg (char nombre[1024], const char *Contenido){
    
    char cat[1024] = ".img";
	char nose[1024];

	FILE *file;

	strcpy(nose, nombre);

	strcat(nose, cat);

	file = fopen(nose, "w");

	if (file == NULL)
	{
		perror("Escrity ");
		return;
	}

	fprintf(file, "%s", Contenido);
	printf("Escrity: Se ha guardado\n");
    
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
void readSprit(char nombre[1024]){
    
    char cat[1024] = ".sprit";
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
Override save_dataProject(char nombre[1024], const char *Contenido, const char *User, const char *Company){
    
    char cat[1024] = ".dat";
	char nose[1024];

	FILE *file;

	strcpy(nose, nombre);

	strcat(nose, cat);

	file = fopen(nose, "w");

	if (file == NULL)
	{
		printf("Escrity: \" %s \" No se pudo crear", nombre);
		return;
	}

	fprintf(file, "%s\nProyectUser %s\nCompany: %s", Contenido, User, Company);
	printf("Escrity: Se ha guardado los datos\n");
    
}
Override read_dataProject(char nombre[1024]){
    
    char cat[1024] = ".dat";
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
static Override Juego_ImprimeF(String *  __fmt, ...){
    
    printf(__fmt);
    
}
static void charClear (){
    
    system("cls");
    
}
static void charNewLines (int cand){
    
    if(cand == 1){
		printf("\n");
	}
	else if(cand == 2){
		printf("\n\n");
	}
    
}
static int Juego_Lee_Tecla(){
    
    return getch();
    
}
Override creatorSprit(char nombre_de_archivo[1024]){
    
    FILE *db;
	char caracters[1024] = {'%', '\\', '|', '=', '[', ']', '<', '>', '{', '}', '@', '#', '$', '_', '&', '-', '+', '(', ')', '/', '*', '\"', '\'', ':', ';', '!', '?', '~', '`', 'N' , 'A' , 'B' , 'C'};
	int opcion = 1;

	int i;

	char cat[1024] = ".sprit";
	char nose[1024];

	strcpy(nose, nombre_de_archivo);

	strcat(nose, cat);

	db = fopen(nose, "a");

	if (db == NULL)
	{
		perror("char ");
	}

	while (opcion != 33)
	{
		charClear();
		printf("\n\nGuardando en: %s\n", nose);
		printf("                                  CreatorSprits\n\n");
		printf("Opciones: 0 - 32\n\n");
		printf("33 para terminar\n\n");
		printf("Version: 1.1\n\n");
		printf("Marterial: \n\n");
		for (i = 0; i < 30; i++)
		{
			printf(" [%c] ", caracters[i]);
		}

		charNewLines(1);
		printf("\n");
		printf(">> ");
		opcion = StrScanInt(opcion);
		charNewLines(1);

		if (opcion == 0)
		{
			fprintf(db, "%c", caracters[0]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[0]);
			Juego_Lee_Tecla();
		}
		else if (opcion == 1)
		{
			fprintf(db, "%c", caracters[1]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[1]);
			Juego_Lee_Tecla();
		}
		if (opcion == 2)
		{
			fprintf(db, "%c", caracters[2]);
		    printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[2]);
			Juego_Lee_Tecla();
		}
		else if (opcion == 3)
		{
			fprintf(db, "%c", caracters[3]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[3]);
			Juego_Lee_Tecla();
		}
		if (opcion == 4)
		{
			fprintf(db, "%c", caracters[4]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[4]);
			Juego_Lee_Tecla();
		}
		else if (opcion == 5)
		{
			fprintf(db, "%c", caracters[5]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[5]);
			Juego_Lee_Tecla();
		}
		if (opcion == 6)
		{
			fprintf(db, "%c", caracters[6]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[6]);
			Juego_Lee_Tecla();
		}
		else if (opcion == 7)
		{
			fprintf(db, "%c", caracters[7]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[7]);
			Juego_Lee_Tecla();
		}
		if (opcion == 8)
		{
			fprintf(db, "%c", caracters[8]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[8]);
			Juego_Lee_Tecla();
		}
		else if (opcion == 9)
		{
			fprintf(db, "%c", caracters[9]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[9]);
			Juego_Lee_Tecla();
		}
		if (opcion == 10)
		{
			fprintf(db, "%c", caracters[10]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[10]);
			Juego_Lee_Tecla();
		}
		else if (opcion == 11)
		{
			fprintf(db, "%c", caracters[11]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[11]);
			Juego_Lee_Tecla();
		}
		if (opcion == 12)
		{
			fprintf(db, "%c", caracters[12]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[12]);
			Juego_Lee_Tecla();
		}
		else if (opcion == 13)
		{
			fprintf(db, "%c", caracters[13]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[13]);
			Juego_Lee_Tecla();
		}
		if (opcion == 14)
		{
			fprintf(db, "%c", caracters[14]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[14]);
			Juego_Lee_Tecla();
		}
		else if (opcion == 15)
		{
			fprintf(db, "%c", caracters[15]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[15]);
			Juego_Lee_Tecla();
		}
		if (opcion == 16)
		{
			fprintf(db, "%c", caracters[16]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[16]);
			Juego_Lee_Tecla();
		}
		else if (opcion == 17)
		{
			fprintf(db, "%c", caracters[17]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[17]);
			Juego_Lee_Tecla();
		}
		if (opcion == 18)
		{
			fprintf(db, "%c", caracters[18]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[18]);
			Juego_Lee_Tecla();
		}
		else if (opcion == 19)
		{
			fprintf(db, "%c", caracters[19]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[19]);
			Juego_Lee_Tecla();
		}
		if (opcion == 20)
		{
			fprintf(db, "%c", caracters[20]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[20]);
			Juego_Lee_Tecla();
		}
		else if (opcion == 21)
		{
			fprintf(db, "%c", caracters[21]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[21]);
			Juego_Lee_Tecla();
		}
		if (opcion == 22)
		{
			fprintf(db, "%c", caracters[22]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[22]);
			Juego_Lee_Tecla();
		}
		else if (opcion == 23)
		{
			fprintf(db, "%c", caracters[23]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[23]);
			Juego_Lee_Tecla();
		}
		if (opcion == 24)
		{
			fprintf(db, "%c", caracters[24]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[24]);
			Juego_Lee_Tecla();
		}
		else if (opcion == 25)
		{
			fprintf(db, "%c", caracters[25]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[25]);
			Juego_Lee_Tecla();
		}
		if (opcion == 26)
		{
			fprintf(db, "%c", caracters[26]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[26]);
			Juego_Lee_Tecla();
		}
		else if (opcion == 27)
		{
			fprintf(db, "%c", caracters[27]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[27]);
			Juego_Lee_Tecla();
		}
		if (opcion == 28)
		{
			fprintf(db, "%c", caracters[28]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[28]);
			Juego_Lee_Tecla();
		}
		else if (opcion == 29)
		{
			fprintf(db, "%c", caracters[29]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[29]);
			Juego_Lee_Tecla();
		}
		if (opcion == 30)
		{
			fprintf(db, "%c", caracters[30]);
			printf("StringLibrary: Se ha guardado el caracter: [%c]\n", caracters[30]);
			Juego_Lee_Tecla();
		}
		else if (opcion == 31)
		{
			fprintf(db, " ");
			printf("StringLibrary: Se ha guardado el caracter: [ ]\n");
			Juego_Lee_Tecla();
		}
		if (opcion == 32)
		{
			fprintf(db, "\n");
			printf("StringLibrary: Se ha guardado el caracter: [\\n]\n");
			Juego_Lee_Tecla();
		}
		else if (opcion == 34)
		{
			StringReadFileModeRB(nose);
			system("pause");
		}
	}

	fclose(db);
    
}
void creator_cpngs (char nombre_de_archivo[1024]){
    
    
    
}//this new
void save_content_vector(let Vxy[][20] , char nombre[1024]){
    
    let i , j;

	char cat[1024] = ".vec";
	char nose[1024];

	FILE *file;

	strcpy(nose, nombre);

	strcat(nose, cat);

	file = fopen(nose, "a");

	if (file == NULL)
	{
		perror("StringLibrary");
		return;
	}

	for(i = 0; i < 20; i++){
		for(j = 0; j < 20; j++){
			fprintf(file,"%c",Vxy[i][j]);
		}
		fprintf(file,"\n");
	}
    
}
Override read_content_fileVector(char nombre[1024]){
    
    char cat[1024] = ".vec";
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

	StringReadFile(nose);
    
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
void file_scene_(const char nameAsset[1024]){
    
    char cat[1024] = ".sce";
    char nose[1024];

    FILE *file;

    strcpy(nose, nameAsset);

    strcat(nose, cat);

    file = fopen(nose, "r");

    StringReadFileModeRB(nose);
    
}

static void _view_(int URL){
    
    if (URL == 20)
    {
        printf("[ ] = %d", URL);
        return;
    }
    else if (URL == 21)
    {
        printf("[\\n] = %d", URL);
        return;
    }
    
    printf("Number: %d\n",URL);
    
}
void create_scene_(char File[1024]){
    
    
    
}
int load_scene_(struct _scenes_ *Scene){
    
    void *voidID = NULL;

    if (Scene->id == (int)voidID)
    {
        printf("Error in _scene_: %s : this id type NULL | function error: load_scene_(struct _scenes_ * Scene); -1\n", Scene->name);
        return -1;
    }
    else
    {
        file_scene_(Scene->name);
    }
    
}//Line 532 the file "testing.c"
int creator_scene_(struct _scenes_ *Scene){
    
    char _scene_large[20];
    FILE *db;
    int opcion = 0;
    int Randomm = 0;

    int i;

    char cat[1024] = ".sce";
    char nose[1024];
    
    void * voidID = NULL;
    
    strcpy(nose, Scene->name);

    strcat(nose, cat);

    db = fopen(nose, "a");

    if (db == NULL){
        perror("Stringgame ");
    }
    
    if(Scene->id == (int)voidID){
        printf("Error in _scene_: %s : this id type NULL | function error: StrCreate_scene_(struct _scenes_ * Scene); -1\n",Scene->name);
        return -1;
    }
    
    if(Scene->actives == (int)voidID || Scene->actives == 0 || Scene->actives == -1){
        return -1;
    }
    
    _scene_large[0] = *Scene->cpng1;
    _scene_large[1] = *Scene->cpng2;
    _scene_large[2] = *Scene->cpng3;
    _scene_large[3] = *Scene->cpng4;
    _scene_large[4] = *Scene->cpng5;
    _scene_large[5] = *Scene->cpng6;
    _scene_large[6] = *Scene->cpng7;
    _scene_large[7] = *Scene->cpng8;
    _scene_large[8] = *Scene->cpng9;
    _scene_large[9] = *Scene->cpng10;
    _scene_large[10] = *Scene->cpng11;
    _scene_large[11] = *Scene->cpng12;
    _scene_large[12] = *Scene->cpng13;
    _scene_large[13] = *Scene->cpng14;
    _scene_large[14] = *Scene->cpng15;
    _scene_large[15] = *Scene->cpng16;
    _scene_large[16] = *Scene->cpng17;
    _scene_large[17] = *Scene->cpng18;
    _scene_large[18] = *Scene->cpng19;
    _scene_large[19] = *Scene->cpng20;
    
    while (opcion != 23)
    {
        charClear();
        StrGotoXY(31, 2);
        printf("Editor Scenes\n\n");
        printf("Nombre de la _scene_: %s\n", nose);

        //printf("Memoria estatica ocupada: %dBytes - 4,98kb\n",memory);
        printf("Opciones: 0 - 22 para caracteres 23 para salir\n\n");
        printf("Version del editador: 1.0\n\n");
        printf("Numero anterior\n\n\n");
        _view_(opcion,Scene);
        printf("\n\n\nMarterial:\n\n");
        for (i = 0; i < Scene->actives; i++)
        {
            printf(" [%c] ", _scene_large[i]);
        }

        charNewLines(1);
        printf("\n");
        printf(">> ");
        opcion = StrScanInt(opcion);
        //GotoXY(0,14);
        charNewLines(1);

        if (opcion == 0)
        {
            fprintf(db, "%c", _scene_large[0]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", _scene_large[0]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 1)
        {
            fprintf(db, "%c", _scene_large[1]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", _scene_large[1]);
            Juego_Lee_Tecla();
        }
        if (opcion == 2)
        {
            fprintf(db, "%c", _scene_large[2]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", _scene_large[2]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 3)
        {
            fprintf(db, "%c", _scene_large[3]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", _scene_large[3]);
            Juego_Lee_Tecla();
        }
        if (opcion == 4)
        {
            fprintf(db, "%c", _scene_large[4]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", _scene_large[4]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 5)
        {
            fprintf(db, "%c", _scene_large[5]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", _scene_large[5]);
            Juego_Lee_Tecla();
        }
        if (opcion == 6)
        {
            fprintf(db, "%c", _scene_large[6]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", _scene_large[6]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 7)
        {
            fprintf(db, "%c", _scene_large[7]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", _scene_large[7]);
            Juego_Lee_Tecla();
        }
        if (opcion == 8)
        {
            fprintf(db, "%c", _scene_large[8]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", _scene_large[8]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 9)
        {
            fprintf(db, "%c", _scene_large[9]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", _scene_large[9]);
            Juego_Lee_Tecla();
        }
        if (opcion == 10)
        {
            fprintf(db, "%c", _scene_large[10]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", _scene_large[10]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 11)
        {
            fprintf(db, "%c", _scene_large[11]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", _scene_large[11]);
            Juego_Lee_Tecla();
        }
        if (opcion == 12)
        {
            fprintf(db, "%c", _scene_large[12]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", _scene_large[12]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 13)
        {
            fprintf(db, "%c", _scene_large[13]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", _scene_large[13]);
            Juego_Lee_Tecla();
        }
        if (opcion == 14)
        {
            fprintf(db, "%c", _scene_large[14]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", _scene_large[14]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 15)
        {
            fprintf(db, "%c", _scene_large[15]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", _scene_large[15]);
            Juego_Lee_Tecla();
        }
        if (opcion == 16)
        {
            fprintf(db, "%c", _scene_large[16]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", _scene_large[16]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 17)
        {
            fprintf(db, "%c", _scene_large[17]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", _scene_large[17]);
            Juego_Lee_Tecla();
        }
        if (opcion == 18)
        {
            fprintf(db, "%c", _scene_large[18]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", _scene_large[18]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 19)
        {
            fprintf(db, "%c", _scene_large[19]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", _scene_large[19]);
            Juego_Lee_Tecla();
        }
        
        if (opcion == 20)
        {
            fprintf(db, " ");
            printf("Stringgame: Se ha guardado el caracter: [ ]\n");
            Juego_Lee_Tecla();
        }
       else if (opcion == 21)
        {
            fprintf(db, "\n");
            printf("Stringgame: Se ha guardado el caracter: [\\n]\n");
            Juego_Lee_Tecla();
        }
        
        if(opcion == 22){
            
            Randomm = StrGenereRandom(0,20);
            
            fprintf(db, "%c", _scene_large[Randomm]);

            printf("Stringgame: Se ha guardado los caracteres: %c", _scene_large[Randomm]);

            Juego_Lee_Tecla();
            
        }
    }
    
}
static void _view (int URL, struct _scenes_ *Scene);//the function creator scene
{
    
    if (URL == 20)
    {
        printf("[ ] = %d", URL);
        return;
    }
    else if (URL == 21)
    {
        printf("[\\n] = %d", URL);
        return;
    }

    char _scene_large[20];
    
    _scene_large[0] = *Scene->cpng1;
    _scene_large[1] = *Scene->cpng2;
    _scene_large[2] = *Scene->cpng3;
    _scene_large[3] = *Scene->cpng4;
    _scene_large[4] = *Scene->cpng5;
    _scene_large[5] = *Scene->cpng6;
    _scene_large[6] = *Scene->cpng7;
    _scene_large[7] = *Scene->cpng8;
    _scene_large[8] = *Scene->cpng9;
    _scene_large[9] = *Scene->cpng10;
    _scene_large[10] = *Scene->cpng11;
    _scene_large[11] = *Scene->cpng12;
    _scene_large[12] = *Scene->cpng13;
    _scene_large[13] = *Scene->cpng14;
    _scene_large[14] = *Scene->cpng15;
    _scene_large[15] = *Scene->cpng16;
    _scene_large[16] = *Scene->cpng17;
    _scene_large[17] = *Scene->cpng18;
    _scene_large[18] = *Scene->cpng19;
    _scene_large[19] = *Scene->cpng20;
    
    printf("[  %c ] = %d\n",_scene_large[URL],URL);
    
}
void showRenderPaint(struct _scenes_ *Scene){
    
    printf("Render Paint: %d\n", Scene->fps);
    
}
let paint_scene(struct _scenes_ *Scene){
    
    int error;

    error = load_scene_(Scene);

    if (error == -1)
    {
        return -1;
    }
    
}

void showObjectCoordinates(struct Object *object){
    
    printf("Coordinates:'%s': X = %d | Y = %d | ID: %d\n", object->Name, object->positionX, object->positionY, object->ID);
    
}

void moveObjectCPNG(struct cpng *posPlayer, const char *key1, const char *key2, const char *key3, const char *key4){
    
    char Keey;

    HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = posPlayer->X;
	dwPos.Y = posPlayer->Y;

	SetConsoleCursorPosition(hCon, dwPos);
	printf("%s\n",posPlayer->data);

	Keey = getch();

	//Movimiento en X
	if(Keey == key1){

	   if(key1 == NULL){
	       return;
	   }

	   posPlayer->X--;
	}

	if(Keey == key2){

	   if(key2 == NULL){
	       return;
	   }

	   posPlayer->X++;
	}

	if(Keey == key3){

	   if(key3 == NULL){
	       return;
	   }

	   posPlayer->Y++;
	}

	if(Keey == key4){

	   if(key4 == NULL){
	       return;
	   }

	   posPlayer->Y--;
	}
    
}

void moveObject(struct Object *posPlayer, const char *player, const char *key1, const char *key2, const char *key3, const char *key4){
    
    char Keey;

    HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = posPlayer->X;
	dwPos.Y = posPlayer->Y;

	SetConsoleCursorPosition(hCon, dwPos);
	printf("%s\n",player);

	Keey = getch();

	//Movimiento en X
	if(Keey == key1){

	   if(key1 == NULL){
	       return;
	   }

	   posPlayer->X--;
	}

	if(Keey == key2){

	   if(key2 == NULL){
	       return;
	   }

	   posPlayer->X++;
	}

	if(Keey == key3){

	   if(key3 == NULL){
	       return;
	   }

	   posPlayer->Y++;
	}

	if(Keey == key4){

	   if(key4 == NULL){
	       return;
	   }

	   posPlayer->Y--;
	}
    
}

int ini_scenes(struct _scenes_ *Scene){
    
    void *voidID = NULL;

    int i;

    if (Scene->id == (int)voidID)
    {
        printf("Error in _scene_: %s : this id type NULL | function error: StrLoad_scene_(struct _scenes_ * Scene); -1\n", Scene->name);
        return -1;
    }
    else
    {
        for (i = 0; i < Scene->calls; i++)
        {
            showRenderPaint(Scene);
            file_scene_(Scene->name);

            usleep(Scene->time_calls);
            system("clear");

            if (i == Scene->calls - 1)
            {
                Scene->fps = Scene->calls;
                i = 0;
            }
        }
    }
}

void start_limit_scenes_(struct _scenes_ *Scene, struct Object *object){
    
    if (object->positionX == Scene->limitX_left)
    {
        object->positionX++;
    }
    if (object->positionY == Scene->limitY_top)
    {
        object->positionY++;
    }
    if (object->positionX == Scene->limitX_rigth)
    {
        object->positionX--;
    }
    if (object->positionY == Scene->limitY_bottom)
    {
        object->positionY--;
    }
    
}

int rp_music(String * Music){
    
    PlaySound( TEXT(Music), NULL, SND_ASYNC);
    
}

int ini_scenes_ob(struct _scenes_ *Scene, struct Object *ob, const char *C, const char *A, const char *D, const char *S, const char *W){
    
    void *voidID = NULL;

    int i;

    if (Scene->id == (int)voidID)
    {
        printf("Error in _scene_: %s : this id type NULL | function error: StrLoad_scene_(struct _scenes_ * Scene); -1\n", Scene->name);
        return -1;
    }
    else
    {
        for (i = 0; i < Scene->calls; i++)
        {
            usleep(Scene->time_calls);
            system("clear");
            StrStartLimit_scenes(Scene, ob);
            StrShowObjectCoordinates(ob);
            file_scene_(Scene->name);
            StrMoveObject(ob, C, A, D, S, W);

            if (i == Scene->calls - 1)
            {
                Scene->fps = Scene->calls;
                i = 0;
            }
        }
    }
    
}
void paintNewObject(struct newObject *Ob, const char *C){
    
    void *voidID = NULL;

    if (Ob->ID == (int)voidID)
    {
        printf("The function StrPaintNewObject() detect a error in ID struct | ID type void | OBJECT: '%s'\n", Ob->name);
        return;
    }

    else
    {
        StrGotoXY(Ob->positionX, Ob->positionY);
        printf("%s", C);
    }
    
}
void show_position_NewObject(struct newObject *ob){
    
    printf("Position the Object '%s': X = %d | Y = %d\n", ob->name, ob->positionX, ob->positionY);
    
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
int boxCollisionActionObjectRigtLefthInX(struct box_collision *object, struct box_collision *newObject, struct Object *ob, struct newObject *new){
    
    if (object->id == (int)NULL || newObject->id == (int)NULL)
    {
        printf("Error detect in fuction: StrBoxCollisonActionObject(); detect ID NULL in boxCollision: '%s'\n", object->name);
        return -1;
    }

    if (newObject->id == (int)NULL)
    {
        printf("Error detect in fuction: StrBoxCollisonActionObject(); detect ID NULL in boxCollision: '%s'\n", newObject->name);
        return -1;
    }

    if (object->id == newObject->id)
    {
        printf("Error detect in fuction StrBoxCollisionActionObject(); detect ID object = ID newObject\n");
        return -1;
    }

    else
    {
        if (ob->positionX + object->posObject.BOXright == new->positionX - newObject->otherObject.BOXLetf / -1)
        {
            ob->positionX--;
            object->condition = true;
        }
    }
}
void StrDebugCollisionRigthLeftInX(struct box_collision *object, struct box_collision *newObject, struct Object *ob, struct newObject *new){
    
    if (object->id == (int)NULL || newObject->id == (int)NULL)
    {
        colorRGBA(1, 0, 0, 0);
        printf("Error detect in fuction: StrBoxCollisonActionObject(); detect ID NULL in boxCollision: '%s'\n", object->name);
        colorRGBA(1, 1, 1, 0);
        return;
    }

    if (newObject->id == (int)NULL)
    {
        colorRGBA(1, 0, 0, 0);
        printf("Error detect in fuction: StrBoxCollisonActionObject(); detect ID NULL in boxCollision: '%s'\n", newObject->name);
        colorRGBA(1, 1, 1, 0);
        return;
    }

    if (object->id == newObject->id)
    {
        colorRGBA(1, 0, 0, 0);
        printf("Error detect in fuction StrBoxCollisionActionObject(); detect ID object = ID newObject\n");
        colorRGBA(1, 1, 1, 0);
        return;
    }

    else
    {
        colorRGBA(1, 0, 1, 0);
        printf("Verify Collisions: objects: '%s' and '%s'\n",ob->Name,new->name);
        printf("(Object)%s : X = %d , Y = %d , BOXrigth = %d | (newObject)%s : X = %d , Y = %d , BOXLetf = %d \n", ob->Name, ob->positionX, ob->positionY, object->posObject.BOXright, new->name, new->positionX, new->positionY, newObject->otherObject.BOXLetf);
        printf("(Object)%s : X = %d + BOXrigth = %d same (newObject)%s : X = %d - BOXLetf = %d/ -1 = (%d)\n", ob->Name, ob->positionX, object->posObject.BOXright, new->name, new->positionX, newObject->otherObject.BOXLetf, ob->positionX + object->posObject.BOXright ? new->positionX : new->positionX - newObject->otherObject.BOXLetf / -1);
        colorRGBA(1, 1, 1, 0);
    }
    
}
//this eye
void move_cpng_mouse(struct cpng * CPNG , POINT cursor){
    
    int x;
   int y;
   
   HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    
    GetCursorPos(&cursor);
    
    x = cursor.x;
    y = cursor.y;
   
    dwPos.X = x;
    dwPos.Y = y;
    
    SetConsoleCursorPosition(hCon, dwPos);
    printf("%s",CPNG->data);
    
}

void moveC(const char * C , POINT cursor){
    
    int x;
   int y;
   
   HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    
    GetCursorPos(&cursor);
    
    x = cursor.x;
    y = cursor.y;
   
    dwPos.X = x;
    dwPos.Y = y;
    
    SetConsoleCursorPosition(hCon, dwPos);
    printf("%s",C);
    
}

int collision_cpng (struct cpng *object, struct newObject *object2, const char *a, int posXoY, int cand){
    
    if (posXoY == 0)
    {
        if (object->X == object2->positionX-2/object2->BOXLetf)
        {
            StrGotoXY(object2->positionX,object2->positionY);
            printf("%s", a);
            //exit(1);
            object->X-=cand;
            return 1;
        }
    }

    else if (posXoY == 1)
    {
        if (object->Y == object2->positionY-2/object2->BOXLetf)
        {
            printf("%s", a);
            //exit(1);
            object->Y -= cand;
            return 1;
        }
    }

    if (posXoY == 2)
    {
        if (object->X == object2->positionX-2/object2->BOXLetf || object->X == object2->positionX+2/object2->BOXLetf)
        {
            printf("%s", a);
            //exit(1);
            object->X -= cand;
            object->Y -= cand;
            return 1;
        }
    }
    
}
int collision_Object (struct Object *object, struct newObject *object2, const char *a, int posXoY, int cand){
    
    if (posXoY == 0)
    {
        if (object->positionX == object2->positionX-2/object2->BOXLetf)
        {
            StrGotoXY(object2->positionX,object2->positionY);
            printf("%s", a);
            //exit(1);
            object->positionX-=cand;
            return 1;
        }
    }

    else if (posXoY == 1)
    {
        if (object->positionY == object2->positionY-2/object2->BOXLetf)
        {
            printf("%s", a);
            //exit(1);
            object->positionY -= cand;
            return 1;
        }
    }

    if (posXoY == 2)
    {
        if (object->positionX == object2->positionX-2/object2->BOXLetf || object->positionX == object2->positionX+2/object2->BOXLetf)
        {
            printf("%s", a);
            //exit(1);
            object->positionX -= cand;
            object->positionY -= cand;
            return 1;
        }
    }
    
}

static void createCpng (const char nameAsset[1024] , const char * data , int op){
    
    char cat[1024] = ".cpng";
	char nose[1024];

	FILE *file;

	strcpy(nose, nameAsset);

	strcat(nose, cat);

	file = fopen(nose, "w");

	if (file == NULL)
	{
		printf("StringLibrary: \" %s \" error no create asset'", nameAsset);
		return;
	}
	
	if(op == 0){
	    
	    fprintf(file, "%s", data);
    	printf("StringLibrary: Se ha guardado\n");
    	fclose(file);
	    
	}
	
	else if(op == 1){
	    
	    fprintf(file, "%s", data);
    	fclose(file);
	    
	}
    
}
void readCpng (char nombre[1024]){
    
    char cat[1024] = ".cpng";
	char nose[1024];

	FILE *file;

	strcpy(nose, nombre);

	strcat(nose, cat);

	file = fopen(nose, "r");

	if (file == NULL)
	{
		printf("StringLibrary: \" %s \" bad adress! ", nombre);
		return;
	}
	
    StringReadFileModeRB(nose);
    
}
void startCpng (struct cpng * Asset){
    
    void * VoidID = NULL;
    
    if(Asset->ID == (int)VoidID){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error StrCpngStart();\n",Asset->Name,Asset->ID);
        return;
    }
    else{
        
        //file_cpng(Asset->Name,Asset->data);
        AttributeText(Asset->color);
        //dataTextures(Texture->nameFile,Texture->nameFile);
        
    }
    
}
void paintCpng (struct cpng * Asset){
    
    void * VoidID = NULL;
    
    if(Asset->ID == (int)VoidID){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error StrAssetPaint();\n",Asset->Name,Asset->ID);
        return;
    }
    
    else{
        
        printf("%s",Asset->data);
        
        //ReadAsset(Asset->Name);
        
    }
    
}
void StrEndCpng (struct cpng * Asset){
    
    void * VoidID = NULL;
    
    if(Asset->ID == (int)VoidID){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error StrAssetEnd();\n",Asset->Name,Asset->ID);
        return;
    }
    else{
        
        StrAttributeText(7);
        
    }
    
}
void showCpngCoordinates (struct cpng * Object){
    
    printf("Coordinates:'%s': X = %d | Y = %d | ID: %d | '%s'\n",Object->Name,Object->X,Object->Y,Object->ID,Object->data);
    
}
static void fileAssets (const char nameAsset[V] , const char * data){
    
    char cat[1024] = ".asset";
	char nose[1024];

	FILE *file;

	strcpy(nose, nameAsset);

	strcat(nose, cat);

	file = fopen(nose, "w");

	if (file == NULL)
	{
		printf("StringLibrary: \" %s \" error no create asset'", nameAsset);
		return;
	}

	fprintf(file, "%s", data);
	printf("StringLibrary: Se ha guardado\n");
	fclose(file);
    
}
void assetStart (struct asset * Asset){
    
    void * VoidID = NULL;
    
    if(Asset->ID == (int)VoidID){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error StrAssetStart();\n",Asset->name,Asset->ID);
        return;
    }
    else{
        
        fileAssets(Asset->name,Asset->data);
        AttributeText(Asset->color);
        //dataTextures(Texture->nameFile,Texture->nameFile);
        
    }
    
}
void assetPaint (struct asset * Asset){
    
    void * VoidID = NULL;
    
    if(Asset->ID == (int)VoidID){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error StrAssetPaint();\n",Asset->name,Asset->ID);
        return;
    }
    
    else{
        
        ReadAsset(Asset->name);
        
    }
    
}
void assetEnd (struct asset * Asset){
    
    void * VoidID = NULL;
    
    if(Asset->ID == (int)VoidID){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error StrAssetEnd();\n",Asset->name,Asset->ID);
        return;
    }
    else{
        
        StrAttributeText(7);
        
    }
    
}
void moveOtherObject (struct newObject * OtherObject){
    
    void * VoidID = NULL;
    
    if(OtherObject->ID == (int)VoidID){
        
        printf("ID of Object type: newObject is null (Object Name: '%s' | Object ID: '%d') in function StrMoveOtherObject\n",OtherObject->name,OtherObject->ID);
        return;
    }
    else{
        
        if(OtherObject->onX1 == 1){
            
            OtherObject->positionX++;
            
        }
        else if (OtherObject->onX1 == 2){
            
            OtherObject->positionX--;
            
        }
        //position Y
        if(OtherObject->onY1 == 1){
            
            OtherObject->positionY++;
            
        }
        else if (OtherObject->onY1 == 2){
            
            OtherObject->positionY--;
            
        }
        else{
            
            return;
            
        }
        
    }
    
}
static void readTexture (char nombre[1024]){
    
    char cat[1024] = ".tr";
	char nose[1024];

	FILE *file;

	strcpy(nose, nombre);

	strcat(nose, cat);

	file = fopen(nose, "r");

	if (file == NULL)
	{
		printf("StringLibrary: \" %s \" -> 'Inixistente' ", nombre);
		return;
	}
    StringReadFileModeRB(nose);
    
}
void usingTexture (struct texture * Texture , const char * otherDraw){
    
    void * VoidID = NULL;
    void * Voidtext = NULL;

    if(Texture->ID == (int)VoidID){
        printf("ID Texture is void (Name Texture: '%s' and ID: %i) in fuction: StrUsingTexture();\n",Texture->name,Texture->ID);
        return;
    }
    else{

        if(otherDraw == Voidtext){

            return;

        }
        else{

             ReadTexture(Texture->nameFile);

        }

    }
    
}
void printTexture (struct texture * Texture){
    
    void * VoidID = NULL;

    if(Texture->ID == (int)VoidID){
        printf("ID Texture is void (Name Texture: '%s' and ID: %i) in fuction: StrPrintTexture();\n",Texture->name,Texture->ID);
        return;
    }

    if(Texture->mode == 0){//Leer mediante un archivo

        ReadTexture(Texture->nameFile);

    }
    else if (Texture->mode == 1){//Simplemente mostrar

        printf("%s",Texture->content);

    }
    else{

        printf("Mode is void , remenmer 0 is file and 1 simple print\n");
        return;

    }
    
}
static void fileTextures (const char nameTexture[V] , const char * contentTexture){
    
    char cat[1024] = ".tr";
	char nose[1024];

	FILE *file;

	strcpy(nose, nameTexture);

	strcat(nose, cat);

	file = fopen(nose, "w");

	if (file == NULL)
	{
		printf("StringLibrary: \" %s \" error no create texture'", nameTexture);
		return;
	}

	fprintf(file, "%s", contentTexture);
	printf("StringLibrary: save texture\n");
	fclose(file);
    
}
static void dataTextures (const char nameTexture[V] , const char * contentTexture , struct texture * data){
    
    char cat[1024] = ".dat";
	char nose[1024];

	FILE *file;

	strcpy(nose, nameTexture);

	strcat(nose, cat);

	file = fopen(nose, "w");

	if (file == NULL)
	{
		printf("StringLibrary: \" %s \" error no create texture'", nameTexture);
		return;
	}

	fprintf(file, "Name texture: %s\nID the texture: %d", contentTexture , data->ID);
	printf("StringLibrary: Se ha guardado\n");
    
}
void textures (struct texture * Texture){
    
    void * nullID = NULL;

    if(Texture->ID == (int)nullID){
        printf("ID Texture is void (Name Texture: '%s' and ID: %i) in fuction: StrTexture();\n",Texture->name,Texture->ID);
        return;
    }
    else{

        fileTextures(Texture->nameFile,Texture->content);
        dataTextures(Texture->nameFile,Texture->nameFile,Texture);

    }
    
}
void showSceneLimits(struct Scene * limitScene){
    
    printf("Scene's limit: Right'X': %d | Letf'X': %d \nDown'Y': %d | Top'Y': %d | Name: '%s' | ID: %d\n",limitScene->limitX,limitScene->limitX2,limitScene->limitY,limitScene->limitY2,limitScene->name,limitScene->ID);
    
}
void paintC (int cand_assets , ...){
    
    int ini;
    char *paint_assets;
    va_list assets;

    va_start(assets,cand_assets);

    for(ini = 0; ini < cand_assets; ++ini){

        paint_assets = va_arg(assets,char*);
        printf("%s",paint_assets);

    }

    va_end(assets);
    
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
/*void showObjectCoordinates (struct Object * Object){
    
    printf("Coordinates:'%s': X = %d | Y = %d | ID: %d\n",Object->Name,Object->positionX,Object->positionY,Object->ID);
    
}*/
void limitObject (struct Object * limitObject , int limitX1 , int limitX2, int limitY1 , int limitY2){
    
    void * VoidID = NULL;// 0

    if(limitObject->ID == (int)VoidID){

        printf("ID the object('%s') this incorrect , (ID value: %d) functionError(StrlimitObject)\n",limitObject->Name,limitObject->ID);
        return ;

    }

    //Posiciones en X de derecha a izquierda
    if(limitObject->positionX == limitX1){

        limitObject->positionX++;

    }

    if(limitObject->positionX == limitX2){

        limitObject->positionX--;

    }

    //Posiciones en Y de arriba a abajo
    if(limitObject->positionY == limitY1){

        limitObject->positionY++;

    }

    if(limitObject->positionY == limitY2){

        limitObject->positionY--;

    }
    
}
void limit_scenes_newObjects(struct _scenes_* Scene, struct newObject * Ob){
    
    if (Ob->positionX == Scene->limitX_left)
    {
        Ob->positionX++;
    }
    if (Ob->positionY == Scene->limitY_top)
    {
        Ob->positionY++;
    }
    if (Ob->positionX == Scene->limitX_rigth)
    {
        Ob->positionX--;
    }
    if (Ob->positionY == Scene->limitY_bottom)
    {
        Ob->positionY--;
    }
    
}

#endif
