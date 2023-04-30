/*
Codigo del programa chardevelopig
*/
#define WIN32_LEAN_AND_MEAN

#include <windows.h>

#include <unistd.h>
#include <commctrl.h>
#include <conio.h>
#include <tchar.h>
#include <sys/types.h>
#include <sys/stat.h>
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
void SaveFile(HWND hwndParent);
void deleteFiles(HWND hwndParent);
void nuevoProyecto(HWND hwndParent);
void CrearCPNG(HWND hwndParent);
void CrearTexture(HWND hwndParent);
void CrearScene(HWND hwndParent);
void abreArchivo(HWND hwndParent);
INT_PTR CALLBACK SaveFileDlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK deleteFileDlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK nuevoProyectoDlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK crearCpngDlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK crearTextureDlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK crearSceneDlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK abreArchivoDlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

HINSTANCE hInst;
HWND hEdit, hEdit2;
int hotkey_id;
String fileName = "sinTitulo.c";
String DeleteFiles = "sinTitulo.rb";
String nombreProyecto = "sinNombre", ubicacionProyecto = "game";
String creadorCpng = "null";
String abre;

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
            1,
            20,
            488,
            250,
            hwndDlg,
            (HMENU)ID_TEXTO,
            GetModuleHandle(NULL),
            NULL);

        return TRUE;

        /*case WM_PAINT:
        hdc = BeginPaint(hwndDlg, &ps);
        TextOut(hdc, 10, 10, fileName, 11);
        EndPaint(hwndDlg, &ps);
        break;*/

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
        case CM_PRUEBA:
            deleteFiles(hwndDlg);
            if (remove(DeleteFiles) == -1)
            {
                SetTitle("CharDeveloping : cmd : error");
                MessageBox(hwndDlg, "El Archivo no se pudo eliminar. . .", "CharDeveloping : Error", MB_ICONERROR);
                SetTitle("CharDeveloping : cmd");
            }
            else
            {
                MessageBox(hwndDlg, "Archivo Eliminado con exito", "CharDeveloping : Exito", MB_ICONINFORMATION);
            }
            return TRUE;
        case CM_CREAR_TEXTURE:
            CrearTexture(hwndDlg);
            user1_cat = ".tex";
            strcpy(user1_copy, creadorCpng);
            strcat(user1_copy, user1_cat);
            Guardar(hEdit2, user1_copy);
            return 0;
        case CM_CREAR_SCENE:
            CrearScene(hwndDlg);
            user1_cat = ".sce";
            strcpy(user1_copy, creadorCpng);
            strcat(user1_copy, user1_cat);
            Guardar(hEdit2, user1_copy);
            return 0;
            //Caso para el boton guardar
        case CM_BTN_GUARDAR:
            SaveFile(hwndDlg);
            Guardar(hEdit, fileName);
            MessageBox(hwndDlg, "Se ha guardado el archivo con exito.", "charDeveliping : Exito", MB_ICONINFORMATION);
            return TRUE;
        /*Casos para colocar las funciones en el edit*/
        case CM_MOVE_CPNG:
            marcarPalabrasPonerCodigo(hEdit, "move_cpng(&posPlayer, KEY_A, KEY_D, KEY_S, KEY_W);");
            return TRUE;
        case CM_HIDDEN_CURSOR:
            marcarPalabrasPonerCodigo(hEdit, "hiddenCursor(false);//true is hidden");
            return TRUE;
        case CM_SET_TITLE:
            marcarPalabrasPonerCodigo(hEdit, "set_tile(\"\");");
            return TRUE;
        case CM_SET_XY:
            marcarPalabrasPonerCodigo(hEdit, "set_xy(0,0);");
            return TRUE;
        case CM_CENTER_TEXT:
            marcarPalabrasPonerCodigo(hEdit, "center_text(\"\");");
            return TRUE;
        case CM_COLOR_RGBA:
            marcarPalabrasPonerCodigo(hEdit, "color_RGBA(1,1,1,0);");
            return TRUE;
        case CM_MOVE_CPNG_MOUSE:
            marcarPalabrasPonerCodigo(hEdit, "move_cpng_mouse(&CPNG , cursor);");
            return TRUE;
        case CM_BUCLE_FOR:
            marcarPalabrasPonerCodigo(hEdit, "for(i = 0; i < 0; i++){\n    //Code\n}");
            return TRUE;
        case BTN_EJECUTAR:
            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            MessageBox(hwndDlg, "Actualmente no tenemos soporte para compilar en gcc se implementara a su debido tiempo.\nPuedes instalar  el compilador gcc con esta url: https://gcc.gnu.org/'", "Aviso", MB_ICONINFORMATION);
            char comando[100];
            sprintf(comando, "cd c:\mingw\bin\gcc.exe -o %s.exe %s.c", user1, user1);
            system(comando);
            char ejecutable[100];
            sprintf(ejecutable, "%s.exe", user1);
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
            return TRUE;
            //caso para abrir el archivo
        case CM_ABRE_ARCHIVO:
            abreArchivo(hwndDlg);
            leerArchivo(hEdit, abre);
            return TRUE;
        case CM_NOTES:
            MessageBox(hwndDlg, "Cambios:\n-Se cambio la ventana principal para mejor comodidad\n-Se agrego la opcion de crear proyectos(parte 1)\n-Ventanas para crear cpngs,textures y scenes", "Cambios de actualizacion: v6.5.1", MB_ICONINFORMATION);
            return TRUE;
        case CM_CREAR_CPNG:
            CrearCPNG(hwndDlg);
            user1_cat = ".cpng";
            strcpy(user1_copy, creadorCpng);
            strcat(user1_copy, user1_cat);
            Guardar(hEdit2, user1_copy);
            return TRUE;
        case CM_START_PROJECTS:
            nuevoProyecto(hwndDlg);
            check = mkdir(ubicacionProyecto);
            if (!check)
            {
                user1_cat = "main.c";
                strcpy(user1_copy, ubicacionProyecto);
                strcat(user1_copy, user1_cat);
                sFile(user1_copy, "#include \"include\\chardeveloping.h\"");
                sFile(user1_copy, "");
                sFile(user1_copy, "int main (void){");
                sFile(user1_copy, "");
                sFile(user1_copy, "    struct cpng player;");
                sFile(user1_copy, "    player.id = 1;");
                sFile(user1_copy, "    player.postition_X = 0;");
                sFile(user1_copy, "    player.postition_Y = 20;");
                sFile(user1_copy, "    strcpy(player.name_cpng,\"player\");");
                sFile(user1_copy, "");
                sFile2(user1_copy, "    set_title(\"");
                sFile2(user1_copy, nombreProyecto);
                sFile(user1_copy, "\");");
                sFile(user1_copy, "    hiddenCursor(true);");
                sFile(user1_copy, "    while(true){");
                sFile(user1_copy, "         ");
                sFile(user1_copy, "         str_cls();");
                sFile(user1_copy, "         show_coordinates_cpng(&player);");
                sFile(user1_copy, "         move_cpng(&player, KEY_A, KEY_D, KEY_S, KEY_W);");
                sFile(user1_copy, "         ");
                sFile(user1_copy, "    }");
                sFile(user1_copy, "");
                sFile(user1_copy, "    return 0;");
                sFile(user1_copy, "}");
                sFile(user1_copy, "");
                user1_cat = "include";
                strcpy(user1_copy, ubicacionProyecto);
                strcat(user1_copy, user1_cat);
                mkdir(user1_copy);
                user1_cat = "assets";
                strcpy(user1_copy, ubicacionProyecto);
                strcat(user1_copy, user1_cat);
                mkdir(user1_copy);
                user1_cat = "charproyect.cp";
                strcpy(user1_copy, ubicacionProyecto);
                strcat(user1_copy, user1_cat);
                mkdir(user1_copy);
                sFile2(user1_copy, "Nombre de proyecto: ");
                sFile(user1_copy, nombreProyecto);
                sFile2(user1_copy, "library: ");
                sFile(user1_copy, "chardeveloping.h");
                sFile2(user1_copy, "charDeveloping version: ");
                s File(user1_copy, "v6.5");
                MessageBox(hwndDlg, "Proyecto creado con exito", "Creacion de proyecto", MB_ICONINFORMATION);
            }
            else
            {
                MessageBox(hwndDlg, "Error al crear el proyecto:\n*No se pudo crear el directorio: \"Unable to create directory\"\n*Mal escrito el nombre de la carpeta", "Creacion de proyecto", MB_ICONERROR);
            }

            return TRUE;

        case CM_SALIR:

            EndDialog(hwndDlg, 0);
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
            if (strcmp(user1, ruteGCC) == 0)
            {
                GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user2, 100);
                MessageBox(hwndDlg, "Se ha guardado la ruta del gcc", "charDeveloping : rute gcc", MB_ICONINFORMATION);
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
                createTextures(user1, user2);
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
                createCpng(cpngFile, user1, user2);
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
    AppendMenu(hMenu2, MF_STRING, CM_ABRE_ARCHIVO, "&Abrir archivo");
    AppendMenu(hMenu2, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu2, MF_STRING, CM_SALIR, "&Salir");
    AppendMenu(hMenu2, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu2, MF_STRING, CM_NAME_PROJECT, "&Nombre del projecto");
    AppendMenu(hMenu3, MF_STRING, CM_CREADOR_TEXTURE, "&Crear Archivo Texture");
    AppendMenu(hMenu3, MF_STRING, CM_CREADOR_CPNG, "&Crear Archivo Cpng");
    AppendMenu(hMenu3, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu3, MF_STRING, CM_CREADOR_CPNGS, "&Crear CPNG file type");
    AppendMenu(hMenu3, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu3, MF_STRING, CM_CREAR_CPNG, "&Crear cpng");
    AppendMenu(hMenu3, MF_STRING, CM_CREAR_SCENE, "&Crear scene");
    AppendMenu(hMenu3, MF_STRING, CM_CREAR_TEXTURE, "&Crear texture");
    AppendMenu(hMenu3, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu3, MF_STRING, CM_CREAR_IMG, "&Crear imagen(nada)");
    AppendMenu(hMenu4, MF_STRING, CM_NOTES, "&Update");
    AppendMenu(hMenu5, MF_STRING, CM_START_PROJECTS, "&Iniciar nuevo projecto");
    AppendMenu(hMenu5, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu5, MF_STRING, CM_NEW_PROJECT, "&Nuevo projecto");
    AppendMenu(hMenu6, MF_STRING, 0, "&Funciones");
    AppendMenu(hMenu6, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu6, MF_STRING, CM_HIDDEN_CURSOR, "&Agregar funcion 'hiddenCursor();'");
    AppendMenu(hMenu6, MF_STRING, CM_SET_TITLE, "&Agregar funcion 'set_title();'");
    AppendMenu(hMenu6, MF_STRING, CM_SET_XY, "&Agregar funcion 'set_xy();'");
    AppendMenu(hMenu6, MF_STRING, CM_CENTER_TEXT, "&Agregar funcion 'center_text();'");
    AppendMenu(hMenu6, MF_STRING, CM_COLOR_RGBA, "&Agregar funcion 'color_RGBA();'");
    AppendMenu(hMenu6, MF_STRING, CM_MOVE_CPNG_MOUSE, "&Agregar funcion 'move_cpng_mouse();'");
    AppendMenu(hMenu6, MF_STRING, CM_MOVE_CPNG, "&Agregar funcion 'move_cpng();'");
    AppendMenu(hMenu6, MF_STRING, CM_BUCLE_FOR, "&Agregar 'bucle for'");
    /* Inserción del menú pop-up */
    AppendMenu(hMenu1, MF_STRING | MF_POPUP, (UINT)hMenu2, "&Archivos");
    AppendMenu(hMenu1, MF_STRING | MF_POPUP, (UINT)hMenu3, "&CharLibrary");
    AppendMenu(hMenu1, MF_STRING | MF_POPUP, (UINT)hMenu6, "&Funciones");
    AppendMenu(hMenu1, MF_STRING | MF_POPUP, (UINT)hMenu4, "&CharDeveloping");
    AppendMenu(hMenu1, MF_STRING | MF_POPUP, (UINT)hMenu5, "&Proyecto");
    SetMenu(hWnd, hMenu1); /* Asigna el menú a la ventana hWnd */
}
// Procedimiento de diálogo de la ventana para guardar archivos
INT_PTR CALLBACK SaveFileDlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        return TRUE;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            GetDlgItemText(hwndDlg, IDC_NAME_FILE, fileName, 100);
            EndDialog(hwndDlg, wParam);
            return TRUE;
        case IDCANCEL:
            EndDialog(hwndDlg, wParam);
            return TRUE;
        }
        break;
    }

    return FALSE;
}

