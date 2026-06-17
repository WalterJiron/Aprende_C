/*
    if else

    if else if else

    (Condi) ? "Hola" : "Adios";


    en C el 1 hace refrencia al true y el 0 al flase
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    int lado1, lado2;

    while (true) {
        while (true) {
            printf("Ingrese el primer lado del rectangulo: ");

            if (scanf("%d", &lado1) == true)
                break;

            printf("\n\tSolo puedes ingresar numeros.\n");

            while (getchar() != '\n'){ }
        }

        while (1) {
            printf("Ingrese el segundo lado del rectangulo: ");

            if (scanf("%d", &lado2) == true)
                break;

            printf("\n\tSolo puedes ingresar numeros.\n");

            while (getchar() != '\n'){ }
        }

        if (lado1 > lado2 || lado2 > lado1)
            break;

        printf("\n\tEn un rectangulo un lado debe ser mayo que le otro.\n");
    }

    for (int columna = 1; columna <= lado1; columna++) {
        for (int fila = 0; fila < lado2; fila++) {

            // Forma tradional:
            // if (columna == 1 || columna == lado1) {
            //     printf("* ");
            // }
            // else if (fila == 0 || fila == lado2 - 1) {
            //     printf("* ");
            // }
            // else{
            //     printf("  ");
            // }

            // Forma con ternarios
            printf(
                (columna == 1 || columna == lado1) ? 
                "* " : 
                (fila == 0 || fila == lado2 - 1) ? 
                    "* ": 
                    "  "
            );
        }
        printf("\n");
    }

    return 0;
}