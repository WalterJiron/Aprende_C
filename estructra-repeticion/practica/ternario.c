#include <stdio.h>

int main(int argc, char const *argv[])
{
    int edad;
    char genro;

    printf("Ingrese la edad: ");
    scanf("%d", &edad);

    printf("Imgrese su genero: ");
    scanf(" %c", &genro);

    printf(
        (edad >= 18) ? (genro == 'M' || genro == 'm') ? "Mayor M\n" : "Mayor F\n" : (genro == 'F' || genro == 'f') ? "Menor F\n"
                                                                                                                   : "Menor M\n");
    return 0;
}
