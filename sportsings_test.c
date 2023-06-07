//Este es un archivo de pruebas de Sportsings para probar funciones antes de se agregadas
#include <stdio.h>

void print_random_abc();
char genere_random_abc();

int main (){

    //Funcion para inprimir una letra de forma aleatoria
    print_random_abc();
    //Funcion que devuelve una letra de forma aleatoria
    printf("\n%c\n",genere_random_abc());

    return 0;

}

void print_random_abc(){
    
    int i;
    
    srand(time(0));
    for (i = 0; i < 10; i++) {
        char letter = (rand() % 26) + 65;
        printf("%c\n", letter);
    }
    
}

char genere_random_abc(){
    
    int i;
    
    srand(time(0));
    for (i = 0; i < 10; i++) {
        char letter = (rand() % 26) + 65;
        return letter;
    }
    
}
