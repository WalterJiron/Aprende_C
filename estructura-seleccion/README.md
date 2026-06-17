# Clase 2 — Estructuras de Selección en C

---

## 1. Introducción

Las **estructuras de selección** permiten que un programa **tome decisiones**. En lugar de ejecutar todas las instrucciones de arriba hacia abajo (secuenciación), el programa evalúa una **condición** y, dependiendo de si es verdadera o falsa, ejecuta un bloque de código u otro.

Este es el salto conceptual más importante después de la secuenciación: pasamos de programas lineales a programas **inteligentes** que pueden reaccionar de manera diferente según los datos que reciben.

### ¿Por qué es importante?

- Permite que los programas **reaccionen** a diferentes situaciones.
- Es la base de toda lógica de negocio: validaciones, permisos, clasificaciones.
- Sin selección, un programa haría exactamente lo mismo sin importar la entrada.
- Toda aplicación real toma decisiones: ¿el usuario tiene permiso?, ¿la contraseña es correcta?, ¿el saldo es suficiente?

### Aplicaciones prácticas

- Validación de datos de entrada (¿es un número positivo? ¿está en rango?).
- Sistemas de clasificación (calificaciones, categorías, rangos).
- Menús de opciones (cajero automático, punto de venta).
- Control de acceso (verificación de credenciales, permisos por rol).
- Cálculos condicionales (descuentos según monto, impuestos según tramo).

---

## 2. Objetivos de Aprendizaje

Al finalizar esta clase, el estudiante será capaz de:

1. Comprender y aplicar la lógica booleana en C (verdadero = no-cero, falso = 0).
2. Utilizar correctamente los **operadores relacionales** (`==`, `!=`, `>`, `<`, `>=`, `<=`).
3. Combinar condiciones con **operadores lógicos** (`&&`, `||`, `!`).
4. Implementar estructuras `if`, `if-else` e `if-else if-else` correctamente.
5. Anidar estructuras de selección de forma organizada y legible.
6. Utilizar la estructura `switch-case` para menús y opciones discretas.
7. Aplicar el **operador ternario** (`? :`) para decisiones simples en una línea.
8. Utilizar el tipo `bool` de `<stdbool.h>` para mejorar la legibilidad del código.

---

## 3. Fundamentos Teóricos

### 3.1. La Verdad en C — Lógica Booleana

A diferencia de lenguajes modernos que tienen un tipo booleano nativo, el C original (K&R C, ANSI C89) **no tenía tipo booleano**. En C, la verdad se define numéricamente:

| Valor | Significado lógico |
|---|---|
| `0` | **Falso** (false) |
| Cualquier valor ≠ 0 | **Verdadero** (true) |

Esto significa que un número como `1`, `-5`, `42` o `0.001` son **todos verdaderos** en un contexto booleano. Solo `0` es falso.

```c
if (1)    // Verdadero  (1 ≠ 0)
if (-5)   // Verdadero  (-5 ≠ 0)
if (0)    // Falso  (0 == 0)
if (0.0)  // Falso  (0.0 == 0)
```

#### El tipo `bool` en C99+

A partir del estándar **C99**, se introdujo la biblioteca `<stdbool.h>`, que define:
- El tipo `bool`
- Las constantes `true` (equivale a `1`) y `false` (equivale a `0`)

```c
#include <stdbool.h>

bool esMayor = true;   // Internamente es 1
bool estaBloqueado = false; // Internamente es 0
```

Esto hace que el código sea **más legible** y autoexplicativo, aunque internamente sigan siendo enteros.

### 3.2. Operadores Relacionales

Los operadores relacionales **comparan dos valores** y devuelven `1` (verdadero) o `0` (falso).

| Operador | Significado | Ejemplo | Resultado |
|---|---|---|---|
| `==` | Igual a | `5 == 5` | `1` (verdadero) |
| `!=` | Distinto de | `5 != 3` | `1` (verdadero) |
| `>` | Mayor que | `5 > 3` | `1` (verdadero) |
| `<` | Menor que | `5 < 3` | `0` (falso) |
| `>=` | Mayor o igual que | `5 >= 5` | `1` (verdadero) |
| `<=` | Menor o igual que | `3 <= 5` | `1` (verdadero) |

