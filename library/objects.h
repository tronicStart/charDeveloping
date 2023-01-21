#ifndef OBJECTS_H
#define OBJECTS_H

#include <stdio.h>
#include <math.h>
#include <windows.h>

#include "strtypes.h"
#include "strdef.h"
#include "strfiles.h"
#include "assets.h"

struct Scene{
    int limitX;
    int limitX2;
    int limitY;
    int limitY2;

    int ID;
    public name[V];

    int Gravity;
    f ObjectInSceneGravity;
    int ObjectInSceneGravityDX;
    
    int color , blocks;

};

struct limit {

    int X;
    int Y;

};

struct texture {

    int ID;
    int mode;
    char name[V];
    char nameFile[V];
    char content[1024];

};

struct asset{
    
    int ID;
    int color;
    char name[V];
    char data[V];
    
};

struct cpng{
    
    int X;
    int Y;
    int Top;
    int Down;
    int Letf;
    int Right;
    int ID;
    char Name[V];
    int color;
    char data[V];
    int range;
    int error;
    char mode[V];
    
};

struct _air_{
    
    int speed;
    f Speed;
    int lado;
    int id;
    int peso;
    f Peso;
    int gravedad : 9;
    
};

struct lava_object
{
    public name[V];
    public cpng[V];
    int animation;
    int rangeX;
    int rangeY;
    int damage;
    int speed;
};

struct water_object
{
    public name[V];
    public cpng1[V];
    public cpng2[V];
    public cpng3[V];
    public cpng4[V];
    public cpng5[V];
    public cpng6[V];
    public cpng7[V];
    public cpng8[V];
    public cpng9[V];
    public cpng10[V];
    public cpng11[V];
    public cpng12[V];
    public cpng13[V];
    public cpng14[V];
    public cpng15[V];
    public cpng16[V];
    public cpng17[V];
    public cpng18[V];
    public cpng19[V];
    public cpng20[V];
    int animation;
    int rangeInX;
    int rangeInY;
    int startPaintInX;
    int startPaintInY;
    int cpngActives;
    int time;
};

struct Object
{
    //Posiciones en X y Y del objeto
    int positionX;
    int positionY;
    //caja de colision
    int BOXTop;
    int BOXDown;
    int BOXLetf;
    int BOXright;
    //Otros
    int ID;
    int range;
    f gravity;
    //Para el nombre del objeto
    public Name[V];
    union{
        
        int top;
        int down;
        int letf;
        int right;
        
    }collision;
    f peso;
    int Peso;
    
};

struct newObject
{
    int positionX;
    int positionY;
    f gravity;
    int BOXTop, BOXDown, BOXLetf, BOXright;
    int ID;
    int range;
    int onX1;
    int onX2;
    int onY1;
    int onY2;
    public name[V];
    union{
        
        int top;
        int down;
        int letf;
        int right;
        
    }collision;
    f peso;
    int Peso;
};

struct box_collision
{
    struct Object posObject;
    struct newObject otherObject;
    int range;
    char name[V];
    int id;
    int condition;
};

struct _scenes_
{
    public name[V];
    int id;
    int actives;
    int fps;
    int calls;
    int time_calls;
    int limitX_left;
    int limitX_rigth;
    int limitY_top;
    int limitY_bottom;
    char cpng1[V], cpng2[V], cpng3[V], cpng4[V], cpng5[V], cpng6[V], cpng7[V], cpng8[V], cpng9[V], cpng10[V], cpng11[V], cpng12[V], cpng13[V], cpng14[V], cpng15[V], cpng16[V], cpng17[V], cpng18[V], cpng19[V], cpng20[V];
};

struct Vector {
    double x, y;
};

struct Body {
    double mass;
    struct Vector position;
    struct Vector velocity;
};

struct Point {
    double x, y;
};

struct Wave {
    double amplitude;
    double wavelength;
    double speed;
    double direction;
};

struct Obj {
    struct Vector position;
    struct Vector velocity;
    double mass;
};

struct Vector gravityForce(struct Obj obj1, struct Obj obj2) {
    double G = 6.67408e-11;  // Constante de gravitación universal
    double distance = sqrt(pow(obj2.position.x - obj1.position.x, 2) + pow(obj2.position.y - obj1.position.y, 2));
    double force = (G * obj1.mass * obj2.mass) / pow(distance, 2);
    double angle = atan2(obj2.position.y - obj1.position.y, obj2.position.x - obj1.position.x);
    struct Vector forceVector = { force * cos(angle), force * sin(angle) };
    return forceVector;
}

