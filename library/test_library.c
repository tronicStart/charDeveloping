/*Este es un archivo de pruebas de charDevloping para probar las funciones de la libreria y detectar posibles errores*/
/*Este codigo solo genera letras aleatorias*/
#include "chardeveloping.h"

int main (){
    
    hiddenCursor(true); // oculta el cursor
    set_title("CharDevelopig : prueba print_random_abc()"); //cambia el nombre de la ventana terminal o simplemente usar la funciòn setTitle() es lo mismo
    
    while(true){ //bucle principal
        
        clear_screen(); // o str_cls() o system("cls"); estas funciones limpia la terminal
        set_color_text(8); //se cambia al color gris el texto
        center_text("Generacion de letras aleatorias\n");//centra el texto
        print_random_abc(); // o genere_random_abc() esta devuelve la letra generada de forma aleatoria
        print_random_abc();
        print_random_abc();
        print_random_abc();
        set_color_text(7); 
        readLine();//se espera una pulsasion de tecla
        
    }
    
    return 0;
}
