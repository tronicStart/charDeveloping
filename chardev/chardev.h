#ifndef CHARDEV_H
#define CHARDEV_H

#include "chardef.h"

static void str_cls(void){

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

static float * matix_4 (){
    float m4[4][4];
    int i,j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            m4[i][j] = 0.0f;
        }
    }
    return m4;
}

static float showFPS() {
    int frames = 0;
    clock_t last_time = 0;
    double fps;
    frames++;
    clock_t current_time = clock();
    if (last_time == 0) {
        last_time = current_time;
        return 0.115;
    }
    double time_diff = ((double)(current_time - last_time)) / CLOCKS_PER_SEC;
    if (time_diff >= 1.0) {
        fps = (double)frames / time_diff;
        //printf("FPS: %.2f", fps);
        frames = 0;
        last_time = current_time;
        return fps;
    }
}



static int printchar(const char* format, ...){
  va_list args;
  va_start(args, format);
  int count = vprintf(format, args);
  va_end(args);
  return count;
}

static void clsAscii(){
    printf("\033[2J\033[1;1H");
}

static void setColor (int color){
    
    HANDLE out;
    out=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(out,color);
    
}

static void setPosXY (int X, int Y){
    HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = X;
	dwPos.Y = Y;
	SetConsoleCursorPosition(hCon, dwPos);
}