void updateObject(struct Obj *obj, double dt) {
    obj->position.x += obj->velocity.x * dt;
    obj->position.y += obj->velocity.y * dt;
}

double waveHeight(struct Wave wave, double x, double t) {
    return wave.amplitude * sin(2 * SETPI / wave.wavelength * (x - wave.speed * t) - wave.direction);
}

void updatePosition(struct Body* body, double time) {
    body->position.x += body->velocity.x * time;
    body->position.y += body->velocity.y * time;
}

void updateVelocity(struct Body* body, struct Vector acceleration, double time) {
    body->velocity.x += acceleration.x * time;
    body->velocity.y += acceleration.y * time;
}

void resolveCollision(struct Body* a, struct Body* b) {
    struct Vector normal = {
        b->position.x - a->position.x,
        b->position.y - a->position.y
    };

    double dist = sqrt(normal.x * normal.x + normal.y * normal.y);
    normal.x /= dist;
    normal.y /= dist;

    double velocityAlongNormal = normal.x * a->velocity.x + normal.y * a->velocity.y;
    double bVelocityAlongNormal = normal.x * b->velocity.x + normal.y * b->velocity.y;

    double combinedMass = a->mass + b->mass;
    double impulse = (2.0 * a->mass * b->mass * (bVelocityAlongNormal - velocityAlongNormal)) / combinedMass;

    a->velocity.x += impulse * normal.x / a->mass;
    a->velocity.y += impulse * normal.y / a->mass;
    b->velocity.x -= impulse * normal.x / b->mass;
    b->velocity.y -= impulse * normal.y / b->mass;
}

void showObjectCoordinates(struct Object *object){
    
    printf("Coordinates:'%s': X = %d | Y = %d | ID: %d\n", object->Name, object->positionX, object->positionY, object->ID);
    
}

void showCoordinatesCpng(struct cpng *object){
    
    printf("Coordinates:'%s': X = %d | Y = %d | ID: %d\n", object->Name, object->X, object->Y, object->ID);
    
}


void moveObjectCPNG(struct cpng *posPlayer, const char *key1, const char *key2, const char *key3, const char *key4){
    
    char Keey;

    HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = posPlayer->X;
	dwPos.Y = posPlayer->Y;

	SetConsoleCursorPosition(hCon, dwPos);
	printf("%s\n",posPlayer->data);

	Keey = getch();

	//Movimiento en X
	if(Keey == key1){

	   if(key1 == NULL){
	       return;
	   }

	   posPlayer->X--;
	}

	if(Keey == key2){

	   if(key2 == NULL){
	       return;
	   }

	   posPlayer->X++;
	}

	if(Keey == key3){

	   if(key3 == NULL){
	       return;
	   }

	   posPlayer->Y++;
	}

	if(Keey == key4){

	   if(key4 == NULL){
	       return;
	   }

	   posPlayer->Y--;
	}
    
}

void moveObject(struct Object *posPlayer, const char *player, const char *key1, const char *key2, const char *key3, const char *key4){
    
    char Keey;

    HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = posPlayer->positionX;
	dwPos.Y = posPlayer->positionY;

	SetConsoleCursorPosition(hCon, dwPos);
	printf("%s\n",player);

	Keey = getch();

	//Movimiento en X
	if(Keey == key1){

	   if(key1 == NULL){
	       return;
	   }

	   posPlayer->positionX--;
	}

	if(Keey == key2){

	   if(key2 == NULL){
	       return;
	   }

	   posPlayer->positionX++;
	}

	if(Keey == key3){

	   if(key3 == NULL){
	       return;
	   }

	   posPlayer->positionY++;
	}

	if(Keey == key4){

	   if(key4 == NULL){
	       return;
	   }

	   posPlayer->positionY--;
	}
    
}