>  **Error crítico:** No confunda `=` (asignación) con `==` (comparación). `if (x = 5)` **asigna** 5 a `x` y siempre es verdadero (porque 5 ≠ 0). `if (x == 5)` **compara** si `x` vale 5.

### 3.3. Operadores Lógicos

Permiten **combinar múltiples condiciones** en una sola expresión:

| Operador | Nombre | Regla | Ejemplo |
|---|---|---|---|
| `&&` | AND (Y) | Verdadero solo si **AMBAS** condiciones son verdaderas | `edad >= 18 && dinero > 0` |
| `\|\|` | OR (O) | Verdadero si **al menos UNA** condición es verdadera | `dia == 'S' \|\| dia == 'D'` |
| `!` | NOT (NO) | **Invierte** el resultado: verdadero→falso, falso→verdadero | `!estaLloviendo` |

#### Tablas de verdad

**AND (`&&`)**:
| A | B | A && B |
|---|---|---|
| V | V | **V** |
| V | F | F |
| F | V | F |
| F | F | F |

**OR (`||`)**:
| A | B | A \|\| B |
|---|---|---|
| V | V | **V** |
| V | F | **V** |
| F | V | **V** |
| F | F | F |

**NOT (`!`)**:
| A | !A |
|---|---|
| V | F |
| F | **V** |

#### Evaluación de cortocircuito (Short-circuit evaluation)

C evalúa las condiciones de **izquierda a derecha** y se detiene tan pronto como el resultado es determinable:

- **`&&`**: Si la primera condición es **falsa**, ya no evalúa la segunda (porque F && cualquiera = F).
- **`||`**: Si la primera condición es **verdadera**, ya no evalúa la segunda (porque V || cualquiera = V).

```c
// Si divisor es 0, C NO evalúa la segunda condición, evitando la división por cero.
if (divisor != 0 && (numerador / divisor) > 2) {
    printf("El cociente es mayor que 2\n");
}
```

### 3.4. Estructura `if` — Selección Simple

Ejecuta un bloque de código **solo si** la condición es verdadera. Si es falsa, simplemente lo salta.

```
         ┌─────────────┐
         │ ¿Condición?  │
         └──────┬───────┘
           ┌────┴────┐
        Sí │         │ No
           ▼         │
    ┌──────────┐     │
    │ Bloque   │     │
    │ de código│     │
    └────┬─────┘     │
         └─────┬─────┘
               ▼
       [Continúa programa]
```

```c
if (condicion) {
    // Se ejecuta SOLO si la condición es verdadera
}
// El programa continúa aquí sin importar el resultado
```

### 3.5. Estructura `if-else` — Selección Doble

Ejecuta un bloque si la condición es verdadera, y **otro bloque diferente** si es falsa. Siempre se ejecuta exactamente uno de los dos.

```
         ┌─────────────┐
         │ ¿Condición?  │
         └──────┬───────┘
           ┌────┴────┐
        Sí │         │ No
           ▼         ▼
    ┌──────────┐ ┌──────────┐
    │ Bloque A │ │ Bloque B │
    └────┬─────┘ └────┬─────┘
         └─────┬─────┘
               ▼
       [Continúa programa]
```

```c
if (condicion) {
    // Bloque A: se ejecuta si la condición es verdadera
} else {
    // Bloque B: se ejecuta si la condición es falsa
}
```

### 3.6. Estructura `if-else if-else` — Selección Múltiple (Escalera)

Permite evaluar **múltiples condiciones** en secuencia. Se ejecuta el bloque de la **primera** condición que sea verdadera. Si ninguna lo es, se ejecuta el `else` final.

```c
if (condicion1) {
    // Se ejecuta si condicion1 es verdadera
} else if (condicion2) {
    // Se ejecuta si condicion1 fue falsa Y condicion2 es verdadera
} else if (condicion3) {
    // Se ejecuta si las anteriores fueron falsas Y condicion3 es verdadera
} else {
    // Se ejecuta si NINGUNA condición anterior fue verdadera
}
```

> **Importante:** Las condiciones se evalúan **en orden**. La primera que sea verdadera ejecuta su bloque y las demás se ignoran. Esto es crucial para rangos numéricos.

### 3.7. Estructura `switch-case`

El `switch` evalúa una expresión y salta al `case` que coincida con su valor. Es ideal para comparar una variable contra **valores discretos y específicos** (no rangos).

