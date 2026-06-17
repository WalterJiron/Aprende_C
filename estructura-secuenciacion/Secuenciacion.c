/*
    CLASE 1 — Estructuras de Secuenciación en C
    Archivo: Secuenciacion.c
    
    EJEMPLO PRINCIPAL: Sistema de Registro de Paciente
    
    Este programa demuestra el flujo de ejecución secuencial completo:
      1. Declaración de variables de distintos tipos primitivos.
      2. Entrada de datos con scanf y el operador &.
      3. Procesamiento con variables de trabajo (auxiliares).
      4. Salida formateada con printf.
    
    Conceptos clave demostrados:
      - Tipos de datos: int, float, char
      - Especificadores de formato: %d, %f, %c
      - Variables de trabajo: edadCalculada, indiceMasaCorporal
      - Formato de precisión decimal: %.2f
      - Caracteres de escape: \n, \t
    
    Compilar: gcc -Wall -std=c99 Secuenciacion.c -o secuenciacion
    Ejecutar: ./secuenciacion
*/

#include <stdio.h> // Biblioteca estándar de entrada/salida (printf, scanf)

int main() {

    // ╔══════════════════════════════════════════════════════╗
    // ║  PASO 1: DECLARACIÓN DE VARIABLES                   ║
    // ║  Reservamos espacio en memoria para cada dato.       ║
    // ╚══════════════════════════════════════════════════════╝
    
    // --- Variables de ENTRADA (datos que proporcionará el usuario) ---
    
    // Variable entera (%d): para almacenar el año de nacimiento.
    // Solo la declaramos; su valor lo leeremos del teclado.
    int anioNacimiento;
    
    // Variable entera con inicialización: el año actual es un dato conocido.
    int anioActual = 2026;
    
    // Variables de punto flotante (%f): para datos con decimales.
    float pesoEnKg;
    float alturaEnMetros;
    
    // Variable de carácter (%c): almacena un único carácter.
    // Internamente se guarda como un número entero (tabla ASCII).
    // Ejemplo: 'A' = 65, 'a' = 97, '0' = 48
    char inicialNombre;
    
    // --- Variables de TRABAJO (auxiliares) ---
    // No son datos del usuario; las usamos para guardar resultados
    // de nuestros cálculos. Son herramientas del programador.
    int edadCalculada;
    float indiceMasaCorporal; // IMC = peso / (altura * altura)

    // ╔══════════════════════════════════════════════════════╗
    // ║  PASO 2: SALIDA INICIAL (Encabezado del programa)   ║
    // ╚══════════════════════════════════════════════════════╝
    
    // \n = salto de línea. Dos \n seguidos dejan una línea en blanco.
    printf("=== REGISTRO DE PACIENTE (SECUENCIACION) ===\n\n");

    // ╔══════════════════════════════════════════════════════╗
    // ║  PASO 3: ENTRADA DE DATOS                           ║
    // ║  Leemos datos del teclado con scanf.                 ║
    // ║  SIEMPRE usamos & antes de la variable en scanf.     ║
    // ╚══════════════════════════════════════════════════════╝
    
    // Lectura de un carácter (%c).
    // NOTA IMPORTANTE: El espacio antes de %c (" %c") le dice a scanf
    // que ignore cualquier carácter en blanco (espacios, tabulaciones,
    // saltos de línea) que hayan quedado en el buffer de entrada.
    // Sin ese espacio, scanf podría leer un '\n' residual como el carácter.
    printf("Ingrese la inicial de su nombre: ");
    scanf(" %c", &inicialNombre); 

    // Lectura de un entero (%d).
    // &anioNacimiento envía la DIRECCIÓN DE MEMORIA de la variable,
    // para que scanf sepa DÓNDE guardar el dato leído.
    printf("Ingrese su anio de nacimiento (ej. 1990): ");
    scanf("%d", &anioNacimiento);

    // Lectura de flotantes (%f).
    printf("Ingrese su peso en kilogramos (ej. 75.5): ");
    scanf("%f", &pesoEnKg);

    printf("Ingrese su altura en metros (ej. 1.75): ");
    scanf("%f", &alturaEnMetros);

    // ╔══════════════════════════════════════════════════════╗
    // ║  PASO 4: PROCESAMIENTO (Variables de trabajo)       ║
    // ║  Realizamos cálculos con los datos ingresados.       ║
    // ╚══════════════════════════════════════════════════════╝
    
    // Cálculo de edad aproximada.
    // El resultado se guarda en la variable de trabajo 'edadCalculada'.
    edadCalculada = anioActual - anioNacimiento;

    // Cálculo del Índice de Masa Corporal (IMC).
    // Fórmula: IMC = peso / (altura²)
    // Los paréntesis aseguran que la multiplicación se haga PRIMERO,
    // respetando la precedencia de operadores.
    indiceMasaCorporal = pesoEnKg / (alturaEnMetros * alturaEnMetros);

    // ╔══════════════════════════════════════════════════════╗
    // ║  PASO 5: SALIDA DE RESULTADOS                       ║
    // ║  Mostramos los datos procesados con formato.         ║
    // ╚══════════════════════════════════════════════════════╝
    
    printf("\n--- RESULTADOS DEL ANALISIS ---\n");
    
    // %c sustituye el valor del char 'inicialNombre'.
    printf("Paciente: %c\n", inicialNombre);
    
    // %d sustituye el valor del int 'edadCalculada'.
    printf("Edad aproximada: %d anios\n", edadCalculada);
    
    // %.2f muestra el float con exactamente 2 decimales.
    // Sin el .2, printf mostraría 6 decimales por defecto (ej. 75.500000).
    printf("Peso ingresado: %.2f kg\n", pesoEnKg);
    printf("Altura ingresada: %.2f m\n", alturaEnMetros);
    printf("Tu Indice de Masa Corporal (IMC) es: %.2f\n", indiceMasaCorporal);

    // ╔══════════════════════════════════════════════════════╗
    // ║  PASO 6: FINALIZACIÓN                               ║
    // ╚══════════════════════════════════════════════════════╝
    
    // return 0 indica al sistema operativo que el programa
    // terminó correctamente, sin errores.
    return 0;
}

/*
    SALIDA ESPERADA (ejemplo con datos ficticios):
    
    === REGISTRO DE PACIENTE (SECUENCIACION) ===

    Ingrese la inicial de su nombre: W
    Ingrese su anio de nacimiento (ej. 1990): 1995
    Ingrese su peso en kilogramos (ej. 75.5): 72.50
    Ingrese su altura en metros (ej. 1.75): 1.75

    --- RESULTADOS DEL ANALISIS ---
    Paciente: W
    Edad aproximada: 31 anios
    Peso ingresado: 72.50 kg
    Altura ingresada: 1.75 m
    Tu Indice de Masa Corporal (IMC) es: 23.67
*/