int ini_scenes(struct _scenes_ *Scene){
    
    void *voidID = NULL;

    int i;

    if (Scene->id == (int)voidID)
    {
        printf("Error in _scene_: %s : this id type NULL | function error: StrLoad_scene_(struct _scenes_ * Scene); -1\n", Scene->name);
        return -1;
    }
    else
    {
        for (i = 0; i < Scene->calls; i++)
        {
            showRenderPaint(Scene);
            file_scene_(Scene->name);

            Sleep(Scene->time_calls);
            system("clear");

            if (i == Scene->calls - 1)
            {
                Scene->fps = Scene->calls;
                i = 0;
            }
        }
    }
}

void start_limit_scenes_(struct _scenes_ *Scene, struct Object *object){
    
    if (object->positionX == Scene->limitX_left)
    {
        object->positionX++;
    }
    if (object->positionY == Scene->limitY_top)
    {
        object->positionY++;
    }
    if (object->positionX == Scene->limitX_rigth)
    {
        object->positionX--;
    }
    if (object->positionY == Scene->limitY_bottom)
    {
        object->positionY--;
    }
    
}

void start_Limit_scenes_(struct _scenes_ *Scene, struct cpng *object){
    
    if (object->X == Scene->limitX_left)
    {
        object->X++;
    }
    if (object->Y == Scene->limitY_top)
    {
        object->Y++;
    }
    if (object->X == Scene->limitX_rigth)
    {
        object->X--;
    }
    if (object->Y == Scene->limitY_bottom)
    {
        object->Y--;
    }
    
}

int ini_scenes_ob(struct _scenes_ *Scene, struct Object *ob, const char *C, const char *A, const char *D, const char *S, const char *W){
    
    void *voidID = NULL;

    int i;

    if (Scene->id == (int)voidID)
    {
        printf("Error in _scene_: %s : this id type NULL | function error: StrLoad_scene_(struct _scenes_ * Scene); -1\n", Scene->name);
        return -1;
    }
    else
    {
        for (i = 0; i < Scene->calls; i++)
        {
            Sleep(Scene->time_calls);
            system("clear");
            start_limit_scenes_(Scene, ob);
            showObjectCoordinates(ob);
            file_scene_(Scene->name);
            moveObject(ob, C, A, D, S, W);

            if (i == Scene->calls - 1)
            {
                Scene->fps = Scene->calls;
                i = 0;
            }
        }
    }
    
}
void paintNewObject(struct newObject *Ob, const char *C){
    
    void *voidID = NULL;

    if (Ob->ID == (int)voidID)
    {
        printf("The function StrPaintNewObject() detect a error in ID struct | ID type void | OBJECT: '%s'\n", Ob->name);
        return;
    }

    else
    {
        go_xy_h(Ob->positionX, Ob->positionY);
        printf("%s", C);
    }
    
}
void show_position_NewObject(struct newObject *ob){
    
    printf("Position the Object '%s': X = %d | Y = %d\n", ob->name, ob->positionX, ob->positionY);
    
}

int load_scene_(struct _scenes_ *Scene){
    
    void *voidID = NULL;

    if (Scene->id == (int)voidID)
    {
        printf("Error in _scene_: %s : this id type NULL | function error: load_scene_(struct _scenes_ * Scene); -1\n", Scene->name);
        return -1;
    }
    else
    {
        file_scene_(Scene->name);
    }
    
}

int boxCollisionActionObjectRigtLefthInX(struct box_collision *object, struct box_collision *newObject, struct Object *ob, struct newObject *new){
    
    if (object->id == (int)NULL || newObject->id == (int)NULL)
    {
        printf("Error detect in fuction: StrBoxCollisonActionObject(); detect ID NULL in boxCollision: '%s'\n", object->name);
        return -1;
    }

    if (newObject->id == (int)NULL)
    {
        printf("Error detect in fuction: StrBoxCollisonActionObject(); detect ID NULL in boxCollision: '%s'\n", newObject->name);
        return -1;
    }

    if (object->id == newObject->id)
    {
        printf("Error detect in fuction StrBoxCollisionActionObject(); detect ID object = ID newObject\n");
        return -1;
    }

    else
    {
        if (ob->positionX + object->posObject.BOXright == new->positionX - newObject->otherObject.BOXLetf / -1)
        {
            ob->positionX--;
            object->condition = true;
        }
    }
}

void move_cpng_mouse(struct cpng * CPNG , POINT cursor){
    
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
    printf("%s",CPNG->data);
    
}

