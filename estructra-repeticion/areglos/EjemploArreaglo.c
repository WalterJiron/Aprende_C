/*
 * =============================================================================
 * Archivo     : EjemploArreaglo.c
 * Modulo      : Estructuras de Repeticion > Arreglos
 * Descripcion : Gestor interactivo de notas estudiantiles usando un arreglo
 *               unidimensional (1D) de longitud variable (VLA — Variable Length
 *               Array). El usuario define cuantas notas quiere gestionar y el
 *               programa las almacena en memoria para calcular estadisticas.
 *
 * Conceptos cubiertos:
 *   - Declaracion y uso de arreglos 1D en C
 *   - VLA (Variable Length Array): arreglo cuyo tamano se define en tiempo de
 *     ejecucion, disponible desde C99.
 *   - Recorrido de arreglos con bucle for (indexacion desde 0)
 *   - Validacion de entrada numerica con scanf y limpieza del buffer
 *   - Calculo de maximo, minimo y promedio sobre un arreglo
 *   - Menu interactivo con do-while y switch-case
 *
 * Compilar    : gcc -Wall -std=c99 EjemploArreaglo.c -o GestorNotas
 * Ejecutar    : ./GestorNotas
 *
 * Nota pedagogica:
 *   Los arreglos en C se indexan desde 0. Si declaras float notas[5], los
 *   indices validos son notas[0], notas[1], notas[2], notas[3], notas[4].
 *   Acceder a notas[5] es comportamiento indefinido (fuera de limites).
 * =============================================================================
 */

#include <stdio.h>

/*
 * Estructura del programa:
 *
 *   1. El usuario define cuantas notas va a gestionar (define el tamano del VLA).
 *   2. Se presenta un menu con 5 opciones:
 *        Opcion 1: Llenar el arreglo ingresando cada nota (0 a 100).
 *                  Durante el ingreso se actualiza la nota mas alta, la mas
 *                  baja y la suma acumulada.
 *        Opcion 2: Mostrar todas las notas ingresadas.
 *        Opcion 3: Mostrar la nota mas alta.
 *        Opcion 4: Mostrar la nota mas baja.
 *        Opcion 5: Calcular y mostrar el promedio.
 *        Opcion 0: Terminar el programa.
 */

