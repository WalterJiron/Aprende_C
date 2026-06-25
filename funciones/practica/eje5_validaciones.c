/*
 * =============================================================================
 * Archivo     : eje5_validaciones.c
 * Modulo      : Funciones > Practica
 * Ejercicio   : 5 de 5
 * Descripcion : Biblioteca de funciones de validacion de entrada de datos
 *               reutilizables.
 *
 * Instrucciones:
 *   1. Declare e implemente las siguientes funciones de validacion:
 *      - `int validarInt(char mensaje[])`: Lee y valida cualquier entero.
 *      - `int validarIntEnRango(char mensaje[], int min, int max)`: Lee un entero
 *        y valida que este en el rango [min, max] inclusive.
 *      - `double validarDouble(char mensaje[])`: Lee y valida cualquier real (double).
 *      - `double validarDoublePositivo(char mensaje[])`: Lee y valida un double > 0.
 *      - `char validarCaracter(char mensaje[], char opA, char opB)`: Lee un caracter
 *        y solo acepta que sea igual a 'opA' o 'opB'.
 *      - `char validarSoN(char mensaje[])`: Lee y valida que sea 'S', 's', 'N' o 'n'.
 *   2. En todas las funciones, si la entrada del usuario falla la validacion,
 *      debe limpiar el buffer `while(getchar() != '\n');` y repetir la solicitud.
 *   3. En main(), cree un programa demostrativo que pruebe el funcionamiento de
 *      cada una de las funciones implementadas.
 *
 * Compilar : gcc -Wall -std=c99 eje5_validaciones.c -o eje5
 * Ejecutar : ./eje5
 * =============================================================================
 */

#include <stdio.h>

// TODO: 1. Declarar prototipos de todas las funciones de validacion.

int main()
{
    // TODO: 2. Implementar demo interactivo llamando a cada funcion de validacion
    // e imprimiendo el resultado obtenido para verificar que funcione.

    return 0;
}

// TODO: 3. Definir validarInt() y validarIntEnRango().

// TODO: 4. Definir validarDouble() y validarDoublePositivo().

// TODO: 5. Definir validarCaracter() y validarSoN().
