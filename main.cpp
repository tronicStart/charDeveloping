/*
Codigo del programa chardevelopig
Creado y modificado por Tronic/TronicStart
*/
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <commctrl.h>
#include <conio.h>
#include <tchar.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "resource.h"
#include "chardevelopingc.h"

#define NUM_PALABRAS_RESERVADAS_C (sizeof(palabrasReservadasC) / sizeof(palabrasReservadasC[0]))
#define NUM_PALABRAS_RESERVADAS_RUBY (sizeof(palabrasReservadasRuby) / sizeof(palabrasReservadasRuby[0]))

BOOL SetBackgroundColor(HWND hEdit, int nStart, int nEnd, COLORREF crColor);
void marcarPalabrasPonerCodigo(HWND hEdit, char *Text);
void InsertarMenu(HWND hWnd);
void Guardar(HWND hctrl, char *fichero);
BOOL leerArchivo(HWND hEdit, LPCTSTR lpFileName);

HINSTANCE hInst;
HWND hEdit;
int hotkey_id;

BOOL CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    //Variables para ser usadas en el programa para entrada de datos por el usuario
    String user1, user2, project_active, user1_copy;
    //Nombre de los archivos de ayuda
    char *user1_cat, MainFile[] = "main.c", cpngFile[] = "cpng.h", structs[] = "objects.h", registros[] = "registers.rg";
    HDC hdc;
    PAINTSTRUCT ps;
    static HINSTANCE hInstance;
    int check, Project_active;
    FILE *fp;
    hotkey_id = GlobalAddAtom("CtrlS");
    RegisterHotKey(NULL, hotkey_id, MOD_CONTROL, 'S');
    // Bucle de mensajes de Windows
    MSG msg;

    switch (uMsg)
    {
    case WM_INITDIALOG:
        /*
         * TODO: Add code to initialize the dialog.
         */
        InsertarMenu(hwndDlg);
        SetTitle("Char Developing : cmd : start");
        printf("Stringgame : open! : ");
        //Creamos el edit text 
        hEdit = CreateWindowEx(
            WS_EX_CLIENTEDGE,
            _T("EDIT"),
            _T(""),
            WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_WANTRETURN,
            210,
            70,
            240,
            170,
            hwndDlg,
            (HMENU)ID_TEXTO,
            GetModuleHandle(NULL),
            NULL);

        return TRUE;

    case WM_PAINT:
        hdc = BeginPaint(hwndDlg, &ps);
        TextOut(hdc, 10, 20, "Comandos", 8);
        TextOut(hdc, 390 - 15, 20, "Editor de texto", 15);
        EndPaint(hwndDlg, &ps);
        break;

    case WM_CLOSE:

        printf("CharDeveloping : ");
        yReadFile("User.dat");
        printf(" : desea salir?\n");
        if (MessageBox(hwndDlg, "Desea cerrar el programa", "Cerrar", MB_ICONQUESTION | MB_YESNO) == IDYES)
        {
            EndDialog(hwndDlg, 0);
        }
        printf("CharDeveloping : ");
        yReadFile("User.dat");
        printf(" : no cerro el programa");

        return TRUE;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
            /* 
             * TODO: Add more control ID's, when needed.
             */
            //Caso para eliminar un archivo
        case CM_PRUEBA:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);

            if (remove(user1) == -1)
            {
                SetTitle("CharDeveloping : cmd : error");
                MessageBox(hwndDlg, "El Archivo no se pudo eliminar...", "CharDeveloping : Error", MB_ICONERROR);
                SetTitle("CharDeveloping : cmd");
            }

            else
            {
                MessageBox(hwndDlg, "Archivo Eliminado con exito", "CharDeveloping : Exito", MB_ICONINFORMATION);
            }

            return TRUE;
            /*
        case CM_CREADOR_SCENE_PRO:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            sFile2(registros, "Registers: User.create.and.file.for.scene=\"");
            sFile2(registros, user1);
            sFile(registros, "\"");
            create_scene_(user1);

            return TRUE;*/
            //Caso para el boton guardar
        case CM_BTN_GUARDAR:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            //marcarPalabrasReservadas(hEdit);
            Guardar(hEdit, user1); //hctrl
            MessageBox(hwndDlg, "Se ha guardado el archivo con exito.", "charDeveliping : Exito", MB_ICONINFORMATION);

            return TRUE;
            //Caso para el boton command
        case CM_VIEW_COMMANDS:

            MessageBox(hwndDlg, "Los comandos que se ven aqui se escriben en el input 1: \n1.-exit.program\nDescripcion:  comando para salir del programa\n2.-clear.screen\nDescripcion:  comando para limpiar la pantalla -> la de la terminal o consola\n3.-view.texture\nDescripcion:  comando para ver una texture\n4.-read.scene\nDescripcion:  comando para leer una esena\n5.-open.creator.scenes\nDescripcion:  comando para abrir el creador de scenas\n6.-create.texture:\nDescripcion: Este comando ayuda a crear un texture\n7.-create.fuction:\nDescripcion: Este comando ayuda a crear las funciones\n8.-create.object:\nDescripcion: Esta instruccion ayuda a crear los objetos\n9.-create.Object:\nDescripcion: Esta instruccion ayuda a crear los newObjects\n10.-create.scene.openCreatorEditCMD:\nDescripcion: Esta instruccion abre el editador de scenes", "charDeveloping: Commands", MB_ICONINFORMATION);

            return TRUE;

        /*Casos para colocar las funciones en el edit*/
        case CM_MOVE_CPNG:

            marcarPalabrasPonerCodigo(hEdit, "moveObjectCPNG(struct cpng *posPlayer, const char *key1, const char *key2, const char *key3, const char *key4);");

            return TRUE;
        case CM_MOVE_OBJECT:

            marcarPalabrasPonerCodigo(hEdit, "moveObject(obj, '@', A, D, S, W);");

            return TRUE;
        case CM_MOVE:

            marcarPalabrasPonerCodigo(hEdit, "move_char (X , Y , String player , String key1 , String key2 , String key3 , String key4);");

            return TRUE;
        case CM_HIDDEN_CURSOR:

            marcarPalabrasPonerCodigo(hEdit, "hiddenCursor (true);");

            return TRUE;
        case CM_SET_TITLE:

            marcarPalabrasPonerCodigo(hEdit, "setTile(\"Name window cmd\");");

            return TRUE;
        case CM_SET_XY:
            marcarPalabrasPonerCodigo(hEdit, "set_xy(0,0);");

            return TRUE;
        case CM_CENTER_TEXT:

            marcarPalabrasPonerCodigo(hEdit, "centerText(\"Text\");");

            return TRUE;
        case CM_COLOR_RGBA:

            marcarPalabrasPonerCodigo(hEdit, "colorRGBA(0,0,0,0);");

            return TRUE;
        case CM_DELETE_FILE:

            marcarPalabrasPonerCodigo(hEdit, "delete_file(\"File name\");");

            return TRUE;
        case CM_LIMIT_OBJECT:

            marcarPalabrasPonerCodigo(hEdit, "limitObject (limitObject , limitX1 , limitX2, limitY1 , limitY2);");

            return TRUE;
        case CM_DEBUG_COLLISION:

            marcarPalabrasPonerCodigo(hEdit, "debugCollision();");

            return TRUE;
        case CM_MOVE_CPNG_MOUSE:

            marcarPalabrasPonerCodigo(hEdit, "move_cpng_mouse();");

            return TRUE;
        case CM_BUCLE_FOR:

            marcarPalabrasPonerCodigo(hEdit, "for(i = 0; i < 0; i++){\n    //Code\n}");

            return TRUE;
        case CM_CREAR_OBJECT:

            marcarPalabrasPonerCodigo(hEdit, "hiddenCursor (true);");

            return TRUE;

        case BTN_EJECUTAR:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            MessageBox(hwndDlg, "Actualmente no tenemos soporte para compilar en gcc se implementara a su debido tiempo.\nPuedes instalar  el compilador gcc con esta url: https://gcc.gnu.org/'", "Aviso", MB_ICONINFORMATION);
            char comando[100];
            sprintf(comando, "cd c:\mingw\bin\gcc.exe -o %s.exe %s.c", user1, user1);
            system(comando);
            char ejecutable[100];
            sprintf(ejecutable, "%s.exe", user1);
            // Captura de errores del GCC
            fp = popen(comando, "r");
            if (!fp)
            {
                MessageBox(hwndDlg, "Error al ejecutar GCC", "CharDeveloping : Error", MB_ICONERROR);
                return TRUE;
            }
            char error[512];
            while (fgets(error, sizeof(error), fp) != NULL)
            {
                MessageBox(hwndDlg, error, "CharDeveloping : GCC error", MB_ICONERROR);
            }
            pclose(fp);
            // Ejecución del archivo ejecutable
            //system(ejecutable);
            //system("dir");

            return TRUE;

            //caso para abrir el archivo
        case CM_ABRE_ARCHIVO:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            leerArchivo(hEdit, user1);

            return TRUE;

        case CM_EXAMPLE1:

            leerArchivo(hEdit, "gravity.c");

            return TRUE;

        case CM_EXAMPLE2:

            leerArchivo(hEdit, "ejemplo_wave.c");

            return TRUE;

        case CM_EXAMPLE3:

            leerArchivo(hEdit, "ejemplo_collision.c");

            return TRUE;
        case CM_NOTES:

            MessageBox(hwndDlg, "Esta update trae:\n1.-Menu de codigo para ayuda\n2.-Prototipo para poder compilar archivos con GCC\n3.-Guardar archivos y leerlos de mejor modo", "Noticia de actualización: v6", MB_ICONINFORMATION);

            return TRUE;
            //caso nulo
        case CM_ARCHIVOS:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT2, user2, 100);

            return TRUE;
            //caso para crear proyectos
        case CM_START_PROJECTS:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            check = mkdir(user1);

            // check if directory is created or not
            if (!check)
            {
                MessageBox(hwndDlg, "Carpeta del proyecto creada con exito", "Creacion de proyecto", MB_ICONINFORMATION);
                printf("Directory the project created\n");
            }
            else
            {
                MessageBox(hwndDlg, "Error al crear el proyecto:\n*No se pudo crear el directorio: \"Unable to create directory\"\n*Mal escrito el nombre de la carpeta", "Creacion de proyecto", MB_ICONERROR);
                printf("Unable to create directory\n");
            }
            Project_active = 1;
            project_active[500] = user1[500];
            user1_cat = "main.c";
            strcpy(user1_copy, user1);
            strcat(user1_copy, user1_cat);
            sFile(user1_copy, "#include \"include\\stringgame.h\"");
            sFile(user1_copy, "");
            sFile(user1_copy, "void paint_game (struct _scenes_ * Scene);");
            sFile(user1_copy, "");
            sFile(user1_copy, "int main (void){");
            sFile(user1_copy, "");
            sFile(user1_copy, "     //Struct of main scene");
            sFile(user1_copy, "     struct _scenes_ mainScene;");
            sFile(user1_copy, "");
            sFile(user1_copy, "     strcpy(mainScene.name,\"mainScene\");");
            sFile(user1_copy, "     mainScene.id = 0;");
            sFile(user1_copy, "     mainScene.actives = 1;//never 0");
            sFile(user1_copy, "");
            sFile(user1_copy, "     while(true){");
            sFile(user1_copy, "");
            sFile(user1_copy, "          paint_game(&mainScene);");
            sFile(user1_copy, "");
            sFile(user1_copy, "  }");
            sFile(user1_copy, "}");
            sFile(user1_copy, "");
            sFile(user1_copy, "void paint_game (struct _scenes_ * Scene){");
            sFile(user1_copy, "");
            sFile(user1_copy, "     StrLoad_scene_(Scene);");
            sFile(user1_copy, "");
            sFile(user1_copy, "}");
            sFile(user1_copy, "");
            user1_cat = "mainScene.sce";
            strcpy(user1_copy, user1);
            strcat(user1_copy, user1_cat);
            sFile(user1_copy, "Void Scene");
            MessageBox(hwndDlg, "Se ha creado el proyecto ", "Inicio de nuevo proyecto", MB_ICONINFORMATION);
            printf("Rute: %s\n", project_active);

            return TRUE;
        case IDC_BTN_CREAR_STRUCT:

            GetDlgItemText(hwndDlg, IDC_STRUCTS, user1, 100);
            sFile2(registros, "Registers: charDeveloping.create.new.function.this.");
            sFile2(registros, user1);
            sFile(registros, "Registers: create");
            sFile2("functions_creator.trash", "void ");
            sFile2("functions_creator.trash", user1);
            sFile("functions_creator.trash", " (void){");
            sFile("functions_creator.trash", "    printf(\"\");");
            sFile2("functions_creator.trash", "}");
            sFile2("functions_creator.txt", "void ");
            sFile2("functions_creator.txt", user1);
            sFile("functions_creator.txt", " (void){");
            sFile("functions_creator.txt", "    printf(\"\");");
            sFile2("functions_creator.txt", "}");

            return TRUE;

        case CM_CREADOR_PROJECTS:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, MainFile, 100);

            createMainCode(MainFile);

            MessageBox(hwndDlg, "Se ha generado un codigo ", "CharDeveloping : create file *c", MB_ICONINFORMATION);

            return TRUE;
            //caso para el creador de cpng's
        case CM_CREADOR_CPNG:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT2, user2, 100);

            createCpng(cpngFile,user1,user2);
            MessageBox(hwndDlg, "Se ha guardado el cpng en el archivo 'cpng.h", "Stringame : save cpng", MB_ICONINFORMATION);

            return TRUE;
            //case para el creador de scenes
        case CM_CREADOR_SCENE:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);

            sFile2("scenes.h", "void scene_");
            sFile2("scenes.h", user1);
            sFile("scenes.h", " (struct _scenes_ * Scenes){");
            sFile("scenes.h", "");
            sFile("scenes.h", "    StrLoad_scene_(Scenes);");
            sFile("scenes.h", "");
            sFile("scenes.h", "}");

            MessageBox(hwndDlg, "Se ha creado la funcion", "Escrity : functions", MB_ICONINFORMATION);

            return TRUE;

        case CM_CREADOR_NEWOBJECT:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            
            createNewObject(structs,user1);

            return TRUE;

        case CM_CREADOR_CPNGS:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            MessageBox(hwndDlg, "Se ha cargado el editador", "Escrity : load edit", MB_ICONINFORMATION);
            cpngs(user1);

            return TRUE;

        case CM_CREADOR_OBJECT:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            if (strcasecmp(user1, pplayer) == 0)
            {
                createObject(structs,user1,user2);
                MessageBox(hwndDlg, "", "", MB_ICONINFORMATION);
            }

            createObject(structs,user1,user2);

            MessageBox(hwndDlg, "Se han escrito el object en el archivo 'objects.h", "Stringame : save object", MB_ICONINFORMATION);

            return TRUE;

        case CM_USE_TEXTURE:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT2, user2, 100);

            sFile(registros, user1);
            sFile2("main.c", "        //print or paint texture ");
            sFile2("main.c", user2);
            sFile2("main.c", "        Coordinates ");
            sFile("main.c", user1);
            sFile2("main.c", "        StrGotoXY(");
            sFile2("main.c", user1);
            sFile("main.c", ");");
            sFile2("main.c", "        texture_");
            sFile2("main.c", user2);
            sFile("main.c", "();");

            MessageBox(hwndDlg, "Se ha escrito la texture", "Stringame : add texture", MB_ICONINFORMATION);

            return TRUE;

        case CM_CREADOR_TEXTURE:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT2, user2, 100);
            
            if (strcmp(user1, pplayer) == 0)
            {
                createTextures(user1,user2);
                MessageBox(hwndDlg, "Se ha guardado la texture en el archivo 'textures.h", "Stringame : save texture", MB_ICONINFORMATION);
            }

            createTextures(user1,user2);
            MessageBox(hwndDlg, "Se ha guardado la texture en el archivo 'textures.h", "Stringame : save texture", MB_ICONINFORMATION);

            return TRUE;

        case CM_NEW_FUCTIONS:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user2, 100);
            sFile2(user2, user1);
            sFile(user2, "{");
            sFile(user2, "    ");
            sFile(user2, "}");

            return TRUE;

        case CM_NAME_PROJECT:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            return TRUE;

        case CM_SALIR:

            EndDialog(hwndDlg, 0);
            return TRUE;

        case CM_CREADOR_ASSET:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT2, user2, 100);
            
            CreateAssets(registros, user1, user2);

            MessageBox(hwndDlg, "Se ha guardado el asset en el archivo 'Assets.h", "Stringgame : save asset", MB_ICONINFORMATION);

            return TRUE;
        case IDC_BTN_QUIT:

            EndDialog(hwndDlg, 0);
            return TRUE;

        case CM_NEW_PROJECT:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT2, user2, 100);
            MessageBox(hwndDlg, "*Antes cree la carpeta donde se almacenara el projecto", "Aviso de ruta", MB_ICONINFORMATION);
            newProject(user1, hwndDlg, user2);

            return TRUE;

        case IDC_BTN_TEST:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            if(strcmp(user1,ruteGCC) == 0){

                GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user2, 100);
                MessageBox(hwndDlg,"Se ha guardado la ruta del gcc","charDeveloping : rute gcc", MB_ICONINFORMATION);

            }

            if (strcmp(user1, loadScene) == 0)
            {
                GetDlgItemText(hwndDlg, IDC_EDIT_INPUT2, user2, 100);
                CLS();
                file_scene_(user2);
            }

            if (strcmp(user1, scenesCreator) == 0)
            {
                GetDlgItemText(hwndDlg, IDC_EDIT_INPUT2, user2, 100);
                CLS();
                StrCreate_scene_(user2);
            }

            if (strcmp(user1, view) == 0)
            {
                GetDlgItemText(hwndDlg, IDC_EDIT_INPUT2, user2, 100);
                StrGotoXY(33, 10);
                yReadFile("textures.dat");
                sFile2("textures.h", "//This coordinates ");
                sFile("textures.h", user2);
                if (remove("textures.dat") == -1)
                {
                    Sleep(1500);
                    EndDialog(hwndDlg, 0);
                }
            }

            if (strcmp(user1, bye) == 0)
            {
                EndDialog(hwndDlg, 0);
            }

            if (strcmp(user1, screen) == 0)
            {
                CLS();
            }
            if (strcmp(user1, crearTexture) == 0)
            {
                printf("Name Texture ");
                scanf("%s", &user1);
                printf("Data Texture: ");
                scanf("%s", &user2);
                createTextures(user1,user2);
            }

            if (strcmp(user1, crearFunction) == 0)
            {
                printf("Name function: ");
                scanf("%s", &user1);
                printf("Data function: ");
                scanf("%s", &user2);
                sFile2(user2, user1);
                sFile(user2, "{");
                sFile(user2, "    ");
                sFile(user2, "}");
            }

            if (strcmp(user1, crearObject) == 0)
            {
                printf("Name object: ");
                scanf("%s", &user1);
                GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
                createObject(structs, user1, "nada");
            }

            if (strcmp(user1, crearNewObject) == 0)
            {
                printf("Name new object: ");
                scanf("%s", &user1);
                createNewObject(structs, user1);
            }

            if (strcmp(user1, crearNewScene) == 0)
            {
                printf("Name Scene: ");
                scanf("%s", &user1);
                sFile2(registros, "Registers: charDeveloping: this-*>createAFileCPNGStrucCPNG+this.load.charDeveloping.Escrity.Commands");
                sFile(registros, user1);
                sFile2("scenes.h", "void scene_");
                sFile2("scenes.h", user1);
                sFile("scenes.h", " (struct _scenes_ * Scenes){");
                sFile("scenes.h", "");
                sFile("scenes.h", "    StrLoad_scene_(Scenes);");
                sFile("scenes.h", "");
                sFile("scenes.h", "}");
            }

            if (strcmp(user1, crearEditorCPNG) == 0)
            {
                printf("Name Cpng: ");
                scanf("%s", &user1);
                cpngs(user1);
            }

            if (strcmp(user1, crearCPNG) == 0)
            {
                printf("Name Cpng: ");
                scanf("%s", &user1);
                printf("Data Cpng: ");
                scanf("%s", &user2);
                createCpng(cpngFile,user1,user2);
            }

            return TRUE;
        }
    }

    return FALSE;
}

