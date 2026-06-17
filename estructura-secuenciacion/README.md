# Clase 1 — Estructuras de Secuenciación en C

---

## 1. Introducción

La **secuenciación** es la estructura de control más fundamental en la programación imperativa. Consiste en ejecutar las instrucciones **exactamente en el orden en que fueron escritas**, de arriba hacia abajo, una tras otra, sin saltos, bifurcaciones ni repeticiones.

Todo programa en C, sin importar su complejidad, se construye sobre esta base. Antes de aprender a tomar decisiones (`if`) o a repetir acciones (`for`, `while`), es imprescindible dominar la ejecución secuencial: declarar variables, leer datos del usuario, procesarlos mediante operaciones y mostrar resultados.

### ¿Por qué es importante?

- Es el **flujo natural** de cualquier algoritmo: entrada → procesamiento → salida.
- Permite comprender cómo la computadora interpreta y ejecuta instrucciones.
- Establece las bases para entender estructuras más complejas.
- Toda aplicación real (calculadoras, formularios, sensores, reportes) contiene bloques secuenciales.

### Aplicaciones prácticas

- Cálculo de áreas, promedios, conversiones de unidades.
- Captura de datos de un formulario y generación de reportes.
- Procesamiento de datos de sensores (temperatura, peso, distancia).
- Cualquier programa que reciba datos, los transforme y muestre un resultado.

---

## 2. Objetivos de Aprendizaje

Al finalizar esta clase, el estudiante será capaz de:

1. Comprender y explicar el flujo de ejecución secuencial en C.
2. Declarar e inicializar variables utilizando los tipos de datos primitivos (`int`, `float`, `double`, `char`).
3. Utilizar correctamente los especificadores de formato (`%d`, `%f`, `%lf`, `%c`, `%s`) en `printf` y `scanf`.
4. Aplicar el operador de dirección de memoria (`&`) para la lectura de datos con `scanf`.
5. Realizar operaciones aritméticas respetando la precedencia de operadores.
6. Identificar y aplicar los roles lógicos de las variables (variables de trabajo, constantes).
7. Formatear la salida en consola utilizando caracteres de escape (`\n`, `\t`).
8. Realizar conversiones de tipos (casting) de forma explícita e implícita.

---

## 3. Fundamentos Teóricos

### 3.1. El Flujo Secuencial

En la programación imperativa, el **flujo secuencial** significa que el procesador ejecuta cada instrucción en el orden exacto en que aparece en el código fuente. No hay saltos, no hay repeticiones, no hay bifurcaciones. Es como leer un libro: página 1, luego página 2, luego página 3.

```
┌─────────────────────────┐
│  Instrucción 1          │  ← Se ejecuta primero
└────────────┬────────────┘
             ▼
┌─────────────────────────┐
│  Instrucción 2          │  ← Se ejecuta segundo
└────────────┬────────────┘
             ▼
┌─────────────────────────┐
│  Instrucción 3          │  ← Se ejecuta tercero
└────────────┬────────────┘
             ▼
          [  FIN  ]
```

Cada línea de código se ejecuta **una sola vez** y en **orden descendente**. Este es el comportamiento por defecto de cualquier programa en C.

### 3.2. Estructura Mínima de un Programa en C

Todo programa en C requiere al menos:

```c
#include <stdio.h>   // Directiva del preprocesador: incluye funciones de E/S

int main() {         // Punto de entrada del programa
    // Aquí van las instrucciones
    return 0;        // Indica al sistema operativo que el programa terminó correctamente
}
```

**Componentes esenciales:**

| Componente | Descripción |
|---|---|
| `#include <stdio.h>` | Incluye la biblioteca estándar de entrada/salida. Sin ella, no podemos usar `printf` ni `scanf`. |
| `int main()` | Función principal. Todo programa en C comienza su ejecución aquí. El `int` indica que la función devuelve un número entero. |
| `{ }` | Las llaves delimitan el **cuerpo** de la función. Todo el código ejecutable va dentro de ellas. |
| `return 0;` | Devuelve `0` al sistema operativo, indicando que el programa finalizó sin errores. Por convención, cualquier valor distinto de `0` indica un error. |

### 3.3. Tipos de Datos Primitivos

C es un lenguaje **tipado estáticamente**: cada variable debe tener un tipo declarado antes de ser utilizada. El tipo determina cuánta memoria se reserva y qué valores puede almacenar.

