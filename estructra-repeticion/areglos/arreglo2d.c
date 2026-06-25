/*
 * =============================================================================
 * Archivo     : arreglo2d.c
 * Modulo      : Estructuras de Repeticion > Arreglos
 * Descripcion : Sistema de registro de empleados usando arreglos paralelos y
 *               un arreglo bidimensional de caracteres para almacenar nombres.
 *               Demuestra como relacionar multiples arreglos por indice comun.
 *
 * Conceptos cubiertos:
 *   - Arreglos 2D de caracteres: char nombres[N][50]
 *   - Arreglos paralelos: varios arreglos 1D con el mismo indice representan
 *     los campos de un mismo registro (nombres[i], eddes[i], sueldos[i])
 *   - Lectura de cadenas con espacios: scanf(" %[^\n]", ...)
 *   - Contador de registros activos (contE)
 *   - VLA (Variable Length Array): tamano definido en tiempo de ejecucion
 *
 * Compilar    : gcc -Wall -std=c99 arreglo2d.c -o GestorEmpleados
 * Ejecutar    : ./GestorEmpleados
 *
 * Nota sobre arreglos paralelos:
 *   Se usan tres arreglos separados para los datos de cada empleado. El indice
 *   comun 'i' relaciona los datos: nombres[i], eddes[i], sueldos[i] pertenecen
 *   al mismo empleado. La alternativa mas robusta es usar struct.
 *
 * Nota sobre char nombres[cantiE][50]:
 *   La primera dimension es la cantidad de empleados.
 *   La segunda dimension (50) es el largo maximo de cada nombre incluyendo '\0'.
 * =============================================================================
 */

#include <stdio.h>

int main()
{
    /* cantiE: capacidad maxima; op: opcion menu; contE: empleados registrados */
    int cantiE, op, contE = 0;

    /* Leer cantidad de empleados con validacion de rango (debe ser > 0) */
    while (1)
    {
        printf("Ingrese la cantidad de personas: ");

        if (scanf("%d", &cantiE) == 1)
        {
            if (cantiE > 0)
                break;

            printf("\n\tLa cantidad debe ser mayor a 0\n");
        }
        else
            printf("\n\tSolo puede ingresar numeros\n");

        while (getchar() != '\n')
            ;
    }

    /* -----------------------------------------------------------------------
     * Arreglos paralelos (VLA)
     *
     * El indice 'i' relaciona los tres arreglos:
     *   nombres[i] = nombre del empleado i
     *   eddes[i]   = edad  del empleado i
     *   sueldos[i] = sueldo del empleado i
     *
     * char nombres[cantiE][50]:
     *   Reserva espacio para 'cantiE' cadenas de hasta 49 chars + '\0'.
     * -------------------------------------------------------------------- */
    char nombres[cantiE][50];  /* Arreglo 2D: cada fila es un nombre         */
    int eddes[cantiE];          /* Edades de los empleados                    */
    float sueldos[cantiE];      /* Sueldos de los empleados                   */

    do
    {
        printf("\n--------- MENU ---------\n");
        printf("1. Ingresar empleados.\n");
        printf("2. Listado de empleados.\n");
        printf("0. Salir.\n");

        while (1)
        {
            printf("Ingrese la opcion que va a realizar: ");

            if (scanf("%d", &op))
                break;

            printf("\n\tSolo puede ingresar numeros\n");

            while (getchar() != '\n')
                ;
        }

        switch (op)
        {
        case 0:
            printf("\nSaliendo...\n");
            break;

        /* -------------------------------------------------------------------
         * Caso 1: Ingresar empleados
         *
         * Un do-while interno permite ingresar varios empleados seguidos.
         * Despues de cada registro se pregunta S/N para continuar.
         *
         * scanf(" %[^\n]", &nombres[contE]):
         *   - El espacio inicial consume el '\n' del scanf anterior.
         *   - %[^\n] lee todo hasta el salto de linea (permite espacios).
         * ---------------------------------------------------------------- */
        case 1:
            if (contE == cantiE)
            {
                printf("Ya se ingresaron todos los empleados.\n");
                break;
            }

            char opSN;
            do
            {
                /* Nombre: permite espacios (ej: "Ana Torres") */
                printf("Ingrese su nombre: ");
                scanf(" %[^\n]", nombres[contE]);

                /* Edad: validar que sea un entero entre 0 y 150 */
                while (1)
                {
                    printf("Ingrese su edad: ");
                    if (scanf("%d", &eddes[contE]) == 1)
                    {
                        if (eddes[contE] >= 0 && eddes[contE] <= 150)
                            break;

                        printf("\n\tLa edad debe estar entre 0 y 150\n");
                    }
                    else
                        printf("\n\tSolo puedes ingresar numeros.\n");

                    while (getchar() != '\n')
                        ;
                }

                /* Sueldo: validar que sea un numero positivo */
                while (1)
                {
                    printf("Ingrese su sueldo: ");

                    if (scanf("%f", &sueldos[contE]) == 1)
                    {
                        if (sueldos[contE] > 0)
                            break;

                        printf("\n\tEl sueldo debe ser mayor que 0\n");
                    }
                    else
                        printf("\n\tSolo puedes ingresar numero.\n");

                    while (getchar() != '\n')
                        ;
                }

                /* Incrementar el contador de empleados efectivos */
                ++contE;

                if (contE == cantiE)
                {
                    printf("Ya se ingresaron todos los empleados.\n");
                    break;
                }

                /* Preguntar si desea ingresar otro empleado (S/N) */
                while (1)
                {
                    printf("Quiere ingresar otro empleado? (S/N): ");
                    scanf(" %c", &opSN);

                    if (opSN == 's' || opSN == 'S' || opSN == 'n' || opSN == 'N')
                    {
                        while (getchar() != '\n')
                            ;
                        break;
                    }

                    printf("\n\tSolo puedes ingresar S o N\n");

                    while (getchar() != '\n')
                        ;
                }

            } while (opSN == 's' || opSN == 'S');

            break;

        /* -------------------------------------------------------------------
         * Caso 2: Mostrar listado
         *
         * Se recorren los arreglos paralelos hasta contE (no hasta cantiE),
         * ya que solo los primeros contE indices tienen datos validos.
         * ---------------------------------------------------------------- */
        case 2:
            if (contE == 0)
            {
                printf("\n\tNo tienes empleados a mostrar.\n");
                break;
            }

            printf("\n------------------------ Listado de empleados ------------------------\n");
            for (int emple = 0; emple < contE; emple++)
            {
                /* Los tres arreglos se acceden con el mismo indice 'emple' */
                printf(
                    "\t%d. %s. tiene la edad de %d y gana %.3f\n",
                    emple + 1, nombres[emple], eddes[emple],
                    sueldos[emple]);
            }

            break;

        default:
            printf("\n\tOpcion invalida.");
            break;
        }

    } while (op != 0);

    return 0;
}