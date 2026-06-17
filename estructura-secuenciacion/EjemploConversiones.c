/*
    CLASE 1 — Estructuras de Secuenciación en C
    Archivo: EjemploConversiones.c
    
    TEMA: Conversiones de Tipo (Casting) en C
    
    Este ejemplo demuestra:
      1. Conversión implícita (automática): C promueve tipos menores a mayores.
      2. Conversión explícita (casting manual): el programador fuerza la conversión.
      3. Pérdida de datos al convertir de mayor a menor precisión.
      4. Relación entre char y su valor numérico ASCII.
    
    Jerarquía de tipos (de menor a mayor):
      char → int → float → double
    
    Compilar: gcc -Wall -std=c99 EjemploConversiones.c -o conversiones
    Ejecutar: ./conversiones
*/

#include <stdio.h>

int main() {

    printf("=== CONVERSIONES DE TIPO (CASTING) EN C ===\n\n");

    // ─────────────────────────────────────────────
    // SECCIÓN 1: Conversión IMPLÍCITA (automática)
    // ─────────────────────────────────────────────
    
    printf("--- 1. Conversion implicita (automatica) ---\n");
    
    // Cuando mezclamos tipos en una operación, C convierte automáticamente
    // el tipo de MENOR rango al de MAYOR rango para no perder información.
    
    int entero = 10;
    float decimal = 3.5;
    
    // C ve: int + float → promueve 'entero' a float → hace la suma como float
    float resultado1 = entero + decimal;
    printf("%d + %.1f = %.2f  (int se promovió a float)\n", entero, decimal, resultado1);
    
    // Otro ejemplo: int * double → el int se promueve a double
    int cantidad = 3;
    double precioUnitario = 29.99;
    double total = cantidad * precioUnitario;
    printf("%d * %.2f = %.2f  (int se promovió a double)\n", cantidad, precioUnitario, total);
    
    // Asignar un int a un float: se convierte automáticamente
    float decimalDesdeEntero = 42;  // 42 → 42.000000
    printf("int 42 asignado a float: %.2f\n\n", decimalDesdeEntero);

    // ─────────────────────────────────────────────
    // SECCIÓN 2: Conversión EXPLÍCITA (casting)
    // ─────────────────────────────────────────────
    
    printf("--- 2. Conversion explicita (casting manual) ---\n");
    
    // A veces NECESITAMOS forzar la conversión para obtener el resultado correcto.
    // Sintaxis: (tipo_destino)variable
    
    int numerador = 7;
    int denominador = 2;
    
    // SIN casting: división entera (trunca los decimales)
    float sinCasting = numerador / denominador;
    printf("Sin casting:  %d / %d = %.2f  (division entera, pierde decimales)\n",
           numerador, denominador, sinCasting);
    
    // CON casting: forzamos que al menos un operando sea float
    float conCasting = (float)numerador / denominador;
    printf("Con casting:  (float)%d / %d = %.2f  (ahora si tiene decimales)\n",
           numerador, denominador, conCasting);
    
    // IMPORTANTE: El casting es TEMPORAL. La variable original NO cambia.
    printf("Despues del casting, numerador sigue siendo int: %d\n\n", numerador);

    // ─────────────────────────────────────────────
    // SECCIÓN 3: Pérdida de datos (truncamiento)
    // ─────────────────────────────────────────────
    
    printf("--- 3. Perdida de datos al convertir ---\n");
    
    // Convertir de float a int TRUNCA los decimales (no redondea).
    float valorDecimal = 9.87;
    int valorTruncado = (int)valorDecimal;  // 9.87 → 9 (se pierden los .87)
    printf("(int)%.2f = %d  (se truncan los decimales, NO se redondea)\n",
           valorDecimal, valorTruncado);
    
    // Otro ejemplo: un número grande en un tipo pequeño puede desbordarse
    int numeroGrande = 260;
    char caracterPequeno = (char)numeroGrande;
    // char solo puede almacenar valores de -128 a 127 (signed) o 0 a 255 (unsigned).
    // 260 no cabe, así que se produce un desbordamiento.
    printf("(char)%d = %d  (desbordamiento: 260 no cabe en un char)\n\n",
           numeroGrande, caracterPequeno);

    // ─────────────────────────────────────────────
    // SECCIÓN 4: char y valores ASCII
    // ─────────────────────────────────────────────
    
    printf("--- 4. Caracteres y valores ASCII ---\n");
    
    // Un char es, internamente, un número entero de 1 byte.
    // Podemos tratar un char como número o como carácter según el especificador.
    
    char letra = 'A';  // 'A' tiene el valor ASCII 65
    
    // Con %c imprimimos el CARÁCTER visual
    printf("Como caracter (%%c): %c\n", letra);
    
    // Con %d imprimimos su VALOR NUMÉRICO ASCII
    printf("Como numero   (%%d): %d\n", letra);
    
    // Podemos hacer aritmética con caracteres
    char letraMinuscula = letra + 32;  // 65 + 32 = 97 = 'a'
    printf("'%c' + 32 = '%c'  (de mayuscula a minuscula)\n", letra, letraMinuscula);
    
    // Podemos asignar un número directamente a un char
    char desdeNumero = 48;  // 48 en ASCII es '0' (el carácter cero)
    printf("El valor ASCII 48 es el caracter: '%c'\n", desdeNumero);
    
    // Recorrido de letras mayúsculas (A=65, B=66, ..., Z=90)
    printf("\nTabla ASCII parcial (A-F):\n");
    for (char c = 'A'; c <= 'F'; c++) {
        printf("  '%c' = %d\n", c, c);
    }
    
    // ─────────────────────────────────────────────
    // SECCIÓN 5: Caso práctico - Conversión de unidades
    // ─────────────────────────────────────────────
    
    printf("\n--- 5. Caso practico: Conversion de unidades ---\n");
    
    int totalSegundos;
    printf("Ingrese un tiempo en segundos: ");
    scanf("%d", &totalSegundos);
    
    // Convertimos segundos a horas, minutos y segundos restantes.
    // Usamos SOLO operadores enteros (/ y %) — no necesitamos decimales.
    int horas = totalSegundos / 3600;          // 3661 / 3600 = 1
    int minutosRestantes = (totalSegundos % 3600) / 60;  // 61 / 60 = 1
    int segundosRestantes = totalSegundos % 60; // 3661 % 60 = 1
    
    printf("%d segundos = %d hora(s), %d minuto(s), %d segundo(s)\n",
           totalSegundos, horas, minutosRestantes, segundosRestantes);

    printf("\n=== FIN DEL EJEMPLO ===\n");
    return 0;
}

