#ifndef OBJECT_H
#define OBJECT_H

#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>
#include "strdef.h"

/*tipos de datos*/
typedef float f;
typedef int * pointer;
typedef char Texture[V];
typedef int array;

typedef struct {
    array range;
    array i;
    array Array[100];
} array_int;

typedef struct {
    array range;
    array i;
    const char * Array[100];
} array_char;

typedef struct {

    double amplitude;
    double wavelength;
    double frequency;
    char c[V];

} water;

typedef struct {

    //datos para crear el objecto principal o jugador 1
    int position_X;
    int position_Y;
    int collision_Top;
    int collision_Down;
    int collision_Letf;
    int collision_Right;
    int id;
    char name_cpng[V];
    int weight;
    int color;
    char asset[V];
    int range;
    char mode[V];
    //datos para crear el objecto segundario o NPC (No player control)
    struct{
        int postition_X;
        int postition_Y;
        int collision_Top;
        int collision_Down;
        int collision_Letf;
        int collision_Right;
        int id;
        char name_npc[V];
        int color;
        char asset[V];
        int range;
        int weight;
        char mode[V];
        //entity para npc
        struct {
            int health;
            int attack;
            int hitbox;
            int id;
        }entity;
    } npc;
    //struct para guardar datos sencillos de un juego
    struct {
        char name[CHAR_SAVE];
        int point;
        int health;
        int i;
        int numbers_objects;
        char read[CHAR_SAVE];
        char name_file[CHAR_SAVE];
        char objects[CHAR_SAVE];
        char Message_save[CHAR_SAVE];
    }save_game;
    //entity para player;
    struct {
        int health;
        int attack;
        int hitbox;
        int id;
    }entity;
} cpng;

typedef struct {

    int id_texture;
    int mode_lecture;
    int color_texture;
    char name_texture[V];
    Texture asset_texture;

} texture;

typedef struct {

    char screen[100][100];
    int width, height;
    int ini_espace_x;
    int ini_espace_y;
    int limitX_1;
    int limitX_2;
    int limitY_1;
    int limitY_2;
    int space_x, space_y;
    char C[50];
    char name[50];

} ini_screen;

typedef struct {

    int limit_X;
    int limit_X2;
    int limit_Y;
    int limit_Y2;
    int id;
    int mode_lecture;
    char name_scene[V];
    struct texture * asset_scene;
    Texture assets;

}scene;

char data[CHAR_SAVE][MAX_SAVE_DATA];

int save_data_game (cpng * cpng){
    
    char cat[1024] = ".save";
	char nose[1024];
	FILE *file;
	
	strcpy(nose, cpng->save_game.name_file);
	strcat(nose, cat);
	file = fopen(nose, "w");
	
	if (file == NULL){
		perror("Charlibrary ");
		return -1;
	}
	
	fprintf(file,"%s\n",cpng->save_game.name);
	fprintf(file,"%i\n",cpng->save_game.point);
	fprintf(file,"%i\n",cpng->save_game.health);
	fprintf(file,"%i\n",cpng->save_game.numbers_objects);
	fprintf(file,"%s\n",cpng->save_game.name_file);
	fprintf(file,"%s\n",cpng->save_game.objects);
	fclose(file);
	printf("%s",cpng->save_game.Message_save);
    
}

int read_data_game(cpng *cpng) {
    
    char cat[1024] = ".save";
    char nose[1024];
    FILE *file;

    strcpy(nose, cpng->save_game.name_file);
    strcat(nose, cat);
    file = fopen(nose, "r");

    if (file == NULL) {
        perror("Charlibrary ");
        return -1;
    } else {
        while (feof(file) == 0) {
            cpng->save_game.i++;
            fgets(cpng->save_game.read, CHAR_SAVE, file);
            strncpy(data[cpng->save_game.i], cpng->save_game.read, CHAR_SAVE);  // se asigna el valor a la matriz
        }
    }
    fclose(file);
    return 0;
}

