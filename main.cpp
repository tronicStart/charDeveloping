#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "resource.h"
#include "funciones.c"

typedef char Public;
typedef char String[500];

/*Lista de comandos de la aplicación: todos se escriben en el input 1*/
Public bye[] = "exit.program";                  //comando para salir
Public screen[] = "clear.screen";               //comando para limpiar la pantalla -> la de la terminal o consola
Public view[] = "view.texture";                 //comando para ver una texture
Public pplayer[] = "player";                    //comando sin uso
Public loadScene[] = "read.scene";              //comando para leer una esena
Public scenesCreator[] = "open.creator.scenes"; //comando para abrir el creador de scenas
Public crearTexture[] = "create.texture";
Public crearFunction[] = "create.fuction";
Public crearObject[] = "create.object";
Public crearNewObject[] = "create.Object";
Public crearNewScene[] = "create.scene.openCreatorEditCMD";
Public crearEditorCPNG[] = "open.editorCPNG.create.cpng";
Public crearCPNG[] = "create.file.cpng";

void InsertarMenu(HWND hWnd);

HINSTANCE hInst;

BOOL CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    String user1, user2, project_active;
    String user1_copy;
    char *user1_cat;
    HDC hdc;
    PAINTSTRUCT ps;
    static HINSTANCE hInstance;
    //char cad[256];
    int check, Project_active;
    char MainFile[] = "main.c";
    char cpngFile[] = "cpng.h";
    char structs[] = "objects.h";
    char registros[] = "registers.rg";

    switch (uMsg)
    {
    case WM_INITDIALOG:
        /*
         * TODO: Add code to initialize the dialog.
         */
        InsertarMenu(hwndDlg);
        SetTitle("Char Developing : cmd : start");
        printf("Stringgame : open! : ");
        sFile(registros, "Registers: charDeveloping.Open");
        sFile(registros, "Registers: Project active.this=0");
        Project_active = 0;

        return TRUE;

    /*case WM_CREATE:

        break;*/

    case WM_PAINT:
        hdc = BeginPaint(hwndDlg, &ps);
        TextOut(hdc, 10, 20, "Commands", 8);
        TextOut(hdc, 250, 20, "New Function", 12);
        EndPaint(hwndDlg, &ps);
        break;

    case WM_CLOSE:

        printf("Stringgame : ");
        yReadFile("User.dat");
        printf(" : desea salir?\n");
        if (MessageBox(hwndDlg, "Desea cerrar Char Developing", "Salir", MB_ICONQUESTION | MB_YESNO) == IDYES)
        {
            sFile(registros, "Registers: charDeveloping.exit");
            sFile(registros, "Registers: Project active.this=0.cancel");
            EndDialog(hwndDlg, 0);
        }
        printf("Stringgame : ");
        yReadFile("User.dat");
        printf(" : cancelo la salida de Char Developing\n");

        return TRUE;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
            /*
                 * TODO: Add more control ID's, when needed.
               */

        case CM_PRUEBA:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);

            sFile2(registros, "Registers: User.redy.delete.this.file=\"");
            sFile2(registros, user1);
            sFile(registros, "\"");

            if (remove(user1) == -1)
            {
                sFile(registros, "Registers: File.user.delete.Error!!!!!");
                SetTitle("Stringgame : cmd : error");
                MessageBox(hwndDlg, "El Archivo no se pudo eliminar...", "Stringgame : delete file : error", MB_ICONERROR);
                SetTitle("Stringgame : cmd");
            }

            else
            {
                sFile2(registros, "Registers: User.delete.this.file=\"");
                sFile2(registros, user1);
                sFile(registros, "\"");
                MessageBox(hwndDlg, "Archivo Eliminado con exito", "Stringgame : delete file", MB_ICONINFORMATION);
            }

            return TRUE;

        case CM_VIEW_COMMANDS:

            sFile(registros, "Registers: charDeveloping: User.press.viewCommands.1.total.commands.5");
            MessageBox(hwndDlg, "Los comandos que se ven aqui se escriben en el input 1: \n1.-exit.program\nDescripcion:  comando para salir del programa\n2.-clear.screen\nDescripcion:  comando para limpiar la pantalla -> la de la terminal o consola\n3.-view.texture\nDescripcion:  comando para ver una texture\n4.-read.scene\nDescripcion:  comando para leer una esena\n5.-open.creator.scenes\nDescripcion:  comando para abrir el creador de scenas", "charDeveloping: Commands", MB_ICONINFORMATION);

            return TRUE;

        case CM_ABRE_ARCHIVO:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            sFile2(registros, "Registers: Open.this.file=\"");
            sFile2(registros, user1);
            sFile(registros, "\"");
            readFilesNormal(user1, hwndDlg);

            return TRUE;

        case CM_ARCHIVOS:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT2, user2, 100);

            return TRUE;

        case CM_START_PROJECTS:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            sFile2(registros, "Registers: Ini.new.folder.save.project.nameorrute=\"");
            sFile2(registros, user1);
            sFile(registros, "\"");
            check = mkdir(user1);

            // check if directory is created or not
            if (!check)
            {
                sFile(registros, "Registers: Ini.new..folder.save.project.is.success.=\"Directory the project created\"");
                MessageBox(hwndDlg, "Carpeta del proyecto creada con exito", "Creacion de proyecto", MB_ICONINFORMATION);
                printf("Directory the project created\n");
            }
            else
            {
                sFile(registros, "Registers: Ini.new.folder.no.save.project.error.check.result.is.-1=\"Unable to create directory\"");
                MessageBox(hwndDlg, "Error al crear el proyecto:\n*No se pudo crear el directorio: \"Unable to create directory\"\n*Mal escrito el nombre de la carpeta", "Creacion de proyecto", MB_ICONERROR);
                printf("Unable to create directory\n");
            }

            sFile(registros, "Registers: Ini.new.ProjectActive.this.1");
            sFile(registros, "Registers: Ini.new.Escrity: create.file.named*main.c");
            sFile(registros, "Registers: Ini.new.CharDevelopingLibrary->mainScene.sce*createMainScene.sce");
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
              sFile2("functions_creator.trash","void ");
              sFile2("functions_creator.trash",user1);
              sFile("functions_creator.trash"," (void){");
              sFile("functions_creator.trash","    printf(\"\");");
              sFile2("functions_creator.trash","}");
              sFile2("functions_creator.txt","void ");
              sFile2("functions_creator.txt",user1);
              sFile("functions_creator.txt"," (void){");
              sFile("functions_creator.txt","    printf(\"\");");
              sFile2("functions_creator.txt","}");

        return TRUE;

        case CM_CREADOR_PROJECTS:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, MainFile, 100);

            sFile(registros, "Regist3rs: CharDeveloping.fake.project.new.create->mainScene.sce*>MainScene.sce");
            sFile("mainScene.sce", "StartScene");
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

            MessageBox(hwndDlg, "Se ha generado un codigo ", "CharDeveloping : create file *c", MB_ICONINFORMATION);

            return TRUE;

        case CM_CREADOR_CPNG:

            if (Project_active == 1)
            {
                user1_cat = "cpngs.h";

                strcpy(user1_copy, project_active);
                strcat(user1_copy, user1_cat);

                GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
                GetDlgItemText(hwndDlg, IDC_EDIT_INPUT2, user2, 100);

                sFile2(user1_copy, "//this is a cpng the ");
                sFile(user1_copy, user1);
                sFile(user1_copy, "");
                sFile2(user1_copy, "char cpng_");
                sFile2(user1_copy, user1);
                sFile(user1_copy, " (void){");
                sFile(user1_copy, "");
                sFile(user1_copy, "       // TODO: Implement this function");
                sFile2(user1_copy, "    struct cpng ");
                sFile2(user1_copy, user1);
                sFile(user1_copy, ";");
                sFile(user1_copy, "");
                sFile(user1_copy, "    ");
                sFile2(user1_copy, user1);
                sFile(user1_copy, ".X = (int)NULL; // o 0");
                sFile(user1_copy, "");
                sFile(user1_copy, "    ");
                sFile2(user1_copy, user1);
                sFile(user1_copy, ".Y = (int)NULL; // o 0");
                sFile(user1_copy, "");
                sFile2(user1_copy, "    ");
                sFile2(user1_copy, user1);
                sFile(user1_copy, ".Top = 1;");
                sFile2(user1_copy, "    ");
                sFile2(user1_copy, user1);
                sFile(user1_copy, ".Down = 1;");
                sFile2(user1_copy, "    ");
                sFile2(user1_copy, user1);
                sFile(user1_copy, ".Letf = 1;");
                sFile2(user1_copy, "    ");
                sFile2(user1_copy, user1);
                sFile(user1_copy, ".Right = 1;");
                sFile2(user1_copy, "    ");
                sFile2(user1_copy, user1);
                sFile(user1_copy, ".ID = 1;");
                sFile2(user1_copy, "    ");
                sFile2(user1_copy, "strcpy(");
                sFile2(user1_copy, user1);
                sFile2(user1_copy, ".Name , \"");
                sFile2(user1_copy, user1);
                sFile(user1_copy, "\");");
                sFile(user1_copy, "");
                sFile2(user1_copy, "    ");
                sFile2(user1_copy, user1);
                sFile(user1_copy, ".color = 3;");
                sFile(user1_copy, "");
                sFile2(user1_copy, "    ");
                sFile2(user1_copy, user1);
                sFile(user1_copy, ".range = 0;");
                sFile2(user1_copy, "    ");
                sFile2(user1_copy, "strcpy(");
                sFile2(user1_copy, user1);
                sFile2(user1_copy, ".data , \"");
                sFile2(user1_copy, user2);
                sFile(user1_copy, "\");");
                sFile(user1_copy, "");
                sFile2(user1_copy, "    StrStartCpng(&");
                sFile2(user1_copy, user1);
                sFile(user1_copy, ");");
                sFile2(user1_copy, "    StrPaintCpng(&");
                sFile2(user1_copy, user1);
                sFile(user1_copy, ");");
                sFile2(user1_copy, "    StrEndCpng(&");
                sFile2(user1_copy, user1);
                sFile(user1_copy, ");");
                sFile(user1_copy, "");
                sFile(user1_copy, "}");
                MessageBox(hwndDlg, "Se ha guardado el cpng en el archivo 'cpng.h", "Stringame : save cpng", MB_ICONINFORMATION);
            }

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT2, user2, 100);

            sFile(registros, "Registers: charDeveloping: this-*>createAFileCPNGStrucCPNG");

            sFile2(cpngFile, "//this is a cpng the ");
            sFile(cpngFile, user1);
            sFile(cpngFile, "");
            sFile2(cpngFile, "char cpng_");
            sFile2(cpngFile, user1);
            sFile(cpngFile, " (void){");
            sFile(cpngFile, "");
            sFile(cpngFile, "       // TODO: Implement this function");
            sFile2(cpngFile, "    struct cpng ");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ";");
            sFile(cpngFile, "");
            sFile(cpngFile, "    ");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ".X = (int)NULL; // o 0");
            sFile(cpngFile, "");
            sFile(cpngFile, "    ");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ".Y = (int)NULL; // o 0");
            sFile(cpngFile, "");
            sFile2(cpngFile, "    ");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ".Top = 1;");
            sFile2(cpngFile, "    ");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ".Down = 1;");
            sFile2(cpngFile, "    ");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ".Letf = 1;");
            sFile2(cpngFile, "    ");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ".Right = 1;");
            sFile2(cpngFile, "    ");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ".ID = 1;");
            sFile2(cpngFile, "    ");
            sFile2(cpngFile, "strcpy(");
            sFile2(cpngFile, user1);
            sFile2(cpngFile, ".Name , \"");
            sFile2(cpngFile, user1);
            sFile(cpngFile, "\");");
            sFile(cpngFile, "");
            sFile2(cpngFile, "    ");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ".color = 3;");
            sFile(cpngFile, "");
            sFile2(cpngFile, "    ");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ".range = 0;");
            sFile2(cpngFile, "    ");
            sFile2(cpngFile, "strcpy(");
            sFile2(cpngFile, user1);
            sFile2(cpngFile, ".data , \"");
            sFile2(cpngFile, user2);
            sFile(cpngFile, "\");");
            sFile(cpngFile, "");
            sFile2(cpngFile, "    StrStartCpng(&");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ");");
            sFile2(cpngFile, "    StrPaintCpng(&");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ");");
            sFile2(cpngFile, "    StrEndCpng(&");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ");");
            sFile(cpngFile, "");
            sFile(cpngFile, "}");
            MessageBox(hwndDlg, "Se ha guardado el cpng en el archivo 'cpng.h", "Stringame : save cpng", MB_ICONINFORMATION);

            return TRUE;

        case CM_CREADOR_SCENE:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            sFile2(registros, "Registers: charDeveloping: this-*>createAFileCPNGStrucCPNG+this");
            sFile(registros, user1);

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
            sFile2(registros, "Registers: charDeveloping: this-*>createAFileObjectStruc+this");
            sFile(registros, user1);
            sFile2(structs, "//This is newObject the ");
            sFile(structs, user1);
            sFile(structs, "");
            sFile2(structs, "struct newObject ");
            sFile2(structs, user1);
            sFile(structs, ";");
            sFile(structs, "");
            sFile2(structs, user1);
            sFile(structs, ".ID = 1;");
            sFile(structs, "");
            sFile2(structs, user1);
            sFile(structs, ".positionX = 0;");
            sFile(structs, user1);
            sFile(structs, ".positionY = 0");
            sFile2(structs, user1);
            sFile(structs, ".BOXTop = 0;");
            sFile(structs, "");
            sFile2(structs, user1);
            sFile(structs, ".BOXDown = 0;");
            sFile(structs, "");
            sFile2(structs, user1);
            sFile(structs, ".BOXLetf = 1;");
            sFile(structs, "");
            sFile2(structs, user1);
            sFile(structs, ".BOXright = 0;");
            sFile(structs, "");

            return TRUE;

        case CM_CREADOR_CPNGS:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            sFile2(registros, "Registers: charDeveloping: openCreatorCPNG...CMD");
            MessageBox(hwndDlg, "Se ha cargado el editador", "Escrity : load edit", MB_ICONINFORMATION);
            cpngs(user1);

            return TRUE;

        case CM_CREADOR_OBJECT:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            sFile2(registros, "Registers: charDeveloping: this-*>createAFileObjectStruc+this");
            sFile(registros, user1);
            if (strcasecmp(user1, pplayer) == 0)
            {
                sFile(structs, "#ifndef OBJECTS_H");
                sFile(structs, "#define OBJECTS_H");
                sFile(structs, "#include \"include/stringgame.h\"");
                sFile(structs, "");
                sFile2(structs, "//This is object the ");
                sFile(structs, user1);
                sFile(structs, "");
                sFile2(structs, "struct Object ");
                sFile2(structs, user1);
                sFile(structs, ";");
                sFile(structs, "");
                sFile2(structs, user1);
                sFile(structs, ".ID = 1;");
                sFile(structs, "");
                sFile2(structs, user1);
                sFile(structs, ".positionX = 0;");
                sFile2(structs, user1);
                sFile(structs, ".positionY = 0");
                sFile2(structs, user1);
                sFile(structs, ".BOXTop = 0;");
                sFile(structs, "");
                sFile2(structs, user1);
                sFile(structs, ".BOXDown = 0;");
                sFile(structs, "");
                sFile2(structs, user1);
                sFile(structs, ".BOXLetf = 1;");
                sFile(structs, "");
                sFile2(structs, user1);
                sFile(structs, ".BOXright = 0;");
                sFile(structs, "");
                MessageBox(hwndDlg, "", "", MB_ICONINFORMATION);
            }

            sFile2(structs, "//This is object the ");
            sFile(structs, user1);
            sFile(structs, "");
            sFile2(structs, "struct Object ");
            sFile2(structs, user1);
            sFile(structs, ";");
            sFile(structs, "");
            sFile2(structs, user1);
            sFile(structs, ".ID = 1;");
            sFile(structs, "");
            sFile2(structs, user1);
            sFile(structs, ".positionX = 0;");
            sFile2(structs, user1);
            sFile(structs, ".positionY = 0");
            sFile2(structs, user1);
            sFile(structs, ".BOXTop = 0;");
            sFile(structs, "");
            sFile2(structs, user1);
            sFile(structs, ".BOXDown = 0;");
            sFile(structs, "");
            sFile2(structs, user1);
            sFile(structs, ".BOXLetf = 1;");
            sFile(structs, "");
            sFile2(structs, user1);
            sFile(structs, ".BOXright = 0;");
            sFile(structs, "");

            MessageBox(hwndDlg, "Se han escrito el object en el archivo 'objects.h", "Stringame : save object", MB_ICONINFORMATION);

            return TRUE;

        case CM_USE_TEXTURE:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT2, user2, 100);

            sFile2(registros, "Registers: charDeveloping: this-*>useAFileObjectStrucTexture+this");
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
            sFile2(registros, "Registers: charDeveloping: this-*>createAFileObjectStrucTexture+this");
            sFile(registros, user1);

            if (strcmp(user1, pplayer) == 0)
            {
                sFile2("textures.h", "//this is a texture the ");
                sFile("textures.h", user1);
                sFile("textures.h", "//This is very import texture , is the player");
                sFile2("textures.h", "char * ");
                sFile2("textures.h", "texture_");
                sFile2("textures.h", user1);
                sFile("textures.h", " (void){");
                sFile("textures.h", "    // TODO: Implement this function");
                sFile2("textures.h", "    struct texture ");
                sFile2("textures.h", user1);
                sFile("textures.h", ";");
                sFile2("textures.h", "    ");
                sFile2("textures.h", user1);
                sFile("textures.h", ".ID = 1;");
                sFile2("textures.h", "    ");
                sFile2("textures.h", user1);
                sFile("textures.h", ".mode = 1;");
                sFile2("textures.h", "    ");
                sFile2("textures.h", "strcpy(");
                sFile2("textures.h", user1);
                sFile2("textures.h", ".name");
                sFile2("textures.h", ",\"Object_");
                sFile2("textures.h", user1);
                sFile("textures.h", "\");");
                sFile2("textures.h", "    ");
                sFile2("textures.h", "strcpy(");
                sFile2("textures.h", user1);
                sFile2("textures.h", ".nameFile");
                sFile2("textures.h", ",\"");
                sFile2("textures.h", user1);
                sFile("textures.h", "\");");
                sFile2("textures.h", "    ");
                sFile2("textures.h", "strcpy(");
                sFile2("textures.h", user1);
                sFile2("textures.h", ".content");
                sFile2("textures.h", ",\"");
                sFile2("textures.h", user2);
                sFile("textures.h", "\"); //Here you data or strings");
                sFile2("textures.h", "    StrPrintTexture(&");
                sFile2("textures.h", user1);
                sFile("textures.h", ");");
                sFile("textures.h", "}");
                sFile("textures.h", "");
                sFile("textures.dat", user2);
                MessageBox(hwndDlg, "Se ha guardado la texture en el archivo 'textures.h", "Stringame : save texture", MB_ICONINFORMATION);
            }

            sFile2("textures.h", "//this is a texture the ");
            sFile("textures.h", user1);
            sFile2("textures.h", "void ");
            sFile2("textures.h", "texture_");
            sFile2("textures.h", user1);
            sFile("textures.h", " (void){");
            sFile("textures.h", "    // TODO: Implement this function");
            sFile2("textures.h", "    struct texture ");
            sFile2("textures.h", user1);
            sFile("textures.h", ";");
            sFile2("textures.h", "    ");
            sFile2("textures.h", user1);
            sFile("textures.h", ".ID = 1;");
            sFile2("textures.h", "    ");
            sFile2("textures.h", user1);
            sFile("textures.h", ".mode = 1;");
            sFile2("textures.h", "    ");
            sFile2("textures.h", "strcpy(");
            sFile2("textures.h", user1);
            sFile2("textures.h", ".name");
            sFile2("textures.h", ",\"Object_");
            sFile2("textures.h", user1);
            sFile("textures.h", "\");");
            sFile2("textures.h", "    ");
            sFile2("textures.h", "strcpy(");
            sFile2("textures.h", user1);
            sFile2("textures.h", ".nameFile");
            sFile2("textures.h", ",\"");
            sFile2("textures.h", user1);
            sFile("textures.h", "\");");
            sFile2("textures.h", "    ");
            sFile2("textures.h", "strcpy(");
            sFile2("textures.h", user1);
            sFile2("textures.h", ".content");
            sFile2("textures.h", ",\"");
            sFile2("textures.h", user2);
            sFile("textures.h", "\"); //Here you data or strings");
            sFile2("textures.h", "    StrPrintTexture(&");
            sFile2("textures.h", user1);
            sFile("textures.h", ");");
            sFile("textures.h", "}");
            sFile("textures.h", "");
            sFile("textures.dat", user2);
            MessageBox(hwndDlg, "Se ha guardado la texture en el archivo 'textures.h", "Stringame : save texture", MB_ICONINFORMATION);

            return TRUE;

        case CM_NEW_FUCTIONS:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user2, 100);
            sFile2(user2, user1);
            sFile(user2, "{");
            sFile(user2, "    ");
            sFile(user2, "}");
            sFile2(registros, "TYP_");
            sFile2(registros, user1);
            sFile2(registros, "();");

            return TRUE;

        case CM_NAME_PROJECT:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            return TRUE;

        case CM_SALIR:
            sFile(registros, "Registers: charDeveloping.exit");
            sFile(registros, "Registers: Project active.this=0.cancel");
            Project_active = 0;
            EndDialog(hwndDlg, 0);
            return TRUE;

        case CM_CREADOR_ASSET:

            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            GetDlgItemText(hwndDlg, IDC_EDIT_INPUT2, user2, 100);

            sFile2(registros, "Registers: charDeveloping: this-*>createAFileObjectAsset+this");
            sFile(registros, user1);
            sFile2("Assets.h", "//this is a asset the ");
            sFile("Assets.h", user1);
            sFile2("Assets.h", "void ");
            sFile2("Assets.h", "asset_");
            sFile2("Assets.h", user1);
            sFile("Assets.h", " (void){");
            sFile("Assets.h", "    // TODO: Implement this function");
            sFile2("Assets.h", "    struct asset ");
            sFile2("Assets.h", user1);
            sFile("Assets.h", ";");
            sFile2("Assets.h", "    ");
            sFile2("Assets.h", user1);
            sFile("Assets.h", ".ID = 1;");
            sFile2("Assets.h", "    ");
            sFile2("Assets.h", user1);
            sFile("Assets.h", ".color = 1;");
            sFile2("Assets.h", "    ");
            sFile2("Assets.h", "strcpy(");
            sFile2("Assets.h", user1);
            sFile2("Assets.h", ".name,\"asset_");
            sFile2("Assets.h", user1);
            sFile("Assets.h", "\");");
            sFile2("Assets.h", "    ");
            sFile2("Assets.h", "strcpy(");
            sFile2("Assets.h", user1);
            sFile2("Assets.h", ".data,");
            sFile2("Assets.h", "\"");
            sFile2("Assets.h", user2);
            sFile("Assets.h", "\");");
            sFile2("Assets.h", "    ");
            sFile2("Assets.h", "StrAssetStart(&");
            sFile2("Assets.h", user1);
            sFile("Assets.h", ");");
            sFile2("Assets.h", "    ");
            sFile2("Assets.h", "StrAssetPaint(&");
            sFile2("Assets.h", user1);
            sFile("Assets.h", ");");
            sFile2("Assets.h", "    ");
            sFile2("Assets.h", "StrAssetEnd(&");
            sFile2("Assets.h", user1);
            sFile("Assets.h", ");");
            sFile("Assets.h", "}");
            sFile("Assets.h", "");
            sFile2("assets.dat", "Name Asset: ");
            sFile2("assets.dat", "asset_");
            sFile("assets.dat", user1);
            sFile("assets.dat", "");
            sFile2("assets.dat", "Asset: ");
            sFile("assets.dat", user2);

            MessageBox(hwndDlg, "Se ha guardado el asset en el archivo 'Assets.h", "Stringgame : save asset", MB_ICONINFORMATION);

            return TRUE;
        case IDC_BTN_QUIT:
            sFile(registros, "Registers: charDeveloping.exit");
            sFile(registros, "Registers: Project active.this=0.cancel");
            Project_active = 0;
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
            sFile(registros, "Registers: charDeveloping.onclick.Commands");

            if (strcmp(user1, loadScene) == 0)
            {
                GetDlgItemText(hwndDlg, IDC_EDIT_INPUT2, user2, 100);
                sFile(registros, "Registers: charDeveloping: Escrity: CharLibrary: Load.Scene.");
                CLS();
                file_scene_(user2);
            }

            if (strcmp(user1, scenesCreator) == 0)
            {
                GetDlgItemText(hwndDlg, IDC_EDIT_INPUT2, user2, 100);
                CLS();
                sFile(registros, "Registers: charDeveloping: Escrity: CharLibrary: Open.SceneCreator.");
                StrCreate_scene_(user2);
            }

            if (strcmp(user1, view) == 0)
            {
                GetDlgItemText(hwndDlg, IDC_EDIT_INPUT2, user2, 100);
                StrGotoXY(33, 10);
                sFile(registros, "Registers: charDeveloping: Escrity: CharLibrary: ViewTexture.dat.delete.exit.progra.");
                yReadFile("textures.dat");
                sFile2("textures.h", "//This coordinates ");
                sFile("textures.h", user2);
                if (remove("textures.dat") == -1)
                {
                    sFile(registros, "Registers: charLibrary : textures.dat : this null");
                    sFile(registros, "Registers: charLibrary : close program...");
                    Sleep(1500);
                    EndDialog(hwndDlg, 0);
                }
            }

            if (strcmp(user1, bye) == 0)
            {
                sFile(registros, "Registers: charDeveloping.exit");
                sFile(registros, "Registers: Project active.this=0.cancel");
                Project_active = 0;
                EndDialog(hwndDlg, 0);
            }

            if (strcmp(user1, screen) == 0)
            {
                sFile(registros, "Registers: charDeveloping: Escrity: CharLibrary: clearCMD");
                CLS();
            }
            if (strcmp(user1, crearTexture) == 0)
            {
            printf("Name Texture ");
            scanf("%s",&user1);
            printf("Data Texture: ");
            scanf("%s",&user2);
            sFile2(registros, "Registers: charDeveloping: this-*>createAFileObjectStrucTexture+this.in.Escrity.library");
            sFile(registros, user1);
            sFile2("textures.h", "//this is a texture the ");
            sFile("textures.h", user1);
            sFile2("textures.h", "void ");
            sFile2("textures.h", "texture_");
            sFile2("textures.h", user1);
            sFile("textures.h", " (void){");
            sFile("textures.h", "    // TODO: Implement this function");
            sFile2("textures.h", "    struct texture ");
            sFile2("textures.h", user1);
            sFile("textures.h", ";");
            sFile2("textures.h", "    ");
            sFile2("textures.h", user1);
            sFile("textures.h", ".ID = 1;");
            sFile2("textures.h", "    ");
            sFile2("textures.h", user1);
            sFile("textures.h", ".mode = 1;");
            sFile2("textures.h", "    ");
            sFile2("textures.h", "strcpy(");
            sFile2("textures.h", user1);
            sFile2("textures.h", ".name");
            sFile2("textures.h", ",\"Object_");
            sFile2("textures.h", user1);
            sFile("textures.h", "\");");
            sFile2("textures.h", "    ");
            sFile2("textures.h", "strcpy(");
            sFile2("textures.h", user1);
            sFile2("textures.h", ".nameFile");
            sFile2("textures.h", ",\"");
            sFile2("textures.h", user1);
            sFile("textures.h", "\");");
            sFile2("textures.h", "    ");
            sFile2("textures.h", "strcpy(");
            sFile2("textures.h", user1);
            sFile2("textures.h", ".content");
            sFile2("textures.h", ",\"");
            sFile2("textures.h", user2);
            sFile("textures.h", "\"); //Here you data or strings");
            sFile2("textures.h", "    StrPrintTexture(&");
            sFile2("textures.h", user1);
            sFile("textures.h", ");");
            sFile("textures.h", "}");
            sFile("textures.h", "");
            sFile("textures.dat", user2);
            }

            if (strcmp(user1, crearFunction) == 0)
            {

            printf("Name function: ");
            scanf("%s",&user1);
            printf("Data function: ");
            scanf("%s",&user2);
            sFile2(user2, user1);
            sFile(user2, "{");
            sFile(user2, "    ");
            sFile(user2, "}");
            sFile2(registros, "Registers: charDeveloping.Escrity::");
            sFile2(registros, user1);
            sFile2(registros, "::endfunc.new.function");
            }

            if (strcmp(user1, crearObject) == 0)
            {
                printf("Name object: ");
            scanf("%s",&user1);
                GetDlgItemText(hwndDlg, IDC_EDIT_INPUT, user1, 100);
            sFile2(registros, "Registers: charDeveloping: this-*>createAFileObjectStruc+this.in.charDeveloping");
            sFile(registros, user1);
            sFile2(structs, "//This is object the ");
            sFile(structs, user1);
            sFile(structs, "");
            sFile2(structs, "struct Object ");
            sFile2(structs, user1);
            sFile(structs, ";");
            sFile(structs, "");
            sFile2(structs, user1);
            sFile(structs, ".ID = 1;");
            sFile(structs, "");
            sFile2(structs, user1);
            sFile(structs, ".positionX = 0;");
            sFile2(structs, user1);
            sFile(structs, ".positionY = 0");
            sFile2(structs, user1);
            sFile(structs, ".BOXTop = 0;");
            sFile(structs, "");
            sFile2(structs, user1);
            sFile(structs, ".BOXDown = 0;");
            sFile(structs, "");
            sFile2(structs, user1);
            sFile(structs, ".BOXLetf = 1;");
            sFile(structs, "");
            sFile2(structs, user1);
            sFile(structs, ".BOXright = 0;");
            sFile(structs, "");

            }

            if (strcmp(user1, crearNewObject) == 0)
            {
                printf("Name new object: ");
            scanf("%s",&user1);
            sFile2(registros, "Registers: charDeveloping: this-*>createAFileObjectStruc+this.in.CharLibrary");
            sFile(registros, user1);
            sFile2(structs, "//This is newObject the ");
            sFile(structs, user1);
            sFile(structs, "");
            sFile2(structs, "struct newObject ");
            sFile2(structs, user1);
            sFile(structs, ";");
            sFile(structs, "");
            sFile2(structs, user1);
            sFile(structs, ".ID = 1;");
            sFile(structs, "");
            sFile2(structs, user1);
            sFile(structs, ".positionX = 0;");
            sFile(structs, user1);
            sFile(structs, ".positionY = 0");
            sFile2(structs, user1);
            sFile(structs, ".BOXTop = 0;");
            sFile(structs, "");
            sFile2(structs, user1);
            sFile(structs, ".BOXDown = 0;");
            sFile(structs, "");
            sFile2(structs, user1);
            sFile(structs, ".BOXLetf = 1;");
            sFile(structs, "");
            sFile2(structs, user1);
            sFile(structs, ".BOXright = 0;");
            sFile(structs, "");
            }

            if (strcmp(user1, crearNewScene) == 0)
            {
                printf("Name Scene: ");
            scanf("%s",&user1);
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
            scanf("%s",&user1);
            sFile2(registros, "Registers: charDeveloping: openCreatorCPNG...CMD....load.commands");
            cpngs(user1);
            }

            if (strcmp(user1, crearCPNG) == 0)
            {

             printf("Name Cpng: ");
            scanf("%s",&user1);
            printf("Data Cpng: ");
            scanf("%s",&user2);
            sFile(registros, "Registers: charDeveloping: this-*>createAFileCPNGStrucCPNG.commands.Escrity");
            sFile2(cpngFile, "//this is a cpng the ");
            sFile(cpngFile, user1);
            sFile(cpngFile, "");
            sFile2(cpngFile, "char cpng_");
            sFile2(cpngFile, user1);
            sFile(cpngFile, " (void){");
            sFile(cpngFile, "");
            sFile(cpngFile, "       // TODO: Implement this function");
            sFile2(cpngFile, "    struct cpng ");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ";");
            sFile(cpngFile, "");
            sFile(cpngFile, "    ");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ".X = (int)NULL; // o 0");
            sFile(cpngFile, "");
            sFile(cpngFile, "    ");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ".Y = (int)NULL; // o 0");
            sFile(cpngFile, "");
            sFile2(cpngFile, "    ");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ".Top = 1;");
            sFile2(cpngFile, "    ");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ".Down = 1;");
            sFile2(cpngFile, "    ");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ".Letf = 1;");
            sFile2(cpngFile, "    ");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ".Right = 1;");
            sFile2(cpngFile, "    ");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ".ID = 1;");
            sFile2(cpngFile, "    ");
            sFile2(cpngFile, "strcpy(");
            sFile2(cpngFile, user1);
            sFile2(cpngFile, ".Name , \"");
            sFile2(cpngFile, user1);
            sFile(cpngFile, "\");");
            sFile(cpngFile, "");
            sFile2(cpngFile, "    ");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ".color = 3;");
            sFile(cpngFile, "");
            sFile2(cpngFile, "    ");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ".range = 0;");
            sFile2(cpngFile, "    ");
            sFile2(cpngFile, "strcpy(");
            sFile2(cpngFile, user1);
            sFile2(cpngFile, ".data , \"");
            sFile2(cpngFile, user2);
            sFile(cpngFile, "\");");
            sFile(cpngFile, "");
            sFile2(cpngFile, "    StrStartCpng(&");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ");");
            sFile2(cpngFile, "    StrPaintCpng(&");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ");");
            sFile2(cpngFile, "    StrEndCpng(&");
            sFile2(cpngFile, user1);
            sFile(cpngFile, ");");
            sFile(cpngFile, "");
            sFile(cpngFile, "}");

            }

            return TRUE;
        }
    }

    return FALSE;
}