int main()
{
    /* -----------------------------------------------------------------------
     * Variables de control del menu y del arreglo
     * op       : opcion elegida por el usuario en cada iteracion del menu
     * cantidadN: cantidad de notas que el usuario desea gestionar (tamano VLA)
     * -------------------------------------------------------------------- */
    int op, cantidadN;

    /* -----------------------------------------------------------------------
     * Variables de estadistica global
     * tidadN       : variable auxiliar no utilizada (puede eliminarse en una
     *                version limpia del codigo)
     * notasMasAlta : almacena el maximo encontrado; inicia en 0 porque toda
     *                nota valida es >= 0
     * notaMasBaja  : almacena el minimo encontrado; inicia en 9999.9 para que
     *                cualquier nota real sea menor al comparar
     * sumaN        : acumulador de todas las notas; tambien se usa como bandera
     *                para saber si ya se ingresaron notas (sumaN == 0 => no hay
     *                notas cargadas, asumiendo que todas las notas son > 0)
     * -------------------------------------------------------------------- */
    float notasMasAlta = 0.0, notaMasBaja = 9999.9, sumaN = 0.0;

    /* -----------------------------------------------------------------------
     * Bloque de lectura y validacion de la cantidad de notas
     *
     * Se usa while(1) con break condicional: es el patron "loop-and-a-half"
     * (bucle y medio). El bucle se rompe solo cuando scanf lee exactamente
     * un entero valido. Si el usuario escribe texto, scanf retorna 0 y se
     * limpia el buffer con while(getchar() != '\n').
     * -------------------------------------------------------------------- */
    while (1)
    {
        printf("Ingrese la cantidad de notas a guardar: ");

        if (scanf("%d", &cantidadN) == 1)
            break; /* Lectura exitosa: se sale del bucle de validacion */

        printf("\n\tSolo puedes ingresar numero.\n");

        /* Limpieza del buffer de entrada: descarta todos los caracteres
         * hasta el salto de linea inclusive, evitando que el scanf del
         * siguiente ciclo lea basura del buffer. */
        while (getchar() != '\n')
            ;
    }

    /* -----------------------------------------------------------------------
     * Declaracion del VLA (Variable Length Array)
     *
     * El tamano del arreglo se determina en tiempo de ejecucion con el valor
     * de cantidadN, que el usuario acaba de ingresar. Esta caracteristica
     * esta disponible desde C99 (opcionalmente en C11).
     *
     * Importante: los VLA se ubican en la pila (stack), por lo que cantidades
     * muy grandes pueden causar desbordamiento de pila. Para uso en produccion
     * se prefiere malloc/free con asignacion dinamica en el heap.
     * -------------------------------------------------------------------- */
    float notas[cantidadN]; /* Arreglo de notas: indices [0 .. cantidadN-1] */

    /* -----------------------------------------------------------------------
     * Ciclo principal del menu (do-while)
     *
     * Se usa do-while para garantizar que el menu se muestre al menos una vez
     * antes de evaluar la condicion de salida (op != 0).
     * -------------------------------------------------------------------- */
    do
    {
        printf("\n----------- MENU -----------\n");
        printf("1. Agregar nota.\n");
        printf("2. Mostrar todas las notas.\n");
        printf("3. La nota mas alta.\n");
        printf("4. La nota mas baja.\n");
        printf("5. Promedio de notas.\n");
        printf("0. Salir.\n");

        /* Validacion de la opcion del menu: mismo patron loop-and-a-half */
        while (1)
        {
            printf("Ingrese las opcion que va a realizar: ");

            if (scanf("%d", &op) == 1)
                break;

            printf("\n\tSolo puedes ingresar numero.\n");

            while (getchar() != '\n')
            {
            }
        }

        switch (op)
        {
        case 0:
            /* Salida limpia del programa */
            printf("\nSaliendo...\n");
            break;

        /* -------------------------------------------------------------------
         * Opcion 1: Cargar todas las notas en el arreglo
         *
         * Se recorre el arreglo completo con un for. Por cada nota se:
         *   a) Valida que sea un numero real (scanf retorna 1)
         *   b) Valida que este en el rango [0, 100]
         *   c) Actualiza notasMasAlta y notaMasBaja en tiempo real
         *   d) Acumula la nota en sumaN para calcular el promedio despues
         * ---------------------------------------------------------------- */
        case 1:
            for (int nota = 0; nota < cantidadN; nota++)
            {
                while (1)
                {
                    printf("Ingrese la %d nota: ", nota + 1);

                    if (scanf("%f", &notas[nota]) == 1)
                    {
                        /* Validacion de rango: la nota debe estar entre 0 y 100 */
                        if (notas[nota] >= 0 && notas[nota] <= 100)
                            break;

                        printf("\n\tLa nota solo puede estar entre 0 y 100\n");
                    }
                    else
                        printf("\n\tSolo puedes ingresar numero.\n");

                    while (getchar() != '\n')
                        ;
                }

                /* Actualizar maximo: si la nota actual supera al maximo
                 * conocido, la nota actual se convierte en el nuevo maximo */
                if (notas[nota] > notasMasAlta)
                    notasMasAlta = notas[nota];

                /* Actualizar minimo: si la nota actual es menor al minimo
                 * conocido, la nota actual se convierte en el nuevo minimo */
                if (notas[nota] < notaMasBaja)
                    notaMasBaja = notas[nota];

                printf("Nota guardada correctamente.\n");

                /* Acumular la nota para el calculo del promedio */
                sumaN += notas[nota];
            }

            break;

        /* -------------------------------------------------------------------
         * Opcion 2: Mostrar todas las notas
         *
         * Se usa sumaN == 0 como bandera para detectar si no se han cargado
         * notas. Esto funciona siempre que al menos una nota sea > 0. Para
         * una solucion mas robusta se podria usar una variable booleana
         * separada (int notasCargadas = 0).
         * ---------------------------------------------------------------- */
        case 2:
            if (sumaN == 0)
            {
                printf("\n\tTiene que ingresar las notas primero.\n");
                break;
            }

            printf("\n-------- Todas las notas --------\n");
            /* Recorrido secuencial del arreglo: indice va de 0 a cantidadN-1 */
            for (int nota = 0; nota < cantidadN; nota++)
            {
                /* %.2f muestra dos decimales para mayor claridad */
                printf("%d nota: %.2f\n", nota + 1, notas[nota]);
            }
            break;

        /* -------------------------------------------------------------------
         * Opcion 3: Mostrar la nota mas alta
         *
         * notasMasAlta fue calculada durante el ingreso (Opcion 1), no se
         * necesita recorrer el arreglo de nuevo.
         * ---------------------------------------------------------------- */
        case 3:
            if (sumaN == 0)
            {
                printf("\n\tTiene que ingresar las notas primero.\n");
                break;
            }

            printf("La nota mas alta es: %.2f\n", notasMasAlta);
            break;

        /* Opcion 4: Mostrar la nota mas baja */
        case 4:
            if (sumaN == 0)
            {
                printf("\n\tTiene que ingresar las notas primero.\n");
                break;
            }
            printf("La nota mas baja es: %.2f\n", notaMasBaja);
            break;

        /* -------------------------------------------------------------------
         * Opcion 5: Calcular el promedio
         *
         * Promedio = suma de todos los elementos / cantidad de elementos
         * sumaN ya contiene la suma acumulada desde la Opcion 1.
         * ---------------------------------------------------------------- */
        case 5:
            if (sumaN == 0)
            {
                printf("\n\tTiene que ingresar las notas primero.\n");
                break;
            }
            printf("El promedio de las notas es: %.2f\n", (sumaN / cantidadN));
            break;

        default:
            printf("La opcion no es valida.\n");
            break;
        }

    } while (op != 0); /* El menu se repite hasta que el usuario elige 0 */

    return 0;
}