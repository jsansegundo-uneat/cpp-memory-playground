#include "hexview.h"
#include <stdio.h>

typedef unsigned char byte;

struct persona_data{
    char nombre[10];
    byte edad;
};

void dos_variables_locales();
void array_enteros();
void registro_datos();
void stack_vs_heap(int);

int main(){

    dos_variables_locales();

    array_enteros();

    registro_datos();

    stack_vs_heap(3);
}

void dos_variables_locales() {
    int numero1 = 1;
    int numero2 = 2;

    printf("\nDos variables locales => \n");
    hex_view_memory(&numero1);    
}

void array_enteros() {
    printf("\nArray de enteros => \n");
    
    int data[] = {1, 2, 3, 4};
    hex_view_memory(data);

    printf("\nRecorrido del array usando bytes => \n");
    
    for(int indice = 0; indice < 4; indice++){
        byte *puntero_base_array = (byte* ) data;
        byte *puntero_elemento = puntero_base_array + (indice * sizeof(int));

        int valor_elemento = (int) *puntero_elemento;

        printf("Elemento %i = %i\n", indice, valor_elemento);
    }
}

void registro_datos(){
    persona_data persona = {"Juan", 22};

    printf("\nEstructura de datos => \n");

    hex_view_memory(&persona);
}

void stack_vs_heap(int headp_data_len){
    printf("\nArray de enteros en stack => \n");

    // Memoria automatica => al salir de la función
    // se libera para reutilizarla. Tamaño definido
    // en tiempo de compilación.
    byte stack_data[] = {1, 2, 3};
    hex_view_memory(stack_data);

    printf("\nArray de enteros en stack => \n");
    
    // Memoria dinamica => Pide al sistema espacio
    // para albergar datos. Tamaño puede definirse
    // en tiempo de ejecución.
    byte *heap_data = new byte[headp_data_len];
    for(int i = 0; i < headp_data_len; i++){
        heap_data[i] = i;
    }

    hex_view_memory(&heap_data);

    // Debe liberarse cuando ya no se use. No es automatica
    // como el stack.
    delete[] heap_data;
}