static void centerText(char* text){
    
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

static void PrintRandomChar (){
    
    int i;
    
    srand(time(0));
    for (i = 0; i < 10; i++) {
        char letter = (rand() % 26) + 65;
        printf("%c\n", letter);
    }
    
}

static char genereRandomChar(){
    int i;
    srand(time(0));
    for (i = 0; i < 10; i++) {
        char letter = (rand() % 26) + 65;
        return letter;
    }
}

static int newRandom (int max){
    
    int r;
	srand(time(NULL));
	r = rand() % max;
	return r;
    
}

//1 para saltar y 0 para no hacerlo    
static void dupliText(char* text, int times, int newline){
    
    int i;
    
    for (i = 0; i < times; i++) {
        if (newline) {
            printf("%s\n", text);
        } else {
            printf("%s", text);
        }
    }
    
}

static void colorRGBA(int R, int G, int B, int A){
    if (A == 0){
        if (R && G && B == 1){
            HANDLE out;
            out = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(out, 7);
            return;
        }
        if (R == 1){
            HANDLE out;
            out = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(out, 4);
            if (R && G == 1){
                HANDLE out;
                out = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(out, 6);
                return;
            }
            if (R && B == 1){
                HANDLE out;
                out = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(out, 5);
                return;
            }
            return;
        }
        if (G == 1){
            HANDLE out;
            out = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(out, 2);
            if (G && R == 1){
                HANDLE out;
                out = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(out, 6);
                return;
            }
            if (G && B == 1){
                HANDLE out;
                out = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(out, 11);
                return;
            }
            return;
        }
        if (B == 1){
            HANDLE out;
            out = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(out, 1);
            if (B && R == 1){
                HANDLE out;
                out = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(out, 5);
                return;
            }
            if (B && G == 1){
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
    else if (A == 1){
        if (R && G && B == 1){
            HANDLE out;
            out = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(out, 7);
            return;
        }
        if (R == 1){
            HANDLE out;
            out = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(out, 68);
            if (R && G == 1){
                HANDLE out;
                out = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(out, 102);
                return;
            }
            if (R && B == 1){
                HANDLE out;
                out = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(out, 85);
                return;
            }
            return;
        }
        if (G == 1){
            HANDLE out;
            out = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(out, 34);
            if (G && R == 1){
                HANDLE out;
                out = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(out, 102);
                return;
            }
            if (G && B == 1){
                HANDLE out;
                out = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(out, 51);
                return;
            }
            return;
        }
        if (B == 1){
            HANDLE out;
            out = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(out, 17);
            if (B && R == 1){
                HANDLE out;
                out = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(out, 85);
                return;
            }
            if (B && G == 1){
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

static int readFiles (const char * file){

    FILE *lectura;
	char variable[1025];

	lectura = fopen(file, "rb");

	if (lectura == NULL){
		perror("CharDev ");
		return ERROR;
	}
	else{
		while (feof(lectura) == 0){
			fgets(variable, 1025, lectura);
			printf("%s", variable);
		}
	}
	fclose(lectura);
}

static void coordCpng(cpng * cpng){
    printf("Coord:'%s': X = %d | Y = %d | ID CPNG: %d | ID ENTITY: %d\n", cpng->name, cpng->posX, cpng->posY, cpng->id_cpng, cpng->entity.id_entity);
}

static int saveCpng (cpng * cpng){
    char extend[1024] = ".cpng";
    char total[1024];
    strcpy(total, cpng->name);
    strcat(total, extend);
    String read = '\0';
    if(cpng->mode_save == 1){
        read = "w";
    } else if(cpng->mode_save == 2){
        read = "a";
    } if(cpng->mode_save == 0 || cpng->mode_save < 1){
        puts("move_save is 0 or at number negative");
        return CPNG_ERROR_FILE;
    }
    FILE * f = fopen(total, read);
    if(f == NULL){
        perror("chardev ");
        return CPNG_ERROR_FILE;
    } else {
        fprintf(f,"%s",cpng->asset);
    }
    fclose(f);
}

int saveTexture (texture * Texture){
    char extend[1024] = ".tex";
    char total[1024];
    strcpy(total, Texture->file_texture);
    strcat(total, extend);
    String read = '\0';
    if(Texture->mode_save == 1){
        read = "w";
    } else if(Texture->mode_save == 2){
        read = "a";
    } if(Texture->mode_save == 0 || Texture->mode_save < 1){
        puts("move_save is 0 or at number negative");
        return TEXTURE_ERROR;
    }
    FILE * f = fopen(total, read);
    if(f == NULL){
        perror("chardev ");
        return TEXTURE_ERROR;
    } else {
        fprintf(f,"%s",Texture->texture);
    }
    fclose(f);
}

int readTexture (texture * Texture){
    
    char extend[1024] = ".tex";
    char total[1024];
    char dataFile[1025];
    strcpy(total, Texture->file_texture);
    strcat(total, extend);
    
    FILE * f = fopen(total, "r");

	if (f == NULL){
		perror("CharDev ");
		return TEXTURE_ERROR;
	}
	else{
		while (feof(f) == 0){
			fgets(dataFile, 1025, f);
			printf("%s", dataFile);
		}
	}
	fclose(f);
}

static int readCpng (cpng * cpng){
    
    char extend[1024] = ".cpng";
    char total[1024];
    char dataFile[1025];
    strcpy(total, cpng->name);
    strcat(total, extend);
    
    FILE * f = fopen(total, "r");

	if (f == NULL){
		perror("CharDev ");
		return TEXTURE_ERROR;
	}
	else{
		while (feof(f) == 0){
			fgets(dataFile, 1025, f);
			printf("%s", dataFile);
		}
	}
	fclose(f);
}

static int moveRandCpng (cpng * cpng, int num_max, int num_1, int num_2, int num_3, int num_4){
    int i = newRandom(num_max);
    if(cpng->id_cpng < 1){
        printf("charDev: 'id_cpng' is 0 or negative");
        return CPNG_ERROR;
    } else {
        HANDLE hCon;
        hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = cpng->posX;
        dwPos.Y = cpng->posY;
        SetConsoleCursorPosition(hCon, dwPos);
        if(i == num_1){
            if(num_1 < 1){
                return CPNG_ERROR;
            }
            cpng->posX--;
        } else if(i == num_2){
            if(num_2 < 1){
                return CPNG_ERROR;
            }
            cpng->posX++;
        } if(i == num_3){
            if(num_3 < 1){
                return CPNG_ERROR;
            }
            cpng->posY--;
        } else if(i == num_4){
            if(num_4 < 1){
                return CPNG_ERROR;
            }
            cpng->posY++;
        }
    }
}

static int moveSimpleCpng (cpng * cpng, const String key_1, const String key_2, const String key_3, const String key_4){
    
    char ch;
    if(cpng->id_cpng < 1){
        printf("charDev: 'id_cpng' is 0 or negative");
        return CPNG_ERROR;
    } else {
        HANDLE hCon;
        hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = cpng->posX;
        dwPos.Y = cpng->posY;
        SetConsoleCursorPosition(hCon, dwPos);
        if (kbhit()) {
            ch = READKEY();
            if (ch == key_1) {
                cpng->posX--;
            } else if (ch == key_2) {
                cpng->posX++;
            } else if (ch == key_3) {
                cpng->posY--;
            } else if (ch == key_4) {
                cpng->posY++;
            }
        }
    }
}

static int movReturs (cpng * cpng, const String key_1, const String key_2, const String key_3, const String key_4){
    char ch;
    if(cpng->id_cpng < 1){
        printf("charDev: 'id_cpng' is 0 or negative");
        return CPNG_ERROR;
    } else {
        HANDLE hCon;
        hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = cpng->posX;
        dwPos.Y = cpng->posY;
        SetConsoleCursorPosition(hCon, dwPos);
        if (kbhit()) {
            ch = READKEY();
            if (ch == key_1) {
                cpng->posX--;
            } else if (ch == key_2) {
                cpng->posX++;
            } else if (ch == key_3) {
                cpng->posY--;
            } else if (ch == key_4) {
                cpng->posY++;
            }
        }
    }
}

static int moveSimpleCpngOp (cpng * cpng, const String key_1, const String key_2, const String key_3, const String key_4, const String key_5, void (*callback)()){
    
    char ch;
    if(cpng->id_cpng < 1){
        printf("charDev: 'id_cpng' is 0 or negative");
        return CPNG_ERROR;
    } else {
        HANDLE hCon;
        hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = cpng->posX;
        dwPos.Y = cpng->posY;
        SetConsoleCursorPosition(hCon, dwPos);
        if (kbhit()) {
            ch = READKEY();
            if (ch == key_1) {
                cpng->posX--;
            } else if (ch == key_2) {
                cpng->posX++;
            } else if (ch == key_3) {
                cpng->posY--;
            } else if (ch == key_4) {
                cpng->posY++;
            } else if (ch == key_5){
                callback();
            }
        }
    }
}

static int moveCpng (cpng * cpng, const String key_1, const String key_2, const String key_3, const String key_4, const String key_5, const String key_6, const String key_7, const String key_8){
    
    char ch;
    if(cpng->id_cpng < 1){
        printf("charDev: 'id_cpng' is 0 or negative");
        return CPNG_ERROR;
    } else {
        HANDLE hCon;
        hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = cpng->posX;
        dwPos.Y = cpng->posY;
        SetConsoleCursorPosition(hCon, dwPos);
        printf("%s",cpng->asset);
        if (kbhit()) {
            ch = READKEY();
            if (ch == key_1) {
                cpng->posX--;
            } else if (ch == key_2) {
                cpng->posX++;
            } else if (ch == key_3) {
                cpng->posY--;
            } else if (ch == key_4) {
                cpng->posY++;
            } else if (ch == key_5) {
                cpng->posY--;
                cpng->posX++;
            } else if (ch == key_6) {
                cpng->posY++;
                cpng->posX--;
            } else if (ch == key_7) {
                cpng->posY++;
                cpng->posX++;
            } else if (ch == key_8) {
                cpng->posY--;
                cpng->posX--;
            }
        }
    }
}

int moveSimpleCpng_changes (cpng * cpng, const int time, const String key_1, const String key_2, const String key_3, const String key_4){
    
    char ch;
    String copy;
    copy = cpng->asset;
    if(cpng->id_cpng < 1){
        printf("charDev: 'id_cpng' is 0 or negative");
        return CPNG_ERROR;
    } else {
        HANDLE hCon;
        hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = cpng->posX;
        dwPos.Y = cpng->posY;
        SetConsoleCursorPosition(hCon, dwPos);
        printf("%s",cpng->asset);
        if (kbhit()) {
            ch = READKEY();
            if (ch == key_1) {
                cpng->posX--;
                cpng->asset = cpng->changes_x;
                usleep(time);
            } else if (ch == key_2) {
                cpng->posX++;
                cpng->asset = cpng->changes_x;
                usleep(time);
            } else if (ch == key_3) {
                cpng->posY--;
                cpng->asset = cpng->changes_y;
                usleep(time);
            } else if (ch == key_4) {
                cpng->posY++;
                cpng->asset = cpng->changes_y;
                usleep(time);
            }
        }
        cpng->asset = copy;
    }
}

void showLimitsScene (Scene * scene){
    printf("Limits: '%s' X_1: %d | X_2: %d | Y_1: %d | Y_2: %d\n",scene->name_scene, scene->limitX_1, scene->limitX_2, scene->limitY_1, scene->limitY_2);
}

int setSceneLimits (Scene * scene, cpng * cpng){
    if(scene->id < 1 || cpng->id_cpng < 1){
        printf("charDev: 'id_cpng' or 'id' of scene is 0 or negative");
        return ERROR;
    } else {
        if(cpng->posX == scene->limitX_1){
            cpng->posX--;
        } else if(cpng->posX == scene->limitX_2){
            cpng->posX++;
        } if(cpng->posY == scene->limitY_1){
            cpng->posY++;
        } else if(cpng->posY == scene->limitY_2){
            cpng->posY--;
        }
    }
}

int setSceneLimits_ (Scene * scene, cpng * cpng){
    if(scene->id < 1 || cpng->id_cpng < 1){
        printf("charDev: 'id_cpng' or 'id' of scene is 0 or negative");
        return ERROR;
    } else {
        if(cpng->posX == scene->limitX_r){
            cpng->posX--;
        } else if(cpng->posX == scene->limitX_iz){
            cpng->posX++;
        } if(cpng->posY == scene->limitY_up){
            cpng->posY++;
        } else if(cpng->posY == scene->limitY_down){
            cpng->posY--;
        }
    }
}

void startScreen (Scene * screen){
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
    system("clear");
    for (i = 0; i < screen->height; i++) {
        for (j = 0; j < screen->width; j++) {
            printf("%c", screen->screen[i][j]);
        }
        printf("\n");
    }
}

static int addDraw(cpng * cpng){
    if(cpng->id_cpng < 1){
        printf("charDev: 'id_cpng' is 0 or negative cpng is: '%s'\n",cpng->name);
        return CPNG_ERROR;
    } else{
        HANDLE hCon;
        hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = cpng->posX;
        dwPos.Y = cpng->posY;
        SetConsoleCursorPosition(hCon, dwPos);
        printf("%s",cpng->asset);
    }
}

static int duplicDraw (cpng * cpng, int times, int newline){
    int i;
    if(cpng->id_cpng < 1){
        printf("charDev: 'id_cpng' is 0 or negative");
        return CPNG_ERROR;
    } else{
        HANDLE hCon;
        hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = cpng->posX;
        dwPos.Y = cpng->posY;
        SetConsoleCursorPosition(hCon, dwPos);
        for (i = 0; i < times; i++) {
            if (newline == 1) {
                printf("%s\n", cpng->asset);
            } else {
                printf("%s", cpng->asset);
            }
        }
    }
}
static int time__ (int t){
    usleep(t);
}

static void jumps (int l){
    int i;
    for(i = 0; i < l; i++){
        printf("\n");
    }
}

static void hiddenCursor (int confirmation){
    
    if(confirmation == true){
        CONSOLE_CURSOR_INFO cci = {100, FALSE};
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
    }
    else if(confirmation == false){
    	CONSOLE_CURSOR_INFO cci = {100, TRUE};
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
    }
    
}

static setTitle (const String title){
    SetConsoleTitle(title);
}

static moveRandsOP (cpng * cpng, int num_max, int num_1, int num_2, int num_3, int num_4, int num_5, *(callback)()){
    int i = newRandom(num_max);
    if(cpng->id_cpng < 1){
        printf("charDev: 'id_cpng' is 0 or negative");
        return CPNG_ERROR;
    } else {
        HANDLE hCon;
        hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = cpng->posX;
        dwPos.Y = cpng->posY;
        SetConsoleCursorPosition(hCon, dwPos);
        if(i == num_1){
            if(num_1 < 0){
                return CPNG_ERROR;
            }
            cpng->posX--;
        } else if(i == num_2){
            if(num_2 < 0){
                return CPNG_ERROR;
            }
            cpng->posX++;
        } if(i == num_3){
            if(num_3 < 0){
                return CPNG_ERROR;
            }
            cpng->posY--;
        } else if(i == num_4){
            if(num_4 < 0){
                return CPNG_ERROR;
            }
            cpng->posY++;
        } if(i == num_5){
            if(num_5 < 0){
                return CPNG_ERROR;
            }
            callback();
        }
    }
}

void ini_game (Scene * d){
    d->addDraw = addDraw;
    d->duplicDraw = duplicDraw;
    d->addColor = setColor;
    d->addText = printchar;
    d->drawWait = time__;
    d->clearScene = str_cls;
    d->hiddenCursor = hiddenCursor;
    d->addTitleConsole = setTitle;
    d->showFps = showFPS;
    d->clearAscii = clsAscii;
    d->addPosXY = setPosXY;
    d->center_text = centerText;
    d->genChar = genereRandomChar;
    d->genRandom = newRandom;
    d->readFile = readFiles;
    d->showCoordDraw = coordCpng;
    d->saveDraw = saveCpng;
    d->readDraw = readCpng;
    d->movRandDraw = moveRandCpng;
    d->movDrawFunc = moveSimpleCpngOp;
    d->rgba = colorRGBA;
    d->movDraw = moveSimpleCpng;
    d->movDraw_ = moveCpng;
    d->addJumpsLines = jumps;
    d->movDrawPos = movReturs;
    d->movRandPosOp = moveRandsOP;
}

#endif
