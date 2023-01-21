#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

#define ESPACE 100
#define MAX_ASSETS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATA_LENGTH 100
#define True 1
#define N 50

typedef void Override;
typedef char String[500];

typedef struct
{
    char name[MAX_NAME_LENGTH];
    char data[MAX_DATA_LENGTH];
} Asset;

char INPUT[ESPACE];
char input[ESPACE];
char input2[ESPACE];
char subText[ESPACE];

Asset assets[MAX_ASSETS];
int assetCount = 0;

void StrGotoXY(int X, int Y)
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = X;
    dwPos.Y = Y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void File(const char *file, const char *data)
{
    FILE *archivo;
    archivo = fopen(file, "a");

    if (archivo == NULL)
    {
        perror("Escrity ");
        return;
    }
    printf("Escrity: guardado: '%s'", file);
    fprintf(archivo, "%s\n", data);
    fclose(archivo);
}

static void StringReadFileModeRB(const char *URL)
{
    FILE *lectura;
    char variable[1025];

    lectura = fopen(URL, "rb");
    if (lectura == NULL)
    {
        perror("StringLibrary ");
        printf("Directorio o Archivo: [\" ");
        printf("%s", URL);
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

void sFile(const char *file, const char *data)
{
    FILE *archivo;

    archivo = fopen(file, "a");

    if (archivo == NULL)
    {
        perror("Escrity ");
        return;
    }
    printf("Escrity: guardado: '%s'", file);
    fprintf(archivo, "%s\n", data);
    fclose(archivo);
}

void sFile2(const char *file, const char *data)
{
    FILE *archivo;

    archivo = fopen(file, "a");

    if (archivo == NULL)

    {
        perror("Escrity ");

        return;
    }

    printf("Escrity: guardado: '%s'", file);

    fprintf(archivo, "%s", data);

    fclose(archivo);
}

void readFilesNormal(const char *URL, HWND hwnd)
{
    FILE *lectura;
    char variable[1025];

    lectura = fopen(URL, "rb");

    if (lectura == NULL)
    {
        perror("Escrity ");
        printf("Directorio o Archivo: [\" ");
        printf("%s", URL);
        printf(". \"] \n");

        sFile("registers.rg", "Registers: Escrity: detect.error.badAdress!!!!file.noOpen");
        sFile("registers.rg", "Registers: Escrity: Debug.bigErrorExit.Adress.Invalid.00000075.thead.deferred.module.PE.CS:0073 SS:0007b ES:0073 FS:0033 GS:0033b:");
        MessageBox(hwnd, "Nose puede abrir el archivo, posibles casos:\n1.-Es posible que este mal escrito el nombre de archivo\n2.-Es posible que el archivo no exista.\n3.-Es posible que el input sea invalido.", "CharDeveloping : Stringgame : open file", MB_ICONERROR);
    }
    else
    {
        sFile2("registers.rg", "Registers: Escrity: file.open.success.this.file=\"");
        sFile2("registers.rg", URL);
        sFile("registers.rg", "\"");
        system("cls");
        printf("View file: \n");
        while (feof(lectura) == 0)
        {
            fgets(variable, 1025, lectura);
            printf("%s", variable);
            MessageBox(hwnd, variable, "charDeveloping : view file", MB_ICONINFORMATION);
        }
    }
    sFile("registers.rg", "Registers: Escrity: execute: fclose();.file");
    fclose(lectura);
}

void yReadFile(const char *URL)
{
    FILE *lectura;
    char variable[1025];

    lectura = fopen(URL, "rb");

    if (lectura == NULL)
    {
        perror("Escrity ");
        printf("Directorio o Archivo: [\" ");
        printf("%s", URL);
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

void fileAssets(const char nameAsset[1024])
{
    char cat[1024] = ".asset";
    char nose[1024];

    FILE *file;

    strcpy(nose, nameAsset);
    strcat(nose, cat);
    file = fopen(nose, "r");
    StringReadFileModeRB(nose);
}

int Random(int inicio, int fin)
{
    srand(time(NULL));
    inicio = rand() % fin;

    return inicio;
}

void Char1(int inicio, int fin)
{
    srand(time(NULL));
    inicio = rand() % fin;

    if (inicio == 0)
    {
        printf("A");
    }
    else if (inicio == 1)
    {
        printf("B");
    }
    if (inicio == 2)
    {
        printf("C");
    }
    else if (inicio == 3)
    {
        printf("D");
    }
    if (inicio == 4)
    {
        printf("E");
    }
    else if (inicio == 5)
    {
        printf("F");
    }
    if (inicio == 6)
    {
        printf("G");
    }
    else if (inicio == 7)
    {
        printf("H");
    }
    if (inicio == 8)
    {
        printf("I");
    }
    else if (inicio == 9)
    {
        printf("J");
    }
    if (inicio == 10)
    {
        printf("K");
    }
    else if (inicio == 11)
    {
        printf("L");
    }
    if (inicio == 12)
    {
        printf("M");
    }
    else if (inicio == 13)
    {
        printf("N");
    }
    if (inicio == 14)
    {
        printf("O");
    }
    else if (inicio == 15)
    {
        printf("P");
    }
    if (inicio == 16)
    {
        printf("Q");
    }
    else if (inicio == 17)
    {
        printf("R");
    }
    if (inicio == 18)
    {
        printf("S");
    }
    else if (inicio == 19)
    {
        printf("T");
    }
    if (inicio == 20)
    {
        printf("U");
    }
    else if (inicio == 21)
    {
        printf("V");
    }
    if (inicio == 22)
    {
        printf("W");
    }
    else if (inicio == 23)
    {
        printf("X");
    }
    if (inicio == 24)
    {
        printf("Y");
    }
    else if (inicio == 25)
    {
        printf("Z");
    }
    if (inicio == 26)
    {
        printf("a");
    }
    else if (inicio == 27)
    {
        printf("b");
    }
    if (inicio == 28)
    {
        printf("c");
    }
    else if (inicio == 29)
    {
        printf("d");
    }
    if (inicio == 30)
    {
        printf("e");
    }
    else if (inicio == 31)
    {
        printf("f");
    }
    if (inicio == 32)
    {
        printf("g");
    }
    else if (inicio == 33)
    {
        printf("h");
    }
    if (inicio == 34)
    {
        printf("i");
    }
    else if (inicio == 35)
    {
        printf("j");
    }
    if (inicio == 36)
    {
        printf("k");
    }
    else if (inicio == 37)
    {
        printf("l");
    }
    if (inicio == 38)
    {
        printf("m");
    }
    else if (inicio == 39)
    {
        printf("n");
    }
    if (inicio == 40)
    {
        printf("o");
    }
    else if (inicio == 41)
    {
        printf("p");
    }
    if (inicio == 42)
    {
        printf("q");
    }
    else if (inicio == 43)
    {
        printf("r");
    }
    if (inicio == 44)
    {
        printf("s");
    }
    else if (inicio == 45)
    {
        printf("t");
    }
    if (inicio == 46)
    {
        printf("u");
    }
    else if (inicio == 47)
    {
        printf("v");
    }
    if (inicio == 48)
    {
        printf("w");
    }
    else if (inicio == 49)
    {
        printf("x");
    }
    if (inicio == 50)
    {
        printf("y");
    }
    else if (inicio == 51)
    {
        printf("z");
    }
}
void SetTitle(const char *title)
{
    SetConsoleTitle(title);
}

void CLS(void)
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

static void GotoXY(int X, int Y)
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = X;
    dwPos.Y = Y;
    SetConsoleCursorPosition(hCon, dwPos);
}

static int StrScanInt(int Int)
{
    fflush(stdin);
    scanf("%i", &Int);
    fflush(stdin);

    return Int;
}

static void charClear()
{
    CLS();
}

static void charNewLines(int cand)
{
    if (cand == 1)
    {
        printf("\n");
    }
    else if (cand == 2)
    {
        printf("\n\n");
    }
}

static void Juego_Lee_Tecla()
{
    getchar();
}

int StrGenereRandom(int inicio, int fin)
{
    srand(time(NULL));
    inicio = rand() % fin;

    return inicio;
}

static void view_asset(int URL)
{
    if (URL == 31)
    {
        printf("[ ] = %d", URL);
        return;
    }
    else if (URL == 32)
    {
        printf("[\\n] = %d", URL);
        return;
    }

    char caracters[1024] = {'%', '\\', '|', '=', '[', ']', '<', '>', '{', '}', '@', '#', '$', '_', '&', '-', '+', '(', ')', '/', '*', '\"', '\'', ':', ';', '!', '?', '~', '`', 'N'};
    printf("[%c] = %d", caracters[URL], URL);
}

void cpngs(char nombre_de_archivo[1024])
{
    FILE *db;
    char caracters[1024] = {'%', '\\', '|', '=', '[', ']', '<', '>', '{', '}', '@', '#', '$', '_', '&', '-', '+', '(', ')', '/', '*', '\"', '\'', ':', ';', '!', '?', '~', '`', 'N', 'A', 'B', 'C'};
    int opcion = 0;
    int Randomm = 0;
    int i;

    char cat[1024] = ".cpng";
    char nose[1024];

    strcpy(nose, nombre_de_archivo);
    strcat(nose, cat);
    db = fopen(nose, "a");

    if (db == NULL)
    {
        perror("Stringgame ");
    }

    while (opcion != 33)
    {
        charClear();
        GotoXY(31, 2);
        printf("Creator cpng\n\n");
        printf("Nombre del archivo: %s\n", nose);
        printf("Opciones: 0 - 32 para caracteres 33 para salir\n\n");
        printf("Version del editador: 1.0\n\n");
        printf("Numero anterior\n\n\n");
        view_asset(opcion);
        printf("\n\n\nMarterial:\n\n");
        for (i = 0; i < 30; i++)
        {
            printf(" [%c] ", caracters[i]);
        }

        charNewLines(1);
        printf("\n");
        printf(">> ");
        opcion = StrScanInt(opcion);
        //GotoXY(0,14);
        charNewLines(1);

        if (opcion == 0)
        {
            fprintf(db, "%c", caracters[0]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[0]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 1)
        {
            fprintf(db, "%c", caracters[1]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[1]);
            Juego_Lee_Tecla();
        }
        if (opcion == 2)
        {
            fprintf(db, "%c", caracters[2]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[2]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 3)
        {
            fprintf(db, "%c", caracters[3]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[3]);
            Juego_Lee_Tecla();
        }
        if (opcion == 4)
        {
            fprintf(db, "%c", caracters[4]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[4]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 5)
        {
            fprintf(db, "%c", caracters[5]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[5]);
            Juego_Lee_Tecla();
        }
        if (opcion == 6)
        {
            fprintf(db, "%c", caracters[6]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[6]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 7)
        {
            fprintf(db, "%c", caracters[7]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[7]);
            Juego_Lee_Tecla();
        }
        if (opcion == 8)
        {
            fprintf(db, "%c", caracters[8]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[8]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 9)
        {
            fprintf(db, "%c", caracters[9]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[9]);
            Juego_Lee_Tecla();
        }
        if (opcion == 10)
        {
            fprintf(db, "%c", caracters[10]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[10]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 11)
        {
            fprintf(db, "%c", caracters[11]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[11]);
            Juego_Lee_Tecla();
        }
        if (opcion == 12)
        {
            fprintf(db, "%c", caracters[12]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[12]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 13)
        {
            fprintf(db, "%c", caracters[13]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[13]);
            Juego_Lee_Tecla();
        }
        if (opcion == 14)
        {
            fprintf(db, "%c", caracters[14]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[14]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 15)
        {
            fprintf(db, "%c", caracters[15]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[15]);
            Juego_Lee_Tecla();
        }
        if (opcion == 16)
        {
            fprintf(db, "%c", caracters[16]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[16]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 17)
        {
            fprintf(db, "%c", caracters[17]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[17]);
            Juego_Lee_Tecla();
        }
        if (opcion == 18)
        {
            fprintf(db, "%c", caracters[18]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[18]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 19)
        {
            fprintf(db, "%c", caracters[19]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[19]);
            Juego_Lee_Tecla();
        }
        if (opcion == 20)
        {
            fprintf(db, "%c", caracters[20]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[20]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 21)
        {
            fprintf(db, "%c", caracters[21]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[21]);
            Juego_Lee_Tecla();
        }
        if (opcion == 22)
        {
            fprintf(db, "%c", caracters[22]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[22]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 23)
        {
            fprintf(db, "%c", caracters[23]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[23]);
            Juego_Lee_Tecla();
        }
        if (opcion == 24)
        {
            fprintf(db, "%c", caracters[24]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[24]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 25)
        {
            fprintf(db, "%c", caracters[25]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[25]);
            Juego_Lee_Tecla();
        }
        if (opcion == 26)
        {
            fprintf(db, "%c", caracters[26]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[26]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 27)
        {
            fprintf(db, "%c", caracters[27]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[27]);
            Juego_Lee_Tecla();
        }
        if (opcion == 28)
        {
            fprintf(db, "%c", caracters[28]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[28]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 29)
        {
            fprintf(db, "%c", caracters[29]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[29]);
            Juego_Lee_Tecla();
        }
        if (opcion == 30)
        {
            fprintf(db, "%c", caracters[30]);
            printf("Stringgame: Se ha guardado el caracter: [%c]\n", caracters[30]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 31)
        {
            fprintf(db, " ");
            printf("Stringgame: Se ha guardado el caracter: [ ]\n");
            Juego_Lee_Tecla();
        }
        if (opcion == 32)
        {
            fprintf(db, "\n");
            printf("Stringgame: Se ha guardado el caracter: [\\n]\n");
            Juego_Lee_Tecla();
        }
        else if (opcion == 100)
        {
            //Juego_Lee_Tecla();

            fprintf(db, "%c%c%c", caracters[1], caracters[0], caracters[0]);

            printf("Stringgame: Se ha guardado los caracteres: %c%c%c", caracters[1], caracters[0], caracters[0]);

            Juego_Lee_Tecla();
        }

        if (opcion == 101)

        {
            //Juego_Lee_Tecla();

            fprintf(db, "%c%c%c", caracters[1], caracters[0], caracters[1]);

            printf("Stringgame: Se ha guardado los caracteres: %c%c%c", caracters[1], caracters[0], caracters[1]);

            Juego_Lee_Tecla();
        }

        else if (opcion == 102)

        {
            //Juego_Lee_Tecla();

            fprintf(db, "%c%c%c", caracters[1], caracters[0], caracters[2]);

            printf("Stringgame: Se ha guardado los caracteres: %c%c%c", caracters[1], caracters[0], caracters[2]);

            Juego_Lee_Tecla();
        }

        if (opcion == -1)
        {
            Randomm = StrGenereRandom(0, 33);

            fprintf(db, "%c", caracters[Randomm]);

            printf("Stringgame: Se ha guardado los caracteres: %c", caracters[Randomm]);

            Juego_Lee_Tecla();
        }
    }

    fclose(db);
}

void file_scene_(const char nameAsset[1024])
{
    char cat[1024] = ".sce";
    char nose[1024];

    FILE *file;

    strcpy(nose, nameAsset);

    strcat(nose, cat);

    file = fopen(nose, "r");

    StringReadFileModeRB(nose);
}

static void _view_(int URL)
{
    char _scene_large[33] = {'%', '\\', '|', '=', '[', ']', '<', '>', '{', '}', '@', '#', '$', '_', '&', '-', '+', '(', ')', '/', '*', '\"', '\'', ':', ';', '!', '?', '~', '`', 'N', 'A', 'B', 'C'};

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

    printf("[ %c ] = %d\n", _scene_large[URL], URL);
}

void create_scene_(char File[1024])
{
    FILE *db;
    char cat[1024] = ".sce";
    char nose[1024];
    char key;

    strcpy(nose, File);
    strcat(nose, cat);
    
    db = fopen(nose, "a");

    if (db == NULL)
    {
        perror("Stringgame ");
    }

    else
    {
        while (key != 'E')
        {
            charClear();
            GotoXY(31, 2);
            printf("Creator Scenes\n\n");
            printf("Nombre de la _scene_: %s\n", nose);
            printf("Presiona 'E' para salir\n");
            printf("Presiona '\\' para salto de linea o presiona '/' para dar un espacio\n");
            charNewLines(1);
            printf("\n");
            printf(">> ");
            key = getch();
            if(key == '\\'){
                fprintf(db, "\n");
            }
            else if(key == '/'){
                fprintf(db," ");
            }
            else{
                fprintf(db, "%c", key);
            }
            charNewLines(1);
        }
    }
}

void StrCreate_scene_(char File[1024])
{
    char _scene_large[33] = {'%', '\\', '|', '=', '[', ']', '<', '>', '{', '}', '@', '#', '$', '_', '&', '-', '+', '(', ')', '/', '*', '\"', '\'', ':', ';', '!', '?', '~', '`', 'N', 'A', 'B', 'C'};
    FILE *db;
    int opcion = 0;
    int Randomm = 0;

    int i;

    char cat[1024] = ".sce";
    char nose[1024];

    strcpy(nose, File);

    strcat(nose, cat);

    db = fopen(nose, "a");

    if (db == NULL)
    {
        perror("Stringgame ");
    }

    while (opcion != 23 || opcion == -1)
    {
        charClear();
        GotoXY(31, 2);
        printf("Editor Scenes\n\n");
        printf("Nombre de la _scene_: %s\n", nose);
        printf("Opciones: 0 - 22 para caracteres 23 para salir\n\n");
        printf("20 = [ ] - 21  = [\\n]");
        printf("Version del editador: 1.0\n\n");
        printf("Numero anterior\n\n\n");
        _view_(opcion);
        printf("\n\n\nMarterial:\n\n");
        for (i = 0; i < 33; i++)
        {
            printf(" [%c] ", _scene_large[i]);
        }

        charNewLines(1);
        printf("\n");
        printf(">> ");
        opcion = StrScanInt(opcion);
        charNewLines(1);

        if (opcion == 0)
        {
            fprintf(db, "%c", _scene_large[0]);
            printf("charDeveloping(Stringgame): Se ha guardado el caracter: [%c]\n", _scene_large[0]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 1)
        {
            fprintf(db, "%c", _scene_large[1]);
            printf("charDeveloping(Stringgame): Se ha guardado el caracter: [%c]\n", _scene_large[1]);
            Juego_Lee_Tecla();
        }
        if (opcion == 2)
        {
            fprintf(db, "%c", _scene_large[2]);
            printf("charDeveloping(Stringgame): Se ha guardado el caracter: [%c]\n", _scene_large[2]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 3)
        {
            fprintf(db, "%c", _scene_large[3]);
            printf("charDeveloping(Stringgame): Se ha guardado el caracter: [%c]\n", _scene_large[3]);
            Juego_Lee_Tecla();
        }
        if (opcion == 4)
        {
            fprintf(db, "%c", _scene_large[4]);
            printf("charDeveloping(Stringgame): Se ha guardado el caracter: [%c]\n", _scene_large[4]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 5)
        {
            fprintf(db, "%c", _scene_large[5]);
            printf("charDeveloping(Stringgame): Se ha guardado el caracter: [%c]\n", _scene_large[5]);
            Juego_Lee_Tecla();
        }
        if (opcion == 6)
        {
            fprintf(db, "%c", _scene_large[6]);
            printf("charDeveloping(Stringgame): Se ha guardado el caracter: [%c]\n", _scene_large[6]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 7)
        {
            fprintf(db, "%c", _scene_large[7]);
            printf("charDeveloping(Stringgame): Se ha guardado el caracter: [%c]\n", _scene_large[7]);
            Juego_Lee_Tecla();
        }
        if (opcion == 8)
        {
            fprintf(db, "%c", _scene_large[8]);
            printf("charDeveloping(Stringgame): Se ha guardado el caracter: [%c]\n", _scene_large[8]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 9)
        {
            fprintf(db, "%c", _scene_large[9]);
            printf("charDeveloping(Stringgame): Se ha guardado el caracter: [%c]\n", _scene_large[9]);
            Juego_Lee_Tecla();
        }
        if (opcion == 10)
        {
            fprintf(db, "%c", _scene_large[10]);
            printf("charDeveloping(Stringgame): Se ha guardado el caracter: [%c]\n", _scene_large[10]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 11)
        {
            fprintf(db, "%c", _scene_large[11]);
            printf("charDeveloping(Stringgame): Se ha guardado el caracter: [%c]\n", _scene_large[11]);
            Juego_Lee_Tecla();
        }
        if (opcion == 12)
        {
            fprintf(db, "%c", _scene_large[12]);
            printf("charDeveloping(Stringgame): Se ha guardado el caracter: [%c]\n", _scene_large[12]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 13)
        {
            fprintf(db, "%c", _scene_large[13]);
            printf("charDeveloping(Stringgame): Se ha guardado el caracter: [%c]\n", _scene_large[13]);
            Juego_Lee_Tecla();
        }
        if (opcion == 14)
        {
            fprintf(db, "%c", _scene_large[14]);
            printf("charDeveloping(Stringgame): Se ha guardado el caracter: [%c]\n", _scene_large[14]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 15)
        {
            fprintf(db, "%c", _scene_large[15]);
            printf("charDeveloping(Stringgame): Se ha guardado el caracter: [%c]\n", _scene_large[15]);
            Juego_Lee_Tecla();
        }
        if (opcion == 16)
        {
            fprintf(db, "%c", _scene_large[16]);
            printf("charDeveloping(Stringgame): Se ha guardado el caracter: [%c]\n", _scene_large[16]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 17)
        {
            fprintf(db, "%c", _scene_large[17]);
            printf("charDeveloping(Stringgame): Se ha guardado el caracter: [%c]\n", _scene_large[17]);
            Juego_Lee_Tecla();
        }
        if (opcion == 18)
        {
            fprintf(db, "%c", _scene_large[18]);
            printf("charDeveloping(Stringgame): Se ha guardado el caracter: [%c]\n", _scene_large[18]);
            Juego_Lee_Tecla();
        }
        else if (opcion == 19)
        {
            fprintf(db, "%c", _scene_large[19]);
            printf("charDeveloping(Stringgame): Se ha guardado el caracter: [%c]\n", _scene_large[19]);
            Juego_Lee_Tecla();
        }

        if (opcion == 20)
        {
            fprintf(db, " ");
            printf("charDeveloping(Stringgame): Se ha guardado el caracter: [ ]\n");
            Juego_Lee_Tecla();
        }
        else if (opcion == 21)
        {
            fprintf(db, "\n");
            printf("charDeveloping(Stringgame): Se ha guardado el caracter: [\\n]\n");
            Juego_Lee_Tecla();
        }

        if (opcion == 22)
        {
            Randomm = StrGenereRandom(0, 20);
            fprintf(db, "%c", _scene_large[Randomm]);
            printf("charDeveloping(Stringgame): Se ha guardado los caracteres: %c", _scene_large[Randomm]);
            Juego_Lee_Tecla();
        }
    }
    fclose(db);
}

Override DuplicText(const char *text, int cantidad, int tipo)
{
    int fin = 0, ale = 0, figura;

    if (tipo == 0)
    {
        while (1)
        {
            fin++;
            printf("%s", text);
            if (fin == cantidad)
            {
                break;
            }
        }
    }
    else if (tipo == 1)
    {
        while (1)
        {
            fin++;
            printf("%s ", text);
            if (fin == cantidad)
            {
                break;
            }
        }
    }
    if (tipo == 2)
    {
        while (1)
        {
            fin++;
            printf("%s\n", text);
            if (fin == cantidad)
            {
                break;
            }
        }
    }

    if (tipo == 3)
    {
        if (text == NULL)
        {
            while (1)
            {
                fin++;
                printf(" ");
                if (fin == cantidad)
                {
                    break;
                }
            }
        }
    }

    if (tipo == -1)
    {
        while (fin != 1620)
        {
            fin++;
            printf("#");
            if (fin == cantidad)
            {
                break;
            }
        }
    }

    if (tipo == -2)
    {
        ale = StrGenereRandom(fin, 1660);
        figura = StrGenereRandom(0, 5);
        if (figura == 0)
        {
            while (fin != ale)
            {
                fin++;
                printf("#");
                if (fin == cantidad)
                {
                    break;
                }
            }
        }
        else if (figura == 1)
        {
            while (fin != ale)
            {
                fin++;
                printf("&");
                if (fin == cantidad)
                {
                    break;
                }
            }
        }

        if (figura == 3)
        {
            while (fin != ale)
            {
                fin++;
                printf("[#]");
                if (fin == cantidad)
                {
                    break;
                }
            }
        }
        else if (figura == 4)
        {
            while (fin != ale)
            {
                fin++;
                printf("=");
                if (fin == cantidad)
                {
                    break;
                }
            }
        }
    }
}

void newProject(const char URL[1024], HWND hwndDlg, const char Name[1024])
{
    char cat[1024] = "/main.c";
    char cat1[] = ".dat";
    char cat2[1024];
    char MainFile[1024];

    FILE *file;

    strcpy(cat2, Name);

    strcat(cat2, cat1);

    strcpy(MainFile, URL);

    strcat(MainFile, cat);

    file = fopen(MainFile, "wb");

    if (file == NULL)
    {
        perror("charDeveloping ");
        return;
    }

    //creación: del archivo mainScene.sce
    sFile("mainScene.sce", "Main Scene. CharDeveloping");
    //creación: del archivo main.c
    sFile(MainFile, "#include \"include\\stringgame.h\"");
    sFile(MainFile, "");
    sFile(MainFile, "void paint_game (struct _scenes_ * Scene);");
    sFile(MainFile, "");
    sFile(MainFile, "int main (void){");
    sFile(MainFile, "");
    sFile(MainFile, "     //Struct of main scene");
    sFile(MainFile, "     struct _scenes_ mainScene;");
    sFile(MainFile, "");
    sFile(MainFile, "     strcpy(mainScene.name,\"mainScene\");");
    sFile(MainFile, "     mainScene.id = 0;");
    sFile(MainFile, "     mainScene.actives = 1;//never 0");
    sFile(MainFile, "");
    sFile(MainFile, "     while(true){");
    sFile(MainFile, "");
    sFile(MainFile, "          paint_game(&mainScene);");
    sFile(MainFile, "");
    sFile(MainFile, "  }");
    sFile(MainFile, "}");
    sFile(MainFile, "");
    sFile(MainFile, "void paint_game (struct _scenes_ * Scene){");
    sFile(MainFile, "");
    sFile(MainFile, "     StrLoad_scene_(Scene);");
    sFile(MainFile, "");
    sFile(MainFile, "}");
    sFile(MainFile, "");
    //creación: del archivo main.ty
    sFile("main.ty", "/*Notas: Este archivo generado es un fichero inutil por el momento. Puedes eliminarlo*/");
    sFile("main.ty", "crea:importation:std;");
    sFile("main.ty", "func<paint_game>(?scene.Scene){");
    sFile("main.ty", "     crea.load_scenes_(Scene);");
    sFile("main.ty", "}");
    sFile("main.ty", "TYP<main>(func){");
    sFile("main.ty", "     ?scene.mainScene;");
    sFile("main.ty", "     mainScene.ini.name::mainScene::end;");
    sFile("main.ty", "     mainScene.ini.id = 1;");
    sFile("main.ty", "     mainScene.ini.actives = 1;");
    sFile("main.ty", "     while(True){");
    sFile("main.ty", "          invocation.func.paint_game(mainScene.today);");
    sFile("main.ty", "     }");
    sFile("main.ty", "}");
    sFile("main.ty", "");
    //Creación: del archivo .dat
    sFile2(Name, "Proyecto: ");
    sFile2(Name, Name);
    sFile(Name, "Archivo principal: ");
    sFile2(Name, "main.c");
    sFile(Name, "Archivo segundario: ");
    sFile2(Name, "main.ty");
    sFile(Name, "URL: ");
    sFile2(Name, MainFile);

    MessageBox(hwndDlg, "Se ha creado el projecto", "Nuevo projecto", MB_ICONINFORMATION);
}

void addAsset(const char *name, const char *data)
{
    if (assetCount >= MAX_ASSETS)
    {
        printf("Error: no hay espacio para más assets.\n");
        return;
    }

    strcpy(assets[assetCount].name, name);
    strcpy(assets[assetCount].data, data);
    assetCount++;
}

void deleteAsset(int index)
{
    if (index < 0 || index >= assetCount)
    {
        printf("Error: el índice es inválido.\n");
        return;
    }

    for (int i = index; i < assetCount - 1; i++)
    {
        assets[i] = assets[i + 1];
    }
    assetCount--;
}

void listAssets()
{
    for (int i = 0; i < assetCount; i++)
    {
        printf("%d. %s\n", i + 1, assets[i].name);
    }
}

void printMenu()
{
    printf("\n");
    printf("1. Añadir un asset\n");
    printf("2. Eliminar un asset\n");
    printf("3. Listar assets\n");
    printf("4. Salir\n");
    printf("\n");
    printf("Elige una opción: ");
}

int creatorAssetMenu()
{
    while (1)
    {
        printMenu();
        int option;
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {
            char name[MAX_NAME_LENGTH];
            char data[MAX_DATA_LENGTH];
            printf("Nombre del asset: ");
            scanf("%s", name);
            printf("Datos del asset: ");
            scanf("%s", data);
            addAsset(name, data);
            break;
        }
        case 2:
        {
            int index;
            printf("Índice del asset a eliminar: ");
            scanf("%d", &index);
            deleteAsset(index - 1);
            break;
        }
        case 3:
            listAssets();
            break;
        case 4:
            return 0;
        default:
            printf("Opción inválida.\n");
            break;
        }
    }
    return 0;
}