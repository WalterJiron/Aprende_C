# Clase 3 — Estructuras de Repetición (Bucles) en C

---

## 1. Introducción

Las **estructuras de repetición** (también llamadas **bucles**, **ciclos** o **loops**) permiten ejecutar un bloque de código **múltiples veces** sin necesidad de escribirlo repetidamente. Son la tercera y última estructura de control fundamental de la programación imperativa.

Mientras la secuenciación ejecuta instrucciones una vez y la selección elige caminos, la repetición **automatiza tareas recurrentes**: procesar listas, validar entradas, generar patrones, calcular sumatorias, buscar datos, y prácticamente cualquier operación que requiera iteración.

### ¿Por qué es importante?

- Permite **automatizar** tareas que se repiten (procesar 1000 registros, sumar N números).
- Reduce drásticamente la cantidad de código: en vez de 100 líneas idénticas, un bucle de 5 líneas.
- Es esencial para trabajar con **colecciones de datos** (arreglos, archivos, bases de datos).
- Sin bucles, un programa solo podría procesar una cantidad fija de datos.

### Aplicaciones prácticas

- Procesamiento de datos: sumar calificaciones, promediar ventas, analizar registros.
- Validación de entrada: repetir la solicitud hasta que el usuario ingrese un dato válido.
- Menús interactivos: mantener un programa funcionando hasta que el usuario decida salir.
- Algoritmos matemáticos: factoriales, series numéricas, tablas de multiplicar.
- Generación de patrones: dibujar figuras con asteriscos, generar reportes tabulados.
- Búsquedas: encontrar un elemento específico en un conjunto de datos.

---

## 2. Objetivos de Aprendizaje

Al finalizar esta clase, el estudiante será capaz de:

1. Comprender la necesidad y la lógica detrás de las estructuras de repetición.
2. Implementar bucles `for` para iteraciones con rango conocido.
3. Implementar bucles `while` para iteraciones con condición de entrada.
4. Implementar bucles `do-while` para iteraciones con condición de salida (ejecución garantizada).
5. Identificar y aplicar los **roles de variables** en bucles: contadoras, acumuladoras y banderas.
6. Distinguir entre `i++` (post-incremento) y `++i` (pre-incremento).
7. Utilizar `break` y `continue` para alterar el flujo interno de un bucle.
8. Implementar **bucles anidados** para problemas bidimensionales.
9. Elegir el tipo de bucle más apropiado según el problema a resolver.

---

## 3. Fundamentos Teóricos

### 3.1. Anatomía de un Bucle

Todo bucle tiene cuatro componentes esenciales:

```
┌──────────────────────────────────────────┐
│  1. INICIALIZACIÓN                        │  Establecer el estado inicial
│     (int i = 0; total = 0;)              │  del bucle antes de entrar.
└──────────────┬───────────────────────────┘
               ▼
         ┌───────────┐    No
         │ 2. CONDICIÓN ├─────────────┐
         │ (¿i < 10?) │              │
         └─────┬──────┘              │
            Sí │                     │
               ▼                     │
    ┌──────────────────┐             │
    │ 3. CUERPO        │             │
    │ (instrucciones   │             │
    │  que se repiten) │             │
    └────────┬─────────┘             │
             ▼                       │
    ┌──────────────────┐             │
    │ 4. ACTUALIZACIÓN │             │
    │ (i++)            │             │
    └────────┬─────────┘             │
             │                       │
             └──── vuelve a ◄────────┘
                  evaluar             
                  condición      [Sale del bucle]
```

Si alguno de estos componentes falla:
- **Sin condición de parada** → Bucle infinito (el programa nunca termina).
- **Sin actualización** → La condición nunca cambia → Bucle infinito.
- **Sin inicialización** → Comportamiento impredecible (variable con basura).

### 3.2. Los Tres Tipos de Bucles en C

| Bucle | Evalúa condición | Garantiza ejecución | Uso principal |
|---|---|---|---|
| `for` | **Antes** de cada iteración | No (puede no ejecutarse) | Rangos conocidos, conteos fijos |
| `while` | **Antes** de cada iteración | No (puede no ejecutarse) | Condiciones dinámicas, centinelas |
| `do-while` | **Después** de cada iteración | **Sí** (mínimo 1 vez) | Menús simples |

