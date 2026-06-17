/*
    CLASE 2 — Estructuras de Selección en C
    Archivo: Seleccion.c
    
    EJEMPLO PRINCIPAL: Sistema de Evaluación Académica
    
    Este programa demuestra:
      1. Uso de <stdbool.h> para variables booleanas (true/false).
      2. Operadores lógicos (&&, ||, !) en condiciones compuestas.
      3. El operador ternario (? :) para decisiones en una línea.
      4. Switch avanzado con tipo char y fall-through intencional.
    
    Compilar: gcc -Wall -std=c99 Seleccion.c -o seleccion
    Ejecutar: ./seleccion
*/

#include <stdio.h>
#include <stdbool.h> // Necesario para usar 'bool', 'true' y 'false' en C99+

int main() {
    printf("=== ESTRUCTURAS DE SELECCION ===\n\n");

    // ╔══════════════════════════════════════════════════════╗
    // ║  SECCIÓN 1: BOOLEANOS Y OPERADORES LÓGICOS          ║
    // ║  Demostración de if-else con condiciones compuestas  ║
    // ╚══════════════════════════════════════════════════════╝
    
    printf("--- EVALUACION ACADEMICA ---\n");
    
    float promedio;
    int asistencias;
    bool tieneBeca = false; // Variable booleana nativa (internamente es 0)

    printf("Ingrese el promedio del alumno (0.0 a 10.0): ");
    scanf("%f", &promedio);

    printf("Ingrese el numero de asistencias (0 a 100): ");
    scanf("%d", &asistencias);

    // Operador AND (&&): AMBAS condiciones deben ser verdaderas.
    // Para aprobar se necesita:
    //   - Promedio >= 6.0 (condición académica)
    //   - Asistencias >= 80 (condición de asistencia)
    // Si cualquiera falla, el resultado es falso.
    if (promedio >= 6.0 && asistencias >= 80) {
        printf("Resultado: El alumno ha APROBADO.\n");
        
        // Estructura ANIDADA: un if dentro de otro if.
        // Solo verificamos la beca si ya sabemos que aprobó.
        if (promedio >= 9.5) {
            tieneBeca = true; // Cambiamos la bandera booleana a verdadero
        }
    } else {
        printf("Resultado: El alumno ha REPROBADO.\n");
    }

    // Operador NOT (!): invierte el valor booleano.
    // !tieneBeca se lee como: "Si NO tiene beca"
    // Si tieneBeca es false (0), !false es true (1) → entra al bloque.
    // Si tieneBeca es true (1), !true es false (0) → va al else.
    if (!tieneBeca) {
        printf("El alumno no aplica para la beca este semestre.\n\n");
    } else {
        printf("Felicidades! El alumno aplica para una BECA de excelencia.\n\n");
    }

    // ╔══════════════════════════════════════════════════════╗
    // ║  SECCIÓN 2: EL OPERADOR TERNARIO (? :)              ║
    // ║  Un if-else compacto para decisiones simples         ║
    // ╚══════════════════════════════════════════════════════╝
    
    printf("--- OPERADOR TERNARIO ---\n");
    int edad;
    printf("Ingrese su edad: ");
    scanf("%d", &edad);

    // Sintaxis: (condicion) ? valor_si_verdadero : valor_si_falso
    //
    // Aquí usamos el ternario DIRECTAMENTE dentro de printf:
    // - Si (edad >= 18) es verdadero → sustituye por "Mayor"
    // - Si (edad >= 18) es falso    → sustituye por "Menor"
    // El %s espera una cadena de texto, y el ternario devuelve una.
    printf("Clasificacion legal: %s de edad.\n\n", (edad >= 18) ? "Mayor" : "Menor");

    // ╔══════════════════════════════════════════════════════╗
    // ║  SECCIÓN 3: SWITCH CON CARACTERES                   ║
    // ║  Fall-through intencional para emular OR lógico      ║
    // ╚══════════════════════════════════════════════════════╝
    
    // El switch es ideal para menús y opciones concretas (char o int).
    // NO funciona con float, double ni strings.
    
    printf("--- SWITCH CON CARACTERES ---\n");
    char categoriaLicencia;
    
    printf("Ingrese la categoria de su licencia de conducir (A, B, C): ");
    scanf(" %c", &categoriaLicencia); // Espacio antes de %c limpia el buffer

    switch (categoriaLicencia) {
        // FALL-THROUGH INTENCIONAL:
        // Si no ponemos 'break', la ejecución "cae" al siguiente caso.
        // Usamos esto a nuestro favor para aceptar mayúsculas Y minúsculas.
        // Funciona como un OR: case 'a' O case 'A' ejecutan el mismo código.
        
        case 'a':       // Si ingresó 'a' minúscula...
        case 'A':       // ...o 'A' mayúscula → ejecuta este bloque
            printf("Licencia Categoria A: Solo para Motocicletas.\n");
            break;      // break DETIENE la ejecución del switch aquí
            
        case 'b':
        case 'B':
            printf("Licencia Categoria B: Automoviles y vehiculos ligeros.\n");
            break;
            
        case 'c':
        case 'C':
            printf("Licencia Categoria C: Camiones de carga pesada.\n");
            break;
            
        default:
            // default se ejecuta si NINGÚN case coincidió.
            // Es buena práctica SIEMPRE incluirlo para manejar entradas inesperadas.
            printf("Categoria no reconocida por el sistema de transito.\n");
            break;
    }

    return 0;
}

/*
    SALIDA ESPERADA (ejemplo):
    
    === ESTRUCTURAS DE SELECCION ===

    --- EVALUACION ACADEMICA ---
    Ingrese el promedio del alumno (0.0 a 10.0): 9.8
    Ingrese el numero de asistencias (0 a 100): 95
    Resultado: El alumno ha APROBADO.
    Felicidades! El alumno aplica para una BECA de excelencia.

    --- OPERADOR TERNARIO ---
    Ingrese su edad: 17
    Clasificacion legal: Menor de edad.

    --- SWITCH CON CARACTERES ---
    Ingrese la categoria de su licencia de conducir (A, B, C): b
    Licencia Categoria B: Automoviles y vehiculos ligeros.
*/
