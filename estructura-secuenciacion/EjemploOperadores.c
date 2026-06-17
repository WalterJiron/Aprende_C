/*
    CLASE 1 — Estructuras de Secuenciación en C
    Archivo: EjemploOperadores.c
    
    TEMA: Operadores Aritméticos y Precedencia
    
    Este ejemplo demuestra:
      1. Los 5 operadores aritméticos: +, -, *, /, %
      2. La diferencia entre división ENTERA y división DECIMAL.
      3. La precedencia de operadores (quién se evalúa primero).
      4. El uso del operador módulo (%) para obtener residuos.
    
    Compilar: gcc -Wall -std=c99 EjemploOperadores.c -o operadores
    Ejecutar: ./operadores
*/

#include <stdio.h>

int main() {

    printf("=== OPERADORES ARITMETICOS Y PRECEDENCIA ===\n\n");

    // ─────────────────────────────────────────────
    // SECCIÓN 1: Los 5 operadores aritméticos
    // ─────────────────────────────────────────────
    
    int a = 17;
    int b = 5;
    
    printf("--- Operadores basicos con a = %d, b = %d ---\n", a, b);
    printf("Suma:           a + b = %d\n", a + b);     // 17 + 5 = 22
    printf("Resta:          a - b = %d\n", a - b);     // 17 - 5 = 12
    printf("Multiplicacion: a * b = %d\n", a * b);     // 17 * 5 = 85
    printf("Division:       a / b = %d\n", a / b);     // 17 / 5 = 3 (¡NO 3.4!)
    printf("Modulo:         a %% b = %d\n", a % b);    // 17 % 5 = 2 (residuo)
    // NOTA: Para imprimir el símbolo % en printf, se escribe %% (doble porcentaje).
    
    // ─────────────────────────────────────────────
    // SECCIÓN 2: División entera vs decimal
    // ─────────────────────────────────────────────
    
    printf("\n--- Division entera vs decimal ---\n");
    
    // PROBLEMA: Cuando ambos operandos son int, C hace DIVISIÓN ENTERA.
    // Esto significa que trunca (corta) los decimales, NO redondea.
    int dividendo = 7;
    int divisor = 2;
    
    // División entre dos enteros: resultado entero (truncado)
    int resultadoEntero = dividendo / divisor;
    printf("7 / 2 (ambos int)   = %d   (trunca los decimales)\n", resultadoEntero);
    
    // SOLUCIÓN: Si necesitamos el resultado decimal, al menos uno de los
    // operandos debe ser float o double.
    
    // Opción A: Usar variables float directamente
    float dividendoF = 7.0;
    float resultadoDecimal = dividendoF / divisor;
    printf("7.0 / 2 (float/int) = %.2f (ahora sí tiene decimales)\n", resultadoDecimal);
    
    // Opción B: Usar casting explícito (convertir temporalmente a float)
    float resultadoCast = (float)dividendo / divisor;
    printf("(float)7 / 2        = %.2f (casting explícito)\n", resultadoCast);
    
    // ─────────────────────────────────────────────
    // SECCIÓN 3: El operador módulo (%)
    // ─────────────────────────────────────────────
    
    printf("\n--- Operador modulo (%%) ---\n");
    printf("El modulo devuelve el RESIDUO de la division entera.\n\n");
    
    // Ejemplo práctico: Determinar si un número es par o impar
    int numero = 15;
    int residuo = numero % 2;
    printf("%d %% 2 = %d", numero, residuo);
    
    // Si el residuo de dividir entre 2 es 0, el número es par.
    // Si el residuo es 1, el número es impar.
    if (residuo == 0) {
        printf("  -> %d es PAR\n", numero);
    } else {
        printf("  -> %d es IMPAR\n", numero);
    }
    
    // Ejemplo práctico: Extraer dígitos de un número
    int numeroCompleto = 1234;
    int ultimoDigito = numeroCompleto % 10;    // 1234 % 10 = 4
    int penultimoDigito = (numeroCompleto / 10) % 10; // 123 % 10 = 3
    printf("\nNumero: %d\n", numeroCompleto);
    printf("Ultimo digito:     %d  (1234 %% 10)\n", ultimoDigito);
    printf("Penultimo digito:  %d  (1234 / 10 = 123, luego 123 %% 10)\n", penultimoDigito);
    
    // ─────────────────────────────────────────────
    // SECCIÓN 4: Precedencia de operadores
    // ─────────────────────────────────────────────
    
    printf("\n--- Precedencia de operadores ---\n");
    printf("Orden: () primero, luego *, /, %%, y finalmente +, -\n\n");
    
    // Sin paréntesis: * y / se evalúan ANTES que + y -
    int sinParentesis = 2 + 3 * 4;      // 2 + (3*4) = 2 + 12 = 14
    int conParentesis = (2 + 3) * 4;     // (2+3) * 4 = 5 * 4 = 20
    
    printf("2 + 3 * 4     = %d  (se evalúa 3*4 primero)\n", sinParentesis);
    printf("(2 + 3) * 4   = %d  (se evalúa 2+3 primero)\n", conParentesis);
    
    // Ejemplo realista: Cálculo de promedio
    // Si queremos el promedio de 3 notas, debemos usar paréntesis:
    float nota1 = 85.0, nota2 = 92.0, nota3 = 78.0;
    
    //  INCORRECTO (sin paréntesis):
    // nota1 + nota2 + nota3 / 3.0 → 85 + 92 + (78/3) = 85 + 92 + 26 = 203
    float promedioMal = nota1 + nota2 + nota3 / 3.0;
    
    //  CORRECTO (con paréntesis):
    // (nota1 + nota2 + nota3) / 3.0 → (85+92+78) / 3 = 255 / 3 = 85
    float promedioBien = (nota1 + nota2 + nota3) / 3.0;
    
    printf("\nNotas: %.0f, %.0f, %.0f\n", nota1, nota2, nota3);
    printf("Promedio MAL  (sin parentesis): %.2f  <- INCORRECTO\n", promedioMal);
    printf("Promedio BIEN (con parentesis): %.2f  <- CORRECTO\n", promedioBien);

    printf("\n=== FIN DEL EJEMPLO ===\n");
    return 0;
}

/*
    SALIDA ESPERADA:
    
    === OPERADORES ARITMETICOS Y PRECEDENCIA ===

    --- Operadores basicos con a = 17, b = 5 ---
    Suma:           a + b = 22
    Resta:          a - b = 12
    Multiplicacion: a * b = 85
    Division:       a / b = 3
    Modulo:         a % b = 2

    --- Division entera vs decimal ---
    7 / 2 (ambos int)   = 3   (trunca los decimales)
    7.0 / 2 (float/int) = 3.50 (ahora sí tiene decimales)
    (float)7 / 2        = 3.50 (casting explícito)

    --- Operador modulo (%) ---
    El modulo devuelve el RESIDUO de la division entera.

    15 % 2 = 1  -> 15 es IMPAR

    Numero: 1234
    Ultimo digito:     4  (1234 % 10)
    Penultimo digito:  3  (1234 / 10 = 123, luego 123 % 10)

    --- Precedencia de operadores ---
    Orden: () primero, luego *, /, %, y finalmente +, -

    2 + 3 * 4     = 14  (se evalúa 3*4 primero)
    (2 + 3) * 4   = 20  (se evalúa 2+3 primero)

    Notas: 85, 92, 78
    Promedio MAL  (sin parentesis): 203.00  <- INCORRECTO
    Promedio BIEN (con parentesis): 85.00   <- CORRECTO

    === FIN DEL EJEMPLO ===
*/