| Tipo | Tamaño típico | Rango aproximado | Uso principal | Especificador |
|---|---|---|---|---|
| `int` | 4 bytes | -2,147,483,648 a 2,147,483,647 | Números enteros (edad, cantidad, año) | `%d` o `%i` |
| `float` | 4 bytes | ±3.4 × 10³⁸ (6-7 dígitos de precisión) | Decimales con precisión simple (peso, precio) | `%f` |
| `double` | 8 bytes | ±1.7 × 10³⁰⁸ (15-16 dígitos de precisión) | Decimales con doble precisión (cálculos científicos) | `%lf` (scanf) / `%f` (printf) |
| `char` | 1 byte | -128 a 127 (o un carácter ASCII) | Un solo carácter ('A', 'z', '9') | `%c` |

**Conceptos clave:**

- **Un byte = 8 bits.** Un `int` de 4 bytes utiliza 32 bits para representar el número en binario.
- **`float` vs `double`:** Ambos almacenan decimales, pero `double` ofrece el doble de precisión. En cálculos científicos o financieros donde la precisión importa, se prefiere `double`.
- **`char` y ASCII:** Internamente, un `char` almacena un número entero (0-127) que corresponde a un carácter en la tabla ASCII. Por ejemplo, `'A'` es el número 65, `'a'` es 97, `'0'` es 48.

### 3.4. Declaración e Inicialización de Variables

**Declarar** una variable significa reservar un espacio en la memoria RAM con un nombre y un tipo. **Inicializar** es asignarle un valor inicial.

```c
// Solo declaración (la variable existe, pero contiene "basura" de memoria)
int edad;

// Declaración con inicialización (la variable existe y tiene un valor definido)
int anioActual = 2026;

// Múltiples declaraciones del mismo tipo
float peso, altura, imc;
```

>  **Advertencia:** Una variable declarada pero no inicializada contiene un valor **indeterminado** (lo que había previamente en esa dirección de memoria). Usar una variable sin inicializar es un error lógico muy común.

### 3.5. Entrada y Salida de Datos

#### `printf` — Salida de datos (imprimir en consola)

`printf` (print formatted) escribe texto formateado en la consola. Utiliza **especificadores de formato** como marcadores de posición que serán reemplazados por los valores de las variables.

```c
printf("Texto con %especificador", variable);
```

Ejemplos:

```c
int edad = 25;
float peso = 72.5;
char inicial = 'W';

printf("Edad: %d años\n", edad);           // Imprime: Edad: 25 años
printf("Peso: %.2f kg\n", peso);            // Imprime: Peso: 72.50 kg
printf("Inicial: %c\n", inicial);           // Imprime: Inicial: W
printf("Edad: %d, Peso: %.1f\n", edad, peso); // Múltiples especificadores
```

#### `scanf` — Entrada de datos (leer del teclado)

`scanf` (scan formatted) lee datos desde el teclado y los almacena en variables. **Requiere el operador `&`** (dirección de memoria) antes de cada variable.

```c
scanf("%especificador", &variable);
```

**¿Por qué se necesita el `&`?** Porque `scanf` necesita saber **dónde** en la memoria RAM debe escribir el valor ingresado. El operador `&` devuelve la **dirección de memoria** de la variable, no su valor.

```
Sin &: scanf recibe el VALOR de la variable (inútil, no sabe dónde guardar)
Con &: scanf recibe la DIRECCIÓN donde debe guardar el dato 
```

### 3.6. Especificadores de Formato — Tabla Completa

| Especificador | Tipo | Uso en `printf` | Uso en `scanf` |
|---|---|---|---|
| `%d` o `%i` | `int` | Imprime un entero | Lee un entero |
| `%f` | `float` | Imprime un decimal | Lee un decimal `float` |
| `%lf` | `double` | Imprime un decimal (también `%f`) | Lee un decimal `double` |
| `%c` | `char` | Imprime un carácter | Lee un carácter |
| `%s` | `char[]` | Imprime una cadena de texto | Lee una cadena (sin espacios) |
| `%x` | `int` | Imprime en hexadecimal | Lee en hexadecimal |
| `%o` | `int` | Imprime en octal | Lee en octal |
| `%p` | puntero | Imprime una dirección de memoria | — |
| `%%` | — | Imprime el carácter `%` literal | — |

**Modificadores de precisión:**

```c
printf("%.2f", 3.14159);   // Imprime: 3.14       (2 decimales)
printf("%.4f", 3.14159);   // Imprime: 3.1416     (4 decimales, con redondeo)
printf("%10d", 42);         // Imprime:         42 (alineado a la derecha, 10 espacios)
printf("%-10d|", 42);       // Imprime: 42        | (alineado a la izquierda)
```

### 3.7. Operadores Aritméticos y Precedencia

