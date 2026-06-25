# Arreglos en C

Guia de referencia completa sobre arreglos unidimensionales y bidimensionales en el lenguaje C, con ejemplos comentados y ejercicios de practica progresivos.

---

## Contenido del Modulo

```
areglos/
├── EjemploArreaglo.c          <- Gestor de notas: arreglo 1D con VLA y menu
├── arreglo2d.c                <- Registro de empleados: arreglos paralelos y 2D
├── practica/
│   ├── eje1_estadisticas.c    <- Mayor, menor, suma, promedio sobre un arreglo
│   ├── eje2_busqueda.c        <- Busqueda lineal con reporte de posiciones
│   ├── eje3_invertir.c        <- Inversion in-place con tecnica de dos indices
│   ├── eje4_ordenamiento.c    <- Bubble Sort con visualizacion de cada pasada
│   └── eje5_tabla2d.c         <- Tabla de multiplicar almacenada en arreglo 2D
└── README.md                  <- Este archivo
```

---

## Que es un Arreglo

Un arreglo (array) es una estructura de datos que agrupa una cantidad fija de elementos del mismo tipo bajo un solo nombre, accedidos por un indice numerico.

En C, los arreglos:
- Son de tamano fijo en tiempo de compilacion (o variable con VLA desde C99).
- Se almacenan de forma contigua en memoria.
- Se indexan desde **0** hasta **n-1** (nunca desde 1).
- No tienen comprobacion de limites: acceder fuera del rango es comportamiento indefinido.

---

## Declaracion y Sintaxis

```c
/* Sintaxis general */
tipoDato nombreArreglo[cantidad];

/* Ejemplos */
int edades[10];          /* 10 enteros: edades[0] .. edades[9]              */
float notas[5];          /* 5 flotantes: notas[0] .. notas[4]               */
char nombre[50];         /* 50 caracteres: nombre[0] .. nombre[49]          */

/* Inicializacion en la declaracion */
int primos[5] = {2, 3, 5, 7, 11};
int ceros[4]  = {0};     /* Inicializa todos los elementos a 0              */

/* VLA: tamano definido en tiempo de ejecucion (C99) */
int n = 8;
int datos[n];            /* El tamano se determina cuando el programa corre */
```

---

## Acceso a Elementos

```c
int notas[5] = {85, 90, 78, 95, 60};

/* Leer un elemento */
int primera = notas[0];  /* 85 */
int ultima  = notas[4];  /* 60 */

/* Escribir un elemento */
notas[2] = 100;          /* notas queda: 85 90 100 95 60 */

/* INCORRECTO: fuera de limites (comportamiento indefinido) */
/* notas[5] = 50; */     /* El indice 5 no existe en un arreglo de 5 */
```

---

## Recorrido con for

El bucle `for` es el idioma natural para recorrer arreglos en C:

```c
int datos[5] = {10, 20, 30, 40, 50};
int n = 5;

/* Recorrido de lectura */
for (int i = 0; i < n; i++)
{
    printf("datos[%d] = %d\n", i, datos[i]);
}

/* Recorrido de escritura: llenar con cuadrados */
for (int i = 0; i < n; i++)
{
    datos[i] = (i + 1) * (i + 1);
}
/* datos queda: 1 4 9 16 25 */
```

---

## VLA: Variable Length Array

Un VLA es un arreglo cuyo tamano se determina en tiempo de ejecucion en lugar de en tiempo de compilacion. Disponible desde C99.

```c
int n;
printf("Cuantos elementos: ");
scanf("%d", &n);

int arreglo[n];  /* Tamano definido por la variable 'n' */
```

Consideraciones importantes sobre los VLA:
- Se ubican en la **pila (stack)**, no en el heap.
- Para tamanos grandes (miles de elementos), conviene usar `malloc` en su lugar.
- Son optativos en C11: el compilador puede no soportarlos si `__STDC_NO_VLA__` esta definido.
- No se pueden inicializar en la declaracion como los arreglos de tamano fijo.

---

## Arreglos de Caracteres (Cadenas)

En C no existe un tipo `string`. Las cadenas se representan como arreglos de `char` terminados en el caracter nulo `'\0'`.

```c
char nombre[50];           /* Arreglo de caracteres, capacidad 49 + '\0'   */

/* Leer una palabra (sin espacios) */
scanf("%s", nombre);       /* El & no es necesario: nombre ya es un puntero */

/* Leer con espacios: formato %[^\n] */
scanf(" %[^\n]", nombre);  /* Lee todo hasta el salto de linea             */

/* Imprimir */
printf("%s\n", nombre);
```

