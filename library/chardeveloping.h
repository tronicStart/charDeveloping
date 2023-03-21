#ifndef CHARDEVELOPING_H
#define CHARDEVELOPING_H

#include "strdef.h"
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>
//#include <sys/sysinfo.h>

/*tipos de datos*/

typedef float f;
typedef int * pointer;
typedef char Texture[V];

struct water{
    
    double amplitude;
    double wavelength;
    double frequency;
    char c[V];
    
};

struct cpng{
    
    //datos para crear el objecto principal o jugador 1
    int postition_X;
    int postition_Y;
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

    } npc;
};

struct texture {

    int id_texture;
    int mode_lecture;
    int color_texture;
    char name_texture[V];
    Texture asset_texture;

};

struct ini_screen{
    
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
    
};

struct scene{
    
    int limit_X;
    int limit_X2;
    int limit_Y;
    int limit_Y2;
    int id;
    int mode_lecture;
    char name_scene[V];
    struct texture * asset_scene;
    Texture assets;

};

int print_text (const char* format, ...){
    
   va_list args;
  va_start(args, format);
  int count = vprintf(format, args);
  va_end(args);
  return count;
    
}

void clear_screen(){
    
    printf("\033[2J\033[1;1H");
    
}

void hiddenCursor (int confirmation){
    
    if(confirmation == true){
    CONSOLE_CURSOR_INFO cci = {100, FALSE};

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
    }
    else if(confirmation == false){
    	CONSOLE_CURSOR_INFO cci = {100, TRUE};

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
    }
    
}

void set_title (const char * title){
    
    SetConsoleTitle(title);
    
}

void set_color_text (int color){
    
    HANDLE out;
    out=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(out,color);
    
}

void set_xy(int X , int Y){
    
    HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = X;
	dwPos.Y = Y;
	SetConsoleCursorPosition(hCon, dwPos);
    
}

void center_text(char* text){
    
    int rows, columns;
    char buffer[256];

    FILE* terminal = popen("stty size", "r");
    fgets(buffer, 256, terminal);
    sscanf(buffer, "%d %d", &rows, &columns);
    pclose(terminal);

    int x = (columns - strlen(text)) / 2;
    printf("\033[%dG", x + 1);
    printf("%s\n", text);
    
}

void print_random_abc(){
    
    int i;
    
    srand(time(0));
    for (i = 0; i < 10; i++) {
        char letter = (rand() % 26) + 65;
        printf("%c\n", letter);
    }
    
}
char genere_random_abc(){
    
    int i;
    
    srand(time(0));
    for (i = 0; i < 10; i++) {
        char letter = (rand() % 26) + 65;
        return letter;
    }
    
}

int read_key(void){
    
    return getch();
    
}

void readLine(void){
    
    getche();
    
}

int genere_random_number(int max){
    
    int inicio;
	srand(time(NULL));
	inicio = rand() % max;

	return inicio;
    
}

void generate_terrian_random(int ROWS, int COLS){
    
    int i,j;
    
    int terrain[ROWS][COLS];
     srand(time(NULL)); // Inicializa el generador de números aleatorios

  // Genera el terreno aleatorio
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      terrain[i][j] = rand() % 2; // Asigna un valor aleatorio de 0 o 1
    }
  }

  // Imprime el terreno
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      if (terrain[i][j] == 0) {
        printf("[&]");
      } else {
        printf("[#]");
      }
    }
    printf("\n"); // Salto de línea para imprimir cada fila
  }
    
}
//1 para saltar y 0 para no hacerlo    
void dupli_text(char* text, int times, int newline){
    int i;
    for (i = 0; i < times; i++) {
        if (newline) {
            printf("%s\n", text);
        } else {
            printf("%s", text);
        }
    }
    
}

void str_cls(void){
    
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD bufferSize, charsWritten;

    COORD topleft = {0, 0};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    bufferSize = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(hConsole, TEXT(' '), bufferSize, topleft, &charsWritten);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, bufferSize, topleft, &charsWritten);
    SetConsoleCursorPosition(hConsole, topleft);
    
}

