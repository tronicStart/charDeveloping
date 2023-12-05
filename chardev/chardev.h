////////////////////////////////////////////////////
// Libreria en desarrollo constante //
//////////////////////////////////////////////////
//version: 0.0.1
//creador: Tronic_start y hack_hero
#ifndef CHARDEV_H
#define CHARDEV_H

#include "chardef.h"

static void addCpngAsset (cpng * d){
    if(d->id < 1){
        printf("charDev: 'id' is 0 or negative cpng is: '%s'\n",d->name);
        return;
    } else{
        HANDLE hCon;
        hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = d->X;
        dwPos.Y = d->Y;
        SetConsoleCursorPosition(hCon, dwPos);
        printf("%s",d->asset);
    }
}

static void coordCpngShow (cpng * d){
    printf("cpng: '%s' | posX = '%i' | posY = '%i'\n",d->name,d->X,d->Y);
}

static void _addCpngOnly (cpng * d){
    printf("%s",d->asset);
}

static void _addCpngFile (cpng * d){
    char extend[1024] = ".cpng";
    char total[1024];
    char dataFile[1025];
    strcpy(total, d->url);
    strcat(total, extend);
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    FILE * f = fopen(total, "r");
	if (f == NULL){
		perror("CharDev ");
		return;
	}
	else{
		dwPos.X = d->X;
        dwPos.Y = d->Y;
        SetConsoleCursorPosition(hCon, dwPos);
		while (feof(f) == 0){
			fgets(dataFile, 1025, f);
			printf("%s", dataFile);
		}
	}
	fclose(f);
}

static void _addCpngFileOnly (cpng * d){
    char dataFile[1025];
    FILE * f = fopen(d->url, "r");
	if (f == NULL){
		perror("CharDev ");
		return;
	}
	else{
		while (feof(f) == 0){
			fgets(dataFile, 1025, f);
			printf("%s", dataFile);
		}
	}
	fclose(f);
}

static void addColor (int color){
    HANDLE out;
    out=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(out,color);
}

static int _addText (const String format, ...){
    va_list args;
    va_start(args, format);
    int count = vprintf(format, args);
    va_end(args);
  return count;
}