El especificador `%[^\n]` en `scanf` es una expresion de conjunto que significa "leer todo hasta encontrar `\n`". El espacio antes del `%` consume blancos anteriores (incluyendo el `\n` de un `scanf` previo).

---

## Arreglos Bidimensionales

Un arreglo 2D es una matriz de filas y columnas. Se declara con dos pares de corchetes:

```c
/* Sintaxis */
tipoDato nombre[filas][columnas];

/* Ejemplo: matriz 3x4 de enteros */
int matriz[3][4];

/* Acceso: matriz[fila][columna] */
matriz[0][0] = 1;   /* Primera fila, primera columna */
matriz[2][3] = 12;  /* Tercera fila, cuarta columna  */

/* Llenado con doble for anidado */
for (int i = 0; i < 3; i++)          /* Recorre filas    */
{
    for (int j = 0; j < 4; j++)      /* Recorre columnas */
    {
        matriz[i][j] = i * 4 + j + 1;
    }
}
```

### Arreglo 2D de caracteres (arreglo de cadenas)

```c
/* 5 nombres de hasta 49 caracteres cada uno */
char nombres[5][50];

scanf(" %[^\n]", nombres[0]);  /* Leer el primer nombre */
printf("%s\n", nombres[0]);    /* Imprimir el primer nombre */
```

---

## Arreglos Paralelos

Cuando se necesita almacenar datos relacionados sin usar `struct`, se pueden usar varios arreglos con el mismo indice:

```c
char nombres[5][50];  /* nombres[i] = nombre del empleado i */
int  edades[5];       /* edades[i]  = edad del empleado i   */
float sueldos[5];     /* sueldos[i] = sueldo del empleado i */

/* El empleado en la posicion 2 tiene: */
printf("%s, %d anios, %.2f de sueldo\n", nombres[2], edades[2], sueldos[2]);
```

Esta tecnica es valida para aprender arreglos, pero en codigo de produccion se prefiere `struct` porque agrupa todos los campos en un solo tipo, es mas legible y evita la posibilidad de que los arreglos queden desincronizados.

---

## Estadisticas Basicas sobre Arreglos

```c
int datos[5] = {10, 45, 3, 22, 18};
int n = 5;

/* Maximo y minimo: inicializar con el primer elemento */
int max = datos[0];
int min = datos[0];
long suma = 0;

for (int i = 0; i < n; i++)
{
    if (datos[i] > max) max = datos[i];
    if (datos[i] < min) min = datos[i];
    suma += datos[i];
}

double promedio = (double)suma / n;

printf("Max: %d, Min: %d, Suma: %ld, Promedio: %.2f\n", max, min, suma, promedio);
/* Salida: Max: 45, Min: 3, Suma: 98, Promedio: 19.60 */
```

Inicializar `max` y `min` con `datos[0]` (en lugar de 0 o un valor arbitrario) garantiza que el resultado sea correcto incluso cuando todos los elementos son negativos o mayores que cualquier constante elegida arbitrariamente.

---

## Busqueda Lineal

```c
int datos[5] = {10, 45, 3, 22, 18};
int n = 5;
int objetivo = 22;
int encontrado = 0;

for (int i = 0; i < n; i++)
{
    if (datos[i] == objetivo)
    {
        printf("Encontrado en la posicion %d\n", i + 1);
        encontrado = 1;
        break; /* Si solo se busca la primera ocurrencia */
    }
}

if (!encontrado)
    printf("No encontrado\n");
```

La busqueda lineal recorre el arreglo de inicio a fin. Su complejidad es O(n): en el peor caso revisa todos los elementos. Para arreglos ordenados, la busqueda binaria es mas eficiente con O(log n).

---

## Inversion de un Arreglo (In-Place)

```c
int arr[5] = {10, 20, 30, 40, 50};
int izq = 0;
int der = 4; /* n - 1 */

while (izq < der)
{
    /* Swap con variable temporal */
    int temp = arr[izq];
    arr[izq] = arr[der];
    arr[der] = temp;

    izq++;
    der--;
}
/* arr queda: 50 40 30 20 10 */
```

Este algoritmo realiza n/2 intercambios y no requiere arreglo auxiliar. La clave es que los indices convergen hacia el centro: cuando `izq >= der`, todos los elementos han sido intercambiados.