| Operador | Operación | Ejemplo | Resultado |
|---|---|---|---|
| `+` | Suma | `5 + 3` | `8` |
| `-` | Resta | `5 - 3` | `2` |
| `*` | Multiplicación | `5 * 3` | `15` |
| `/` | División | `5 / 3` | `1` (división entera) |
| `%` | Módulo (residuo) | `5 % 3` | `2` |

**Precedencia de operadores** (de mayor a menor prioridad):

1. `()` — Paréntesis (se evalúan primero)
2. `*`, `/`, `%` — Multiplicación, división, módulo
3. `+`, `-` — Suma y resta

>  **División entera:** Cuando ambos operandos son `int`, C realiza **división entera** (trunca los decimales). `5 / 3` da `1`, no `1.666`. Para obtener decimales, al menos uno de los operandos debe ser `float` o `double`: `5.0 / 3` da `1.666667`.

### 3.8. Conversiones de Tipo (Casting)

#### Conversión implícita (automática)

C convierte automáticamente un tipo de menor rango a uno de mayor rango cuando se mezclan en una expresión:

```
char → int → float → double
```

```c
int entero = 5;
float decimal = 2.5;
float resultado = entero + decimal;  // 'entero' se promueve automáticamente a float
// resultado = 7.5
```

#### Conversión explícita (casting manual)

Se usa la sintaxis `(tipo)` antes de la expresión para forzar una conversión:

```c
int a = 5, b = 3;
float resultado = (float)a / b;  // Forzamos que 'a' sea tratado como float
// resultado = 1.666667 (ya no es división entera)
```

### 3.9. Roles de las Variables

Aunque técnicamente todas son variables, conceptualmente las clasificamos según su función:

| Rol | Descripción | Ejemplo |
|---|---|---|
| **Variable de entrada** | Almacena datos proporcionados por el usuario | `edad`, `peso`, `nombre` |
| **Variable de trabajo (auxiliar)** | Almacena resultados intermedios de cálculos | `promedio`, `area`, `imc` |
| **Constante** | Valor que no cambia durante la ejecución | `PI`, `GRAVEDAD`, `IVA` |

**Definir constantes en C:**

```c
// Método 1: Directiva del preprocesador (no es una variable, es sustitución textual)
#define PI 3.14159
#define IVA 0.15

// Método 2: Variable constante (ocupa memoria, pero no se puede modificar)
const float GRAVEDAD = 9.81;
const int DIAS_SEMANA = 7;
```

### 3.10. Caracteres de Escape

Son secuencias especiales que comienzan con `\` y producen efectos de formato en la consola:

| Secuencia | Efecto | Ejemplo visual |
|---|---|---|
| `\n` | Salto de línea (Enter) | Texto↵ |
| `\t` | Tabulación horizontal (Tab) | Texto→   → |
| `\\` | Imprime una barra invertida `\` | `C:\Users` |
| `\"` | Imprime una comilla doble `"` | `Dijo "hola"` |
| `\'` | Imprime una comilla simple `'` | `It's` |
| `\0` | Carácter nulo (fin de cadena) | — |
| `\a` | Sonido de alerta (beep) |  |

---

## 4. Sintaxis y Estructura

### 4.1. Estructura General de un Programa Secuencial

```c
// PASO 1: Directivas del preprocesador
#include <stdio.h>    // Siempre necesaria para E/S
#define CONSTANTE 100  // Constantes simbólicas (opcional)

// PASO 2: Función principal
int main() {
    // PASO 3: Declaración de variables
    int variable1;
    float variable2 = 0.0;
    
    // PASO 4: Entrada de datos
    printf("Ingrese un valor: ");
    scanf("%d", &variable1);
    
    // PASO 5: Procesamiento
    float resultado = variable1 * variable2;
    
    // PASO 6: Salida de datos
    printf("Resultado: %.2f\n", resultado);
    
    // PASO 7: Finalización
    return 0;
}
```

### 4.2. Reglas Sintácticas Fundamentales

1. **Cada instrucción termina con punto y coma** (`;`).
2. **Las variables deben declararse antes de usarse** (en C89, al inicio del bloque; en C99+, en cualquier punto).
3. **C distingue mayúsculas de minúsculas:** `edad`, `Edad` y `EDAD` son tres variables diferentes.
4. **Los nombres de variables** deben empezar con una letra o `_`, no pueden contener espacios ni caracteres especiales, y no pueden ser palabras reservadas (`int`, `return`, `if`, etc.).
5. **Los comentarios** no se ejecutan:
   - Una línea: `// Este es un comentario`
   - Multilínea: `/* Este es un comentario de varias líneas */`

### 4.3. Buenas Prácticas de Nombrado

