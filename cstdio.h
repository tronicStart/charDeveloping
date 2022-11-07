#ifndef _CSTDIO_H
#define _CSTDIO_H

#include "ctipes.h"
#include "cdefines.h"

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

void show_var_p (unsigned int var)//funcion para mostrar el peso en bytes de una variable
{
    printf("%ld bytes\n", sizeof(var));
}
void clscr(void)//function for clear the cmd
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
String * scan_string (String * fmt)//funcion para leer un string
{
    fflush(stdin);
	scanf("%s",&fmt);

	return * fmt;
}
void dream (DWORD time)//funcion para dormir el programa temporalmente
{
    Sleep(time);
}
void hidden_cursor(let condition)//funcion para ocultar el cursor
{
    if(condition == true){
    CONSOLE_CURSOR_INFO cci = {100, FALSE};

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
    }
    else if(condition == false){
    	CONSOLE_CURSOR_INFO cci = {100, TRUE};

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
    }
}
void setTitle (const char * title)//funcion para ponerle un titulo a la cmd
{
    SetConsoleTitle(title);
}
void AttributeText(int color)//funcion para pintar el texto de la cmd
{
    HANDLE out;
    out=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(out,color);
}
void go_xy(int X , int Y)//funcion para mover el texto a una posicion concreta
{
    HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = X;
	dwPos.Y = Y;
	SetConsoleCursorPosition(hCon, dwPos);
}
void exit_program(void)//funcion para salir del programa
{
    exit(1);
}
int scan_int(int Int)//funcion para leer un numero
{
    fflush(stdin);
	scanf("%i", &Int);
	fflush(stdin);

	return Int;
}
void AsciiInt (const char *b)//funcion para mostrar el valor ascii de una variable char
{
    printf("%d", b);
}
void randC(int inicio, int fin)//funcion para generar una letra aleatoria
{
    srand(time(NULL));
	inicio = rand() % fin;

	if(inicio == 0){
		printf("A");
	}
	else if(inicio == 1){
		printf("B");
	}
	if(inicio == 2){
		printf("C");
	}
	else if(inicio == 3){
		printf("D");
	}
	if(inicio == 4){
		printf("E");
	}
	else if(inicio == 5){
		printf("F");
	}
	if(inicio == 6){
		printf("G");
	}
	else if(inicio == 7){
		printf("H");
	}
	if(inicio == 8){
		printf("I");
	}
	else if(inicio == 9){
		printf("J");
	}
	if(inicio == 10){
		printf("K");
	}
	else if(inicio == 11){
		printf("L");
	}
	if(inicio == 12){
		printf("M");
	}
	else if(inicio == 13){
		printf("N");
	}
	if(inicio == 14){
		printf("O");
	}
	else if(inicio == 15){
		printf("P");
	}
	if(inicio == 16){
		printf("Q");
	}
	else if(inicio == 17){
		printf("R");
	}
	if(inicio == 18){
		printf("S");
	}
	else if(inicio == 19){
		printf("T");
	}
	if(inicio == 20){
		printf("U");
	}
	else if(inicio == 21){
		printf("V");
	}
	if(inicio == 22){
		printf("W");
	}
	else if(inicio == 23){
		printf("X");
	}
	if(inicio == 24){
		printf("Y");
	}
	else if(inicio == 25){
		printf("Z");
	}

	if(inicio == 26){
		printf("a");
	}
	else if(inicio == 27){
		printf("b");
	}
	if(inicio == 28){
		printf("c");
	}
	else if(inicio == 29){
		printf("d");
	}
	if(inicio == 30){
		printf("e");
	}
	else if(inicio == 31){
		printf("f");
	}
	if(inicio == 32){
		printf("g");
	}
	else if(inicio == 33){
		printf("h");
	}
	if(inicio == 34){
		printf("i");
	}
	else if(inicio == 35){
		printf("j");
	}
	if(inicio == 36){
		printf("k");
	}
	else if(inicio == 37){
		printf("l");
	}
	if(inicio == 38){
		printf("m");
	}
	else if(inicio == 39){
		printf("n");
	}
	if(inicio == 40){
		printf("o");
	}
	else if(inicio == 41){
		printf("p");
	}
	if(inicio == 42){
		printf("q");
	}
	else if(inicio == 43){
		printf("r");
	}
	if(inicio == 44){
		printf("s");
	}
	else if(inicio == 45){
		printf("t");
	}
	if(inicio == 46){
		printf("u");
	}
	else if(inicio == 47){
		printf("v");
	}
	if(inicio == 48){
		printf("w");
	}
	else if(inicio == 49){
		printf("x");
	}
	if(inicio == 50){
		printf("y");
	}
	else if(inicio == 51){
		printf("z");
	}
}
int readKey(void)//funcion que devuelve la tecla presionada
{
    return getch();
}
void readLine(void)//funcion para esperar una linea
{
    getche();
}
Override SystemCommand (Public *comand)//funcion que es igual a la funcion system
{
    system(comand);
}
int  Equls(const char *str1, const char *str2)//funcion para comparar strings
{
    if (strcmp(str1, str2) == 0)
	{
		printf("True");
		return true;
	}
	else
	{
		printf("False");
		return false;
	}
}
void createLines (int lines)//funcion para crear salto de lineas. Una maximo de 10
{
    if (lines == 0)
	{
		printf("");
	}
	else if (lines == 1)
	{
		printf("\n");
	}
	if (lines == 2)
	{
		printf("\n");
	}
	else if (lines == 3)
	{
		printf("\n\n\n");
	}
	if (lines == 4)
	{
		printf("\n\n\n\n");
	}
	else if (lines == 5)
	{
		printf("\n\n\n\n\n");
	}
	if (lines == 6)
	{
		printf("\n\n\n\n\n\n");
	}
	else if (lines == 7)
	{
		printf("\n\n\n\n\n\n\n");
	}
	if (lines == 8)
	{
		printf("\n\n\n\n\n\n\n\n");
	}
	else if (lines == 9)
	{
		printf("\n\n\n\n\n\n\n\n\n");
	}
	if (lines == 10)
	{
		printf("\n\n\n\n\n\n\n\n\n\n");
	}
}
int randInt(int number)//funcion para generar un numero aleatorio
{
    int start;
    srand(time(NULL));
	start = rand() % number;

	return number;
}
Override duplicText (String *text, int cantidad, int tipo)//funcion para duplicar el texto
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

let binary (char numero){

    unsigned int contador = 128;// 2 ^ (N - 1)

	for(contador; contador > 0; contador >>= 1){

	    if(contador & numero){

	        return 1;

	    } else{

	        return 0;

	    }
	}

}

#endif