void InsertarMenu(HWND hWnd)
{
    HMENU hMenu1, hMenu2, hMenu3, hMenu4, hMenu5, hMenu6;
    hMenu1 = CreateMenu();
    hMenu2 = CreateMenu();
    hMenu3 = CreateMenu();
    hMenu4 = CreateMenu();
    hMenu5 = CreateMenu();
    hMenu6 = CreateMenu();
    /* Manipulador para el primer menú pop-up */
    AppendMenu(hMenu2, MF_STRING, CM_PRUEBA, "&Eliminar archivo");
    AppendMenu(hMenu2, MF_STRING, CM_BTN_GUARDAR, "&Guardar archivo");
    AppendMenu(hMenu2, MF_STRING, CM_ARCHIVOS, "&Crear archivo");
    AppendMenu(hMenu2, MF_STRING, CM_ABRE_ARCHIVO, "&Abrir archivo");
    AppendMenu(hMenu2, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu2, MF_STRING, CM_SALIR, "&Salir");
    AppendMenu(hMenu2, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu2, MF_STRING, CM_NAME_PROJECT, "&Nombre del projecto");
    AppendMenu(hMenu3, MF_STRING, CM_CREADOR_TEXTURE, "&Crear Archivo Texture");
    AppendMenu(hMenu3, MF_STRING, CM_CREADOR_CPNG, "&Crear Archivo Cpng");
    AppendMenu(hMenu3, MF_STRING, CM_CREADOR_ASSET, "&Crear Archivo Asset");
    AppendMenu(hMenu3, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu3, MF_STRING, CM_CREADOR_OBJECT, "&Crear Archivo objects");
    AppendMenu(hMenu3, MF_STRING, CM_CREADOR_NEWOBJECT, "&Crear Archivo newObject");
    AppendMenu(hMenu3, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu3, MF_STRING, CM_CREADOR_CPNGS, "&Crear CPNG file type");
    AppendMenu(hMenu3, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu3, MF_STRING, CM_CREADOR_SCENE, "&Crear Scene");
    AppendMenu(hMenu3, MF_STRING, CM_CREADOR_SCENE_PRO, "&Crear Scene (v1)");
    AppendMenu(hMenu3, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu3, MF_STRING, CM_EXAMPLE1, "&Abrir ejemplo gravity");
    AppendMenu(hMenu3, MF_STRING, CM_EXAMPLE2, "&Abrir ejemplo wave");
    AppendMenu(hMenu3, MF_STRING, CM_EXAMPLE3, "&Abrir ejemplo collisión");
    AppendMenu(hMenu3, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu3, MF_STRING, CM_ABRE_CPNG, "&Abrir CPNG");
    AppendMenu(hMenu4, MF_STRING, CM_VIEW_COMMANDS, "&Ver commands");
    AppendMenu(hMenu4, MF_STRING, CM_NOTES, "&Update notes");
    AppendMenu(hMenu5, MF_STRING, CM_START_PROJECTS, "&Iniciar nuevo projecto");
    AppendMenu(hMenu5, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu5, MF_STRING, CM_NEW_PROJECT, "&Nuevo projecto");
    AppendMenu(hMenu6, MF_STRING, 0, "&Funciones");
    AppendMenu(hMenu6, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu6, MF_STRING, CM_HIDDEN_CURSOR, "&Agregar funcion 'hiddenCursor();'");
    AppendMenu(hMenu6, MF_STRING, CM_SET_TITLE, "&Agregar funcion 'setTitle();'");
    AppendMenu(hMenu6, MF_STRING, CM_SET_XY, "&Agregar funcion 'set_xy();'");
    AppendMenu(hMenu6, MF_STRING, CM_CENTER_TEXT, "&Agregar funcion 'center_text();'");
    AppendMenu(hMenu6, MF_STRING, CM_DELETE_FILE, "&Agregar funcion 'delete_file();'");
    AppendMenu(hMenu6, MF_STRING, CM_DEBUG_COLLISION, "&Agregar funcion 'debugCollision();'");
    AppendMenu(hMenu6, MF_STRING, CM_COLOR_RGBA, "&Agregar funcion 'colorRGBA();'");
    AppendMenu(hMenu6, MF_STRING, CM_LIMIT_OBJECT, "&Agregar funcion 'limitObject();'");
    AppendMenu(hMenu6, MF_STRING, CM_MOVE_CPNG_MOUSE, "&Agregar funcion 'move_cpng_mouse();'");
    AppendMenu(hMenu6, MF_STRING, CM_MOVE_CPNG, "&Agregar funcion 'move_cpng();'");
    AppendMenu(hMenu6, MF_STRING, CM_MOVE_OBJECT, "&Agregar funcion 'move_object();'");
    AppendMenu(hMenu6, MF_STRING, CM_MOVE, "&Agregar funcion 'move_char();'");
    AppendMenu(hMenu6, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu6, MF_STRING, 0, "&Code");
    AppendMenu(hMenu6, MF_STRING, 0, NULL);
    AppendMenu(hMenu6, MF_STRING, CM_BUCLE_FOR, "&Agregar codigo: 'bucle for'");
    AppendMenu(hMenu6, MF_STRING, CM_CREAR_OBJECT, "&Agregar codigo: 'crear Object'");
    /* Inserción del menú pop-up */
    AppendMenu(hMenu1, MF_STRING | MF_POPUP, (UINT)hMenu2, "&Archivos");
    AppendMenu(hMenu1, MF_STRING | MF_POPUP, (UINT)hMenu3, "&CharLibrary");
    AppendMenu(hMenu1, MF_STRING | MF_POPUP, (UINT)hMenu6, "&Funciones");
    AppendMenu(hMenu1, MF_STRING | MF_POPUP, (UINT)hMenu4, "&CharDeveloping");
    AppendMenu(hMenu1, MF_STRING | MF_POPUP, (UINT)hMenu5, "&Proyecto");
    SetMenu(hWnd, hMenu1); /* Asigna el menú a la ventana hWnd */
}