```c
//  CORRECTO: nombres descriptivos en camelCase
int anioNacimiento;
float pesoEnKilogramos;
char inicialDelNombre;

//  INCORRECTO: nombres ambiguos o sin significado
int x;
float a;
char c;

//  CORRECTO: constantes en MAYÚSCULAS con guion bajo
#define VELOCIDAD_LUZ 299792458
const float TASA_INTERES = 0.05;
```

---

## 5. Ejemplos Explicados Paso a Paso

### Ejemplo 1: Registro de Paciente (ver `Secuenciacion.c`)

Este ejemplo demuestra el flujo secuencial completo: declarar variables de distintos tipos, leer datos del usuario, realizar cálculos con variables de trabajo y mostrar los resultados formateados.

**Conceptos clave demostrados:**
- Tipos `int`, `float`, `char`
- Especificadores `%d`, `%f`, `%c`
- Variables de trabajo (`edadCalculada`, `indiceMasaCorporal`)
- Formato de salida con `%.2f`

### Ejemplo 2: Operadores Aritméticos y Precedencia (ver `EjemploOperadores.c`)

Este ejemplo muestra cómo funcionan los operadores aritméticos, la diferencia entre división entera y decimal, y la importancia del orden de evaluación.

### Ejemplo 3: Conversiones de Tipo (ver `EjemploConversiones.c`)

Este ejemplo demuestra las conversiones implícitas y explícitas entre tipos de datos, mostrando cuándo y por qué son necesarias.

---

## 6. Ejercicios Prácticos

### Nivel Básico

**Ejercicio 1 — Datos Personales:**
Escriba un programa que solicite al usuario su nombre (como carácter inicial), edad y estatura en metros. Muestre los datos ingresados con formato:
```
Inicial: J
Edad: 20 años
Estatura: 1.75 m
```

**Ejercicio 2 — Área de un Rectángulo:**
Escriba un programa que solicite la base y la altura de un rectángulo (como números decimales) y calcule su área y perímetro. Muestre los resultados con 2 decimales.

**Ejercicio 3 — Conversión de Temperatura:**
Escriba un programa que convierta una temperatura de grados Celsius a Fahrenheit.
Fórmula: `F = (C × 9/5) + 32`

### Nivel Intermedio

**Ejercicio 4 — Desglose de Cambio:**
Dado un monto en centavos (ingresado como `int`), calcule cuántas monedas de 25, 10, 5 y 1 centavo se necesitan para dar el cambio exacto, utilizando la menor cantidad de monedas posible.
Ejemplo: 87 centavos = 3×25 + 1×10 + 0×5 + 2×1.
*Pista: Use el operador módulo `%` y la división entera `/`.*

**Ejercicio 5 — Intercambio de Variables:**
Escriba un programa que declare dos variables enteras, las muestre, luego intercambie sus valores usando una variable auxiliar, y vuelva a mostrarlas. Explique por qué la variable auxiliar es necesaria.

**Ejercicio 6 — Cálculo de Salario:**
Un empleado gana un salario por hora. Escriba un programa que lea el salario por hora y las horas trabajadas, luego calcule:
- Salario bruto = horas × salario/hora
- Deducción (15% del salario bruto)
- Salario neto = salario bruto - deducción

### Nivel Desafiante

**Ejercicio 7 — Distancia entre Dos Puntos:**
Dados dos puntos en un plano cartesiano (x1, y1) y (x2, y2), calcule la distancia euclidiana entre ellos.
Fórmula: `d = √((x2-x1)² + (y2-y1)²)`
*Pista: Necesitará incluir `<math.h>` y usar `sqrt()` y `pow()`. Compile con `-lm`.*

**Ejercicio 8 — Conversión de Tiempo:**
Dado un tiempo total en segundos (ingresado como `int`), conviértalo a horas, minutos y segundos restantes.
Ejemplo: 3661 segundos = 1 hora, 1 minuto, 1 segundo.

---

## 7. Errores Comunes

### Error 1: Olvidar el `&` en `scanf`

```c
//  ERROR: El programa se comportará de forma impredecible o se cerrará
int edad;
scanf("%d", edad);    // Falta el &

//  CORRECTO:
scanf("%d", &edad);   // & envía la dirección de memoria
```
**Consecuencia:** El programa intenta escribir en una dirección de memoria aleatoria, causando un fallo de segmentación (`segmentation fault`) o datos corruptos.

### Error 2: Usar especificador incorrecto

```c
//  ERROR: Usar %d para leer un float
float precio;
scanf("%d", &precio);  // %d es para int, no para float

//  CORRECTO:
scanf("%f", &precio);  // %f para float
```
**Consecuencia:** Los bytes se interpretan incorrectamente, produciendo valores basura.

