/*
    CLASE 3 — Estructuras de Repetición (Bucles) en C
    Archivo: EjemploWhileValidacion.c
    
    TEMA: Validación de Entrada con while(1)
    
    Este ejemplo demuestra:
      1. El uso del bucle while(1) con break, que es el patrón ideal para validaciones en C.
      2. Validaciones robustas de entrada (rangos de números).
      3. Limpieza manual del buffer de entrada al fallar scanf.
      4. Creación de un menú interactivo robusto que nunca se rompe.
    
    CASO PRÁCTICO: Sistema y menú que no se cuelgan si el usuario ingresa texto.
    
    Compilar: gcc -Wall -std=c99 EjemploWhileValidacion.c -o validacion
    Ejecutar: ./validacion
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("=== VALIDACION ROBUSTA CON WHILE(1) ===\n\n");

    int edad;
    int resultadoLectura;
    
    // ─────────────────────────────────────────────
    // CASO 1: Validación de Rango y Tipo
    // ─────────────────────────────────────────────
    
    printf("--- 1. Validacion de Edad (18 a 120) ---\n");
    
    // while(1) es perfecto aquí: iteramos infinitamente hasta que
    // los datos sean correctos, y usamos 'break' para salir.
    while (1) {
        printf("Por favor, ingrese su edad (18-120): ");
        
        // scanf devuelve la cantidad de elementos leídos correctamente.
        resultadoLectura = scanf("%d", &edad);
        
        if (resultadoLectura != 1) {
            printf("Error: Debe ingresar un numero entero valido.\n\n");
            // Limpiar buffer
            while (getchar() != '\n');
            
        } else if (edad < 18 || edad > 120) {
            printf("Error: La edad %d esta fuera del rango permitido.\n\n", edad);
            
        } else {
            // Lectura correcta y en rango. Salimos del bucle.
            break;
        }
    }
    
    printf(">> Edad aceptada: %d anios.\n\n", edad);

    // ─────────────────────────────────────────────
    // CASO 2: Menú Interactivo Completo
    // ─────────────────────────────────────────────
    
    printf("--- 2. Menu Interactivo ---\n");
    
    int opcion;
    bool salir = false;
    
    while (!salir) {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Ver informacion de perfil\n");
        printf("2. Cambiar contrasenia\n");
        printf("3. Salir del sistema\n");
        
        // Validamos la lectura del menú con un while(1) interno
        while (1) {
            printf("Seleccione una opcion: ");
            resultadoLectura = scanf("%d", &opcion);
            
            if (resultadoLectura != 1) {
                printf("\nEntrada invalida. Ingrese un numero del 1 al 3.\n\n");
                while (getchar() != '\n'); // Limpiar buffer
            } else if (opcion < 1 || opcion > 3) {
                printf("\n> Opcion %d no es valida. Intente de nuevo.\n\n", opcion);
            } else {
                break; // Opción válida
            }
        }
        
        // Evaluamos la opción elegida
        switch (opcion) {
            case 1:
                printf("\n> Mostrando informacion de perfil (Edad: %d)\n", edad);
                break;
            case 2:
                printf("\n> Procesando cambio de contrasenia...\n");
                break;
            case 3:
                printf("\n> Guardando datos... Saliendo del sistema.\n");
                salir = true;
                break;
        }
        
    } // El bucle se repite mientras NO queramos salir

    printf("\n=== FIN DEL PROGRAMA ===\n");
    return 0;
}

/*
    SALIDA ESPERADA:
    
    === VALIDACION ROBUSTA CON WHILE(1) ===

    --- 1. Validacion de Edad (18 a 120) ---
    Por favor, ingrese su edad (18-120): hola
    Error: Debe ingresar un numero entero valido.

    Por favor, ingrese su edad (18-120): 15
    Error: La edad 15 esta fuera del rango permitido.

    Por favor, ingrese su edad (18-120): 25
    >> Edad aceptada: 25 anios.

    --- 2. Menu Interactivo ---

    --- MENU PRINCIPAL ---
    1. Ver informacion de perfil
    2. Cambiar contrasenia
    3. Salir del sistema
    Seleccione una opcion: texto
    Entrada invalida. Ingrese un numero del 1 al 3.

    Seleccione una opcion: 4
    > Opcion 4 no es valida. Intente de nuevo.

    Seleccione una opcion: 1
    > Mostrando informacion de perfil (Edad: 25)

    --- MENU PRINCIPAL ---
    1. Ver informacion de perfil
    2. Cambiar contrasenia
    3. Salir del sistema
    Seleccione una opcion: 3
    > Guardando datos... Saliendo del sistema.

    === FIN DEL PROGRAMA ===
*/
