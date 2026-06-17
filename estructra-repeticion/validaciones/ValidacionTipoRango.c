/*
    MÓDULO COMPLEMENTARIO — Validación de Entrada en C
    Archivo: ValidacionTipoRango.c
    
    TEMA: Validación Completa de Tipos y Rangos
    
    Este programa demuestra:
      1. Cómo detectar cuando scanf falla (entrada no numérica).
      2. Cómo limpiar el buffer de entrada para evitar bucles infinitos.
      3. Validación dual: primero TIPO (¿es número?), luego RANGO (¿está en límites?).
      4. Validación de caracteres con espacio antes de %c.
      5. Limpieza manual del buffer de entrada con getchar().
      6. Uso de while (1) como estructura ideal para validaciones.
    
    CASO PRÁCTICO: Sistema de registro de un centro médico que
    no se rompe con entradas incorrectas del usuario.
    
    Compilar: gcc -Wall -std=c99 ValidacionTipoRango.c -o validacion_tipo
    Ejecutar: ./validacion_tipo
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("╔════════════════════════════════════════╗\n");
    printf("║   REGISTRO MEDICO - CENTRO DE SALUD   ║\n");
    printf("╚════════════════════════════════════════╝\n\n");

    // ─────────────────────────────────────────────
    // CAMPO 1: Edad del paciente (entero, 1-120)
    // ─────────────────────────────────────────────
    // Validación: TIPO (debe ser entero) + RANGO (1-120)
    
    int edad;
    int lecturaExitosa; // Almacena el retorno de scanf
    
    printf("--- DATOS DEL PACIENTE ---\n\n");
    
    while (1) {
        printf("Ingrese la edad del paciente (1-120): ");
        
        // scanf devuelve cuántos elementos leyó exitosamente.
        // Si pedimos %d y el usuario escribe "25", devuelve 1 (éxito).
        // Si pedimos %d y el usuario escribe "abc", devuelve 0 (fallo).
        lecturaExitosa = scanf("%d", &edad);
        
        if (lecturaExitosa != 1) {
            // CASO 1: El usuario no ingresó un número.
            // Los caracteres inválidos siguen en el buffer.
            printf("  >> Error: Debe ingresar un NUMERO entero.\n");
            printf("     Ejemplo valido: 25\n\n");
            while (getchar() != '\n'); // Limpiar los caracteres inválidos del buffer
            
        } else if (edad < 1 || edad > 120) {
            // CASO 2: Es un número pero fuera de rango.
            printf("  >> Error: La edad %d esta fuera del rango permitido (1-120).\n\n", edad);
            
        } else {
            // CASO 3: Lectura exitosa y en rango. Salimos del bucle.
            break;
        }
    }
    
    printf("  >> Edad aceptada: %d anios.\n\n", edad);

    // ─────────────────────────────────────────────
    // CAMPO 2: Peso del paciente (decimal, 0.5-500.0)
    // ─────────────────────────────────────────────
    // Validación: TIPO (debe ser float) + RANGO (0.5-500.0)
    
    float peso;
    
    while (1) {
        printf("Ingrese el peso en kg (0.5 - 500.0): ");
        lecturaExitosa = scanf("%f", &peso);
        
        if (lecturaExitosa != 1) {
            printf("  >> Error: Debe ingresar un numero decimal.\n");
            printf("     Ejemplo valido: 72.5\n\n");
            while (getchar() != '\n');
            
        } else if (peso < 0.5 || peso > 500.0) {
            printf("  >> Error: El peso %.2f esta fuera del rango (0.5-500.0).\n\n", peso);
            
        } else {
            break;
        }
    }
    
    printf("  >> Peso aceptado: %.2f kg.\n\n", peso);

    // ─────────────────────────────────────────────
    // CAMPO 3: Sexo del paciente (carácter: M o F)
    // ─────────────────────────────────────────────
    // Validación: Que sea uno de los caracteres permitidos.
    // Acepta mayúsculas y minúsculas.
    
    char sexo;
    
    while (1) {
        printf("Ingrese el sexo del paciente (M/F): ");
        
        // IMPORTANTE: El espacio antes de %c (" %c") le dice a scanf
        // que DESCARTE cualquier espacio en blanco residual del buffer
        // (incluyendo el '\n' que quedó de lecturas anteriores).
        // Sin este espacio, scanf leería el '\n' como el carácter.
        scanf(" %c", &sexo);
        
        // Verificamos si es un valor válido (M, m, F, f)
        if (sexo == 'M' || sexo == 'm' || sexo == 'F' || sexo == 'f') {
            break; // Valor válido, salimos del bucle
        } else {
            printf("  >> Error: Solo se acepta 'M' (masculino) o 'F' (femenino).\n");
            printf("     Usted ingreso: '%c'\n\n", sexo);
        }
    }
    
    // Normalizar a mayúscula para almacenamiento consistente
    if (sexo == 'm') sexo = 'M';
    if (sexo == 'f') sexo = 'F';
    
    printf("  >> Sexo aceptado: %c\n\n", sexo);

    // ─────────────────────────────────────────────
    // CAMPO 4: Tipo de sangre (carácter con validación múltiple)
    // ─────────────────────────────────────────────
    
    char tipoSangre;
    
    while (1) {
        printf("Ingrese tipo de sangre (A/B/O): ");
        scanf(" %c", &tipoSangre);
        
        if (tipoSangre == 'A' || tipoSangre == 'a' ||
            tipoSangre == 'B' || tipoSangre == 'b' ||
            tipoSangre == 'O' || tipoSangre == 'o') {
            break;
        } else {
            printf("  >> Error: Tipos validos son A, B u O.\n\n");
        }
    }
    
    if (tipoSangre >= 'a') tipoSangre -= 32; // Convertir a mayúscula (ASCII)
    printf("  >> Tipo de sangre aceptado: %c\n\n", tipoSangre);

    // ─────────────────────────────────────────────
    // RESUMEN DEL REGISTRO
    // ─────────────────────────────────────────────
    
    printf("╔════════════════════════════════════════╗\n");
    printf("║         REGISTRO COMPLETADO            ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║  Edad:          %3d anios              ║\n", edad);
    printf("║  Peso:          %6.2f kg               ║\n", peso);
    printf("║  Sexo:          %c                      ║\n", sexo);
    printf("║  Tipo de sangre: %c                     ║\n", tipoSangre);
    printf("╚════════════════════════════════════════╝\n");

    return 0;
}

/*
    SALIDA ESPERADA (con entradas inválidas y válidas):

    ╔════════════════════════════════════════╗
    ║   REGISTRO MEDICO - CENTRO DE SALUD   ║
    ╚════════════════════════════════════════╝

    --- DATOS DEL PACIENTE ---

    Ingrese la edad del paciente (1-120): abc
      >> Error: Debe ingresar un NUMERO entero.
         Ejemplo valido: 25

    Ingrese la edad del paciente (1-120): -5
      >> Error: La edad -5 esta fuera del rango permitido (1-120).

    Ingrese la edad del paciente (1-120): 150
      >> Error: La edad 150 esta fuera del rango permitido (1-120).

    Ingrese la edad del paciente (1-120): 35
      >> Edad aceptada: 35 anios.

    Ingrese el peso en kg (0.5 - 500.0): texto
      >> Error: Debe ingresar un numero decimal.
         Ejemplo valido: 72.5

    Ingrese el peso en kg (0.5 - 500.0): 72.5
      >> Peso aceptado: 72.50 kg.

    Ingrese el sexo del paciente (M/F): X
      >> Error: Solo se acepta 'M' (masculino) o 'F' (femenino).
         Usted ingreso: 'X'

    Ingrese el sexo del paciente (M/F): m
      >> Sexo aceptado: M

    Ingrese tipo de sangre (A/B/O): a
      >> Tipo de sangre aceptado: A

    ╔════════════════════════════════════════╗
    ║         REGISTRO COMPLETADO            ║
    ╠════════════════════════════════════════╣
    ║  Edad:           35 anios              ║
    ║  Peso:           72.50 kg              ║
    ║  Sexo:          M                      ║
    ║  Tipo de sangre: A                     ║
    ╚════════════════════════════════════════╝
*/