int debug_collision_cpngs_ncp(cpng *Ob){

    if (Ob->id < 0){
        color_RGBA(1, 0, 0, 0);
        printf("Error detected in function debug_collision_cpngs_ncp(); detected ID is negative\n");
        color_RGBA(1, 1, 1, 0);
    }

    if (Ob->npc.id < 0){
        color_RGBA(1, 0, 0, 0);
        printf("Error detected in function debug_collision_cpngs_ncp(); detected ID NULL in boxCollision:\n");
        color_RGBA(1, 1, 1, 0);
        return -1;
    }

    else{
        color_RGBA(1, 0, 1, 0);
        printf("Verify Collisions: objects: '%s' and '%s'\n", Ob->name_cpng, Ob->npc.name_npc);
        printf("(Object)%s : X = %d , Y = %d , BOXright = %d | (newObject)%s : X = %d , Y = %d , BOXleft = %d \n", Ob->name_cpng, Ob->postition_X, Ob->postition_Y, Ob->collision_Right, Ob->npc.name_npc, Ob->npc.postition_X, Ob->npc.postition_Y, Ob->npc.collision_Letf);
        printf("(Object)%s : X = %d + BOXright = %d same (newObject)%s : X = %d - BOXleft = %d/ -1 = (%d)\n", Ob->name_cpng, Ob->postition_X, Ob->collision_Right, Ob->npc.name_npc, Ob->npc.postition_X, Ob->npc.collision_Letf, Ob->postition_X + Ob->collision_Right == Ob->npc.postition_X ? Ob->npc.postition_X : Ob->npc.postition_X - Ob->npc.collision_Letf / -1);
        color_RGBA(1, 1, 1, 0);
    }
    return 0;
}

int collision_cpng_detection(cpng *cpng_obj) {
    // Comprobamos si hay colisión en el eje X
    if ((cpng_obj->postition_X + cpng_obj->collision_Right >= cpng_obj->npc.postition_X + cpng_obj->npc.collision_Left) &&
        (cpng_obj->npc.postition_X + cpng_obj->npc.collision_Right >= cpng_obj->postition_X + cpng_obj->collision_Left)) {
        // Comprobamos si hay colisión en el eje Y
        if ((cpng_obj->postition_Y + cpng_obj->collision_Down >= cpng_obj->npc.postition_Y + cpng_obj->npc.collision_Top) &&
            (cpng_obj->npc.postition_Y + cpng_obj->npc.collision_Down >= cpng_obj->postition_Y + cpng_obj->collision_Top)) {
            return 1; // hay colisión
        }
    }
    return 0; // no hay colisión
}

array_int *new_array_int(array_int *Array, ...) {

    array *Arra = malloc(Array->range * sizeof(array));
    va_list valist;
    va_start(valist, Array->range);

    for (Array->i = 0; Array->i < Array->range; Array->i++) {
        array x = va_arg(valist, array);
        Arra[Array->i] = x;
    }

    va_end(valist);

    for (Array->i = 0; Array->i < Array->range; Array->i++) {
        Array->Array[Array->i] = Arra[Array->i];
    }

    free(Arra);

    return Array;

}

array_char * new_array_char(array_char * Array, ...){

    array *Arra = malloc(Array->range * sizeof(array));
    va_list valist;
    va_start(valist, Array->range);

    for (Array->i = 0; Array->i < Array->range; Array->i++) {
        char * x = va_arg(valist, char *);
        Arra[Array->i] = x;
    }

    va_end(valist);

    for (Array->i = 0; Array->i < Array->range; Array->i++) {
        Array->Array[Array->i] = Arra[Array->i];
    }

    free(Arra);

    return Array;

}

void start_cpng (cpng * Asset){

    if(Asset->id < 0){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error start_cpng();\n",Asset->name_cpng,Asset->id);
        return;
    }
    else{
        set_color_text(Asset->color);
    }

}

void paint_cpng (cpng * Asset){

    if(Asset->id < 0){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error paint_cpng();\n",Asset->name_cpng,Asset->id);
        return;
    }

    print_text("%s",Asset->asset);

}

void end_cpng (cpng * Asset){

    if(Asset->id < 0){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error end_cpng();\n",Asset->name_cpng,Asset->id);
        return;
    }

    set_color_text(7);

}

void read_files (const char * file){

    FILE *lectura;
	char variable[1025];

	lectura = fopen(file, "rb");

	if (lectura == NULL){
		perror("CharDeveloping ");
		printf("Directorio o Archivo: [\" ");
		printf("%s", file);
		printf(". \"] \n");
	}
	else{
		while (feof(lectura) == 0){
			fgets(variable, 1025, lectura);
			printf("%s", variable);
		}
	}
	fclose(lectura);

}

