/*
    Se requiere que el usuario ingrese el la longituda en cm de un
    lado de un cuadrado y en base a esa longituda le entregamos un
    cuadrado.

    eje:
    ****
    *  *
    *  *
    ****
*/

#include <stdio.h>

int main()
{
    int longi;

    printf("Ingrese la longituda de un lado del cuadrado: ");
    scanf("%d", &longi);

    for (int columna = 1; columna <= longi; columna++)
    {
        for (int fila = 1; fila <= longi; fila++)
        {
            printf("* ");
        }
        printf("\n");
    }
}