### 3.3. Bucle `for`

Es el bucle más estructurado. **Los tres componentes** (inicialización, condición, actualización) están en una sola línea, lo que lo hace ideal cuando **sabemos cuántas veces** queremos repetir.

```c
for (inicializacion; condicion; actualizacion) {
    // Cuerpo del bucle
}
```

**Flujo de ejecución:**
1. Se ejecuta la **inicialización** (una sola vez, al inicio).
2. Se evalúa la **condición**. Si es falsa, el bucle termina.
3. Se ejecuta el **cuerpo** del bucle.
4. Se ejecuta la **actualización**.
5. Se vuelve al paso 2.

```c
// Ejemplo: Imprimir los números del 1 al 5
for (int i = 1; i <= 5; i++) {
    printf("%d ", i);
}
// Salida: 1 2 3 4 5

// Ejemplo: Contar de 10 a 0 (decremento)
for (int i = 10; i >= 0; i--) {
    printf("%d ", i);
}
// Salida: 10 9 8 7 6 5 4 3 2 1 0

// Ejemplo: Contar de 2 en 2
for (int i = 0; i <= 20; i += 2) {
    printf("%d ", i);
}
// Salida: 0 2 4 6 8 10 12 14 16 18 20
```

### 3.4. Bucle `while`

Evalúa la condición **antes** de cada iteración. Si la condición es falsa desde el inicio, el cuerpo **nunca se ejecuta**. Es ideal cuando **no sabemos cuántas veces** se repetirá.

```c
while (condicion) {
    // Cuerpo del bucle
    // IMPORTANTE: Algo aquí debe eventualmente hacer la condición falsa
}
```

```c
// Ejemplo: Leer números hasta que el usuario ingrese 0
int numero;
printf("Ingrese un numero (0 para salir): ");
scanf("%d", &numero);

while (numero != 0) {
    printf("Ingresaste: %d\n", numero);
    printf("Ingrese otro numero (0 para salir): ");
    scanf("%d", &numero);
}
```

### 3.5. Bucle `do-while`

Evalúa la condición **después** de cada iteración, lo que **garantiza que el cuerpo se ejecute al menos una vez**. Ideal para menús y validación de entrada.

```c
do {
    // Cuerpo del bucle (se ejecuta al menos 1 vez)
} while (condicion);  // ← NOTA: Tiene punto y coma al final
```

```c
// Ejemplo: Menú que se muestra al menos una vez
int opcion;
do {
    printf("1. Jugar\n");
    printf("2. Opciones\n");
    printf("3. Salir\n");
    scanf("%d", &opcion);
} while (opcion != 3);
```

### 3.6. Roles de las Variables en Bucles

Para que un bucle sea útil y no infinito, las variables dentro de él cumplen **roles específicos**:

#### 3.6.1. Variables Contadoras

Llevan la cuenta de cuántas veces ha ocurrido algo. Se incrementan (o decrementan) en una **cantidad fija** (generalmente 1) en cada iteración.

```c
int contador = 0;           // Inicialización en 0
contador = contador + 1;    // Forma explícita
contador++;                 // Forma abreviada (post-incremento)
++contador;                 // Forma abreviada (pre-incremento)
```

#### 3.6.2. Variables Acumuladoras

"Recolectan" o **suman valores que varían** en cada iteración. A diferencia del contador que suma siempre 1, el acumulador suma el valor de otra variable.

```c
float totalVentas = 0.0;     // ¡DEBE inicializarse en 0!
totalVentas += ventaActual;   // Suma el valor variable de cada iteración
// Equivale a: totalVentas = totalVentas + ventaActual;
```

>  **Regla de oro:** Los acumuladores **SIEMPRE deben inicializarse** antes del bucle:
> - En `0` si acumulan sumas
> - En `1` si acumulan multiplicaciones (productos)
> 
> Si no se inicializan, contendrán basura de memoria y el resultado será incorrecto.

#### 3.6.3. Banderas o Centinelas (Flags)

