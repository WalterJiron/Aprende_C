/*
 * =============================================================================
 * Archivo     : ejemplo1.c
 * Modulo      : Funciones
 * Descripcion : Sistema de registro de empleados refactorizado con funciones.
 *               Este archivo es la version evolucionada del sistema de empleados
 *               visto en arreglo2d.c. La diferencia clave es que la logica ha
 *               sido distribuida en funciones especializadas y reutilizables,
 *               en lugar de estar toda dentro de main().
 *
 * Conceptos cubiertos:
 *   - Prototipo de funcion (declaracion anticipada)
 *   - Definicion de funcion fuera de main
 *   - Tipos de retorno: int, float, char, void
 *   - Parametros de entrada: arreglos y cadenas de caracteres
 *   - Funciones de validacion reutilizables (patron de diseno utilitario)
 *   - Variable global: uso y consideraciones
 *   - Llamadas a funcion desde main y desde otras funciones
 *
 * Compilar    : gcc -Wall -std=c99 ejemplo1.c -o GestionEmpleados
 * Ejecutar    : ./GestionEmpleados
 *
 * Estructura del programa:
 *   main()                <- Orquesta el flujo general
 *   menu()                <- Muestra opciones y retorna la opcion elegida
 *   listadoEmpleados()    <- Imprime todos los empleados registrados
 *   validarInt()          <- Lee y valida un entero, retorna el valor
 *   validarFlotante()     <- Lee y valida un flotante, retorna el valor
 *   validarSoN()          <- Lee y valida 'S' o 'N', retorna el caracter
 *
 * Comparacion con arreglo2d.c (version sin funciones):
 *   En arreglo2d.c toda la validacion de entrada esta repetida en cada punto
 *   del programa. Aqui, las funciones validarInt(), validarFlotante() y
 *   validarSoN() encapsulan ese patron y se invocan donde se necesiten,
 *   eliminando la repeticion de codigo (principio DRY: Don't Repeat Yourself).
 *
 * Nota sobre la variable global contE:
 *   contE se declara fuera de todas las funciones. Esto la hace accesible
 *   desde cualquier funcion del archivo sin pasarla como parametro. Si bien
 *   es conveniente para este ejemplo, las variables globales en proyectos
 *   grandes dificultan el rastreo de quien modifica el estado. La alternativa
 *   es pasar contE como puntero a las funciones que lo necesiten modificar.
 * =============================================================================
 */

#include <stdio.h>

/*
 * =============================================================================
 * PROTOTIPOS DE FUNCIONES
 *
 * Un prototipo (o declaracion de funcion) informa al compilador sobre la
 * existencia de una funcion antes de que sea definida. Esto permite llamar
 * a la funcion desde main aunque su implementacion aparezca despues en el
 * archivo.
 *
 * Formato del prototipo:
 *   TipoRetorno NombreFuncion(TipoParam1, TipoParam2, ...);
 *
 * Los nombres de los parametros son opcionales en el prototipo, solo se
 * requieren los tipos. Sin embargo, incluir los nombres mejora la legibilidad.
 * =============================================================================
 */

/**
 * menu - Muestra el menu principal y solicita una opcion al usuario.
 *
 * Retorna el numero de opcion seleccionado (validado como entero).
 * La validacion de tipo se delega a validarInt().
 *
 * Retorna: int — la opcion elegida por el usuario.
 */
int menu();

/**
 * listadoEmpleados - Imprime el listado completo de empleados registrados.
 *
 * Parametros:
 *   nombres[][50] : arreglo 2D de cadenas con los nombres de los empleados.
 *                   El segundo tamano (50) debe ser especificado en el prototipo
 *                   porque C necesita conocer el paso de columna para calcular
 *                   las direcciones de memoria.
 *   eddes[]       : arreglo de enteros con las edades de los empleados.
 *   sueldos[]     : arreglo de flotantes con los sueldos de los empleados.
 *
 * La cantidad de empleados a mostrar se toma de la variable global contE.
 * No retorna valor (void).
 */
void listadoEmpleados(char[][50], int[], float[]);

/**
 * validarInt - Lee y valida que la entrada del usuario sea un entero.
 *
 * Muestra el mensaje indicado y repite la solicitud hasta obtener un entero
 * valido. Descarta cualquier entrada no numerica del buffer.
 *
 * Parametros:
 *   mensaje[] : cadena de texto a mostrar como prompt antes de leer.
 *
 * Retorna: int — el entero valido ingresado por el usuario.
 */