static void _rgba (int R, int G, int B, int A){
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

static void _addJumpLine (int lines){
    int i;
    for(i = 0; i < lines; i++){
        printf("\n");
    }
}

static void _duplicCpng (cpng * d, int times, int newline){
    int i;
    if(d->id < 1){
        printf("charDev: 'id' is 0 or negative");
        return;
    } else{
        HANDLE hCon;
        hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = d->X;
        dwPos.Y = d->Y;
        SetConsoleCursorPosition(hCon, dwPos);
        for (i = 0; i < times; i++) {
            if (newline == 1) {
                printf("%s\n", d->asset);
            } else {
                printf("%s", d->asset);
            }
        }
    }
}

static void _duplicChar (const String asset, int times, int newline){
    int i;
    for (i = 0; i < times; i++) {
            if (newline == 1) {
                printf("%s\n", asset);
            } else {
                printf("%s", asset);
            }
    }
}

static void _duplicCpngFile (cpng * d, int times, int newline){
    int i;
    char dataFile[1025];
    FILE * f = fopen(d->url, "r");
	if (f == NULL){
		perror("CharDev ");
		return;
	}
	else{
		while (feof(f) == 0){
			fgets(dataFile, 1025, f);
			printf("%s", dataFile);
		}
	}
	fclose(f);
    for (i = 0; i < times; i++) {
            if (newline == 1) {
                printf("%s\n", dataFile);
            } else {
                printf("%s", dataFile);
            }
    }
}

static void _saveCpngFile (cpng * d){
    FILE * fp = fopen(d->url,"a");
    if(fp == NULL){
        perror("chardev ");
        return;
    } else {
        fprintf(fp, "%s", d->asset);
        fclose(fp);
    }
}

static void _gotoXY (int x, int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

static void _centerText (const String text){
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

static void _addJumpLineColor (int color, int lines){
    int i;
    for(i = 0; i < lines; i++){
        addColor(color);
        printf("\n");
        addColor(7);
    }
}

static int _getSizeConsoleX (){
    int rows, columns;
    char buffer[256];
    FILE * terminal = popen("stty size","r");
    fgets(buffer, 256, terminal);
    sscanf(buffer, "%d %d",&rows,&columns);
    pclose(terminal);
    return columns;
}

static int _getSizeConsoleY (){
    int rows,columns;
    char buffer[256];
    FILE * terminal = popen("stty size","r");
    fgets(buffer, 256, terminal);
    sscanf(buffer, "%d %d", &rows, &columns);
    pclose(terminal);
    return rows;
}

static int _randomInt (int n){
    int r;
    srand(time(NULL));
    r = rand() % n;
    return r;
}

static char _getRandomChar(){
    int i;
    srand(time(0));
    for (i = 0; i < 10; i++) {
        char letter = (rand() % 26) + 65;
        return letter;
    }
}

static void _readLine (){
    getche();
}

static int _readKey (){
    return getch();
}

//mov functions
static void _moveCpng (cpng * d, const String key_1, const String key_2, const String key_3, const String key_4){
    char ch;
    if(d->id < 1){
        printf("charDev: 'id' is 0 or negative");
        return;
    } else {
        if (kbhit()) {
            ch = READKEY();
            if (ch == key_1) {
                d->X--;
            } else if (ch == key_2) {
                d->X++;
            } else if (ch == key_3) {
                d->Y--;
            } else if (ch == key_4) {
                d->Y++;
            }
        }
    }
}

static void _setLimitCpng (cpng * d, int limit_right, int limit_left, int limit_up, int limit_down){
    if(d->id < 1){
        printf("charDev: 'id' is 0 or negative");
        return;
    } else {
        if(d->X == limit_right){
            d->X--;
        } else if(d->X == limit_left){
            d->X++;
        } if(d->Y == limit_up){
            d->Y++;
        } else if(d->Y == limit_down){
            d->Y--;
        }
    }
}

static void _moveCpngDiagonal (cpng * d, const String key_1, const String key_2, const String key_3, const String key_4, const String key_5, const String key_6, const String key_7, const String key_8){
    char ch;
    if(d->id < 1){
        printf("charDev: 'id' is 0 or negative");
        return;
    } else {
        if (kbhit()) {
            ch = READKEY();
            if (ch == key_1) {
                d->X--;
            } else if (ch == key_2) {
                d->X++;
            } else if (ch == key_3) {
                d->Y--;
            } else if (ch == key_4) {
                d->Y++;
            } else if (ch == key_5) {
                d->Y--;
                d->X++;
            } else if (ch == key_6) {
                d->Y++;
                d->X--;
            } else if (ch == key_7) {
                d->Y++;
                d->X++;
            } else if (ch == key_8) {
                d->Y--;
                d->X--;
            }
        }
    }
}

static void _moveCpngFunc (cpng * d, const String key_1, const String key_2, const String key_3, const String key_4, const String key_5, void (*callback)()){
    char ch;
    if(d->id < 1){
        printf("charDev: 'id' is 0 or negative");
        return;
    } else {
        if (kbhit()) {
            ch = READKEY();
            if (ch == key_1) {
                d->X--;
            } else if (ch == key_2) {
                d->X++;
            } else if (ch == key_3) {
                d->Y--;
            } else if (ch == key_4) {
                d->Y++;
            } else if (ch == key_5){
                callback();
            }
        }
    }
}

static void _moveCpngDiagonalFunc (cpng * d, const String key_1, const String key_2, const String key_3, const String key_4, const String key_5, const String key_6, const String key_7, const String key_8, const String key_9, void (*callback)()){
    char ch;
    if(d->id < 1){
        printf("charDev: 'id' is 0 or negative");
        return;
    } else {
        if (kbhit()) {
            ch = READKEY();
            if (ch == key_1) {
                d->X--;
            } else if (ch == key_2) {
                d->X++;
            } else if (ch == key_3) {
                d->Y--;
            } else if (ch == key_4) {
                d->Y++;
            } else if (ch == key_5) {
                d->Y--;
                d->X++;
            } else if (ch == key_6) {
                d->Y++;
                d->X--;
            } else if (ch == key_7) {
                d->Y++;
                d->X++;
            } else if (ch == key_8) {
                d->Y--;
                d->X--;
            } else if(ch == key_9) {
                callback();
            }
        }
    }
}

static void _setLimitCpngT (cpng * d, scene * sc){
    if(d->id < 1){
        printf("charDev: 'id' is 0 or negative");
        return;
    } else {
        if(d->X == sc->limit_right){
            d->X--;
        } else if(d->X == sc->limit_left){
            d->X++;
        } if(d->Y == sc->limit_up){
            d->Y++;
        } else if(d->Y == sc->limit_down){
            d->Y--;
        }
    }
}

static void _moveCpngOnly (cpng * p, int limit, int a, int d, int w, int s){
    int r;
    srand(time(NULL));
    r = rand() % limit;
    if(p->id < 1){
        printf("charDev: 'id' is 0 or negative");
        return;
    } else {
        if (r == a) {
                p->X--;
            } else if (r == d) {
                p->X++;
            } else if (r == w) {
                p->Y--;
            } else if (r == s) {
                p->Y++;
            }
    }
}

static void _moveCpngOnlyDiagonal (cpng * p, int limit, int a, int d, int w, int s, int q, int e, int y, int x){
    int r;
    srand(time(NULL));
    r = rand() % limit;
    if(p->id < 1){
        printf("charDev: 'id' is 0 or negative");
        return;
    } else {
        if (r == a) {
            p->X--;
        } else if (r == d) {
            p->X++;
        } else if (r == w) {
            p->Y--;
        } else if (r == s) {
            p->Y++;
        } else if (r == q){
            p->Y--;
            p->X++;
        } else if (r == e) {
            p->Y++;
            p->X--;
        } else if (r == y) {
            p->Y++;
            p->X++;
        } else if (r == x) {
            p->Y--;
            p->X--;
       }
    }
}

static void _moveCpngOnlyFunc (cpng * p, int limit, int a, int d, int w, int s, int f, void (*callback)()){
    int r;
    srand(time(NULL));
    r = rand() % limit;
    if(p->id < 1){
        printf("charDev: 'id' is 0 or negative");
        return;
    } else {
        if (r == a) {
           p->X--;
        } else if (r == d) {
           p->X++;
        } else if (r == w) {
           p->Y--;
        } else if (r == s) {
           p->Y++;
        } else if (r == f) {
            callback();
        }
    }
}

static void _moveCpngOnlyDiagonalFunc (cpng * p, int limit, int a, int d, int w, int s, int q, int e, int y, int x, int f, void (*callback)()){
    int r;
    srand(time(NULL));
    r = rand() % limit;
    if(p->id < 1){
        printf("charDev: 'id' is 0 or negative");
        return;
    } else {
        if (r == a) {
            p->X--;
        } else if (r == d) {
            p->X++;
        } else if (r == w) {
            p->Y--;
        } else if (r == s) {
            p->Y++;
        } else if (r == q){
            p->Y--;
            p->X++;
        } else if (r == e) {
            p->Y++;
            p->X--;
        } else if (r == y) {
            p->Y++;
            p->X++;
        } else if (r == x) {
            p->Y--;
            p->X--;
       } else if (r == f) {
           callback();
       }
    }
}

static int _createFile (const String name, const String lec, const String dat){
    FILE * fp = fopen(name,lec);
    if(fp != NULL){
        fprintf(fp, "%s", dat);
    } else {
        perror("charDev ");
        return -1;
    }
    fclose(fp);
}

static void _readFile (const String file){
    FILE *lectura;
    char variable[1025];
    lectura = fopen(file, "rb");
    if (lectura == NULL){
		perror("CharDev ");
		return -1;
	}
	else{
		while (feof(lectura) == 0){
			fgets(variable, 1025, lectura);
			printf("%s", variable);
		}
	}
	fclose(lectura);
}

static int _extractDataFileCpng (char matriz[][1024], cpng * p){
    FILE *archivo;
    int i, j;
    archivo = fopen(p->url, "r");
    if (archivo == NULL) {
        return -1;
    }
    for (i = 0; i < p->files; i++) {
        if (fgets(matriz[i], p->columns, archivo) == NULL) {
            return 1;
        }
    }
    fclose(archivo);
}

static int _extractDataFile (char matriz[][1024], const String url, int files, int columns){
    FILE *archivo;
    int i, j;
    archivo = fopen(url, "r");
    if (archivo == NULL) {
        return -1;
    }
    for (i = 0; i < files; i++) {
        if (fgets(matriz[i], columns, archivo) == NULL) {
            return 1;
        }
    }
    fclose(archivo);
}

static int _saveCpng (cpng * p){
    FILE * fp = fopen(p->url,p->lecture);
    if(fp == NULL){
        perror("charDev ");
        return -1;
    } else {
        fprintf(fp,"%s", p->asset);
    }
    fclose(fp);
}

static void _hiddenCursor (int confirmation){
    if(confirmation == GAMETRUE){
        CONSOLE_CURSOR_INFO cci = {100, FALSE};
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
    }
    else if(confirmation == GAMEFALSE){
    	CONSOLE_CURSOR_INFO cci = {100, TRUE};
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
    }
}

static void _addTitleConsole (const String title){
    SetConsoleTitle(title);
}

static void _clearConsole (){
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

void start_scene (scene * s){
    s->addCpng = addCpngAsset;
    s->addCpngOnly = _addCpngOnly;
    s->coordCpng = coordCpngShow;
    s->addCpngFile = _addCpngFile;
    s->addCpngFileOnly = _addCpngFileOnly;
    s->setColor = addColor;
    s->addText = _addText;
    s->rgba = _rgba;
    s->addJumpLine = _addJumpLine;
    s->addJumpLineColor = _addJumpLineColor;
    s->duplicCpng = _duplicCpng;
    s->duplicChar = _duplicChar;
    s->duplicCpngFile = _duplicCpngFile;
    s->saveCpngFile = _saveCpngFile;
    s->gotoXY = _gotoXY;
    s->centerText = _centerText;
    s->getRandomInt = _randomInt;
    s->getRandomChar = _getRandomChar;
    s->readLine = _readLine;
    s->readKey = _readKey;
    s->hiddenCursor = _hiddenCursor;
    s->addTitleConsole = _addTitleConsole;
    s->clearConsole = _clearConsole;
    s->getSizeConsoleX = _getSizeConsoleX;
    s->getSizeConsoleY = _getSizeConsoleY;
    s->mov.moveCpng = _moveCpng;
    s->mov.moveCpngDiagonal = _moveCpngDiagonal;
    s->mov.moveCpngFunc = _moveCpngFunc;
    s->mov.moveCpngDiagonalFunc = _moveCpngDiagonalFunc;
    s->mov.moveCpngOnly = _moveCpngOnly;
    s->mov.moveCpngOnlyDiagonal = _moveCpngOnlyDiagonal;
    s->mov.moveCpngOnlyFunc = _moveCpngOnlyFunc;
    s->mov.moveCpngOnlyDiagonalFunc = _moveCpngOnlyDiagonalFunc;
    s->mov.setLimitCpng = _setLimitCpng;
    s->mov.setLimitCpng_ = _setLimitCpngT;
    s->Files.createFile = _createFile;
    s->Files.readFile = _readFile;
    s->Files.extractDataFileCpng = _extractDataFileCpng;
    s->Files.extractDataFile = _extractDataFile;
    s->Files.saveCpng = _saveCpng;
}

#endif
