/*Este es un archivo para probar funciones y de mas cosas*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef int array;

typedef struct {
    array range;
    array i;
    array Array[100];
} array_int;

array_int *new_array_int(array_int *Array, ...) {
    
    array *Arra = malloc(Array->range * sizeof(array));
    va_list valist;
    va_start(valist, Array->range);
    for (Array->i = 0; Array->i < Array->range; Array->i++) {
        array x = va_arg(valist, array);
        Arra[Array->i] = x;
    }
    va_end(valist);
    for (Array->i = 0; Array->i < Array->range; Array->i++) {
        Array->Array[Array->i] = Arra[Array->i];
    }
    free(Arra);
    return Array;
    
}

int main (){

   array_int numeros;

   numeros.range = 3;
   numeros.Array[0] = *new_array_int(&numeros,9,2,7)->Array;
   
   for(array i = 0; i < numeros.range; i++){
         printf("[%i]",numeros.Array[i]);
   }
   
   printf("\n");

   numeros.range = 6;
   numeros.Array[0] = *new_array_int(&numeros,9,4,7,8,0,5)->Array;
   
   for(array i = 0; i < numeros.range; i++){
         printf("[%i]",numeros.Array[i]);
   }
   
   printf("\n");

   return 0;
}