void move_cpng_file(cpng *posPlayer, const char *key1, const char *key2, const char *key3, const char *key4){
    if(posPlayer->id < 0){
        printf("Error un el ID es negativo\n");
    }

    char Keey;
    char cat[1024] = ".cpng";
    char nose[1024];
    strcpy(nose, posPlayer->name_cpng);
    strcat(nose, cat);

    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = posPlayer->postition_X;
    dwPos.Y = posPlayer->postition_Y;
    SetConsoleCursorPosition(hCon, dwPos);
    read_files(nose);

    Keey = getch();

    if (Keey == key1){
        if (key1 == '\0'){
            return;
        }
        posPlayer->postition_X--;
    }

    if (Keey == key2){
        if (key2 == '\0'){
            return;
        }
        posPlayer->postition_X++;
    }

    if (Keey == key3){
        if (key3 == '\0'){
            return;
        }
        posPlayer->postition_Y++;
    }

    if (Keey == key4){
        if (key4 == '\0'){
            return;
        }
        posPlayer->postition_Y--;
    }
}

void start_read_cpng (cpng * Asset){

    if(Asset->id < 0){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error start_read_cpng();\n",Asset->name_cpng,Asset->id);
        return;
    }

    char cat[1024] = ".cpng";
	char nose[1024];

	FILE *file;

	strcpy(nose, Asset->asset);
	strcat(nose, cat);
	file = fopen(nose, "r");

	if (file == NULL){
		perror("Charlibrary ");
		return;
	}

	set_color_text(Asset->color);
    fclose(file);

}

void paint_read_cpng (cpng * Asset){

    if(Asset->id < 0){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error paint_read_cpng();\n",Asset->name_cpng,Asset->id);
        return;
    }
    read_files(Asset->name_cpng);

}
void end_read_cpng (cpng * Asset){

    if(Asset->id < 0){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error end_read_cpng();\n",Asset->name_cpng,Asset->id);
        return;
    }
    set_color_text(7);

}

int create_cpng (cpng * cpng){

    if(cpng->id < 0){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error create_cpng();\n",cpng->name_cpng,cpng->id);
        return -1;
    }

    char cat[1024] = ".cpng";
	char nose[1024];

	FILE *file;

	strcpy(nose, cpng->asset);
	strcat(nose, cat);
	file = fopen(nose, "w");
	if (file == NULL){
		perror("Charlibrary ");
		return -1;
	}
	fprintf(file,"%s",cpng->asset);
	fclose(file);

}

void move_cpng(cpng *posPlayer, const char *key1, const char *key2, const char *key3, const char *key4){

    char Keey;

    HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = posPlayer->postition_X;
	dwPos.Y = posPlayer->postition_Y;
	SetConsoleCursorPosition(hCon, dwPos);
	printf("%s\n",posPlayer->asset);
	Keey = getch();
	//Movimiento en X
	if(Keey == key1){
	   if(key1 == '\0'){
	       return;
	   }
	   posPlayer->postition_X--;
	}

	if(Keey == key2){
	   if(key2 == '\0'){
	       return;
	   }
	   posPlayer->postition_X++;
	}

	if(Keey == key3){
	   if(key3 == '\0'){
	       return;
	   }
	   posPlayer->postition_Y++;
	}

	if(Keey == key4){
	   if(key4 == '\0'){
	       return;
	   }
	   posPlayer->postition_Y--;
	}

}

void move_cpng_mouse(cpng * CPNG , POINT cursor){

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
    printf("%s",CPNG->asset);

}

void move_ncp_cpng (cpng * cpng){

    if(cpng->id < 0){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error move_ncp_cpng();\n",cpng->name_cpng,cpng->id);
        return;
    }

    int pos_x = genere_random_number(cpng->npc.range);
    int pos_y = genere_random_number(cpng->npc.range);

    if(pos_x < cpng->npc.range){
        cpng->npc.postition_X++;
    }

    if(pos_x < cpng->npc.range-1){
        cpng->npc.postition_X--;
    }

    if(pos_y < cpng->npc.range-2){
        cpng->npc.postition_Y++;
    }

    if(pos_y < cpng->npc.range-3){
        cpng->npc.postition_Y--;
    }

}

int read_Texture (Texture nombre){

    char cat[1024] = ".tex";
	char nose[1024];

	FILE *file;

	strcpy(nose, nombre);
	strcat(nose, cat);
	file = fopen(nose, "w");

	if (file == NULL){
		perror("Charlibrary ");
		return -1;
	}
   read_files(nose);

}
int read_texture (texture * texture){

    if(texture->id_texture < 0){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error read_texture();\n",texture->name_texture,texture->id_texture);
        return -1;
    }

    char cat[1024] = ".tex";
	char nose[1024];

	FILE *file;

	strcpy(nose, texture->name_texture);
	strcat(nose, cat);
	file = fopen(nose, "w");

	if (file == NULL){
		perror("Charlibrary ");
		return -1;
	}

}

int print_texture (texture * texture){

    if(texture->id_texture < 0){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error print_texture();\n",texture->name_texture,texture->id_texture);
        return -1;
    }
    read_files(texture->name_texture);

}

