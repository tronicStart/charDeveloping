#ifndef STRGAME_H
#define STRGAME_H

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#include "strtypes.h"
#include "strfiles.h"

int printstr (const char* format, ...) {//función similar o igual a printf()
  va_list args;
  va_start(args, format);
  int count = vprintf(format, args);
  va_end(args);
  return count;
}

void clearScreen() {
    /*
    \033[2J borra todo el contenido de la pantalla,
     \033[1;1H coloca el cursor en la posición superior izquierda de la pantalla
    */
    printf("\033[2J\033[1;1H");
    
}

void dreamConsole (int time) {
    #ifdef _WIN32
        Sleep(time);
    #else
        usleep(time);
    #endif
}

void hiddenCursor (let confirmation) {
    if(confirmation == true){
    CONSOLE_CURSOR_INFO cci = {100, FALSE};

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
    }
    else if(confirmation == false){
    	CONSOLE_CURSOR_INFO cci = {100, TRUE};

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
    }
}

void setTitle (const char * title){

	SetConsoleTitle(title);

}

void setColorText (int color){
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

void exitProgram()
{
	exit(1);
}

void center_text(char* text) {
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

void print_random_abc() {
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        char letter = (rand() % 26) + 65;
        printf("%c\n", letter);
    }
}

char genere_random_abc() {
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        char letter = (rand() % 26) + 65;
        return letter;
    }
}

int readKey(void)
{
	return getch();
}

void readLine(void)
{
	 getche();
}

int genere_random_number(int max)
{
	int inicio;
	srand(time(NULL));
	inicio = rand() % max;

	return inicio;
}
//1 para saltar linea y 0 para no hacerlo
void dupli_text(char* text, int times, int newline) {
    for (int i = 0; i < times; i++) {
        if (newline) {
            printf("%s\n", text);
        } else {
            printf("%s", text);
        }
    }
}

void str_cls(void)
{
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

#endif