Variables (usualmente `bool` o `int`) que indican si un **evento específico ha ocurrido**. Se usan para controlar cuándo debe detenerse un bucle.

```c
#include <stdbool.h>

bool encontrado = false;     // Bandera inicializada

while (!encontrado) {
    // Buscar algo...
    if (/* condición de éxito */) {
        encontrado = true;   // Cambiar la bandera detiene el bucle
    }
}
```

### 3.7. Operadores de Incremento: `i++` vs `++i`

Ambos suman 1 a la variable, pero difieren en **cuándo** lo hacen si están **dentro de una expresión**:

| Operador | Nombre | Comportamiento |
|---|---|---|
| `i++` | Post-incremento | Usa el valor **actual**, luego suma 1 |
| `++i` | Pre-incremento | Suma 1 **primero**, luego usa el nuevo valor |

```c
int a = 5;
int b = a++;    // b = 5 (usa el valor actual de a), luego a se vuelve 6
printf("a=%d, b=%d\n", a, b); // a=6, b=5

int c = 5;
int d = ++c;    // c se vuelve 6 PRIMERO, luego d = 6
printf("c=%d, d=%d\n", c, d); // c=6, d=6
```

> **Nota práctica:** En el bloque de actualización de un `for` (`for(i=0; i<10; i++)`) o como instrucción aislada (`i++;`), **no hay diferencia funcional**. La distinción solo importa cuando se usan dentro de expresiones más grandes.

### 3.8. Control de Flujo: `break` y `continue`

Permiten **alterar el flujo normal** de un bucle desde su interior:

| Instrucción | Efecto | Analogía |
|---|---|---|
| `break` | **Termina** el bucle inmediatamente. Sale por completo. | Botón de "abortar misión" |
| `continue` | **Salta** el resto de la iteración actual y pasa a la siguiente. | Botón de "saltar este turno" |

```c
// break: Salir del bucle cuando encontremos el 5
for (int i = 1; i <= 10; i++) {
    if (i == 5) break;
    printf("%d ", i);
}
// Salida: 1 2 3 4

// continue: Saltar los números pares
for (int i = 1; i <= 10; i++) {
    if (i % 2 == 0) continue;
    printf("%d ", i);
}
// Salida: 1 3 5 7 9
```

### 3.9. Bucles Anidados

Un bucle dentro de otro. El bucle **interno** se ejecuta completamente por cada iteración del bucle **externo**. Son esenciales para trabajar con matrices, tablas y patrones bidimensionales.

```
Bucle externo (filas): iteración 1
    Bucle interno (columnas): iteración 1, 2, 3, ..., N
Bucle externo (filas): iteración 2
    Bucle interno (columnas): iteración 1, 2, 3, ..., N
...
```

Si el bucle externo itera M veces y el interno N veces, el cuerpo del interno se ejecuta **M × N veces**.

```c
// Ejemplo: Tabla de multiplicar del 1 al 3, del 1 al 5
for (int tabla = 1; tabla <= 3; tabla++) {        // Bucle externo: 3 tablas
    for (int mult = 1; mult <= 5; mult++) {       // Bucle interno: 5 multiplicaciones
        printf("%d x %d = %d\n", tabla, mult, tabla * mult);
    }
    printf("---\n");
}
// Total de printf ejecutados: 3 × 5 = 15
```

### 3.10. ¿Qué Bucle Usar? — Guía de Decisión Profunda

Elegir el bucle correcto no es solo cuestión de preferencia personal: cada uno tiene un **propósito comunicativo**. El bucle que elijas le dice al lector de tu código **qué tipo de problema estás resolviendo**. Usar el bucle equivocado no producirá un error de compilación, pero sí hará tu código confuso y difícil de mantener.

#### 3.10.1. Usar `for` — Cuando conoces el rango o la cantidad

El `for` es la elección correcta cuando:
- **Sabes exactamente cuántas veces** se va a repetir (o puedes calcularlo antes de entrar al bucle).
- Estás **recorriendo un rango numérico** (del 1 al 100, del 0 al N-1).
- Estás **iterando sobre una colección** con índice (arreglos, cadenas de texto).
- El **inicio, condición y paso** son claros y caben en una sola línea.

