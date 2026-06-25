/*
 * =============================================================================
 * Archivo     : eje4_ordenamiento.c
 * Modulo      : Arreglos > Practica
 * Ejercicio   : 4 de 5
 * Descripcion : Ordenamiento de un arreglo de enteros usando el algoritmo
 *               Bubble Sort (ordenamiento burbuja). Se muestra el estado del
 *               arreglo despues de cada pasada completa para visualizar el
 *               proceso de ordenamiento.
 *
 * Instrucciones:
 *   1. Pida el tamano del arreglo, declarelo y cargue sus datos.
 *   2. Muestre el arreglo original.
 *   3. Aplique el algoritmo de ordenamiento burbuja.
 *   4. Muestre el arreglo despues de cada pasada externa.
 *   5. Adicione la bandera de optimizacion (huboSwap) para detener la ejecucion
 *      si el arreglo ya esta ordenado antes de completar todas las pasadas.
 *   6. Muestre el arreglo ordenado final.
 *
 * Compilar : gcc -Wall -std=c99 eje4_ordenamiento.c -o eje4
 * Ejecutar : ./eje4
 * =============================================================================
 */

#include <stdio.h>

void mostrar(int arr[], int n, char etiqueta[])
{
    printf("%s: ", etiqueta);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // TODO: 1. Leer cantidad de elementos y declarar el arreglo.

    // TODO: 2. Llenar el arreglo.

    // TODO: 3. Mostrar el arreglo original.

    // TODO: 4. Implementar Bubble Sort con optimizacion (bandera de swap)
    // y visualizacion del estado del arreglo en cada pasada.

    // TODO: 5. Mostrar el arreglo ordenado final.

    return 0;
}