```c
switch (expresion) {
    case valor1:
        // Se ejecuta si expresion == valor1
        break;
    case valor2:
        // Se ejecuta si expresion == valor2
        break;
    default:
        // Se ejecuta si ningún case coincidió (es opcional pero recomendado)
        break;
}
```

**Reglas del `switch`:**
1. La expresión debe ser de tipo `int` o `char` (nunca `float`, `double` ni `string`).
2. Los valores de cada `case` deben ser **constantes** (no variables).
3. **`break` es obligatorio** después de cada bloque. Sin él, la ejecución "cae" al siguiente `case` (fall-through).
4. `default` es el caso por defecto; es buena práctica siempre incluirlo.

#### Fall-through intencional

A veces se omite el `break` a propósito para agrupar casos:

```c
switch (letra) {
    case 'a':
    case 'A':
        // Se ejecuta si letra es 'a' O 'A'
        printf("Vocal A\n");
        break;
}
```

### 3.8. Operador Ternario (`? :`)

Es una forma compacta de escribir un `if-else` **simple** en una sola línea.

```c
resultado = (condicion) ? valor_si_verdadero : valor_si_falso;
```

Equivale a:
```c
if (condicion) {
    resultado = valor_si_verdadero;
} else {
    resultado = valor_si_falso;
}
```

**Cuándo usar el ternario:**
-  Para asignaciones simples basadas en una condición.
-  Dentro de un `printf` para elegir entre dos textos.
-  **NO** para lógica compleja o múltiples instrucciones.

### 3.9. `if-else` vs `switch` — ¿Cuándo usar cada uno?

| Criterio | `if-else` | `switch` |
|---|---|---|
| **Comparar rangos** (>, <, >=) |  Sí |  No |
| **Comparar valores exactos** |  Sí |  Sí (más limpio) |
| **Condiciones complejas** (&&, \|\|) |  Sí |  No |
| **Tipo float/double** |  Sí |  No |
| **Menús de opciones** | Posible |  Ideal |
| **Legibilidad con muchos casos** | Regular |  Excelente |

---

## 4. Sintaxis y Estructura

### 4.1. Sintaxis Completa de `if-else`

```c
// Selección simple
if (condicion) {
    instrucciones;
}

// Selección doble
if (condicion) {
    instrucciones_verdadero;
} else {
    instrucciones_falso;
}

// Selección múltiple (escalera)
if (condicion1) {
    instrucciones1;
} else if (condicion2) {
    instrucciones2;
} else {
    instrucciones_default;
}
```

### 4.2. Sintaxis Completa de `switch`

```c
switch (variable_o_expresion) {
    case CONSTANTE_1:
        instrucciones;
        break;
    case CONSTANTE_2:
        instrucciones;
        break;
    // ... más casos ...
    default:
        instrucciones_por_defecto;
        break;
}
```

### 4.3. Reglas Importantes

1. **Siempre use llaves `{}`**, incluso para bloques de una sola línea. Esto previene errores sutiles al agregar líneas después.
2. **Ordene las condiciones de más específica a más general** en escaleras `if-else if`.
3. **No compare `float`/`double` con `==`**. Por errores de precisión, use un rango: `if (fabs(x - 3.14) < 0.0001)`.
4. **Siempre incluya `default` en `switch`**, incluso si cree que nunca se ejecutará.
5. **Nunca omita `break` accidentalmente** en un `switch`.

---

## 5. Ejemplos Explicados Paso a Paso

### Ejemplo 1: Selección Avanzada con Booleanos (ver `Seleccion.c`)

Demuestra el uso de `<stdbool.h>`, operadores lógicos (`&&`, `||`, `!`), operador ternario, y `switch` con caracteres incluyendo fall-through intencional para aceptar mayúsculas y minúsculas.

### Ejemplo 2: Escalera if-else if con Rangos (ver `EjemploIfElseAnidado.c`)

Demuestra la clasificación por rangos numéricos usando escalera `if-else if-else`, estructuras anidadas, y la importancia del orden de las condiciones.

### Ejemplo 3: Menú Interactivo con Switch (ver `EjemploSwitchMenu.c`)

Implementa un menú de calculadora completo usando `switch-case`, con validación de entrada y manejo del caso `default`.

---

## 6. Ejercicios Prácticos

### Nivel Básico

**Ejercicio 1 — Par o Impar:**
Escriba un programa que lea un número entero y determine si es par o impar.
*Pista: Use el operador `%` (módulo). Un número es par si `numero % 2 == 0`.*