void Guardar(HWND hctrl, char *fichero)
{
    FILE *fs;
    int nLineas, longitud, i;
    char linea[1024];

    fs = fopen(fichero, "w");
    if (fs)
    {
        nLineas = SendMessage(hctrl, EM_GETLINECOUNT, 0, 0);
        for (i = 0; i < nLineas; i++)
        {
            *(WORD *)linea = 1024;
            longitud = SendMessage(hctrl, EM_GETLINE, (WPARAM)i, (LPARAM)linea);
            linea[longitud] = 0;
            fprintf(fs, "%s\n", linea);
        }
        fclose(fs);
    }
}

BOOL leerArchivo(HWND hEdit, LPCTSTR lpFileName)
{
    // Abre el archivo y obtiene su tamaño en bytes
    HANDLE hFile = CreateFile(lpFileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile != INVALID_HANDLE_VALUE)
    {
        DWORD dwSize = GetFileSize(hFile, NULL);
        if (dwSize != INVALID_FILE_SIZE)
        {
            // Reserva memoria para almacenar el contenido del archivo
            LPVOID lpBuffer = malloc(dwSize + sizeof(TCHAR));
            if (lpBuffer)
            {
                // Lee el contenido del archivo en la memoria reservada
                DWORD dwRead;
                ReadFile(hFile, lpBuffer, dwSize, &dwRead, NULL);
                if (dwRead == dwSize)
                {
                    // Agrega un caracter n
                    // Establece el contenido del control de edición de texto con el contenido del archivo
                    SetWindowText(hEdit, (TCHAR *)lpBuffer);
                }
                free(lpBuffer);
            }
        }
        CloseHandle(hFile);
        return TRUE;
    }
    return FALSE;
}

void marcarPalabrasPonerCodigo(HWND hEdit, TCHAR *Text)
{
    int nCursorPos = (int)SendMessage(hEdit, EM_GETSEL, 0, 0);
    SendMessage(hEdit, EM_SETSEL, nCursorPos, nCursorPos);
    SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)Text);
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst = hInstance;
    // The user interface is a modal dialog box
    return DialogBox(hInstance, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DialogProc);
}