void printC(int cand_assets , ...){
    
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

void draw_square(int size, const char * c){
    int i,j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                printf("%s ",c);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    
}

void draw_triangle(int size, const char * c){
    int i,j,k;
    
    for (i = 1; i <= size; i++) {
        for (j = 1; j <= size - i; j++) {
            printf(" ");
        }
        for (k = 1; k <= 2 * i - 1; k++) {
            printf("%s",c);
        }
        printf("\n");
    }
    
}

void color_RGBA(int R, int G, int B, int A){
    
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

void move_cpng(struct cpng *posPlayer, const char *key1, const char *key2, const char *key3, const char *key4){
    
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

	   if(key1 == NULL){
	       return;
	   }

	   posPlayer->postition_X--;
	}

	if(Keey == key2){

	   if(key2 == NULL){
	       return;
	   }

	   posPlayer->postition_X++;
	}

	if(Keey == key3){

	   if(key3 == NULL){
	       return;
	   }

	   posPlayer->postition_Y++;
	}

	if(Keey == key4){

	   if(key4 == NULL){
	       return;
	   }

	   posPlayer->postition_Y--;
	}
    
}

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
    printf("%s",CPNG->asset);
    
}

/*int debug_collision_cpngs_ncp(struct cpng * Ob){
    
    if(Ob->id < 0){
        color_RGBA(1, 0, 0, 0);
        printf("Error detect in fuction StrBoxCollisionActionObject(); detect ID is negative\n");
        color_RGBA(1, 1, 1, 0);
    }
    
    if (Ob->npc.id < 0)
    {
        color_RGBA(1, 0, 0, 0);
        printf("Error detect in fuction: StrBoxCollisonActionObject(); detect ID NULL in boxCollision:\n");
        color_RGBA(1, 1, 1, 0);
        return -1;
    }
    
    else
    {
        color_RGBA(1, 0, 1, 0);
        printf("Verify Collisions: objects: '%s' and '%s'\n",Ob->name_cpng,Ob->npc.name_npc);
        printf("(Object)%s : X = %d , Y = %d , BOXrigth = %d | (newObject)%s : X = %d , Y = %d , BOXLetf = %d \n", Ob->Name, Ob->positionX, Ob->positionY, Ob->collision.right, Ob->name, Ob->positionX, Ob->positionY, Ob->collision.letf);
        printf("(Object)%s : X = %d + BOXrigth = %d same (newObject)%s : X = %d - BOXLetf = %d/ -1 = (%d)\n", Ob->Name, Ob->positionX, Ob->collision.right, ob->name, ob->positionX, ob->collision.letf, Ob->positionX + Ob->collision.right ? ob->positionX : ob->positionX - ob->collision.letf / -1 );
        color_RGBA(1, 1, 1, 0);
    }
    
}*/

void start_cpng (struct cpng * Asset){
    
    if(Asset->id < 0){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error start_cpng();\n",Asset->name_cpng,Asset->id);
        return;
    }
    else{
        
        set_color_text(Asset->color);
        
    }
    
}

void paint_cpng (struct cpng * Asset){
    
    if(Asset->id < 0){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error paint_cpng();\n",Asset->name_cpng,Asset->id);
        return;
    }
    
    print_text("%s",Asset->asset);
    
}
void end_cpng (struct cpng * Asset){
    
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

	if (lectura == NULL)
	{
		perror("Escrity ");
		printf("Directorio o Archivo: [\" ");
		printf("%s", file);
		printf(". \"] \n");
	}
	else
	{
		while (feof(lectura) == 0)
		{
			fgets(variable, 1025, lectura);
			printf("%s", variable);
		}
	}
	fclose(lectura);
    
}

void move_cpng_file(struct cpng *posPlayer, const char *key1, const char *key2, const char *key3, const char *key4)
{
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
    dwPos.X = posPlayer->X;
    dwPos.Y = posPlayer->Y;

    SetConsoleCursorPosition(hCon, dwPos);
    read_files(nose);

    Keey = getch();

    if (Keey == key1)
    {
        if (key1 == '\0')
        {
            return;
        }

        posPlayer->X--;
    }

    if (Keey == key2)
    {
        if (key2 == '\0')
        {
            return;
        }

        posPlayer->X++;
    }

    if (Keey == key3)
    {
        if (key3 == '\0')
        {
            return;
        }

        posPlayer->Y++;
    }

    if (Keey == key4)
    {
        if (key4 == '\0')
        {
            return;
        }

        posPlayer->Y--;
    }
}

void start_read_cpng (struct cpng * Asset){
    
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

	if (file == NULL)
	{
		perror("Charlibrary ");
		return;
	}
	
	set_color_text(Asset->color);
    
}

void paint_read_cpng (struct cpng * Asset){
    
    if(Asset->id < 0){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error paint_read_cpng();\n",Asset->name_cpng,Asset->id);
        return;
    }
    
    read_files(Asset->name_cpng);
    
}
void end_read_cpng (struct cpng * Asset){
    
    if(Asset->id < 0){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error end_read_cpng();\n",Asset->name_cpng,Asset->id);
        return;
    }
    
    set_color_text(7);
    
}