INT_PTR CALLBACK deleteFileDlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        return TRUE;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            GetDlgItemText(hwndDlg, IDC_DELETE_FILE, DeleteFiles, 100);
            EndDialog(hwndDlg, wParam);
            return TRUE;
        case IDCANCEL:
            EndDialog(hwndDlg, wParam);
            return TRUE;
        }
        break;
    }

    return FALSE;
}

INT_PTR CALLBACK nuevoProyectoDlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        return TRUE;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            GetDlgItemText(hwndDlg, IDC_NOMBRE_PROYECTO, nombreProyecto, 100);
            GetDlgItemText(hwndDlg, IDC_UBICACION_PROYECTO, ubicacionProyecto, 100);
            EndDialog(hwndDlg, wParam);
            return TRUE;
        case IDCANCEL:
            EndDialog(hwndDlg, wParam);
            return TRUE;
        }
        break;
    }

    return FALSE;
}

INT_PTR CALLBACK crearCpngDlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        hEdit2 = CreateWindowEx(
            WS_EX_CLIENTEDGE,
            _T("EDIT"),
            _T(""),
            WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_WANTRETURN,
            1,
            50,
            488,
            250,
            hwndDlg,
            (HMENU)ID_TEXTO2,
            GetModuleHandle(NULL),
            NULL);
        return TRUE;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            GetDlgItemText(hwndDlg, IDC_CREA_CPNG, creadorCpng, 200);
            EndDialog(hwndDlg, wParam);
            return TRUE;
        case IDC_BTNG_GUARDAR_CPNG:
            Guardar(hEdit2, creadorCpng);
            return TRUE;
        case IDCANCEL:

            EndDialog(hwndDlg, wParam);
            return TRUE;
        }
        break;
    }

    return FALSE;
}
INT_PTR CALLBACK crearTextureDlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        hEdit2 = CreateWindowEx(
            WS_EX_CLIENTEDGE,
            _T("EDIT"),
            _T(""),
            WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_WANTRETURN,
            1,
            50,
            488,
            250,
            hwndDlg,
            (HMENU)ID_TEXTO2,
            GetModuleHandle(NULL),
            NULL);
        return TRUE;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            GetDlgItemText(hwndDlg, IDC_CREA_SCENE, creadorCpng, 200);
            EndDialog(hwndDlg, wParam);
            return TRUE;
        case IDC_BTNG_GUARDAR_TEXTURE:
            Guardar(hEdit2, creadorCpng);
            return TRUE;
        case IDCANCEL:
            EndDialog(hwndDlg, wParam);
            return TRUE;
        }
        break;
    }
    return FALSE;
}
INT_PTR CALLBACK crearSceneDlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        hEdit2 = CreateWindowEx(
            WS_EX_CLIENTEDGE,
            _T("EDIT"),
            _T(""),
            WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_WANTRETURN,
            1,
            50,
            488,
            250,
            hwndDlg,
            (HMENU)ID_TEXTO2,
            GetModuleHandle(NULL),
            NULL);
        return TRUE;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            GetDlgItemText(hwndDlg, IDC_CREA_SCENE, creadorCpng, 200);
            EndDialog(hwndDlg, wParam);
            return TRUE;
        case IDC_BTNG_GUARDAR_SCENE:
            Guardar(hEdit2, creadorCpng);
            return TRUE;
        case IDCANCEL:
            EndDialog(hwndDlg, wParam);
            return TRUE;
        }
        break;
    }
    return FALSE;
}
INT_PTR CALLBACK abreArchivoDlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        return TRUE;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            GetDlgItemText(hwndDlg, IDC_ABRE_ARCHIVO, abre, 100);
            EndDialog(hwndDlg, wParam);
            return TRUE;
        case IDCANCEL:
            EndDialog(hwndDlg, wParam);
            return TRUE;
        }
        break;
    }

    return FALSE;
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