**Analogía del mundo real:** Es como un reloj despertador programado. Sabes que sonará exactamente 5 veces. No hay incertidumbre.

```c
//  IDEAL para for: Recorrer un rango fijo
for (int i = 1; i <= 12; i++) {
    printf("%d x 5 = %d\n", i, i * 5);
}

//  IDEAL para for: Recorrer un arreglo
int notas[] = {85, 92, 78, 95, 88};
int n = 5;
for (int i = 0; i < n; i++) {
    printf("Nota %d: %d\n", i + 1, notas[i]);
}

//  IDEAL para for: Contar de N a 0 (cuenta regresiva)
for (int segundos = 10; segundos >= 0; segundos--) {
    printf("%d... ", segundos);
}
printf("¡Despegue!\n");

//  IDEAL para for: Recorrer caracteres de una cadena
char nombre[] = "Carlos";
for (int i = 0; nombre[i] != '\0'; i++) {
    printf("Caracter %d: '%c'\n", i, nombre[i]);
}
```

**¿Cuándo NO usar `for`?** Cuando no sabes cuántas veces se repetirá. Un `for` sin una condición de conteo clara es confuso:

```c
//  MAL USO de for: No hay rango claro, la condición depende de entrada del usuario
for (;;) {
    int x;
    scanf("%d", &x);
    if (x == 0) break;
}
// Esto funciona pero es mejor con while
```

#### 3.10.2. Usar `while` — Cuando la condición manda

El `while` es la elección correcta cuando:
- **No sabes cuántas veces** se repetirá (depende de datos externos o condiciones dinámicas).
- La condición **puede ser falsa desde el inicio** (quizás el bucle no se ejecute nunca).
- Estás **esperando un evento**: leer un archivo, procesar una cola de mensajes, buscar un dato.
- Tienes un **centinela** (valor especial que indica el fin): leer números hasta que el usuario ingrese -1.

**Analogía del mundo real:** Es como pescar. Lanzas el anzuelo y esperas. Puede que pesques algo en el primer intento, en el décimo, o que nunca pesques nada. No hay un número fijo de intentos.

```c
//  IDEAL para while: Leer datos hasta un centinela
int numero;
printf("Ingrese numeros (-1 para terminar): ");
scanf("%d", &numero);

while (numero != -1) {
    printf("Procesando: %d\n", numero);
    printf("Siguiente: ");
    scanf("%d", &numero);
}

//  IDEAL para while: Procesar una condición dinámica
int saldo = 1000;
int retiro;
printf("Saldo: $%d\n", saldo);
printf("Monto a retirar (0 para cancelar): ");
scanf("%d", &retiro);

while (retiro > 0 && saldo > 0) {
    if (retiro > saldo) {
        printf("Fondos insuficientes.\n");
    } else {
        saldo -= retiro;
        printf("Retiro exitoso. Saldo restante: $%d\n", saldo);
    }
    printf("Monto a retirar (0 para cancelar): ");
    scanf("%d", &retiro);
}

//  IDEAL para while: Búsqueda lineal
int datos[] = {4, 8, 15, 16, 23, 42};
int buscado = 16;
int i = 0;
int encontrado = 0;

while (i < 6 && !encontrado) {
    if (datos[i] == buscado) {
        encontrado = 1;
    }
    i++;
}
```

**¿Cuándo NO usar `while`?** Cuando tienes un conteo fijo y conocido. Un `while` con un contador explícito es un `for` disfrazado:

```c
//  MAL USO de while: Esto es un for disfrazado
int i = 0;
while (i < 10) {
    printf("%d\n", i);
    i++;
}

//  MEJOR: Expresar la intención claramente con for
for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
}
```

#### 3.10.3. Usar `do-while` — Cuando necesitas ejecutar primero, preguntar después

El `do-while` es la elección correcta cuando:
- El cuerpo **debe ejecutarse al menos una vez** antes de evaluar la condición.
- Estás implementando un **menú de opciones** (necesitas mostrarlo antes de que el usuario elija).
- Estás **validando entrada del usuario** (necesitas pedirle el dato antes de verificarlo).
- El **dato que evalúa la condición** se genera DENTRO del bucle.