int collision_cpng (struct cpng *object, struct newObject *object2, const char *a, int posXoY, int cand){
    
    if (posXoY == 0)
    {
        if (object->X == object2->positionX-2/object2->BOXLetf)
        {
            go_xy_h(object2->positionX,object2->positionY);
            printf("%s", a);
            //exit(1);
            object->X-=cand;
            return 1;
        }
    }

    else if (posXoY == 1)
    {
        if (object->Y == object2->positionY-2/object2->BOXLetf)
        {
            printf("%s", a);
            //exit(1);
            object->Y -= cand;
            return 1;
        }
    }

    if (posXoY == 2)
    {
        if (object->X == object2->positionX-2/object2->BOXLetf || object->X == object2->positionX+2/object2->BOXLetf)
        {
            printf("%s", a);
            //exit(1);
            object->X -= cand;
            object->Y -= cand;
            return 1;
        }
    }
    
}
int collision_Object (struct Object *object, struct newObject *object2, const char *a, int posXoY, int cand){
    
    if (posXoY == 0)
    {
        if (object->positionX == object2->positionX-2/object2->BOXLetf)
        {
            go_xy_h(object2->positionX,object2->positionY);
            printf("%s", a);
            //exit(1);
            object->positionX-=cand;
            return 1;
        }
    }

    else if (posXoY == 1)
    {
        if (object->positionY == object2->positionY-2/object2->BOXLetf)
        {
            printf("%s", a);
            //exit(1);
            object->positionY -= cand;
            return 1;
        }
    }

    if (posXoY == 2)
    {
        if (object->positionX == object2->positionX-2/object2->BOXLetf || object->positionX == object2->positionX+2/object2->BOXLetf)
        {
            printf("%s", a);
            //exit(1);
            object->positionX -= cand;
            object->positionY -= cand;
            return 1;
        }
    }
    
}

void startCpng (struct cpng * Asset){
    
    void * VoidID = NULL;
    
    if(Asset->ID == (int)VoidID){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error StrCpngStart();\n",Asset->Name,Asset->ID);
        return;
    }
    else{
        
        setColorText(Asset->color);
        
    }
    
}
void paintCpng (struct cpng * Asset){
    
    void * VoidID = NULL;
    
    if(Asset->ID == (int)VoidID){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error StrAssetPaint();\n",Asset->Name,Asset->ID);
        return;
    }
    
    else{
        
        printf("%s",Asset->data);
        
    }
    
}
void endCpng (struct cpng * Asset){
    
    void * VoidID = NULL;
    
    if(Asset->ID == (int)VoidID){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error StrAssetEnd();\n",Asset->Name,Asset->ID);
        return;
    }
    else{
        
        setColorText(7);
        
    }
    
}

void showCpngCoordinates (struct cpng * Object){
    
    printf("Coordinates:'%s': X = %d | Y = %d | ID: %d | '%s'\n",Object->Name,Object->X,Object->Y,Object->ID,Object->data);
    
}

static void fileAssets (const char nameAsset[V] , const char * data){
    
    char cat[1024] = ".asset";
	char nose[1024];

	FILE *file;

	strcpy(nose, nameAsset);

	strcat(nose, cat);

	file = fopen(nose, "w");

	if (file == NULL)
	{
		perror("");
		return;
	}

	fprintf(file, "%s", data);
	printf("Se ha guardado\n");
	fclose(file);
    
}