int validarInt(char[]);

/**
 * validarFlotante - Lee y valida que la entrada del usuario sea un numero
 *                   de punto flotante.
 *
 * Parametros:
 *   mensaje[] : cadena de texto a mostrar como prompt antes de leer.
 *
 * Retorna: float — el numero flotante valido ingresado por el usuario.
 */
float validarFlotante(char[]);

/**
 * validarSoN - Lee y valida que la entrada sea exactamente 'S', 's', 'N' o 'n'.
 *
 * Parametros:
 *   mensaje[] : cadena de texto a mostrar como prompt antes de leer.
 *
 * Retorna: char — el caracter valido ('S', 's', 'N' o 'n').
 */
char validarSoN(char[]);

/* -----------------------------------------------------------------------
 * Variable global: contE
 *
 * Registra cuantos empleados han sido ingresados hasta el momento. Se
 * declara fuera de main para que tanto main() como listadoEmpleados()
 * puedan leerla y modificarla sin pasarla como argumento.
 *
 * Se inicializa en 0 porque al inicio no hay empleados registrados.
 * -------------------------------------------------------------------- */
int contE = 0;

/* =============================================================================
 * FUNCION PRINCIPAL: main
 *
 * Orquesta el flujo del programa:
 *   1. Lee la cantidad maxima de empleados.
 *   2. Declara los arreglos VLA con esa capacidad.
 *   3. Presenta el menu en un ciclo do-while.
 *   4. Delega cada opcion a las funciones correspondientes.
 * ============================================================================= */
int main()
{
    int cantiE, op;

    /* Solicitar la cantidad de empleados usando la funcion de validacion */
    cantiE = validarInt("Ingrese la cantidad de empleados: ");

    /* Declarar los arreglos paralelos con capacidad cantiE (VLA) */
    char nombres[cantiE][50]; /* Arreglo 2D para nombres (permite espacios) */
    int eddes[cantiE];         /* Edades de los empleados                   */
    float sueldos[cantiE];     /* Sueldos de los empleados                  */

    do
    {
        /* menu() muestra las opciones y retorna la opcion validada */
        op = menu();

        switch (op)
        {
        case 0:
            printf("\nSaliendo...\n");
            break;

        /* -------------------------------------------------------------------
         * Caso 1: Ingresar empleados
         *
         * Se usa un do-while interno para permitir ingresar varios empleados
         * consecutivamente. Al final de cada registro se pregunta S/N para
         * continuar o detenerse.
         * ---------------------------------------------------------------- */
        case 1:
            if (contE == cantiE)
            {
                printf("Ya se ingresaron todos los empleados.\n");
                break;
            }

            char opSN;
            do
            {
                /* Leer nombre con espacios directamente con scanf */
                printf("Ingrese su nombre: ");
                scanf(" %[^\n]", nombres[contE]);

                /* Delegar validacion de edad a validarInt */
                eddes[contE] = validarInt("Ingrese su edad: ");

                /* Delegar validacion de sueldo a validarFlotante */
                sueldos[contE] = validarFlotante("Ingrese su sueldo: ");

                /* Incrementar contador de empleados registrados */
                ++contE;

                if (contE == cantiE)
                {
                    printf("Ya se ingresaron todos los empleados.\n");
                    break;
                }

                /* Preguntar si desea continuar usando validarSoN */
                opSN = validarSoN("Quiere ingresar otro empleado? (S/N): ");

            } while (opSN == 's' || opSN == 'S');

            break;

        case 2:
            /* Delegar la visualizacion a listadoEmpleados */
            listadoEmpleados(nombres, eddes, sueldos);
            break;

        default:
            printf("\n\tOpcion invalida.");
            break;
        }

    } while (op != 0);

    return 0;
}

/* =============================================================================
 * DEFINICION DE FUNCIONES
 *
 * Las definiciones aparecen despues de main gracias a los prototipos
 * declarados al inicio del archivo.
 * ============================================================================= */

/**
 * menu - Muestra las opciones del sistema y retorna la opcion elegida.
 *
 * Imprime el menu en pantalla y usa validarInt() para asegurar que la
 * entrada sea un numero entero valido.
 *
 * Retorna: int — numero de opcion seleccionado.
 */
