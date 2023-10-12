#include "chardev.h"

void paint_game (Scene *, cpng *, cpng *, int, int, int);

int main (){
    Scene game;
    game.id = 1;
    //cpng del mapa
    cpng map;
    map.id_cpng = 1;
    map.posX = 0;
    map.posY = 0;
    map.color = 1;
    map.var_i = 0;
    map.name = "world";
    //cpng de los dwafts
    cpng dwafts;
    dwafts.id_cpng = 1;
    dwafts.entity.id_entity = 1;
    dwafts.posX = 10;
    dwafts.posY = 7;
    dwafts.color = 2;
    dwafts.name = "Dwafts";
    dwafts.var_i = 1;//Total de Dwafts
    dwafts.asset = "#";
    long int money = 0;
    int num_rand;
    int aux,v,m;
    int on_m = 0;
    int velocity = 90;
    char key;
    int velocity_cost = 3;
    int money_cost = 7;
    ini_game(&game);
    game.hiddenCursor(1);
    game.addTitleConsole("Dwafts");
    while(GAME_TRUE){
        paint_game(&game,&map,&dwafts,money,velocity_cost,money_cost);
        if(map.var_i == 0){
            dwafts.posX++;
        }
        if(dwafts.posX == 39 && dwafts.posY == 7){
            dwafts.posX = 10;
            dwafts.posY = 18;
        }
        if(dwafts.posX == 39 && dwafts.posY == 18){
            dwafts.posX = 10;
            dwafts.posY = 25;
        }
        if(dwafts.posX == 22 && dwafts.posY == 25){
            dwafts.posX--;
            dwafts.asset = "X<o>";
            map.var_i = 1;
        }
        if(map.var_i == 1){
            dwafts.posX--;
        }
        if(dwafts.posX == 9 && dwafts.posY == 25){
            dwafts.posX = 38;
            dwafts.posY = 18;
        }
        if(dwafts.posX == 9 && dwafts.posY == 18){
            dwafts.posX = 38;
            dwafts.posY = 7;
        }
        //tramo del uno al inizio
        if(dwafts.posX == 9 && dwafts.posY == 7){
            map.var_i = 0;
            if(on_m == 0){
                money++;
            }
            if(on_m == 1){
                money += 2;
                if(money_cost > 21){
                    money += 3;
                }
                if(money_cost > 40){
                    money += 6;
                }
            }
            dwafts.asset = "X";
        }
        //casos si presiono alguna tecla
        key = game.getKey();
        if(money == velocity_cost || money > velocity_cost){
            if(key == 'q'){
                money -= velocity_cost;
                aux =+ velocity - 100;
                velocity =+ 70;
                if(velocity_cost > 6){
                    velocity =+ 10;
                }
                if(velocity_cost > 40){
                    velocity =+ 1000;
                }
                v =+ velocity_cost + 3;
                velocity_cost = v;
            }
        }
        if(money > money_cost){
            if(key == 'a'){
                money -= money_cost;
                m =+ money_cost + 7;
                money_cost = m;
                on_m = 1;
            }
        }
        game.drawWait(velocity);
        game.clearScene();
    }
    return 0;
}

void paint_game (Scene * game, cpng * map, cpng * dwafts, int money, int velocity_cost, int money_cost){
    game->addPosXY(0,1);
    game->readDraw(map);
    game->addJumpsLines(1);
    game->addPosXY(43,2);
    game->addText("Money: $%i\n",money);
    if(money > 1){
        game->addPosXY(43,4);
        game->addText("Presionar");
        game->addPosXY(43,5);
        game->addText("[Q]velocidad = $%d",velocity_cost);
    }
    if(money > 6){
        game->addPosXY(43,6);
        game->addText("[A]Money = $%d",money_cost);
    }
    game->addColor(dwafts->color);
    game->addDraw(dwafts);
    game->addColor(7);
}
