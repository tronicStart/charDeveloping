#ifndef TEXT_H
#define TEXT_H

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include "strdef.h"

void view_fps() {
    
    static int frames = 0;
    static clock_t last_time = 0;
    double fps;
    
    frames++;
    clock_t current_time = clock();
    if (last_time == 0) {
        last_time = current_time;
        return;
    }
    
    double time_diff = ((double)(current_time - last_time)) / CLOCKS_PER_SEC;
    if (time_diff >= 1.0) {
        fps = (double)frames / time_diff;
        printf("FPS: %.2f\n", fps);
        frames = 0;
        last_time = current_time;
    }
}

char* extract_string(const char* str, int start, int end) {
    
    int len = strlen(str);
    
    if (end > len) {
        end = len;
    }
    if (start > end) {
        return NULL;
    }
    
    int sub_len = end - start;
    char* sub_str = (char*)malloc((sub_len + 1) * sizeof(char));
    
    if (sub_str == NULL) {
        return NULL;
    }
    
    int i, j;
    
    for (i = start, j = 0; i < end; i++, j++) {
        sub_str[j] = str[i];
    }
    
    sub_str[j] = '\0';
    
    return sub_str;
}

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
        else{
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
        else{
            HANDLE out;
            out = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(out, 0);
        }
    }
    
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

#endif