int create_cpng (struct cpng * cpng){
    
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

	if (file == NULL)
	{
		perror("Charlibrary ");
		return -1;
	}
	
	fprintf(file,"%s",cpng->asset);
	
	fclose(file);
    
}

void move_ncp_cpng (struct cpng * cpng){
    
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

	if (file == NULL)
	{
		perror("Charlibrary ");
		return -1;
	}
	
   read_files(nose);
    
}
int read_texture (struct texture * texture){
    
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

	if (file == NULL)
	{
		perror("Charlibrary ");
		return -1;
	}
    
}

int print_texture (struct texture * texture){
    
    if(texture->id_texture < 0){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error print_texture();\n",texture->name_texture,texture->id_texture);
        return -1;
    }
    
    read_files(texture->name_texture);
    
}

int create_texture (struct texture * texture){
    
    char cat[1024] = ".tex";
	char nose[1024];

	FILE *file;

	strcpy(nose, texture->name_texture);

	strcat(nose, cat);

	file = fopen(nose, "w");

	if (file == NULL)
	{
		perror("Charlibrary ");
		return -1;
	}
	
	fprintf(file,"%s",texture->asset_texture);
	
	fclose(file);
    
}

int create_data_textures (struct texture * texture){
    
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

	if (file == NULL)
	{
		perror("charlibrary ");
		return -1;
	}

	fprintf(file, "name texture: %s\nid texture: %d\nAsset texture: \n%s",texture->name_texture,texture->id_texture,texture->asset_texture);
    
}
void show_scene_limits(struct scene * limitScene){
    
    print_text("Limit X: limit 1: %s | limit 2: %d\n Limit Y: limit 3: %d| limit 4: %d\n",limitScene->limit_X,limitScene->limit_X2,limitScene->limit_Y,limitScene->limit_Y2);
    
}

void ini_screen (struct ini_screen * screen){
    
    int i,j;
    
    // Inicializar la matriz de pantalla con asteriscos
    for (i = 0; i < screen->height; i++) {
        for (j = 0; j < screen->width; j++) {
            screen->screen[i][j] = *screen->C;
        }
    }
    
    // Cambiar los caracteres en las coordenadas (x, y) a espacios en blanco
    for (i = screen->ini_espace_y; i < screen->ini_espace_y + screen->space_y && i < screen->height; i++) {
        for (j = screen->ini_espace_x; j < screen->ini_espace_x + screen->space_x && j < screen->width; j++) {
            screen->screen[i][j] = ' ';
        }
    }
    // Mostrar la pantalla en la terminal
    str_cls();
    for (i = 0; i < screen->height; i++) {
        for (j = 0; j < screen->width; j++) {
            printf("%c", screen->screen[i][j]);
        }
        printf("\n");
    }
    
}

void start_limit_ (struct ini_screen * sc, struct cpng * cpng){
    
    if(sc->limitX_1 < 0 || sc->limitX_2 < 0 || sc->limitY_1 < 0 || sc->limitY_2 < 0 ){
        printf("Error uno de los limites tiene una valor negativo\n");
    }
    if (cpng->postition_X == sc->limitX_1)
    {
        cpng->postition_X++;
    }
    if (cpng->postition_Y == sc->limitY_1)
    {
        cpng->postition_Y++;
    }
    if (cpng->postition_X == sc->limitX_2)
    {
        cpng->postition_X--;
    }
    if (cpng->postition_Y == sc->limitY_2)
    {
        cpng->postition_Y--;
    }
    
}

void water_onde(struct water *w, int tiempo){
    
    // Tamaño de la pantalla de la terminal
    int width = 80;
    int height = 20;
    int i, j;
    double y;

    // Bucle para cada fila de la pantalla
    for (i = 0; i < height; i++)
    {
        // Calcular la posición vertical de la onda
        y = w->amplitude * sin(2 * M_PI * i / w->wavelength + w->frequency * j);

        // Bucle para cada columna de la pantalla
        for (j = 0; j < width; j++)
        {
            // Si la posición vertical es igual a la posición horizontal,
            // mostrar un carácter
            if ((int)y == j)
            {
                printf("%s", w->c);
            }
            else
            {
                printf(" ");
            }
        }
        Sleep(tiempo);
        // Salto de línea al final de cada fila
        printf("\n");
    }

    // Incrementar el tiempo (frecuencia) de la onda
    w->frequency += 0.1;
    
}

void show_coordinates_ncp(struct cpng *object){
    
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

void show_coordinates_cpng(struct cpng *object){
    
    printf("Coordinates:'%s': X = %d | Y = %d | ID: %d\n", object->name_cpng, object->postition_X, object->postition_Y, object->id);
    
}



#endif
