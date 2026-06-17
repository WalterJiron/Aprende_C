/*
    CLASE 2 — Estructuras de Selección en C
    Archivo: EjemploSwitchMenu.c
    
    TEMA: Menú Interactivo con switch-case
    
    Este ejemplo demuestra:
      1. Implementación de un menú de opciones con switch.
      2. Diferencia entre switch con int y con char.
      3. Manejo del caso default para entradas inválidas.
      4. Operaciones aritméticas condicionales (calculadora).
      5. Validación de operaciones peligrosas (división por cero).
    
    CASO PRÁCTICO: Calculadora básica con menú de operaciones.
    
    Compilar: gcc -Wall -std=c99 EjemploSwitchMenu.c -o menu
    Ejecutar: ./menu
*/

#include <stdio.h>

int main() {

    printf("╔════════════════════════════════════╗\n");
    printf("║      CALCULADORA BASICA EN C       ║\n");
    printf("╚════════════════════════════════════╝\n\n");

    // ─────────────────────────────────────────────
    // PASO 1: Lectura de los operandos
    // ─────────────────────────────────────────────
    
    float numero1, numero2;
    
    printf("Ingrese el primer numero:  ");
    scanf("%f", &numero1);
    
    printf("Ingrese el segundo numero: ");
    scanf("%f", &numero2);
    
    // ─────────────────────────────────────────────
    // PASO 2: Menú de operaciones
    // ─────────────────────────────────────────────
    
    printf("\n--- Seleccione una operacion ---\n");
    printf("  1. Suma (+)\n");
    printf("  2. Resta (-)\n");
    printf("  3. Multiplicacion (*)\n");
    printf("  4. Division (/)\n");
    printf("  5. Modulo (%%)\n");
    printf("Opcion: ");
    
    int opcion;
    scanf("%d", &opcion);
    
    // ─────────────────────────────────────────────
    // PASO 3: Switch para ejecutar la operación
    // ─────────────────────────────────────────────
    
    // Variable para almacenar el resultado.
    // La declaramos aquí para usarla en varios cases.
    float resultado;
    
    // Variable para el símbolo de la operación (para el resumen final).
    char simbolo;
    
    // Variable para indicar si la operación fue exitosa.
    int operacionValida = 1; // 1 = verdadero (asumimos que sí)
    
    printf("\n");
    
    switch (opcion) {
        case 1:
            // SUMA
            resultado = numero1 + numero2;
            simbolo = '+';
            printf("Operacion: SUMA\n");
            break;
            
        case 2:
            // RESTA
            resultado = numero1 - numero2;
            simbolo = '-';
            printf("Operacion: RESTA\n");
            break;
            
        case 3:
            // MULTIPLICACIÓN
            resultado = numero1 * numero2;
            simbolo = '*';
            printf("Operacion: MULTIPLICACION\n");
            break;
            
        case 4:
            // DIVISIÓN
            // Validación crítica: NO se puede dividir entre cero.
            // Esto causaría un comportamiento indefinido en el programa.
            if (numero2 == 0) {
                printf("ERROR: No se puede dividir entre cero.\n");
                printf("La division entre cero es matematicamente indefinida.\n");
                operacionValida = 0; // Marcamos como operación inválida
            } else {
                resultado = numero1 / numero2;
                simbolo = '/';
                printf("Operacion: DIVISION\n");
            }
            break;
            
        case 5:
            // MÓDULO (residuo de la división)
            // El módulo requiere enteros en C estándar, así que convertimos.
            if (numero2 == 0) {
                printf("ERROR: No se puede calcular el modulo con divisor cero.\n");
                operacionValida = 0;
            } else {
                // Casting a int para poder usar el operador %
                resultado = (float)((int)numero1 % (int)numero2);
                simbolo = '%';
                printf("Operacion: MODULO (con valores truncados a enteros)\n");
                printf("  Nota: %d %% %d\n", (int)numero1, (int)numero2);
            }
            break;
            
        default:
            // Se ejecuta si la opción no coincide con ningún case.
            // Es BUENA PRÁCTICA siempre incluir default para manejar
            // entradas inesperadas del usuario.
            printf("ERROR: Opcion '%d' no reconocida.\n", opcion);
            printf("Las opciones validas son del 1 al 5.\n");
            operacionValida = 0;
            break;
    }
    
    // ─────────────────────────────────────────────
    // PASO 4: Mostrar resultado (solo si fue válida)
    // ─────────────────────────────────────────────
    
    if (operacionValida) {
        printf("\n╔════════════════════════════════════╗\n");
        printf("║  %.2f %c %.2f = %.2f\n", numero1, simbolo, numero2, resultado);
        printf("╚════════════════════════════════════╝\n");
    } else {
        printf("\nLa operacion no pudo completarse.\n");
    }

    return 0;
}

/*
    SALIDA ESPERADA (ejemplo con suma):

    ╔════════════════════════════════════╗
    ║      CALCULADORA BASICA EN C       ║
    ╚════════════════════════════════════╝

    Ingrese el primer numero:  15.5
    Ingrese el segundo numero: 4.3

    --- Seleccione una operacion ---
      1. Suma (+)
      2. Resta (-)
      3. Multiplicacion (*)
      4. Division (/)
      5. Modulo (%)
    Opcion: 1

    Operacion: SUMA

    ╔════════════════════════════════════╗
    ║  15.50 + 4.30 = 19.80
    ╚════════════════════════════════════╝
    
    ─────────────────────────────────────
    
    SALIDA ESPERADA (ejemplo con división por cero):

    Ingrese el primer numero:  10
    Ingrese el segundo numero: 0
    Opcion: 4

    ERROR: No se puede dividir entre cero.
    La division entre cero es matematicamente indefinida.

    La operacion no pudo completarse.
*/
