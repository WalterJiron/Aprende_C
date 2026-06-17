/*
    CLASE 3 — Estructuras de Repetición (Bucles) en C
    Archivo: EjemploBuclesAnidados.c
    
    TEMA: Bucles Anidados y Generación de Patrones
    
    Este ejemplo demuestra:
      1. Cómo funciona un bucle for dentro de otro bucle for.
      2. La relación entre iteraciones externas (filas) e internas (columnas).
      3. Generación de patrones bidimensionales (cuadrado, triángulo, rectángulo hueco).
      4. Uso de variables dependientes (el bucle interno depende del externo).
    
    CASO PRÁCTICO: Generador de figuras geométricas con asteriscos.
    
    Compilar: gcc -Wall -std=c99 EjemploBuclesAnidados.c -o anidados
    Ejecutar: ./anidados
*/

#include <stdio.h>

int main() {
    printf("=== BUCLES ANIDADOS Y PATRONES ===\n\n");

    // ─────────────────────────────────────────────
    // PATRÓN 1: Cuadrado sólido (Independientes)
    // ─────────────────────────────────────────────
    
    printf("--- 1. Cuadrado Solido 5x5 ---\n");
    int tamano = 5;
    
    // BUCLE EXTERNO: Controla las FILAS (saltos de línea)
    for (int fila = 1; fila <= tamano; fila++) {
        
        // BUCLE INTERNO: Controla las COLUMNAS (asteriscos por fila)
        // Por CADA iteración del externo, el interno se ejecuta COMPLETAMENTE
        for (int col = 1; col <= tamano; col++) {
            printf("* ");
        }
        
        // Después de imprimir todos los asteriscos de la fila, saltamos de línea
        printf("\n");
    }
    printf("\n");

    // ─────────────────────────────────────────────
    // PATRÓN 2: Triángulo rectángulo (Dependiente)
    // ─────────────────────────────────────────────
    
    printf("--- 2. Triangulo Rectangulo ---\n");
    
    // Aquí el bucle interno DEPENDE del externo.
    // La condición del interno es 'col <= fila'.
    // Fila 1: col va hasta 1 (1 asterisco)
    // Fila 2: col va hasta 2 (2 asteriscos)
    // Fila 3: col va hasta 3 (3 asteriscos)...
    
    for (int fila = 1; fila <= tamano; fila++) {
        for (int col = 1; col <= fila; col++) {
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");

    // ─────────────────────────────────────────────
    // PATRÓN 3: Rectángulo hueco (Con condicionales)
    // ─────────────────────────────────────────────
    
    printf("--- 3. Rectangulo Hueco 5x7 ---\n");
    int filas = 5;
    int columnas = 7;
    
    for (int f = 1; f <= filas; f++) {
        for (int c = 1; c <= columnas; c++) {
            
            // ¿Cuándo imprimimos un asterisco?
            // - Si es la primera fila (f == 1)
            // - Si es la última fila (f == filas)
            // - Si es la primera columna (c == 1)
            // - Si es la última columna (c == columnas)
            if (f == 1 || f == filas || c == 1 || c == columnas) {
                printf("* ");
            } else {
                // Si estamos en el "interior", imprimimos espacios
                printf("  "); 
            }
        }
        printf("\n");
    }
    printf("\n");

    // ─────────────────────────────────────────────
    // PATRÓN 4: Tabla de Multiplicar (Procesamiento de datos)
    // ─────────────────────────────────────────────
    
    printf("--- 4. Tabla de Multiplicar (1 al 5) ---\n");
    
    // Encabezado
    printf("    |");
    for(int i = 1; i <= 5; i++) printf("%4d", i);
    printf("\n----+--------------------\n");
    
    // Contenido
    for (int fila = 1; fila <= 5; fila++) {
        
        // Columna de la izquierda
        printf("%3d |", fila);
        
        // Multiplicaciones
        for (int col = 1; col <= 5; col++) {
            // El formato %4d asegura que cada número ocupe 4 espacios,
            // alineando perfectamente las columnas
            printf("%4d", fila * col);
        }
        printf("\n");
    }

    printf("\n=== FIN DEL EJEMPLO ===\n");
    return 0;
}

/*
    SALIDA ESPERADA:

    === BUCLES ANIDADOS Y PATRONES ===

    --- 1. Cuadrado Solido 5x5 ---
    * * * * * 
    * * * * * 
    * * * * * 
    * * * * * 
    * * * * * 

    --- 2. Triangulo Rectangulo ---
    * 
    * * 
    * * * 
    * * * * 
    * * * * * 

    --- 3. Rectangulo Hueco 5x7 ---
    * * * * * * * 
    *           * 
    *           * 
    *           * 
    * * * * * * * 

    --- 4. Tabla de Multiplicar (1 al 5) ---
        |   1   2   3   4   5
    ----+--------------------
      1 |   1   2   3   4   5
      2 |   2   4   6   8  10
      3 |   3   6   9  12  15
      4 |   4   8  12  16  20
      5 |   5  10  15  20  25

    === FIN DEL EJEMPLO ===
*/