**Analogía del mundo real:** Es como un examen con derecho a repetir. Primero haces el examen (al menos una vez), y después se evalúa si aprobaste. Si no aprobaste, lo vuelves a intentar.

```c
//  IDEAL para do-while: Menú de opciones
int opcion;
do {
    printf("\n=== MENU ===\n");
    printf("1. Nuevo registro\n");
    printf("2. Buscar\n");
    printf("3. Salir\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1: printf("Creando registro...\n"); break;
        case 2: printf("Buscando...\n"); break;
        case 3: printf("Adios!\n"); break;
        default: printf("Opcion invalida.\n"); break;
    }
} while (opcion != 3);

//  IDEAL para do-while: Ejecutar al menos una vez antes de verificar
int edad;
do {
    printf("Ingrese su edad (1-120): ");
    scanf("%d", &edad);
    if (edad < 1 || edad > 120) {
        printf("Error: edad fuera de rango.\n");
    }
} while (edad < 1 || edad > 120);
// Al salir del bucle, 'edad' tiene un valor válido garantizado

//  IDEAL para do-while: Juego "adivina el número"
int secreto = 42, intento;
do {
    printf("Adivina el numero: ");
    scanf("%d", &intento);
    if (intento < secreto) printf("Mas alto!\n");
    else if (intento > secreto) printf("Mas bajo!\n");
} while (intento != secreto);
printf("Correcto!\n");
```

**¿Cuándo NO usar `do-while`?** Cuando la condición podría ser falsa desde el inicio y NO queremos ejecutar el cuerpo:

```c
//  MAL USO de do-while: Si n fuera 0, no deberíamos ejecutar nada
int n = 0;
int i = 1;
do {
    printf("%d\n", i);
    i++;
} while (i <= n);
// Imprime "1" incluso cuando n es 0. No es lo que queremos.

//  MEJOR: Usar while para evitar la ejecución innecesaria
int i = 1;
while (i <= n) {
    printf("%d\n", i);
    i++;
}
```

#### 3.10.4. Bucles infinitos controlados — `while(1)` / `for(;;)`

Para programas que deben ejecutarse indefinidamente hasta una condición interna:

```c
// Servidor, daemon, sistema embebido
while (1) {
    int comando = recibirComando();
    if (comando == APAGAR) break;
    procesarComando(comando);
}

// Equivalente con for
for (;;) {
    // ...
    if (condicionDeSalida) break;
}
```

#### 3.10.5. Tabla Comparativa Completa

| Criterio | `for` | `while` | `do-while` |
|---|---|---|---|
| **¿Cuándo evalúa?** | Antes de cada iteración | Antes de cada iteración | Después de cada iteración |
| **¿Ejecuta al menos 1 vez?** | No garantizado | No garantizado | **Sí, siempre** |
| **¿Cuántas iteraciones?** | Conocidas de antemano | Desconocidas | Desconocidas (mínimo 1) |
| **Componentes en la sintaxis** | 3 en una línea | Solo condición | Solo condición + `;` |
| **Mejor para** | Conteos, rangos, arreglos | Centinelas, búsquedas, streams | Menús, validación de entrada |
| **Ejemplo típico** | Tabla de multiplicar | Leer hasta EOF | Pedir contraseña |
| **Peligro principal** | Off-by-one (±1 iteración) | Olvidar actualización → infinito | Ejecutar cuando no debería |

#### 3.10.6. Diagrama de Decisión

```
¿Necesitas repetir algo?
│
├── ¿Sabes CUÁNTAS veces?
│   ├── SÍ → FOR
│   │   Ejemplos: tabla de multiplicar, recorrer arreglo,
│   │   cuenta regresiva, generar patrones, series numéricas
│   │
│   └── NO → ¿Debe ejecutarse AL MENOS 1 vez?
│       │
│       ├── SÍ → DO-WHILE
│       │   Ejemplos: menú de opciones, validar edad,
│       │   pedir contraseña, juego "adivina", reintentos
│       │
│       └── NO (podría no ejecutarse) → WHILE
│           Ejemplos: leer archivo hasta EOF, buscar en lista,
│           procesar cola, esperar señal, centinela -1
│
└── ¿Es un proceso continuo (servidor, daemon)?
    └── WHILE(1) con BREAK interno
        Ejemplos: servidor web, sistema operativo, monitor de sensores
```