int create_texture (texture * texture){

    char cat[1024] = ".tex";
	char nose[1024];

	FILE *file;

	strcpy(nose, texture->name_texture);
	strcat(nose, cat);
	file = fopen(nose, "w");

	if (file == NULL){
		perror("Charlibrary ");
		return -1;
	}

	fprintf(file,"%s",texture->asset_texture);
	fclose(file);

}

int create_data_textures (texture * texture){

    if(texture->id_texture < 0){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error create_data_textures();\n",texture->name_texture,texture->id_texture);
        return -1;
    }

    char cat[1024] = ".dat";
	char nose[1024];

	FILE *file;

	strcpy(nose, texture->name_texture);
	strcat(nose, cat);
	file = fopen(nose, "w");

	if (file == NULL){
		perror("charlibrary ");
		return -1;
	}
	fprintf(file, "name texture: %s\nid texture: %d\nAsset texture: \n%s",texture->name_texture,texture->id_texture,texture->asset_texture);

}
void show_scene_limits(scene * limitScene){
    print_text("Limit X: limit 1: %s | limit 2: %d\n Limit Y: limit 3: %d| limit 4: %d\n",limitScene->limit_X,limitScene->limit_X2,limitScene->limit_Y,limitScene->limit_Y2);
}

void start_screen (ini_screen * screen){

    int i,j;

    for (i = 0; i < screen->height; i++) {
        for (j = 0; j < screen->width; j++) {
            screen->screen[i][j] = *screen->C;
        }
    }

    for (i = screen->ini_espace_y; i < screen->ini_espace_y + screen->space_y && i < screen->height; i++) {
        for (j = screen->ini_espace_x; j < screen->ini_espace_x + screen->space_x && j < screen->width; j++) {
            screen->screen[i][j] = ' ';
        }
    }

    str_cls();
    for (i = 0; i < screen->height; i++) {
        for (j = 0; j < screen->width; j++) {
            printf("%c", screen->screen[i][j]);
        }
        printf("\n");
    }

}

void start_limit_ (ini_screen * sc, cpng * cpng){

    if(sc->limitX_1 < 0 || sc->limitX_2 < 0 || sc->limitY_1 < 0 || sc->limitY_2 < 0 ){
        printf("Error uno de los limites tiene una valor negativo\n");
    }

    if (cpng->postition_X == sc->limitX_1){
        cpng->postition_X++;
    }

    if (cpng->postition_Y == sc->limitY_1){
        cpng->postition_Y++;
    }

    if (cpng->postition_X == sc->limitX_2){
        cpng->postition_X--;
    }

    if (cpng->postition_Y == sc->limitY_2){
        cpng->postition_Y--;
    }

}
//funciones para probar antes de crear algo concreto
void water_onde(water *w, int tiempo){

    int width = 80;
    int height = 20;
    int i, j;
    double y;

    for (i = 0; i < height; i++){
        y = w->amplitude * sin(2 * M_PI * i / w->wavelength + w->frequency * j);
        for (j = 0; j < width; j++){
            if ((int)y == j){
                printf("%s", w->c);
            }
            else{
                printf(" ");
            }
        }
        Sleep(tiempo);
        printf("\n");
    }
    w->frequency += 0.1;

}

void show_coordinates_ncp(cpng *object){
    print_text("Coordinates_ncp: X = %i | Y = %i\n",object->npc.postition_X,object->npc.postition_Y);
}

void show_hour (){

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    printf("La hora actual es: %02d:%02d:%02d\n", t->tm_hour, t->tm_min, t->tm_sec);

}

void fps_counter() {

    static int frame_count = 0;
    static clock_t last_time = 0;
    clock_t current_time = clock();

    if (last_time == 0) {
        last_time = current_time;
    }

    frame_count++;
    if ((current_time - last_time) >= CLOCKS_PER_SEC) {
        double fps = (double)frame_count * CLOCKS_PER_SEC / (double)(current_time - last_time);
        printf("FPS: %.2f\n", fps);
        last_time = current_time;
        frame_count = 0;
    }

}

void render_ (int num_functions, ...){

    int i;

    va_list function_list;
    va_start(function_list, num_functions);

    while (1) {
        for (i = 0; i < num_functions; i++) {
            void (*current_function)() = va_arg(function_list, void (*)());
            current_function();
        }
    }

    va_end(function_list);

}

void show_coordinates_cpng(cpng *object){
    printf("Coordinates:'%s': X = %d | Y = %d | ID: %d\n", object->name_cpng, object->postition_X, object->postition_Y, object->id);
}

#endif
