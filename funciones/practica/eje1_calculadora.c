/*
 * =============================================================================
 * Archivo     : eje1_calculadora.c
 * Modulo      : Funciones > Practica
 * Ejercicio   : 1 de 5
 * Descripcion : Calculadora modular con menu donde cada operacion matematica
 *               (sumar, restar, multiplicar, dividir) se implementa en una
 *               funcion independiente.
 *
 * Instrucciones:
 *   1. Declare los prototipos de las funciones al inicio del archivo:
 *      - double sumar(double, double);
 *      - double restar(double, double);
 *      - double multiplicar(double, double);
 *      - double dividir(double, double);
 *      - int mostrarMenu();
 *      - double leerDouble(char[]);
 *   2. Implemente la funcion mostrarMenu() que muestre las opciones (1. Sumar,
 *      2. Restar, 3. Multiplicar, 4. Dividir, 0. Salir) y valide que se ingrese un entero.
 *   3. Implemente leerDouble(char mensaje[]) para solicitar y validar numeros decimales.
 *   4. En main(), construya el bucle del menu. Cuando se seleccione una operacion:
 *      - Solicite los dos operandos utilizando leerDouble().
 *      - Si es division, valide que el divisor NO sea cero en main() antes de llamar
 *        a dividir(). Si es cero, muestre un mensaje de error.
 *      - Llame a la funcion correspondiente y muestre el resultado formateado.
 *   5. Nota: No utilice punteros para este ejercicio.
 *
 * Compilar : gcc -Wall -std=c99 eje1_calculadora.c -o eje1
 * Ejecutar : ./eje1
 * =============================================================================
 */

#include <stdio.h>

// TODO: 1. Declarar los prototipos de funciones.

int main()
{
    // TODO: 2. Implementar el bucle principal de control en main.
    // Leer la opcion del menu, los operandos, y procesar las operaciones
    // llamando a las funciones correspondientes.
    // Recuerde validar la division entre cero antes de llamar a dividir().

    return 0;
}

// TODO: 3. Definir la funcion mostrarMenu().

// TODO: 4. Definir la funcion leerDouble(char mensaje[]).

// TODO: 5. Definir las funciones para sumar, restar, multiplicar y dividir.