#### 3.10.7. Errores de Elección Frecuentes

**Error 1: Usar `for` cuando no hay rango claro**
```c
//  Confuso: ¿cuántas veces se repetirá?
for (int intentos = 0; !acertoContrasena; intentos++) { ... }

//  Más claro con while o do-while:
do {
    printf("Ingrese contrasena: ");
    scanf("%d", &intento);
} while (intento != contrasenaCorrecta);
```

**Error 2: Usar `while` para menús (olvidando la primera ejecución)**
```c
//  Requiere código duplicado para mostrar el menú antes del bucle
int opcion = -1; // Valor artificial para entrar al while
while (opcion != 3) {
    printf("1. Opcion A\n2. Opcion B\n3. Salir\n");
    scanf("%d", &opcion);
}

//  do-while elimina la necesidad de valor artificial:
int opcion;
do {
    printf("1. Opcion A\n2. Opcion B\n3. Salir\n");
    scanf("%d", &opcion);
} while (opcion != 3);
```

**Error 3: Usar `do-while` cuando podría no ejecutarse**
```c
//  Si el archivo está vacío, no deberíamos procesar nada
do {
    dato = leerDato(archivo);
    procesar(dato);
} while (!finDeArchivo(archivo));
// Procesará un dato basura si el archivo está vacío

//  while protege contra archivos vacíos:
while (!finDeArchivo(archivo)) {
    dato = leerDato(archivo);
    procesar(dato);
}
```

---

## 4. Sintaxis y Estructura

### 4.1. Sintaxis del `for`

```c
for (inicializacion; condicion; actualizacion) {
    instrucciones;
}

// Ejemplo concreto:
for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
}
```

### 4.2. Sintaxis del `while`

```c
inicializacion;
while (condicion) {
    instrucciones;
    actualizacion;
}

// Ejemplo concreto:
int i = 0;
while (i < 10) {
    printf("%d\n", i);
    i++;
}
```

### 4.3. Sintaxis del `do-while`

```c
inicializacion;
do {
    instrucciones;
    actualizacion;
} while (condicion);  // ← ¡No olvidar el punto y coma!

// Ejemplo concreto:
int i = 0;
do {
    printf("%d\n", i);
    i++;
} while (i < 10);
```

### 4.4. Equivalencia entre los tres bucles

Los tres bucles pueden resolver los mismos problemas. La elección depende de la **legibilidad** y la **naturaleza del problema**:

```c
// Los tres imprimen: 0 1 2 3 4

// FOR (más compacto para rangos)
for (int i = 0; i < 5; i++) {
    printf("%d ", i);
}

// WHILE (más flexible para condiciones)
int i = 0;
while (i < 5) {
    printf("%d ", i);
    i++;
}

// DO-WHILE (garantiza al menos una ejecución)
int j = 0;
do {
    printf("%d ", j);
    j++;
} while (j < 5);
```

---

## 5. Ejemplos Explicados Paso a Paso

### Ejemplo 1: Roles de Variables en Bucles (ver `Repeticion.c`)

Demuestra de forma práctica los tres roles de variables: **contadoras** (bucle for), **acumuladoras** (sumatoria de pesos) y **banderas** (menú de cajero con while + bool). También muestra `break` y `continue`.

### Ejemplo 2: Bucles Anidados y Patrones (ver `EjemploBuclesAnidados.c`)

Genera patrones visuales con asteriscos usando bucles anidados: cuadrado sólido, triángulo rectángulo y rectángulo hueco. Ideal para entender la relación fila-columna.

### Ejemplo 3: Validación con while(1) (ver `EjemploWhileValidacion.c`)

Implementa un sistema de registro con validación robusta de entrada usando `while(1)`: valida rangos numéricos, menús de opciones, y muestra por qué `while(1)` con `break` es ideal para validaciones complejas.

---

## 6. Ejercicios Prácticos

### Nivel Básico