// Función que muestra la ventana de guardar archivo
void SaveFile(HWND hwndParent)
{
    DialogBoxParam(hInst, MAKEINTRESOURCE(ID_NUEVO_ARCHIVO), hwndParent, SaveFileDlgProc, 0);
}
//Funcion que muestra la ventana de eliminar archivo
void deleteFiles(HWND hwndParent)
{
    DialogBoxParam(hInst, MAKEINTRESOURCE(DLG_DELETE_FILE), hwndParent, deleteFileDlgProc, 0);
}
//Funcion que muestra la ventana de crear proyecto
void nuevoProyecto(HWND hwndParent)
{
    DialogBoxParam(hInst, MAKEINTRESOURCE(DLG_NUEVO_PROYECTO), hwndParent, nuevoProyectoDlgProc, 0);
}
//Funcion que muestra la ventana para crear cpngs
void CrearCPNG(HWND hwndParent)
{
    DialogBoxParam(hInst, MAKEINTRESOURCE(DLG_CREAR_CPNG), hwndParent, crearCpngDlgProc, 0);
}
void CrearTexture(HWND hwndParent)
{
    DialogBoxParam(hInst, MAKEINTRESOURCE(DLG_CREAR_TEXTURE), hwndParent, crearTextureDlgProc, 0);
}
void CrearScene(HWND hwndParent)
{
    DialogBoxParam(hInst, MAKEINTRESOURCE(DLG_CREAR_SCENE), hwndParent, crearSceneDlgProc, 0);
}
//Funcion que muestra la ventana para crear cpngs
void abreArchivo(HWND hwndParent)
{
    DialogBoxParam(hInst, MAKEINTRESOURCE(DLG_LEER_ARCHIVO), hwndParent, abreArchivoDlgProc, 0);
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst = hInstance;
    // The user interface is a modal dialog box
    return DialogBox(hInstance, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DialogProc);
}
