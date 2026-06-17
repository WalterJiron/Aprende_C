/*
    CLASE 3 — Estructuras de Repetición (Bucles) en C
    Archivo: Repeticion.c
    
    EJEMPLO PRINCIPAL: Roles de Variables en Bucles
    
    Este programa demuestra de forma práctica los tres roles fundamentales
    que cumplen las variables dentro de los bucles:
      1. Variables CONTADORAS (bucle for) — cuentan iteraciones.
      2. Variables ACUMULADORAS (sumatoria) — recolectan valores variables.
      3. Variables BANDERA/Centinela (bucle while + bool) — controlan cuándo parar.
    
    También demuestra:
      - Alteración de flujo con break y continue.
      - Uso de stdbool.h para banderas booleanas.
    
    Compilar: gcc -Wall -std=c99 Repeticion.c -o repeticion
    Ejecutar: ./repeticion
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("=== ROLES DE VARIABLES EN BUCLES ===\n\n");

    // ╔══════════════════════════════════════════════════════╗
    // ║  SECCIÓN 1: ACUMULADORES Y CONTADORES (Bucle FOR)   ║
    // ║  Caso: Calcular el peso total de 3 paquetes.         ║
    // ╚══════════════════════════════════════════════════════╝
    
    printf("--- EJERCICIO DE SUMATORIA ---\n");
    
    int cantidadPaquetes = 3;   // Cuántas veces se repetirá el ciclo
    float pesoActual;           // Variable de entrada (cambia cada iteración)
    
    // REGLA DE ORO: Los acumuladores SIEMPRE se inicializan ANTES del bucle.
    // Para sumas → inicializar en 0.0
    // Para productos (multiplicaciones) → inicializar en 1.0
    // Si no se inicializa, acumulará "basura" de memoria.
    float acumuladorPesoTotal = 0.0; 
    
    // Bucle FOR: ideal porque sabemos exactamente cuántas veces repetir (3).
    // 'i' es la variable CONTADORA: va de 1 a 3, incrementando en 1.
    //
    // Flujo: i=1 → condición(1<=3? sí) → cuerpo → i++ → i=2 → ...
    for (int i = 1; i <= cantidadPaquetes; i++) {
        printf("Ingrese el peso del paquete %d en kg: ", i);
        scanf("%f", &pesoActual);
        
        // ACUMULADOR en acción:
        // acumuladorPesoTotal += pesoActual
        // Equivale a: acumuladorPesoTotal = acumuladorPesoTotal + pesoActual
        //
        // Iteración 1: 0.0 + 2.5 = 2.5
        // Iteración 2: 2.5 + 3.0 = 5.5
        // Iteración 3: 5.5 + 1.5 = 7.0
        acumuladorPesoTotal += pesoActual; 
    }
    
    printf("El peso total acumulado es: %.2f kg\n\n", acumuladorPesoTotal);


    // ╔══════════════════════════════════════════════════════╗
    // ║  SECCIÓN 2: BANDERAS / CENTINELAS (Bucle WHILE)     ║
    // ║  Caso: Cajero automático que opera hasta que el      ║
    // ║  usuario decide salir.                               ║
    // ╚══════════════════════════════════════════════════════╝
    
    printf("--- EJERCICIO DE CAJERO (USO DE BANDERAS) ---\n");
    
    // La BANDERA (flag) es una variable booleana que indica si un evento
    // ha ocurrido. Aquí controla cuándo el usuario quiere salir.
    bool salirDelSistema = false;   // Inicia en false: el usuario NO quiere salir
    int opcionMenu;
    
    // WHILE: El bucle continúa MIENTRAS la bandera sea false.
    // !salirDelSistema se lee: "Mientras NO salir del sistema"
    // Cuando salirDelSistema cambie a true, !true = false → el bucle termina.
    while (!salirDelSistema) {
        printf("1. Consultar Saldo\n");
        printf("2. Retirar Efectivo\n");
        printf("3. Salir del Cajero\n");
        printf("Seleccione opcion: ");
        scanf("%d", &opcionMenu);
        
        if (opcionMenu == 1) {
            printf("Su saldo es $500.00\n\n");
        } else if (opcionMenu == 2) {
            printf("Retiro procesado.\n\n");
        } else if (opcionMenu == 3) {
            // El usuario eligió salir → cambiamos la bandera.
            // En la SIGUIENTE evaluación de la condición del while,
            // !true será false, y el bucle terminará.
            salirDelSistema = true;
            printf("Saliendo del sistema...\n\n");
        } else {
            printf("Opcion invalida.\n\n");
        }
    }


    // ╔══════════════════════════════════════════════════════╗
    // ║  SECCIÓN 3: CONTROL DE FLUJO: BREAK Y CONTINUE     ║
    // ║  Caso: Procesar números impares, abortar al          ║
    // ║  encontrar el 5.                                     ║
    // ╚══════════════════════════════════════════════════════╝
    
    printf("--- EJERCICIO DE BREAK Y CONTINUE ---\n");
    
    for (int contador = 1; contador <= 10; contador++) {
        
        // CONTINUE: Si el número es par, saltamos esta iteración.
        // El operador % (módulo) devuelve el residuo de la división.
        // Si contador % 2 == 0, el número es par.
        if (contador % 2 == 0) {
            // continue SALTA directamente a la actualización (contador++)
            // y luego a evaluar la condición. NO ejecuta lo que está abajo.
            continue; 
        }
        
        // Esta línea SOLO se ejecuta para números impares
        // (porque los pares fueron "saltados" por continue)
        printf("Procesando numero impar: %d\n", contador);
        
        // BREAK: Si encontramos el 5, terminamos el bucle completamente.
        if (contador == 5) {
            printf("Numero 5 encontrado! ABORTANDO BUCLE CON BREAK.\n");
            // break DESTRUYE el bucle for. La ejecución salta a la línea
            // inmediatamente después del cierre del for (}).
            // No importa que el contador todavía no haya llegado a 10.
            break; 
        }
    }

    printf("\nFin del programa.\n");
    return 0;
}

/*
    SALIDA ESPERADA (con datos de ejemplo):

    === ROLES DE VARIABLES EN BUCLES ===

    --- EJERCICIO DE SUMATORIA ---
    Ingrese el peso del paquete 1 en kg: 2.5
    Ingrese el peso del paquete 2 en kg: 3.0
    Ingrese el peso del paquete 3 en kg: 1.5
    El peso total acumulado es: 7.00 kg

    --- EJERCICIO DE CAJERO (USO DE BANDERAS) ---
    1. Consultar Saldo
    2. Retirar Efectivo
    3. Salir del Cajero
    Seleccione opcion: 1
    Su saldo es $500.00

    1. Consultar Saldo
    2. Retirar Efectivo
    3. Salir del Cajero
    Seleccione opcion: 3
    Saliendo del sistema...

    --- EJERCICIO DE BREAK Y CONTINUE ---
    Procesando numero impar: 1
    Procesando numero impar: 3
    Procesando numero impar: 5
    Numero 5 encontrado! ABORTANDO BUCLE CON BREAK.

    Fin del programa.
*/
