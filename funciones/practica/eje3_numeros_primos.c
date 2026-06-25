/*
 * =============================================================================
 * Archivo     : eje3_numeros_primos.c
 * Modulo      : Funciones > Practica
 * Ejercicio   : 3 de 5
 * Descripcion : Determina si un numero es primo usando una funcion booleana,
 *               y genera un listado de numeros primos hasta N.
 *
 * Instrucciones:
 *   1. Escriba la funcion `int esPrimo(int n)` que retorne 1 si n es primo,
 *      y 0 en caso contrario.
 *      - Pista de optimizacion: verifique divisores solo desde 2 hasta la raiz
 *        cuadrada de n (incluida la cabecera <math.h> y la funcion `sqrt()`).
 *   2. Escriba la funcion `int listarPrimos(int limite)` que recorra todos los
 *      numeros enteros desde 2 hasta `limite`, imprima en pantalla aquellos que sean
 *      primos usando `esPrimo(i)`, y retorne la cantidad total de primos encontrados.
 *   3. Escriba una funcion de lectura validada de enteros mayores a cero.
 *   4. En main(), provea un menu interactivo para:
 *      - Verificar un numero individual (usando esPrimo).
 *      - Mostrar todos los primos hasta N y el conteo total (usando listarPrimos).
 *
 * Compilar : gcc -Wall -std=c99 eje3_numeros_primos.c -o eje3 -lm
 * Ejecutar : ./eje3
 * =============================================================================
 */

#include <stdio.h>
#include <math.h>

// TODO: 1. Declarar los prototipos de las funciones.

int main()
{
    // TODO: 2. Implementar menu y las llamadas a las funciones.

    return 0;
}

// TODO: 3. Definir la funcion esPrimo(int n).
// Recuerde retornar 0 para n < 2, y probar divisores hasta sqrt(n).

// TODO: 4. Definir la funcion listarPrimos(int limite).
// Debe usar esPrimo() internamente e ir mostrando los resultados.

// TODO: 5. Definir la funcion de lectura validada para enteros positivos.