**Ejercicio 2 — Mayor de Tres:**
Escriba un programa que lea tres números enteros y determine cuál es el mayor de los tres. Considere el caso de empates.

**Ejercicio 3 — Vocal o Consonante:**
Escriba un programa que lea un carácter y determine si es una vocal o una consonante. Use `switch` y considere mayúsculas y minúsculas.

### Nivel Intermedio

**Ejercicio 4 — Calculadora de Descuentos:**
Una tienda ofrece descuentos según el monto de compra:
- Menos de $100: Sin descuento
- De $100 a $499.99: 10% de descuento
- De $500 a $999.99: 20% de descuento
- $1000 o más: 30% de descuento

Lea el monto de compra, calcule el descuento y muestre el monto final.

**Ejercicio 5 — Clasificador de Triángulos:**
Dados los tres lados de un triángulo, determine:
1. Si los lados forman un triángulo válido (la suma de dos lados siempre debe ser mayor al tercero).
2. Si es válido, clasifíquelo como: equilátero (3 lados iguales), isósceles (2 lados iguales) o escaleno (todos diferentes).

**Ejercicio 6 — Calificación con Letras:**
Lea una calificación numérica (0-100) y conviértala a letra:
- 90-100: A (Excelente)
- 80-89: B (Muy Bueno)
- 70-79: C (Bueno)
- 60-69: D (Regular)
- 0-59: F (Reprobado)

Valide que la calificación esté en el rango 0-100.

### Nivel Desafiante

**Ejercicio 7 — Calculadora de Impuestos Progresiva:**
Implemente un sistema de impuestos progresivo:
- Primeros $10,000: 0% de impuesto
- De $10,001 a $30,000: 15% sobre el excedente de $10,000
- De $30,001 a $60,000: 25% sobre el excedente de $30,000
- Más de $60,000: 35% sobre el excedente de $60,000

El impuesto es **acumulativo** (cada tramo se calcula por separado).

**Ejercicio 8 — Año Bisiesto:**
Escriba un programa que determine si un año es bisiesto. Un año es bisiesto si:
- Es divisible entre 4, **EXCEPTO** si es divisible entre 100.
- Pero **SÍ** es bisiesto si es divisible entre 400.

Ejemplos: 2024 (sí), 1900 (no), 2000 (sí), 2023 (no).

---

## 7. Errores Comunes

### Error 1: Confundir `=` con `==`

```c
//  ERROR: Asignación en vez de comparación
if (edad = 18) {  // Asigna 18 a edad. Siempre verdadero (18 ≠ 0).
    printf("Es mayor de edad\n");
}

//  CORRECTO: Comparación
if (edad == 18) {
    printf("Tiene exactamente 18 años\n");
}
```

### Error 2: Olvidar `break` en `switch`

```c
//  ERROR: Sin break, se ejecutan TODOS los casos siguientes (fall-through)
switch (opcion) {
    case 1:
        printf("Opcion 1\n");
        // ¡Falta break! La ejecución cae a case 2
    case 2:
        printf("Opcion 2\n");
        break;
}
// Si opcion es 1, imprime "Opcion 1" Y "Opcion 2"

//  CORRECTO:
switch (opcion) {
    case 1:
        printf("Opcion 1\n");
        break;  // Detiene la ejecución aquí
    case 2:
        printf("Opcion 2\n");
        break;
}
```

### Error 3: Condiciones mal estructuradas en rangos

```c
//  ERROR: La segunda condición nunca se ejecuta si la primera es verdadera
if (nota >= 60) {
    printf("Aprobado\n");
} else if (nota >= 90) {
    // ¡NUNCA se llega aquí! Una nota >= 90 ya cumplió nota >= 60
    printf("Excelente\n");
}

//  CORRECTO: Evaluar de mayor a menor (o de más específico a más general)
if (nota >= 90) {
    printf("Excelente\n");
} else if (nota >= 60) {
    printf("Aprobado\n");
} else {
    printf("Reprobado\n");
}
```

### Error 4: Usar `switch` con tipos incompatibles

```c
//  ERROR: switch no acepta float ni strings
float precio = 9.99;
switch (precio) {   // ERROR DE COMPILACIÓN
    case 9.99: break;
}

//  CORRECTO: switch solo con int o char
int opcion = 2;
switch (opcion) {
    case 1: break;
    case 2: break;
}
```

