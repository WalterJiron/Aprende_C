# Funciones en C

Guia de referencia completa sobre funciones en el lenguaje C, con explicacion detallada de prototipos, parametros, retorno, alcance de variables y buenas practicas. Incluye ejemplos comentados y ejercicios progresivos.

---

## Contenido del Modulo

```
funciones/
├── ejemplo1.c                          <- Sistema de empleados refactorizado
│                                          con funciones especializadas
├── practica/
│   ├── eje1_calculadora.c             <- Calculadora con funcion por operacion
│   ├── eje2_conversion_temperatura.c  <- Conversiones con funciones puras
│   ├── eje3_numeros_primos.c          <- Funcion booleana esPrimo()
│   ├── eje4_estadisticas_arreglo.c    <- Paso de arreglos a funciones
│   └── eje5_validaciones.c            <- Biblioteca de validaciones reutilizables
└── README.md                          <- Este archivo
```

---

## Por que usar funciones

Sin funciones, el codigo crece de forma lineal dentro de `main()`. A medida que el programa se vuelve mas complejo, el codigo se repite, es dificil de leer y casi imposible de mantener.

Las funciones permiten:

- **Reutilizacion**: escribir la logica una sola vez y llamarla desde multiples puntos.
- **Legibilidad**: `resultado = calcularPromedio(datos, n)` es mas claro que un bloque de 10 lineas en linea.
- **Aislamiento**: una funcion bien escrita puede probarse de forma independiente.
- **Separacion de responsabilidades**: cada funcion hace exactamente una cosa (principio de responsabilidad unica).

---

## Anatomia de una Funcion

Una funcion en C tiene tres partes: prototipo, definicion y llamada.

### Prototipo (Declaracion Anticipada)

Informa al compilador que la funcion existe antes de que aparezca su implementacion. Permite que `main` llame a funciones definidas despues en el mismo archivo.

```c
/* Formato del prototipo */
TipoRetorno NombreFuncion(TipoParam1, TipoParam2, ...);

/* Ejemplos */
int sumar(int, int);                  /* Prototipo minimo (sin nombres)       */
int sumar(int a, int b);              /* Prototipo con nombres (mas legible)   */
void mostrarMensaje(void);            /* Sin parametros, sin retorno           */
double calcularPromedio(float[], int); /* Arreglo y entero como parametros    */
```

Los nombres de los parametros son opcionales en el prototipo, pero incluirlos mejora la comprension sin esfuerzo adicional.

### Definicion

Contiene la implementacion real de la funcion.

```c
/* Formato de la definicion */
TipoRetorno NombreFuncion(TipoParam1 nombre1, TipoParam2 nombre2)
{
    /* Cuerpo de la funcion */
    return valor; /* Obligatorio si TipoRetorno != void */
}
```

### Llamada

Donde se invoca la funcion para ejecutarla.

```c
int resultado = sumar(5, 3);         /* Llamada con captura del retorno */
mostrarMensaje();                     /* Llamada sin captura (void o ignorado) */
printf("%.2f\n", calcularPromedio(arr, n)); /* Resultado pasado directamente */
```

---

## Tipos de Retorno

### void: sin retorno

La funcion realiza una accion pero no produce un valor de retorno. Se usa para funciones de presentacion o que modifican el estado a traves de sus parametros.

```c
/* Funcion void: no necesita return (o puede usar return; sin valor) */
void imprimirSeparador()
{
    printf("-----------------------------\n");
}

/* Llamada: no se puede asignar su resultado */
imprimirSeparador();
```

### Retorno de tipo primitivo

```c
int sumar(int a, int b)
{
    return a + b;  /* La expresion se evalua y se devuelve al punto de llamada */
}

float calcularIVA(float precio, float porcentaje)
{
    return precio * porcentaje / 100.0f;
}

/* Una funcion puede tener multiples return (retorno anticipado) */
int esPar(int n)
{
    if (n % 2 == 0)
        return 1;  /* Retorno anticipado si se cumple la condicion */
    return 0;      /* Retorno por defecto */
}
```

### Retorno de estado (1/0 como booleano)

Antes de `stdbool.h`, es comun retornar `int` con 1 para verdadero y 0 para falso:

```c
int esPrimo(int n)
{
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

/* Uso en condicional */
if (esPrimo(17))
    printf("17 es primo\n");
```

---

## Parametros

### Paso por valor

En C, los parametros primitivos (int, float, double, char) se pasan **por valor**: la funcion recibe una copia del argumento. Modificar el parametro dentro de la funcion no afecta a la variable original.