void InsertarMenu(HWND hWnd)
{
    HMENU hMenu1, hMenu2, hMenu3, hMenu4, hMenu5;

    hMenu1 = CreateMenu();
    hMenu2 = CreateMenu();
    hMenu3 = CreateMenu();
    hMenu4 = CreateMenu();
    hMenu5 = CreateMenu();
    /* Manipulador para el primer menú pop-up */
    AppendMenu(hMenu2, MF_STRING, CM_PRUEBA, "&Eliminar archivo");
    AppendMenu(hMenu2, MF_STRING, CM_ARCHIVOS, "&Crear archivo");
    AppendMenu(hMenu2, MF_STRING, CM_ABRE_ARCHIVO, "&Abrir archivo");
    AppendMenu(hMenu2, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu2, MF_STRING, CM_SALIR, "&Salir");
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
    AppendMenu(hMenu3, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu3, MF_STRING, CM_ABRE_CPNG, "&Abrir CPNG");
    AppendMenu(hMenu4, MF_STRING, CM_VIEW_COMMANDS, "&Ver commands");
    AppendMenu(hMenu2, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu2, MF_STRING, CM_NAME_PROJECT, "&Nombre del projecto");
    AppendMenu(hMenu5, MF_STRING, CM_BUILD_PROJECT, "&build project file c");
    AppendMenu(hMenu5, MF_STRING, CM_NEW_FUCTIONS, "&Generate function");
    AppendMenu(hMenu5, MF_STRING, CM_START_PROJECTS, "&Iniciar nuevo projecto");
    AppendMenu(hMenu5, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu5, MF_STRING, CM_CREADOR_PROJECTS, "&Generate code main");
    AppendMenu(hMenu5, MF_STRING, CM_NEW_PROJECT, "&Nuevo projecto");
    /* Inserción del menú pop-up */
    AppendMenu(hMenu1, MF_STRING | MF_POPUP, (UINT)hMenu2, "&Archivos");
    AppendMenu(hMenu1, MF_STRING | MF_POPUP, (UINT)hMenu3, "&Structs");
    AppendMenu(hMenu1, MF_STRING | MF_POPUP, (UINT)hMenu4, "&Commands");
    AppendMenu(hMenu1, MF_STRING | MF_POPUP, (UINT)hMenu5, "&Project");
    SetMenu(hWnd, hMenu1); /* Asigna el menú a la ventana hWnd */
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst = hInstance;
    // The user interface is a modal dialog box
    return DialogBox(hInstance, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DialogProc);
}