**Ejercicio 1 — Tabla de Multiplicar:**
Escriba un programa que lea un número entero y muestre su tabla de multiplicar del 1 al 12.

**Ejercicio 2 — Sumatoria:**
Escriba un programa que lea N números ingresados por el usuario y muestre su suma total y promedio. El valor de N debe ser solicitado al inicio.

**Ejercicio 3 — Conteo Regresivo:**
Escriba un programa que lea un número positivo y haga una cuenta regresiva hasta 0, mostrando cada número. Al final, imprima "¡Despegue!".

### Nivel Intermedio

**Ejercicio 4 — Factorial:**
Escriba un programa que calcule el factorial de un número ingresado por el usuario.
Recuerde: `5! = 5 × 4 × 3 × 2 × 1 = 120` y `0! = 1`.
*Pista: Use un acumulador inicializado en 1 con multiplicación.*

**Ejercicio 5 — Números Primos:**
Escriba un programa que determine si un número ingresado es primo o no.
Un número primo solo es divisible entre 1 y sí mismo.
*Pista: Intente dividir el número entre todos los enteros desde 2 hasta número/2. Si alguno da residuo 0, no es primo.*

**Ejercicio 6 — Validación de Contraseña:**
Escriba un programa que solicite una contraseña numérica (un entero). La contraseña correcta es `1234`. El usuario tiene un máximo de 3 intentos. Use `while(1)` con un contador de intentos y `break`.

### Nivel Desafiante

**Ejercicio 7 — Pirámide de Números:**
Escriba un programa que, dado un número N, genere una pirámide:
```
    1
   1 2
  1 2 3
 1 2 3 4
1 2 3 4 5
```
*Pista: Necesita bucles anidados: uno para espacios y otro para números.*

**Ejercicio 8 — Serie de Fibonacci:**
Genere los primeros N términos de la serie de Fibonacci: 0, 1, 1, 2, 3, 5, 8, 13...
Cada término es la suma de los dos anteriores.
*Pista: Necesita dos variables auxiliares para recordar los dos valores previos.*

**Ejercicio 9 — Máximo y Mínimo:**
Lea N números del usuario y determine cuál fue el mayor y cuál fue el menor. No use arreglos; actualice las variables `max` y `min` en cada iteración.

---

## 7. Errores Comunes

### Error 1: Bucle infinito por olvidar la actualización

```c
//  ERROR: i nunca cambia, la condición siempre es verdadera
int i = 0;
while (i < 10) {
    printf("%d\n", i);
    // ¡Falta i++! → Bucle infinito
}

//  CORRECTO:
int i = 0;
while (i < 10) {
    printf("%d\n", i);
    i++;  // Actualización que eventualmente hace falsa la condición
}
```

### Error 2: Error de uno (off-by-one)

```c
//  ERROR: Imprime 0 a 9 (10 números), pero queríamos 1 a 10
for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
}

//  CORRECTO (opción A): Empezar en 1, condición <=
for (int i = 1; i <= 10; i++) {
    printf("%d\n", i);
}

//  CORRECTO (opción B): Empezar en 0, sumar 1 al imprimir
for (int i = 0; i < 10; i++) {
    printf("%d\n", i + 1);
}
```

### Error 3: No inicializar el acumulador

```c
//  ERROR: 'suma' contiene basura de memoria
int suma; // Podría ser -858993460 o cualquier valor aleatorio
for (int i = 1; i <= 5; i++) {
    suma += i;  // Acumula sobre basura
}
printf("Suma: %d\n", suma); // Resultado impredecible

//  CORRECTO:
int suma = 0;  // Inicializar SIEMPRE en 0 para sumas
for (int i = 1; i <= 5; i++) {
    suma += i;
}
printf("Suma: %d\n", suma); // Suma: 15
```

### Error 4: Olvidar el punto y coma del `do-while`

```c
//  ERROR DE COMPILACIÓN:
do {
    printf("Hola\n");
} while (condicion)  // Falta el ;

//  CORRECTO:
do {
    printf("Hola\n");
} while (condicion);  // ← El punto y coma es obligatorio
```

### Error 5: Usar `=` en vez de `==` en la condición del bucle

