#include "include\stringgame.h"
#include "textures.h"//Archivo de las textures

void paint_game(struct Scene * main_Scene);
int main (void){
    struct Scene Main_Scene;
    StrSetTitle("Char Game");
    StrHiddenCursor(true);
    Project_CharDeveloping();
    while(true){
        string_clrscr();
        paint_game(&Main_Scene);
    }
    return 0;
}

void paint_game(struct Scene * main_Scene){
    
    strcpy(main_Scene->name,"main_Scene");
    main_Scene->ID = 1;
    main_Scene->limitX = 80;
    main_Scene->limitX2 = -1;
    main_Scene->limitY = 10
    main_Scene->limitY2 = -1
    StrGotXY(33,10);
    printf("Stringgame");

}