int menu()
{
    printf("\n--------- MENU ---------\n");
    printf("1. Ingresar empleados.\n");
    printf("2. Listado de empleados.\n");
    printf("0. Salir.\n");

    /* Se reutiliza validarInt para leer la opcion del menu */
    return validarInt("Ingrese la opcion que va a realizar: ");
}

/**
 * listadoEmpleados - Muestra todos los empleados registrados hasta el momento.
 *
 * Lee la variable global contE para saber cuantos empleados hay.
 * Recorre los arreglos paralelos con el mismo indice para mostrar cada
 * registro.
 *
 * Parametros:
 *   nombres : arreglo 2D de cadenas
 *   eddes   : arreglo de edades
 *   sueldos : arreglo de sueldos
 */
void listadoEmpleados(char nombres[][50], int eddes[], float sueldos[])
{
    /* Verificar si hay datos antes de intentar mostrar */
    if (contE == 0)
    {
        printf("\n\tNo tienes empleados a mostrar.\n");
        return; /* Retorno anticipado: equivale a un break en un switch */
    }

    printf("\n------------------------ Listado de empleados ------------------------\n");

    /* Recorrer solo los registros efectivamente ingresados (0 a contE-1) */
    for (int emple = 0; emple < contE; emple++)
    {
        printf(
            "\t%d. %s. tiene la edad de %d y gana %.3f\n",
            emple + 1, nombres[emple], eddes[emple],
            sueldos[emple]);
    }
}

/**
 * validarInt - Lee un entero del usuario con validacion de tipo.
 *
 * Muestra el mensaje, intenta leer con scanf. Si la lectura falla (el
 * usuario ingresa texto u otro tipo), limpia el buffer y vuelve a
 * intentarlo. El bucle se rompe solo cuando scanf retorna 1 (exito).
 *
 * Parametros:
 *   mensaje : texto que se muestra como prompt antes de la lectura.
 *
 * Retorna: int — el primer entero valido ingresado por el usuario.
 *
 * Nota: esta funcion NO valida el rango del numero. Si se necesita un rango
 * especifico (ej: edad entre 0 y 150), la validacion de rango debe hacerse
 * en el punto de llamada o en una funcion separada validarIntEnRango().
 */
int validarInt(char mensaje[])
{
    int num;

    while (1)
    {
        printf("%s", mensaje);

        if (scanf("%d", &num) == 1)
            return num; /* Lectura exitosa: retornar el valor inmediatamente */

        /* La lectura fallo: informar y limpiar el buffer */
        printf("\n\tSolo puedes ingresar numeros.\n");

        /* Descartar todos los caracteres hasta el proximo '\n' */
        while (getchar() != '\n')
            ;
    }
}

/**
 * validarFlotante - Lee un numero de punto flotante con validacion de tipo.
 *
 * Funcionamiento identico a validarInt pero usando el formato %f para
 * aceptar numeros con decimales.
 *
 * Parametros:
 *   mensaje : texto que se muestra como prompt antes de la lectura.
 *
 * Retorna: float — el primer flotante valido ingresado por el usuario.
 */
float validarFlotante(char mensaje[])
{
    float num;

    while (1)
    {
        printf("%s", mensaje);

        if (scanf("%f", &num) == 1)
            return num;

        printf("\n\tSolo puedes ingresar numeros.\n");

        while (getchar() != '\n')
            ;
    }
}

/**
 * validarSoN - Lee un caracter S o N (en mayuscula o minuscula).
 *
 * Acepta: 'S', 's', 'N', 'n'. Cualquier otro valor provoca un nuevo
 * intento. Se usa el formato " %c" (con espacio antes) para descartar
 * blancos y el '\n' del scanf anterior antes de leer el caracter.
 *
 * Parametros:
 *   mensaje : texto que se muestra como prompt antes de la lectura.
 *
 * Retorna: char — 'S', 's', 'N' o 'n' segun lo que ingreso el usuario.
 */
char validarSoN(char mensaje[])
{
    char opSN;

    while (1)
    {
        printf("%s", mensaje);

        /* " %c" con espacio: consume blancos antes de leer el caracter */
        scanf(" %c", &opSN);

        if (opSN == 's' || opSN == 'S' || opSN == 'n' || opSN == 'N')
        {
            /* Limpiar el resto de la linea antes de retornar */
            while (getchar() != '\n')
                ;
            return opSN;
        }

        printf("\n\tSolo puedes ingresar S o N\n");

        while (getchar() != '\n')
            ;
    }
}