---

## Ordenamiento Burbuja (Bubble Sort)

```c
int arr[5] = {64, 34, 25, 12, 22};
int n = 5;

for (int pasada = 0; pasada < n - 1; pasada++)
{
    int huboSwap = 0;

    for (int j = 0; j < n - 1 - pasada; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            int temp   = arr[j];
            arr[j]     = arr[j + 1];
            arr[j + 1] = temp;
            huboSwap   = 1;
        }
    }

    if (!huboSwap) break; /* Arreglo ya ordenado, no continuar */
}
/* arr queda: 12 22 25 34 64 */
```

Idea del algoritmo: en cada pasada, el elemento mas grande "burbujea" hacia el final. Despues de k pasadas, los k elementos mas grandes estan en su posicion definitiva. La bandera `huboSwap` optimiza el caso donde el arreglo queda ordenado antes de completar todas las pasadas.

---

## Errores Comunes

| Error | Descripcion | Solucion |
|---|---|---|
| Acceso fuera de limites | `arr[n]` en un arreglo de `n` elementos | Usar indices de 0 a n-1 |
| Inicializar max/min con 0 | Falla con arreglos de negativos | Inicializar con `arr[0]` |
| VLA sin validacion | `int arr[n]` con n <= 0 causa comportamiento indefinido | Validar que n > 0 antes de declarar |
| Confundir longitud de cadena | `char nombre[50]` solo puede almacenar 49 caracteres utiles + '\0' | Reservar un espacio extra para el terminador |
| No limpiar el buffer | `scanf` deja `\n` en el buffer, el siguiente `scanf` lo lee | Usar `while(getchar() != '\n');` despues de cada lectura |

---

## Buenas Practicas

- Siempre validar que el tamano del VLA sea mayor que 0 antes de declararlo.
- Usar constantes o variables con nombre descriptivo para el tamano del arreglo: `int n = 10;` es mejor que usar `10` disperso en el codigo.
- Inicializar el maximo con el primer elemento del arreglo, no con 0.
- Para arreglos grandes en produccion, usar `malloc` y `free` en lugar de VLA.
- Usar `struct` en lugar de arreglos paralelos cuando los datos representan un mismo registro.
- Incluir comentarios que indiquen el rango de indices validos al declarar el arreglo.

---

## Compilar y Ejecutar

```bash
# Compilar los ejemplos principales
gcc -Wall -std=c99 EjemploArreaglo.c -o GestorNotas
gcc -Wall -std=c99 arreglo2d.c -o GestorEmpleados

# Compilar los ejercicios de practica
gcc -Wall -std=c99 practica/eje1_estadisticas.c -o practica/eje1
gcc -Wall -std=c99 practica/eje2_busqueda.c      -o practica/eje2
gcc -Wall -std=c99 practica/eje3_invertir.c      -o practica/eje3
gcc -Wall -std=c99 practica/eje4_ordenamiento.c  -o practica/eje4
gcc -Wall -std=c99 practica/eje5_tabla2d.c       -o practica/eje5

# Ejecutar
./GestorNotas
./practica/eje1
```

---

## Orden de Estudio

| Paso | Archivo | Concepto central |
|---|---|---|
| 1 | EjemploArreaglo.c | Arreglo 1D con VLA, llenado y estadisticas basicas en el ingreso |
| 2 | arreglo2d.c | Arreglos paralelos, arreglo 2D de cadenas |
| 3 | practica/eje1_estadisticas.c | Calcular estadisticas en una pasada separada del llenado |
| 4 | practica/eje2_busqueda.c | Busqueda lineal con bandera y conteo de ocurrencias |
| 5 | practica/eje3_invertir.c | Inversion in-place con dos indices |
| 6 | practica/eje4_ordenamiento.c | Bubble Sort con optimizacion de bandera |
| 7 | practica/eje5_tabla2d.c | Arreglo 2D, doble bucle, formateo de salida |

---

## Relacion con Otros Modulos

- **Repeticion**: Los arreglos requieren dominios de bucles `for`, `while` y `do-while` para su recorrido.
- **Funciones**: El siguiente paso natural es encapsular operaciones sobre arreglos (llenar, mostrar, buscar, ordenar) en funciones reutilizables.
- **Structs** (avanzado): Reemplazar arreglos paralelos por registros estructurados.