### Error 5: Comparar `float` con `==`

```c
//  PELIGROSO: Los float tienen errores de precisión
float x = 0.1 + 0.2;  // No es exactamente 0.3 (es 0.300000012...)
if (x == 0.3) {
    printf("Iguales\n");  // Probablemente NO se ejecuta
}

//  CORRECTO: Comparar con tolerancia
#include <math.h>
if (fabs(x - 0.3) < 0.0001) {
    printf("Aproximadamente iguales\n");
}
```

### Error 6: No usar llaves en bloques de una línea

```c
//  PELIGROSO: Solo la primera línea está dentro del if
if (edad >= 18)
    printf("Mayor de edad\n");
    printf("Puede votar\n");  // ¡SIEMPRE se ejecuta! No está dentro del if

//  CORRECTO: Siempre use llaves
if (edad >= 18) {
    printf("Mayor de edad\n");
    printf("Puede votar\n");
}
```

---

## 8. Buenas Prácticas

1. **Siempre use llaves `{}`**, incluso para bloques de una sola instrucción. Esto previene errores cuando se agregan líneas después.

2. **Valide la entrada del usuario** antes de procesarla. No asuma que el usuario ingresará datos correctos.

3. **Ordene las condiciones de más específica a más general** en escaleras `if-else if`. Para rangos, vaya de mayor a menor.

4. **Use variables `bool` con nombres descriptivos** para condiciones complejas:
   ```c
   bool esAprobado = (promedio >= 6.0 && asistencias >= 80);
   if (esAprobado) { ... }
   ```

5. **Prefiera `switch` sobre cadenas largas de `if-else if`** cuando compara una variable contra valores discretos conocidos.

6. **Siempre incluya `default` en `switch`** para manejar valores inesperados.

7. **Mantenga la anidación máxima en 2-3 niveles.** Si necesita más, considere refactorizar con funciones o variables booleanas intermedias.

8. **Use el operador ternario solo para asignaciones simples.** Si la lógica es compleja, use `if-else` tradicional.

9. **Documente las condiciones complejas** con comentarios que expliquen la lógica de negocio:
   ```c
   // Un paciente es de riesgo si tiene más de 60 años
   // O si tiene una condición preexistente sin importar la edad
   if (edad > 60 || tieneCondicionPrevia) { ... }
   ```

---

## 9. Resumen de la Clase

| Concepto | Descripción clave |
|---|---|
| **Lógica booleana** | En C, `0` es falso y cualquier valor ≠ 0 es verdadero. `<stdbool.h>` añade `bool`, `true`, `false`. |
| **Operadores relacionales** | `==`, `!=`, `>`, `<`, `>=`, `<=` — Comparan y devuelven 1 o 0. |
| **Operadores lógicos** | `&&` (Y), `\|\|` (O), `!` (NO) — Combinan condiciones. |
| **if / if-else** | Selección simple y doble. Ejecuta bloques según una condición. |
| **if-else if-else** | Escalera de selección múltiple. Evalúa condiciones en orden. |
| **switch-case** | Selección múltiple para valores discretos (`int`, `char`). Requiere `break`. |
| **Operador ternario** | `(cond) ? v1 : v2` — if-else compacto para asignaciones simples. |
| **Evaluación cortocircuito** | `&&` no evalúa la 2ª condición si la 1ª es falsa; `\|\|` no evalúa si la 1ª es verdadera. |

### Diagrama de decisión — ¿Qué estructura usar?

```
¿Necesita tomar una decisión?
│
├── ¿Es una sola condición simple?
│   └── Use: if / if-else
│
├── ¿Son varias condiciones con rangos (>, <, >=)?
│   └── Use: if-else if-else (escalera)
│
├── ¿Compara UNA variable contra valores exactos (int/char)?
│   └── Use: switch-case
│
└── ¿Es una asignación simple basada en una condición?
    └── Use: operador ternario (? :)
```

### Archivos de esta clase:

| Archivo | Contenido |
|---|---|
| `Seleccion.c` | Ejemplo principal: booleanos, operadores lógicos, ternario y switch con char |
| `EjemploIfElseAnidado.c` | Clasificación de calificaciones con escalera if-else if y validación |
| `EjemploSwitchMenu.c` | Calculadora interactiva con menú switch-case |