```c
//  ERROR: Asigna 1 a i, que siempre es verdadero → bucle infinito
while (i = 1) {
    printf("Iteracion\n");
}

//  CORRECTO:
while (i == 1) {
    printf("Iteracion\n");
}
```

### Error 6: Poner punto y coma después de `for` o `while`

```c
//  ERROR SUTIL: El punto y coma crea un bucle vacío
for (int i = 0; i < 5; i++);  // ← Este ; es el "cuerpo" (vacío)
{
    printf("%d\n", i);  // Se ejecuta una sola vez, fuera del bucle
}

//  CORRECTO: Sin punto y coma después del paréntesis
for (int i = 0; i < 5; i++) {
    printf("%d\n", i);
}
```

---

## 8. Buenas Prácticas

1. **Siempre inicialice contadores y acumuladores.** Contadores en `0` o `1`, acumuladores de suma en `0`, acumuladores de producto en `1`.

2. **Use `for` cuando conozca el número de iteraciones.** Es más legible y compacto: todo el control del bucle está en una línea.

3. **Use `do-while` para menús simples y `while(1)` para validación de entrada.** Garantiza claridad y robustez.

4. **Evite bucles anidados de más de 3 niveles.** Si necesita más, considere usar funciones para separar la lógica.

5. **Nombre sus variables de control descriptivamente:** `fila`, `columna`, `intento` son mejores que `i`, `j`, `k` (excepto en bucles simples y convencionales).

6. **No modifique la variable de control dentro del cuerpo del `for`.** Esto hace el código difícil de seguir y propenso a errores.

7. **Use `break` con moderación.** Un `break` bien ubicado puede simplificar la lógica, pero múltiples `break` hacen el flujo difícil de seguir.

8. **Verifique siempre que su bucle puede terminar.** Antes de ejecutar, pregúntese: "¿Hay alguna condición que haga que este bucle nunca termine?"

9. **Prefiera `++i` sobre `i++`** en la actualización del `for`. Aunque en C para tipos primitivos la diferencia es negligible, es una buena costumbre (en C++ la diferencia puede ser significativa con objetos).

---

## 9. Resumen de la Clase

| Concepto | Descripción clave |
|---|---|
| **for** | Bucle compacto para rangos conocidos. Inicialización, condición y actualización en una línea. |
| **while** | Evalúa la condición ANTES. Puede no ejecutarse nunca. Ideal para condiciones dinámicas. |
| **do-while** | Evalúa la condición DESPUÉS. Se ejecuta al menos 1 vez. Ideal para menús. |
| **Contador** | Variable que se incrementa en valor fijo (generalmente 1). Ejemplo: `i++`. |
| **Acumulador** | Variable que suma valores variables. Debe inicializarse en 0. Ejemplo: `total += venta`. |
| **Bandera/Centinela** | Variable bool/int que controla cuándo detener el bucle. |
| **break** | Termina el bucle inmediatamente (sale por completo). |
| **continue** | Salta a la siguiente iteración (omite el resto del cuerpo actual). |
| **Bucles anidados** | Un bucle dentro de otro. El interno se ejecuta completamente por cada iteración del externo. |
| **`i++` vs `++i`** | Post-incremento vs pre-incremento. En `for` da igual; en expresiones, difieren en el momento de incrementar. |

### Archivos de esta clase:

| Archivo | Contenido |
|---|---|
| `Repeticion.c` | Ejemplo principal: contadores, acumuladores, banderas, break y continue |
| `EjemploBuclesAnidados.c` | Patrones con asteriscos: cuadrado, triángulo, rectángulo hueco |
| `EjemploWhileValidacion.c` | Sistema de registro con validación robusta de entrada usando while(1) |

### Archivos de práctica (`practica/`):

| Archivo | Contenido |
|---|---|
| `practica/eje1.c` | Ejercicio complementario: tabla de multiplicar con for, while y do-while |
| `practica/caso1.c` | Ejercicio complementario: cuadrado de asteriscos con bucles anidados |
| `practica/rectangulo.c` | Ejercicio complementario: rectángulo hueco con ternarios y validación |
| `practica/ternario.c` | Ejercicio complementario: clasificación con ternarios anidados |