```c
void triplicar(int n)
{
    n = n * 3;  /* Modifica la copia local, no la variable del llamador */
}

int main()
{
    int x = 5;
    triplicar(x);
    printf("%d\n", x); /* Imprime 5, no 15 */
    return 0;
}
```

Para modificar la variable original desde una funcion, se necesitan punteros (tema avanzado).

### Paso de arreglos

Los arreglos **siempre se pasan por referencia implicita**: la funcion recibe la direccion del primer elemento, no una copia. Por eso, modificar el arreglo dentro de la funcion si afecta al original.

```c
void duplicarElementos(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] *= 2;  /* Modifica el arreglo original */
}

/* El tamano del arreglo DEBE pasarse como parametro separado.
   C no tiene forma de conocer el tamano de un arreglo solo con su nombre. */
int calcularSuma(int arr[], int n)
{
    int suma = 0;
    for (int i = 0; i < n; i++)
        suma += arr[i];
    return suma;
}
```

### Paso de cadenas (arreglos de char)

Las cadenas son arreglos de `char`, por lo que se pasan igual que los arreglos: por referencia.

```c
void mostrarMensaje(char texto[])
{
    printf("%s\n", texto);
}

int validarInt(char mensaje[])
{
    int num;
    while (1)
    {
        printf("%s", mensaje); /* Usa la cadena sin copiarla */
        if (scanf("%d", &num) == 1)
            return num;
        printf("\tSolo numeros.\n");
        while (getchar() != '\n')
            ;
    }
}
```

### Arreglos 2D como parametros

Cuando se pasa un arreglo 2D a una funcion, se debe especificar el tamano de todas las dimensiones excepto la primera:

```c
/* Correcto: se especifica el tamano de la segunda dimension */
void mostrarNombres(char nombres[][50], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
        printf("%s\n", nombres[i]);
}

/* Incorrecto: el compilador no puede calcular los offsets de memoria */
/* void mostrarNombres(char nombres[][], int cantidad) { ... } */
```

---

## Variables Locales vs Variables Globales

### Variables locales

Declaradas dentro de una funcion. Solo existen mientras la funcion esta en ejecucion. Cada llamada a la funcion crea nuevas copias de las variables locales.

```c
int calcular(int x)
{
    int resultado = x * 2;  /* resultado es local: solo existe aqui */
    return resultado;
}
/* 'resultado' deja de existir cuando la funcion retorna */
```

### Variables globales

Declaradas fuera de todas las funciones. Son accesibles desde cualquier funcion del archivo. Persisten durante toda la ejecucion del programa.

```c
int contadorGlobal = 0;  /* Variable global */

void incrementar()
{
    contadorGlobal++;  /* Modifica la variable global directamente */
}

int main()
{
    incrementar();
    incrementar();
    printf("%d\n", contadorGlobal); /* Imprime 2 */
    return 0;
}
```

Las variables globales son convenientes para compartir estado entre funciones, pero en proyectos grandes generan dependencias ocultas y dificultan el rastreo de quien modifica el estado. Se prefiere pasar datos explicitamente como parametros.

---

## Patron de Validacion de Entrada

El patron de validacion es una de las aplicaciones mas practicas de las funciones. En lugar de repetir el bloque `while(1) / scanf / if / while(getchar())` en cada punto del programa, se encapsula en una funcion reutilizable:

```c
/* Sin funciones: codigo repetido en cada punto de lectura */
int n;
while (1)
{
    printf("Ingrese un numero: ");
    if (scanf("%d", &n) == 1) break;
    printf("Solo numeros.\n");
    while (getchar() != '\n') ;
}

int m;
while (1)
{
    printf("Ingrese otro numero: ");
    if (scanf("%d", &m) == 1) break;
    printf("Solo numeros.\n");
    while (getchar() != '\n') ;
}

/* Con funciones: legible, sin repeticion */
int validarInt(char mensaje[])
{
    int num;
    while (1)
    {
        printf("%s", mensaje);
        if (scanf("%d", &num) == 1) return num;
        printf("Solo numeros.\n");
        while (getchar() != '\n') ;
    }
}

int n = validarInt("Ingrese un numero: ");
int m = validarInt("Ingrese otro numero: ");
```

---

## Funciones Puras

Una funcion pura es aquella que:
1. Siempre retorna el mismo resultado para los mismos argumentos.
2. No tiene efectos secundarios (no modifica variables globales, no imprime, no lee).

Son las mas faciles de entender, probar y reutilizar:

```c
/* Funcion pura: dado el mismo argumento, siempre retorna lo mismo */
double celsiusAFahrenheit(double c)
{
    return c * 9.0 / 5.0 + 32.0;
}

/* No pura: imprime (efecto secundario) */
void mostrarTemperatura(double c)
{
    printf("%.2f C = %.2f F\n", c, celsiusAFahrenheit(c));
}
```

---

## Estructura Recomendada de un Archivo con Funciones

```c
#include <stdio.h>

/* 1. Prototipos (declaraciones anticipadas) */
int funcion1(int, int);
void funcion2(char[]);

/* 2. Variables globales (si son necesarias) */
int estado = 0;

/* 3. Funcion principal */
int main()
{
    /* Orquestra el flujo, delega detalles a las funciones */
    return 0;
}

/* 4. Implementaciones de las funciones */
int funcion1(int a, int b) { return a + b; }
void funcion2(char msg[])  { printf("%s\n", msg); }
```

---

## Errores Comunes

| Error | Descripcion | Solucion |
|---|---|---|
| Usar funcion antes de declararla | El compilador no conoce el tipo de retorno | Agregar prototipo al inicio del archivo |
| Pasar arreglo 2D sin el segundo tamano | `char nombres[][]` causa error de compilacion | Especificar `char nombres[][50]` |
| Modificar parametro esperando cambiar el original | Los tipos primitivos se pasan por valor (copia) | Usar punteros para modificar el original |
| No limpiar el buffer despues de scanf | El siguiente scanf lee el '\n' residual | Agregar `while(getchar() != '\n');` |
| Variable global oculta un bug | Multiples funciones modifican el estado global sin saberlo | Minimizar globales; pasar datos como parametros |
| Funcion que hace demasiado | Dificil de entender y reutilizar | Dividir en funciones mas pequenas con una sola responsabilidad |

---

## Buenas Practicas

- Nombrar las funciones con un verbo que describa la accion: `calcularPromedio`, `mostrarMenu`, `validarEntrada`.
- Cada funcion debe hacer exactamente una cosa (principio de responsabilidad unica).
- Documentar cada funcion con: que hace, que parametros espera y que retorna.
- Colocar los prototipos al inicio del archivo, antes de `main`.
- Preferir funciones pequenas (menos de 40 lineas) sobre funciones largas.
- Evitar variables globales cuando sea posible; pasar datos como parametros.
- Validar siempre los argumentos de entrada en funciones criticas.

---

## Compilar y Ejecutar

```bash
# Ejemplo principal
gcc -Wall -std=c99 ejemplo1.c -o GestionEmpleados
./GestionEmpleados

# Ejercicios de practica
gcc -Wall -std=c99 practica/eje1_calculadora.c             -o practica/eje1
gcc -Wall -std=c99 practica/eje2_conversion_temperatura.c  -o practica/eje2
gcc -Wall -std=c99 practica/eje3_numeros_primos.c          -o practica/eje3 -lm
gcc -Wall -std=c99 practica/eje4_estadisticas_arreglo.c    -o practica/eje4
gcc -Wall -std=c99 practica/eje5_validaciones.c            -o practica/eje5

# Ejecutar
./practica/eje1
```

Nota: `eje3_numeros_primos.c` requiere `-lm` para enlazar la biblioteca matematica que provee `sqrt()`.

---

## Orden de Estudio

| Paso | Archivo | Concepto central |
|---|---|---|
| 1 | ejemplo1.c | Prototipo, definicion, llamada; funciones void, int, float, char |
| 2 | practica/eje1_calculadora.c | Funciones puras, separacion de logica y presentacion |
| 3 | practica/eje2_conversion_temperatura.c | Funciones matematicas, composicion de funciones |
| 4 | practica/eje3_numeros_primos.c | Funcion booleana, reutilizacion dentro de bucle |
| 5 | practica/eje4_estadisticas_arreglo.c | Paso de arreglos, tamano como parametro separado |
| 6 | practica/eje5_validaciones.c | Funciones genericas, parametros de rango y caracter |

---

## Relacion con Otros Modulos

- **Repeticion**: Las funciones de validacion usan `while(1)` con `break` condicional, patron proveniente del modulo de repeticion.
- **Arreglos**: Las funciones que operan sobre arreglos (llenar, mostrar, calcular estadisticas) son el puente natural entre ambos modulos.
- **Structs** (avanzado): El siguiente nivel de organizacion agrupa datos relacionados en tipos personalizados que luego se pasan a funciones.
- **Archivos de cabecera** (avanzado): Los prototipos pueden extraerse a archivos `.h` para compartirse entre multiples archivos `.c`.
