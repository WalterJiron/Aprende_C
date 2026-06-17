/*
    MÓDULO COMPLEMENTARIO — Validación de Entrada en C
    Archivo: ValidacionMenu.c
    
    TEMA: Menú Interactivo Robusto con Validación Completa
    
    Este programa demuestra:
      1. Menú principal con validación de opción usando while(1).
      2. Sub-validación dentro de operaciones (monto de retiro).
      3. Confirmación de operaciones críticas (Sí/No).
      4. Intentos limitados para operaciones sensibles (PIN).
      5. Combinación de while(1), switch, y limpieza de buffer.
    
    CASO PRÁCTICO: Cajero automático simplificado que no se rompe
    sin importar lo que el usuario escriba.
    
    Compilar: gcc -Wall -std=c99 ValidacionMenu.c -o validacion_menu
    Ejecutar: ./validacion_menu
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("╔════════════════════════════════════════╗\n");
    printf("║     CAJERO AUTOMATICO - BANCO ALFA     ║\n");
    printf("╚════════════════════════════════════════╝\n\n");

    // ─────────────────────────────────────────────
    // PASO 1: Autenticación con PIN (intentos limitados)
    // ─────────────────────────────────────────────
    
    const int PIN_CORRECTO = 1234;
    const int MAX_INTENTOS = 3;
    int intentos = 0;
    bool autenticado = false;
    int pin;
    int lectura;
    
    printf("--- AUTENTICACION ---\n");
    
    while (1) {
        intentos++;
        
        // Validación en línea del PIN (tipo + rango)
        while (1) {
            printf("Ingrese su PIN (4 digitos): ");
            lectura = scanf("%d", &pin);
            
            if (lectura != 1) {
                printf("  >> Error: Debe ingresar un numero entero.\n\n");
                while (getchar() != '\n'); // Limpiar buffer
            } else if (pin < 1000 || pin > 9999) {
                printf("  >> Error: El valor debe estar entre 1000 y 9999.\n\n");
            } else {
                break; // PIN tiene formato correcto
            }
        }
        
        if (pin == PIN_CORRECTO) {
            autenticado = true;
            printf("  >> PIN correcto. Bienvenido.\n\n");
            break; // Autenticación exitosa
        } else {
            printf("  >> PIN incorrecto.");
            if (intentos < MAX_INTENTOS) {
                printf(" Intentos restantes: %d\n\n", MAX_INTENTOS - intentos);
            } else {
                printf("\n");
                break; // Se acabaron los intentos
            }
        }
    }
    
    // Si no se autenticó, terminar el programa
    if (!autenticado) {
        printf("\n  >> CUENTA BLOQUEADA: Excedio el maximo de %d intentos.\n", MAX_INTENTOS);
        printf("  >> Contacte a su sucursal bancaria.\n");
        return 1; // Código de error
    }
    
    // ─────────────────────────────────────────────
    // PASO 2: Menú principal con validación
    // ─────────────────────────────────────────────
    
    float saldo = 5000.00;
    int opcion;
    bool salir = false;
    char confirmacion;
    
    while (!salir) {
        // Mostrar menú
        printf("╔════════════════════════════════════════╗\n");
        printf("║          MENU PRINCIPAL                ║\n");
        printf("╠════════════════════════════════════════╣\n");
        printf("║  1. Consultar saldo                    ║\n");
        printf("║  2. Depositar dinero                   ║\n");
        printf("║  3. Retirar dinero                     ║\n");
        printf("║  4. Salir                              ║\n");
        printf("╚════════════════════════════════════════╝\n");
        
        // Leer opción con validación de tipo + rango en línea
        while (1) {
            printf("Seleccione una opcion (1-4): ");
            lectura = scanf("%d", &opcion);
            
            if (lectura != 1) {
                printf("  >> Error: Debe ingresar un numero entero.\n\n");
                while (getchar() != '\n'); // Limpiar buffer
            } else if (opcion < 1 || opcion > 4) {
                printf("  >> Error: El valor debe estar entre 1 y 4.\n\n");
            } else {
                break;
            }
        }
        
        printf("\n");
        
        switch (opcion) {
            case 1:
                // ─── CONSULTA DE SALDO ───
                printf("  Su saldo actual es: $%.2f\n\n", saldo);
                break;
                
            case 2: {
                // ─── DEPÓSITO ───
                float deposito;
                // Validamos que el monto sea positivo en línea
                while (1) {
                    printf("  Monto a depositar: $");
                    lectura = scanf("%f", &deposito);
                    
                    if (lectura != 1) {
                        printf("  >> Error: Debe ingresar un numero.\n\n");
                        while (getchar() != '\n'); // Limpiar buffer
                    } else if (deposito <= 0) {
                        printf("  >> Error: El monto debe ser positivo.\n\n");
                    } else {
                        break;
                    }
                }
                
                // Confirmación de la operación
                printf("  Va a depositar $%.2f.\n", deposito);
                while (1) {
                    printf("  Confirmar deposito? (S/N): ");
                    scanf(" %c", &confirmacion);
                    
                    if (confirmacion == 'S' || confirmacion == 's' || 
                        confirmacion == 'N' || confirmacion == 'n') {
                        break;
                    } else {
                        printf("  >> Solo se acepta S (si) o N (no).\n\n");
                    }
                }
                
                if (confirmacion == 'S' || confirmacion == 's') {
                    saldo += deposito;
                    printf("  >> Deposito exitoso. Nuevo saldo: $%.2f\n\n", saldo);
                } else {
                    printf("  >> Deposito cancelado.\n\n");
                }
                break;
            }
                
            case 3: {
                // ─── RETIRO ───
                if (saldo <= 0) {
                    printf("  >> No tiene fondos disponibles.\n\n");
                    break;
                }
                
                printf("  Saldo disponible: $%.2f\n", saldo);
                float retiro;
                while (1) {
                    printf("  Monto a retirar: $");
                    lectura = scanf("%f", &retiro);
                    
                    if (lectura != 1) {
                        printf("  >> Error: Debe ingresar un numero.\n\n");
                        while (getchar() != '\n'); // Limpiar buffer
                    } else if (retiro <= 0) {
                        printf("  >> Error: El monto debe ser positivo.\n\n");
                    } else {
                        break;
                    }
                }
                
                // Validar que no exceda el saldo
                if (retiro > saldo) {
                    printf("  >> Error: Fondos insuficientes.\n");
                    printf("     Solicito: $%.2f | Disponible: $%.2f\n\n", retiro, saldo);
                } else {
                    // Confirmación para retiros
                    printf("  Va a retirar $%.2f.\n", retiro);
                    while (1) {
                        printf("  Confirmar retiro? (S/N): ");
                        scanf(" %c", &confirmacion);
                        
                        if (confirmacion == 'S' || confirmacion == 's' || 
                            confirmacion == 'N' || confirmacion == 'n') {
                            break;
                        } else {
                            printf("  >> Solo se acepta S (si) o N (no).\n\n");
                        }
                    }
                             
                    if (confirmacion == 'S' || confirmacion == 's') {
                        saldo -= retiro;
                        printf("  >> Retiro exitoso. Nuevo saldo: $%.2f\n\n", saldo);
                    } else {
                        printf("  >> Retiro cancelado.\n\n");
                    }
                }
                break;
            }
                
            case 4:
                // ─── SALIR ───
                while (1) {
                    printf("  Desea salir del cajero? (S/N): ");
                    scanf(" %c", &confirmacion);
                    
                    if (confirmacion == 'S' || confirmacion == 's' || 
                        confirmacion == 'N' || confirmacion == 'n') {
                        break;
                    } else {
                        printf("  >> Solo se acepta S (si) o N (no).\n\n");
                    }
                }
                         
                if (confirmacion == 'S' || confirmacion == 's') {
                    salir = true;
                    printf("  >> Gracias por usar nuestro cajero. Hasta pronto.\n");
                } else {
                    printf("  >> Operacion cancelada. Regresando al menu.\n\n");
                }
                break;
        }
        
    } // Fin del menú principal

    return 0;
}

/*
    SALIDA ESPERADA (ejemplo de interacción):

    ╔════════════════════════════════════════╗
    ║     CAJERO AUTOMATICO - BANCO ALFA     ║
    ╚════════════════════════════════════════╝

    --- AUTENTICACION ---
    Ingrese su PIN (4 digitos): abc
      >> Error: Debe ingresar un numero entero.

    Ingrese su PIN (4 digitos): 999
      >> Error: El valor debe estar entre 1000 y 9999.

    Ingrese su PIN (4 digitos): 5555
      >> PIN incorrecto. Intentos restantes: 2

    Ingrese su PIN (4 digitos): 1234
      >> PIN correcto. Bienvenido.

    ╔════════════════════════════════════════╗
    ║          MENU PRINCIPAL                ║
    ╠════════════════════════════════════════╣
    ║  1. Consultar saldo                    ║
    ║  2. Depositar dinero                   ║
    ║  3. Retirar dinero                     ║
    ║  4. Salir                              ║
    ╚════════════════════════════════════════╝
    Seleccione una opcion (1-4): hola
      >> Error: Debe ingresar un numero entero.

    Seleccione una opcion (1-4): 7
      >> Error: El valor debe estar entre 1 y 4.

    Seleccione una opcion (1-4): 1

      Su saldo actual es: $5000.00

    Seleccione una opcion (1-4): 3

      Saldo disponible: $5000.00
      Monto a retirar: $200
      Va a retirar $200.00.
      Confirmar retiro? (S/N): s
      >> Retiro exitoso. Nuevo saldo: $4800.00

    Seleccione una opcion (1-4): 4

      Desea salir del cajero? (S/N): S
      >> Gracias por usar nuestro cajero. Hasta pronto.
*/