### Error 3: División entera no esperada

```c
//  ERROR: Resultado esperado 1.666, pero da 1
int a = 5, b = 3;
float resultado = a / b;  // División entera: 5/3 = 1

//  CORRECTO: Forzar al menos un operando a float
float resultado = (float)a / b;  // Ahora da 1.666667
```

### Error 4: No inicializar variables

```c
//  ERROR: 'total' contiene basura de memoria
int total;
total = total + 5;  // ¿Cuánto vale 'total' antes de sumarle 5? No se sabe.

//  CORRECTO:
int total = 0;
total = total + 5;  // Ahora sabemos que total = 5
```

### Error 5: Confundir `=` con `==`

```c
//  ERROR: Esto ASIGNA 10 a edad, no compara
if (edad = 10)  // Asignación, siempre será verdadero (10 ≠ 0)

//  CORRECTO:
if (edad == 10) // Comparación
```
*Nota: Este error es más relevante en selección, pero se introduce aquí porque la confusión comienza al aprender la asignación `=`.*

### Error 6: Olvidar `\n` en `printf` antes de `scanf`

```c
//  PROBLEMA: El texto y la entrada aparecen en la misma línea sin separación clara
printf("Ingrese edad: ");
scanf("%d", &edad);
printf("Edad: %d", edad);  // Se pega con la siguiente salida

//  CORRECTO:
printf("Edad: %d\n", edad);  // \n separa la salida
```

---

## 8. Buenas Prácticas

1. **Siempre inicialice las variables.** Nunca confíe en que el valor por defecto será `0`. En C, las variables locales no se inicializan automáticamente.

2. **Use nombres descriptivos.** `indiceMasaCorporal` es infinitamente mejor que `imc` o `x`. El código se lee más de lo que se escribe.

3. **Comente el porqué, no el qué.** Un comentario como `// Suma 1 a i` es inútil. Uno como `// Avanzamos al siguiente paciente` explica la intención.

4. **Declare constantes para valores fijos.** Si un valor como `3.14159` o `0.15` aparece en su código, defínalo como constante con un nombre descriptivo (`PI`, `TASA_IVA`).

5. **Use `%.Nf` para controlar decimales.** Mostrar `72.500000` al usuario es poco profesional. Use `%.2f` para mostrar `72.50`.

6. **Un `printf` explicativo antes de cada `scanf`.** El usuario debe saber qué dato ingresar. Nunca haga un `scanf` sin un `printf` previo que lo solicite.

7. **Compile con warnings activados.** Use `gcc -Wall -std=c99 archivo.c -o programa`. El flag `-Wall` activa todas las advertencias y le ayudará a detectar errores antes de ejecutar.

8. **Indente consistentemente.** Use 4 espacios o 1 tabulación por nivel de profundidad. Nunca mezcle ambos.

---

## 9. Resumen de la Clase

| Concepto | Descripción clave |
|---|---|
| **Secuenciación** | Ejecución de instrucciones de arriba hacia abajo, sin saltos ni repeticiones. |
| **Tipos primitivos** | `int` (enteros), `float`/`double` (decimales), `char` (carácter). |
| **printf** | Imprime datos formateados en consola usando especificadores (`%d`, `%f`, `%c`). |
| **scanf** | Lee datos del teclado. Requiere `&` para indicar la dirección de memoria. |
| **Operadores** | Aritméticos (`+`, `-`, `*`, `/`, `%`) con reglas de precedencia. |
| **Casting** | Conversión entre tipos: implícita (automática) o explícita (`(float)variable`). |
| **Variables de trabajo** | Variables auxiliares que almacenan resultados intermedios de cálculos. |
| **Constantes** | Valores fijos definidos con `#define` o `const`. |
| **Caracteres de escape** | `\n` (salto de línea), `\t` (tabulación), `\\` (barra invertida). |

### Flujo de trabajo de un programa secuencial:

```
1. Incluir bibliotecas necesarias (#include)
2. Declarar variables (con tipos apropiados)
3. Solicitar y leer datos del usuario (printf + scanf)
4. Procesar los datos (operaciones aritméticas)
5. Mostrar los resultados (printf con formato)
6. Retornar 0 (finalización exitosa)
```

### Archivos de esta clase:

| Archivo | Contenido |
|---|---|
| `Secuenciacion.c` | Ejemplo principal: Registro de paciente con cálculo de IMC |
| `EjemploOperadores.c` | Operadores aritméticos, precedencia y división entera vs decimal |
| `EjemploConversiones.c` | Conversiones de tipo implícitas y explícitas (casting) |