void readAsset (char nombre[1024]){
    
    char cat[1024] = ".asset";
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

void assetStart (struct asset * Asset){
    
    void * VoidID = NULL;
    
    if(Asset->ID == (int)VoidID){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error StrAssetStart();\n",Asset->name,Asset->ID);
        return;
    }
    else{
        
        fileAssets(Asset->name,Asset->data);
        setColorText(Asset->color);
        //dataTextures(Texture->nameFile,Texture->nameFile);
        
    }
    
}
void assetPaint (struct asset * Asset){
    
    void * VoidID = NULL;
    
    if(Asset->ID == (int)VoidID){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error StrAssetPaint();\n",Asset->name,Asset->ID);
        return;
    }
    
    else{
        
         readAsset(Asset->name);
        
    }
    
}
void assetEnd (struct asset * Asset){
    
    void * VoidID = NULL;
    
    if(Asset->ID == (int)VoidID){
        printf("ID Asset is void (Name Asset: '%s' and ID: %i) funcion error StrAssetEnd();\n",Asset->name,Asset->ID);
        return;
    }
    else{
        
        setColorText(7);
        
    }
    
}
void moveOtherObject (struct newObject * OtherObject){
    
    void * VoidID = NULL;
    
    if(OtherObject->ID == (int)VoidID){
        
        printf("ID of Object type: newObject is null (Object Name: '%s' | Object ID: '%d') in function StrMoveOtherObject\n",OtherObject->name,OtherObject->ID);
        return;
    }
    else{
        
        if(OtherObject->onX1 == 1){
            
            OtherObject->positionX++;
            
        }
        else if (OtherObject->onX1 == 2){
            
            OtherObject->positionX--;
            
        }
        //position Y
        if(OtherObject->onY1 == 1){
            
            OtherObject->positionY++;
            
        }
        else if (OtherObject->onY1 == 2){
            
            OtherObject->positionY--;
            
        }
        else{
            
            return;
            
        }
        
    }
    
}

static void readTexture (char nombre[1024]){
    
    char cat[1024] = ".tr";
	char nose[1024];

	FILE *file;

	strcpy(nose, nombre);

	strcat(nose, cat);

	file = fopen(nose, "r");

	if (file == NULL)
	{
		printf("StringLibrary: \" %s \" -> 'Inixistente' ", nombre);
		return;
	}
    StringReadFileModeRB(nose);
    
}
void usingTexture (struct texture * Texture , const char * otherDraw){
    
    void * VoidID = NULL;
    void * Voidtext = NULL;

    if(Texture->ID == (int)VoidID){
        printf("ID Texture is void (Name Texture: '%s' and ID: %i) in fuction: StrUsingTexture();\n",Texture->name,Texture->ID);
        return;
    }
    else{

        if(otherDraw == Voidtext){

            return;

        }
        else{

             readTexture(Texture->nameFile);

        }

    }
    
}
void printTexture (struct texture * Texture){
    
    void * VoidID = NULL;

    if(Texture->ID == (int)VoidID){
        printf("ID Texture is void (Name Texture: '%s' and ID: %i) in fuction: StrPrintTexture();\n",Texture->name,Texture->ID);
        return;
    }

    if(Texture->mode == 0){//Leer mediante un archivo

        readTexture(Texture->nameFile);

    }
    else if (Texture->mode == 1){//Simplemente mostrar

        printf("%s",Texture->content);

    }
    else{

        printf("Mode is void , remenmer 0 is file and 1 simple print\n");
        return;

    }
    
}
static void fileTextures (const char nameTexture[V] , const char * contentTexture){
    
    char cat[1024] = ".tr";
	char nose[1024];

	FILE *file;

	strcpy(nose, nameTexture);

	strcat(nose, cat);

	file = fopen(nose, "w");

	if (file == NULL)
	{
		printf("StringLibrary: \" %s \" error no create texture'", nameTexture);
		return;
	}

	fprintf(file, "%s", contentTexture);
	printf("StringLibrary: save texture\n");
	fclose(file);
    
}
static void dataTextures (const char nameTexture[V] , const char * contentTexture , struct texture * data){
    
    char cat[1024] = ".dat";
	char nose[1024];

	FILE *file;

	strcpy(nose, nameTexture);

	strcat(nose, cat);

	file = fopen(nose, "w");

	if (file == NULL)
	{
		printf("StringLibrary: \" %s \" error no create texture'", nameTexture);
		return;
	}

	fprintf(file, "Name texture: %s\nID the texture: %d", contentTexture , data->ID);
	printf("StringLibrary: Se ha guardado\n");
    
}
void textures (struct texture * Texture){
    
    void * nullID = NULL;

    if(Texture->ID == (int)nullID){
        printf("ID Texture is void (Name Texture: '%s' and ID: %i) in fuction: StrTexture();\n",Texture->name,Texture->ID);
        return;
    }
    else{

        fileTextures(Texture->nameFile,Texture->content);
        dataTextures(Texture->nameFile,Texture->nameFile,Texture);

    }
    
}
void showSceneLimits(struct Scene * limitScene){
    
    printf("Scene's limit: Right'X': %d | Letf'X': %d \nDown'Y': %d | Top'Y': %d | Name: '%s' | ID: %d\n",limitScene->limitX,limitScene->limitX2,limitScene->limitY,limitScene->limitY2,limitScene->name,limitScene->ID);
    
}

void limitObject (struct Object * limitObject , int limitX1 , int limitX2, int limitY1 , int limitY2){
    
    void * VoidID = NULL;// 0

    if(limitObject->ID == (int)VoidID){

        printf("ID the object('%s') this incorrect , (ID value: %d) functionError(StrlimitObject)\n",limitObject->Name,limitObject->ID);
        return ;

    }

    //Posiciones en X de derecha a izquierda
    if(limitObject->positionX == limitX1){

        limitObject->positionX++;

    }

    if(limitObject->positionX == limitX2){

        limitObject->positionX--;

    }

    //Posiciones en Y de arriba a abajo
    if(limitObject->positionY == limitY1){

        limitObject->positionY++;

    }

    if(limitObject->positionY == limitY2){

        limitObject->positionY--;

    }
    
}
void limit_scenes_newObjects(struct _scenes_* Scene, struct newObject * Ob){
    
    if (Ob->positionX == Scene->limitX_left)
    {
        Ob->positionX++;
    }
    if (Ob->positionY == Scene->limitY_top)
    {
        Ob->positionY++;
    }
    if (Ob->positionX == Scene->limitX_rigth)
    {
        Ob->positionX--;
    }
    if (Ob->positionY == Scene->limitY_bottom)
    {
        Ob->positionY--;
    }
    
}

int create_cpng (struct cpng * cpng){
    
    void * voidID = NULL;
    
    cpng->error = -1;
    
    if(cpng->ID == (int)voidID){
        
        printf("create_cpng: error id is NULL\n");
        
        return cpng->error;
        
    }
    
    char cat[1024] = ".cpng";
    char nose[1024];

    FILE *file;

    strcpy(nose, cpng->Name);

    strcat(nose, cat);

    file = fopen(nose, cpng->mode);
    
    fprintf(file, "%s",cpng->data);
    printf("Se ha creado\n");
    
}

int read_cpng (struct cpng * cpng){
    
    void * voidID = NULL;
    
    int negative = -1;
    
    cpng->error = -1;
    
    if(cpng->ID == (int)voidID || cpng->ID == negative || negative){
        
        printf("read_cpng: error id is NULL or negative: ID is = cpng.%s = %d negative = %d\n",cpng->Name,cpng->ID,negative);
        
        return cpng->error;
        
    }
    
    char cat[1024] = ".cpng";
    char nose[1024];

    FILE *file;

    strcpy(nose, cpng->Name);

    strcat(nose, cat);

    file = fopen(nose, "r");
    
    StringReadFileModeRB(nose);
    
}

int _gravity_ (struct Object * ob){
    
    void * voidID = NULL;
    
    if(ob->ID == (int)voidID){
        
        printf("Error the ID of struct Object is NULL\n");
        return -1;
        
    }
    
    if(ob->Peso >= PESO_DEFAULT){
        
        ob->positionY++;
        
    }
    
    else{
        
        ob->positionY--;
        
    }
    
}

void showSpeed_air_integer (struct _air_ * A){
    
    printf("Speed: %d\n",A->speed);
     
}

void showSpeed_air_float(struct _air_ * A){
    
    printf("Speed: %f\n",A->Speed);
    
}

int start_air (struct _air_ * A, struct Object * ob, int option){
    
    void * voidID = NULL;
    
    if(A->id == (int)voidID){
        
        printf("Error the ID of struct _air_ is NULL\n");
        return -1;
        
    }
    
    if(ob->ID == (int)voidID){
        
        printf("Error the ID of struct Object is NULL\n");
        return -1;
        
    }
    
    /*si el peso es menor que el aire por efecto 
    el objecto se mueve de su posicion general
    caso contrario no.*/
    
    if(A->lado == 1){
        
        if(A->peso < PESO_DEFAULT){
            
            ob->positionX++;
            
        }
        
        if(A->peso > PESO_DEFAULT){
            
            ;
            
        }
        
        if(A->peso == PESO_DEFAULT){
            
            ;
            
        }
        
    }
    
}

void debugCollisionLetfRigthInX(struct box_collision *object, struct box_collision *newObject, struct Object *ob, struct newObject *new)
{
    if (object->id == (int)NULL )
    {
        colorRGBA(1, 0, 0, 0);
        printf("Error detect in fuction: StrBoxCollisonActionObject(); detect ID NULL in boxCollision: '%s'\n", object->name);
        colorRGBA(1, 1, 1, 0);
        return;
    }

    if (newObject->id == (int)NULL)
    {
        colorRGBA(1, 0, 0, 0);
        printf("Error detect in fuction: StrBoxCollisonActionObject(); detect ID NULL in boxCollision: '%s'\n", newObject->name);
        colorRGBA(1, 1, 1, 0);
        return;
    }

    if (object->id == newObject->id)
    {
        colorRGBA(1, 0, 0, 0);
        printf("Error detect in fuction StrBoxCollisionActionObject(); detect ID object = ID newObject\n");
        colorRGBA(1, 1, 1, 0);
        return;
    }

    else
    {
        colorRGBA(1, 0, 1, 0);
        printf("Verify Collisions: objects: '%s' and '%s'\n",ob->Name,new->name);
        printf("(Object)%s : X = %d , Y = %d , BOXrigth = %d | (newObject)%s : X = %d , Y = %d , BOXLetf = %d \n", ob->Name, ob->positionX, ob->positionY, object->posObject.BOXright, new->name, new->positionX, new->positionY, newObject->otherObject.BOXLetf);
        printf("(Object)%s : X = %d + BOXrigth = %d same (newObject)%s : X = %d - BOXLetf = %d/ -1 = (%d)\n", ob->Name, ob->positionX, object->posObject.BOXright, new->name, new->positionX, newObject->otherObject.BOXLetf, ob->positionX + object->posObject.BOXright ? new->positionX : new->positionX - newObject->otherObject.BOXLetf / -1 );
        colorRGBA(1, 1, 1, 0);
    }
}

int debugCollision(struct Object * Ob, struct newObject * ob){
    
    if(Ob->ID == ob->ID){
        colorRGBA(1, 0, 0, 0);
        printf("Error detect in fuction StrBoxCollisionActionObject(); detect ID object = ID newObject\n");
        colorRGBA(1, 1, 1, 0);
    }
    
    if (Ob->ID == (int)NULL)
    {
        colorRGBA(1, 0, 0, 0);
        printf("Error detect in fuction: StrBoxCollisonActionObject(); detect ID NULL in boxCollision: '%s'\n", Ob->Name);
        colorRGBA(1, 1, 1, 0);
        return -1;
    }

    if (ob->ID == (int)NULL)
    {
        colorRGBA(1, 0, 0, 0);
        printf("Error detect in fuction: StrBoxCollisonActionObject(); detect ID NULL in boxCollision: '%s'\n", ob->name);
        colorRGBA(1, 1, 1, 0);
        return -1;
    }
    
    else
    {
        colorRGBA(1, 0, 1, 0);
        printf("Verify Collisions: objects: '%s' and '%s'\n",Ob->Name,ob->name);
        printf("(Object)%s : X = %d , Y = %d , BOXrigth = %d | (newObject)%s : X = %d , Y = %d , BOXLetf = %d \n", Ob->Name, Ob->positionX, Ob->positionY, Ob->collision.right, ob->name, ob->positionX, ob->positionY, ob->collision.letf);
        printf("(Object)%s : X = %d + BOXrigth = %d same (newObject)%s : X = %d - BOXLetf = %d/ -1 = (%d)\n", Ob->Name, Ob->positionX, Ob->collision.right, ob->name, ob->positionX, ob->collision.letf, Ob->positionX + Ob->collision.right ? ob->positionX : ob->positionX - ob->collision.letf / -1 );
        colorRGBA(1, 1, 1, 0);
    }
    
}

void startLimit_scenes(struct _scenes_ *Scene, struct Object *object)
{
    if (object->positionX == Scene->limitX_left)
    {
        object->positionX++;
    }
    if (object->positionY == Scene->limitY_top)
    {
        object->positionY++;
    }
    if (object->positionX == Scene->limitX_rigth)
    {
        object->positionX--;
    }
    if (object->positionY == Scene->limitY_bottom)
    {
        object->positionY--;
    }
}

void showPositionNewObject(struct newObject *ob)
{
    printf("Position the Object '%s': X = %d | Y = %d\n", ob->name, ob->positionX, ob->positionY);
}

#endif