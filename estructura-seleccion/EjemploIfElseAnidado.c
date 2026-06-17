/*
    CLASE 2 — Estructuras de Selección en C
    Archivo: EjemploIfElseAnidado.c
    
    TEMA: Escalera if-else if-else y Selección Anidada
    
    Este ejemplo demuestra:
      1. Escalera if-else if-else para clasificar por rangos numéricos.
      2. La importancia del ORDEN de las condiciones.
      3. Validación de datos de entrada antes de procesarlos.
      4. Estructuras if-else anidadas para decisiones dependientes.
    
    CASO PRÁCTICO: Sistema de clasificación de calificaciones con
    categorización adicional por rendimiento.
    
    Compilar: gcc -Wall -std=c99 EjemploIfElseAnidado.c -o anidado
    Ejecutar: ./anidado
*/

#include <stdio.h>
#include <stdbool.h>

int main() {

    printf("=== CLASIFICADOR DE CALIFICACIONES ===\n\n");

    float calificacion;
    
    printf("Ingrese la calificacion del estudiante (0 a 100): ");
    scanf("%f", &calificacion);
    
    // ─────────────────────────────────────────────
    // PASO 1: Validación de entrada
    // ─────────────────────────────────────────────
    // ANTES de procesar, verificamos que el dato sea válido.
    // Si no lo es, mostramos un error y terminamos con return 1.
    // (return 1 indica al sistema operativo que hubo un error)
    
    if (calificacion < 0 || calificacion > 100) {
        printf("ERROR: La calificacion debe estar entre 0 y 100.\n");
        printf("Usted ingreso: %.2f\n", calificacion);
        return 1; // Salimos del programa con código de error
    }

    // ─────────────────────────────────────────────
    // PASO 2: Escalera if-else if-else
    // ─────────────────────────────────────────────
    // 
    // REGLA FUNDAMENTAL: Las condiciones se evalúan DE ARRIBA HACIA ABAJO.
    // La PRIMERA condición que sea verdadera ejecuta su bloque y las demás
    // se IGNORAN completamente.
    //
    // Por eso, para rangos numéricos, debemos ir de MAYOR a MENOR:
    // - Si evaluamos >= 60 primero, una nota de 95 entraría ahí (incorrecto).
    // - Si evaluamos >= 90 primero, solo las notas de 90+ entran ahí (correcto).
    
    char letraCalificacion;
    
    if (calificacion >= 90) {
        // Rango: [90, 100]
        letraCalificacion = 'A';
        printf("Calificacion: A - EXCELENTE\n");
    } else if (calificacion >= 80) {
        // Rango: [80, 89.99] — Ya sabemos que es < 90 (por el else)
        letraCalificacion = 'B';
        printf("Calificacion: B - MUY BUENO\n");
    } else if (calificacion >= 70) {
        // Rango: [70, 79.99] — Ya sabemos que es < 80
        letraCalificacion = 'C';
        printf("Calificacion: C - BUENO\n");
    } else if (calificacion >= 60) {
        // Rango: [60, 69.99] — Ya sabemos que es < 70
        letraCalificacion = 'D';
        printf("Calificacion: D - REGULAR\n");
    } else {
        // Rango: [0, 59.99] — Ninguna condición anterior se cumplió
        letraCalificacion = 'F';
        printf("Calificacion: F - REPROBADO\n");
    }
    
    // ─────────────────────────────────────────────
    // PASO 3: Selección anidada
    // ─────────────────────────────────────────────
    // Dentro del resultado anterior, hacemos una sub-clasificación.
    // Esto demuestra cómo anidar if-else dentro de otro if-else.
    
    printf("\n--- Analisis detallado ---\n");
    
    bool aprobo = (calificacion >= 60);
    
    if (aprobo) {
        printf("Estado: APROBADO\n");
        
        // Sub-clasificación anidada para aprobados
        if (calificacion >= 95) {
            printf("Distincion: Cuadro de Honor\n");
            printf("Elegible para beca de excelencia.\n");
        } else if (calificacion >= 85) {
            printf("Distincion: Mención Honorífica\n");
        } else {
            printf("Distincion: Sin distincion especial\n");
        }
        
    } else {
        printf("Estado: REPROBADO\n");
        
        // Sub-clasificación anidada para reprobados
        if (calificacion >= 50) {
            printf("Observacion: Puede presentar examen de recuperacion.\n");
        } else if (calificacion >= 30) {
            printf("Observacion: Debe repetir el curso.\n");
        } else {
            printf("Observacion: Se recomienda tutoria especializada.\n");
        }
    }
    
    // ─────────────────────────────────────────────
    // PASO 4: Resumen con operador ternario
    // ─────────────────────────────────────────────
    
    printf("\n--- Resumen ---\n");
    printf("Calificacion numerica: %.1f\n", calificacion);
    printf("Calificacion letra:    %c\n", letraCalificacion);
    printf("Resultado final:       %s\n", aprobo ? "APROBADO" : "REPROBADO");

    return 0;
}

/*
    SALIDA ESPERADA (ejemplo con 92.5):

    === CLASIFICADOR DE CALIFICACIONES ===

    Ingrese la calificacion del estudiante (0 a 100): 92.5
    Calificacion: A - EXCELENTE

    --- Analisis detallado ---
    Estado: APROBADO
    Distincion: Sin distincion especial

    --- Resumen ---
    Calificacion numerica: 92.5
    Calificacion letra:    A
    Resultado final:       APROBADO
    
    ─────────────────────────────────────
    
    SALIDA ESPERADA (ejemplo con 45.0):

    === CLASIFICADOR DE CALIFICACIONES ===

    Ingrese la calificacion del estudiante (0 a 100): 45.0
    Calificacion: F - REPROBADO

    --- Analisis detallado ---
    Estado: REPROBADO
    Observacion: Puede presentar examen de recuperacion.

    --- Resumen ---
    Calificacion numerica: 45.0
    Calificacion letra:    F
    Resultado final:       REPROBADO
*/
