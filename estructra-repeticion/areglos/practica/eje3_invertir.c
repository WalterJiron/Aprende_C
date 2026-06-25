/*
 * =============================================================================
 * Archivo     : eje3_invertir.c
 * Modulo      : Arreglos > Practica
 * Ejercicio   : 3 de 5
 * Descripcion : Invertir un arreglo en su lugar (in-place) sin usar un arreglo
 *               auxiliar.
 *
 * Instrucciones:
 *   1. Solicite la cantidad de enteros, valide e inicialice el VLA.
 *   2. Llene el arreglo con datos ingresados por el usuario.
 *   3. Muestre el arreglo original en una sola linea.
 *   4. Invierta el arreglo en su lugar (in-place) usando dos indices:
 *      uno desde el inicio (0) y otro desde el final (n-1), e intercambie
 *      los valores correspondientes usando una variable auxiliar (temp)
 *      hasta que se crucen en el centro.
 *   5. Muestre el arreglo resultante para verificar la inversion.
 *
 * Compilar : gcc -Wall -std=c99 eje3_invertir.c -o eje3
 * Ejecutar : ./eje3
 * =============================================================================
 */

#include <stdio.h>

// Funcion opcional para imprimir un arreglo en una linea
void imprimirArreglo(int arr[], int n, char etiqueta[])
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
    // TODO: 1. Solicitar cantidad de elementos y declarar el arreglo.

    // TODO: 2. Llenar el arreglo con datos del usuario.

    // TODO: 3. Mostrar el arreglo original.

    // TODO: 4. Implementar algoritmo de inversion in-place (dos indices y swap).

    // TODO: 5. Mostrar el arreglo invertido.

    return 0;
}