/*
    SALIDA ESPERADA (con entrada 3661):

    === CONVERSIONES DE TIPO (CASTING) EN C ===

    --- 1. Conversion implicita (automatica) ---
    10 + 3.5 = 13.50  (int se promovió a float)
    3 * 29.99 = 89.97  (int se promovió a double)
    int 42 asignado a float: 42.00

    --- 2. Conversion explicita (casting manual) ---
    Sin casting:  7 / 2 = 3.00  (division entera, pierde decimales)
    Con casting:  (float)7 / 2 = 3.50  (ahora si tiene decimales)
    Despues del casting, numerador sigue siendo int: 7

    --- 3. Perdida de datos al convertir ---
    (int)9.87 = 9  (se truncan los decimales, NO se redondea)
    (char)260 = 4  (desbordamiento: 260 no cabe en un char)

    --- 4. Caracteres y valores ASCII ---
    Como caracter (%c): A
    Como numero   (%d): 65
    'A' + 32 = 'a'  (de mayuscula a minuscula)
    El valor ASCII 48 es el caracter: '0'

    Tabla ASCII parcial (A-F):
      'A' = 65
      'B' = 66
      'C' = 67
      'D' = 68
      'E' = 69
      'F' = 70

    --- 5. Caso practico: Conversion de unidades ---
    Ingrese un tiempo en segundos: 3661
    3661 segundos = 1 hora(s), 1 minuto(s), 1 segundo(s)

    === FIN DEL EJEMPLO ===
*/
