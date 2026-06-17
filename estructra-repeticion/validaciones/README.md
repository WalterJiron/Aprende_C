# Módulo Complementario — Validación de Entrada en C

---

## 1. Introducción

La **validación de entrada** es el proceso de verificar que los datos proporcionados por el usuario cumplan con las reglas esperadas **antes de procesarlos**. Es una de las habilidades más importantes en la programación profesional, porque un programa que confía ciegamente en la entrada del usuario es un programa que **fallará inevitablemente**.

En C, la validación es especialmente crítica porque el lenguaje **no protege contra errores de entrada** de forma automática. Si el usuario ingresa texto cuando el programa espera un número, `scanf` falla silenciosamente, y el programa puede entrar en un bucle infinito, corromper memoria o producir resultados basura.

### ¿Por qué es fundamental?

- **Robustez:** Un programa sin validación se rompe con la primera entrada inesperada.
- **Seguridad:** Entradas no validadas son la causa #1 de vulnerabilidades (buffer overflow, inyección de código).
- **Experiencia de usuario:** Un buen programa guía al usuario cuando comete un error, no se cuelga.
- **Integridad de datos:** Datos incorrectos que entran al sistema producen resultados incorrectos que se propagan.

### Principio fundamental: **Nunca confíes en el usuario**

> Todo dato que proviene del exterior (teclado, archivo, red) es **potencialmente peligroso** hasta que se demuestre lo contrario. Siempre valida antes de procesar.

---

## 2. Objetivos de Aprendizaje

Al finalizar este módulo, el estudiante será capaz de:

1. Comprender por qué `scanf` puede fallar y cómo detectar esos fallos.
2. Implementar validación de **tipo** (¿el usuario ingresó un número o texto?).
3. Implementar validación de **rango** (¿el número está dentro de los límites permitidos?).
4. Limpiar correctamente el **buffer de entrada** cuando `scanf` falla.
5. Combinar validación de tipo y rango en un patrón reutilizable.
6. Aplicar validación en menús interactivos con reintentos limitados.
7. Validar caracteres individuales (opciones de menú, respuestas sí/no).
8. Entender los riesgos de seguridad de no validar (buffer overflow con `scanf("%s")`).

---

## 3. Fundamentos Teóricos

### 3.1. El Problema del Buffer de Entrada

Cuando el usuario escribe algo y presiona Enter, los caracteres se almacenan en un **buffer de entrada** (un espacio temporal en memoria). `scanf` lee de este buffer según el especificador de formato:

```
Buffer de entrada: "42\n"
                    ^^  ^
                    ||  └── Carácter '\n' del Enter
                    |└── Dígito '2'
                    └── Dígito '4'
```

Si `scanf("%d", &x)` encuentra `"42\n"`, extrae `42`, convierte a entero, y deja `"\n"` en el buffer.

**Problema 1: Entrada no numérica**

```
El usuario escribe: "hola\n"
scanf("%d", &x) intenta leer un entero
→ Encuentra 'h', que NO es un dígito
→ FALLA: No extrae nada, NO consume los caracteres
→ "hola\n" SIGUE en el buffer
→ Si hay otro scanf, volverá a fallar con los mismos caracteres
→ RESULTADO: Bucle infinito
```

**Problema 2: El `\n` residual con `%c`**

```
Primer scanf("%d", &edad): Lee "25", deja "\n" en buffer
Segundo scanf("%c", &letra): Lee el "\n" del buffer, NO espera al usuario
→ RESULTADO: Se "salta" la lectura del carácter
```

### 3.2. El Retorno de `scanf`

`scanf` devuelve un **entero** que indica cuántos elementos leyó exitosamente:

| Valor de retorno | Significado |
|---|---|
| `N` (positivo) | Leyó N elementos correctamente |
| `0` | No leyó ningún elemento (formato no coincide) |
| `EOF` (-1) | Error de lectura o fin de archivo |

```c
int resultado = scanf("%d", &numero);

if (resultado == 1) {
    // Lectura exitosa: 'numero' tiene un valor válido
} else if (resultado == 0) {
    // El usuario no ingresó un número (probablemente texto)
} else {
    // Error grave (EOF o problema de lectura)
}
```

### 3.3. Limpieza del Buffer de Entrada

Cuando `scanf` falla, los caracteres inválidos **permanecen en el buffer**. Si no los limpiamos, el siguiente `scanf` volverá a fallar con los mismos caracteres, creando un **bucle infinito**.

```c
// Bucle para limpiar el buffer de entrada
while (getchar() != '\n');
```

**¿Cómo funciona?**
- `getchar()` extrae **un carácter** del buffer cada vez.
- El `while` continúa extrayendo hasta encontrar `'\n'` (el Enter).
- Al terminar, el buffer está limpio y listo para la siguiente lectura.

### 3.4. Tipos de Validación

| Tipo | Pregunta que responde | Ejemplo |
|---|---|---|
| **Tipo** | ¿El dato es del tipo correcto? | ¿Ingresó un número o texto? |
| **Rango** | ¿El valor está dentro de límites? | ¿La edad está entre 1 y 120? |
| **Formato** | ¿El dato tiene la estructura esperada? | ¿La fecha es DD/MM/AAAA? |
| **Lógica** | ¿El dato tiene sentido en contexto? | ¿El mes de nacimiento ≤ 12? |
| **Seguridad** | ¿El dato es seguro de procesar? | ¿La cadena cabe en el buffer? |

### 3.5. Patrón Universal de Validación con `while(1)`

El bucle infinito `while(1)` combinado con `break` es la estructura más clara y segura para validar entrada en C porque:
1. Necesitamos pedir el dato repetidamente hasta que sea correcto.
2. La validación suele tener múltiples pasos (verificar si es número, luego verificar rango).
3. `break` nos permite salir exactamente en el punto donde estamos seguros de que el dato es válido.

```c
// PATRÓN: Validación completa con while(1) (tipo + rango)
int valor;
int lecturaExitosa;

while (1) {
    printf("Ingrese un valor (1-100): ");
    lecturaExitosa = scanf("%d", &valor);

    if (lecturaExitosa != 1) {
        // Falló la lectura (ej: ingresó texto)
        printf("Error: Debe ingresar un numero.\n");
        while (getchar() != '\n'); // Limpiar caracteres inválidos
        
    } else if (valor < 1 || valor > 100) {
        // Es número, pero está fuera del rango
        printf("Error: El valor debe estar entre 1 y 100.\n");
        
    } else {
        // Es número y está en rango. Salimos del bucle.
        break;
    }
}

// Aquí 'valor' está GARANTIZADO entre 1 y 100
```

### 3.6. Validación de Caracteres

Para leer un carácter con validación, hay que tener cuidado con el `\n` residual:

```c
char respuesta;
while (1) {
    printf("¿Desea continuar? (S/N): ");
    scanf(" %c", &respuesta);  // El espacio antes de %c ignora whitespace
    
    if (respuesta == 'S' || respuesta == 's' || 
        respuesta == 'N' || respuesta == 'n') {
        break; // Valor válido, salir del bucle
    } else {
        printf("Error: Solo se acepta S o N.\n");
    }
}
```

>  **Importante:** El espacio antes de `%c` en `scanf(" %c", &var)` le dice a `scanf` que descarte cualquier espacio en blanco pendiente en el buffer (incluyendo `\n` de lecturas anteriores).

### 3.7. Validación con Intentos Limitados

En sistemas reales (contraseñas, PINs), el usuario tiene un número máximo de intentos:

```c
#define MAX_INTENTOS 3
int contrasenaCorrecta = 1234;
int intento;
int intentosUsados = 0;
int accesoConcedido = 0;

while (1) {
    intentosUsados++;
    printf("Intento %d de %d - Ingrese contrasena: ", intentosUsados, MAX_INTENTOS);
    scanf("%d", &intento);
    
    if (intento == contrasenaCorrecta) {
        accesoConcedido = 1;
        break; // Éxito, salir del bucle
    } else {
        printf("Contrasena incorrecta.\n");
        if (intentosUsados >= MAX_INTENTOS) {
            break; // Se acabaron los intentos, salir del bucle
        }
        printf("Le quedan %d intentos.\n\n", MAX_INTENTOS - intentosUsados);
    }
}

if (accesoConcedido) {
    printf("Acceso concedido.\n");
} else {
    printf("Cuenta bloqueada por exceder intentos.\n");
}
```

### 3.8. Seguridad: El Peligro de `scanf("%s")`

`scanf("%s", cadena)` lee una cadena **sin límite de tamaño**. Si el usuario ingresa más caracteres de los que caben en el arreglo, se produce un **buffer overflow** (escritura fuera de los límites del arreglo), que puede:
- Corromper otras variables en memoria.
- Causar un fallo de segmentación (crash).
- Permitir la ejecución de código malicioso (vulnerabilidad de seguridad).

```c
//  PELIGROSO: Sin límite de lectura
char nombre[20];
scanf("%s", nombre);  // Si el usuario escribe 50 caracteres: BUFFER OVERFLOW

//  SEGURO: Limitar la lectura con ancho máximo
char nombre[20];
scanf("%19s", nombre);  // Lee máximo 19 caracteres (1 para '\0')

//  MÁS SEGURO: Usar fgets para cadenas con espacios
char nombre[50];
printf("Ingrese su nombre completo: ");
fgets(nombre, sizeof(nombre), stdin);
// fgets lee hasta 49 caracteres O hasta '\n', lo que ocurra primero
```

---

## 4. Ejemplos Explicados

### Ejemplo 1: Validación Completa de Tipos y Rangos (ver `ValidacionTipoRango.c`)

Implementa un sistema de registro que valida:
- Que la edad sea un número entero (no texto) y esté entre 1 y 120.
- Que el peso sea un número decimal y esté entre 0.5 y 500.0.
- Que el sexo sea un carácter válido ('M' o 'F').

Demuestra la limpieza manual del buffer y el patrón while(1) con validación dual (tipo + rango).

### Ejemplo 2: Menú Robusto con Reintentos (ver `ValidacionMenu.c`)

Implementa un menú de sistema bancario que:
- Valida que la opción sea numérica.
- Valida que esté en el rango de opciones disponibles.
- Para operaciones sensibles (retiro), valida que el monto sea positivo y no exceda el saldo.
- Implementa confirmación de operaciones críticas (sí/no) en línea.

---

## 5. Ejercicios Prácticos

### Nivel Básico

**Ejercicio 1 — Validar número positivo:**
Escriba un programa que solicite un número entero positivo (mayor que 0). Si el usuario ingresa un número negativo, cero, o texto, muestre un mensaje de error y vuelva a solicitar.

**Ejercicio 2 — Validar vocal:**
Escriba un programa que pida al usuario una vocal (a, e, i, o, u). Acepte mayúsculas y minúsculas. Si ingresa otro carácter, muestre un error y repita.

### Nivel Intermedio

**Ejercicio 3 — Registro con validación completa:**
Cree un programa que solicite nombre (máximo 30 caracteres), edad (1-120), y calificación (0.0-100.0). Valide cada campo completamente antes de pasar al siguiente.

**Ejercicio 4 — PIN de seguridad:**
Implemente un sistema de PIN de 4 dígitos (1000-9999) con máximo 3 intentos. Si falla los 3, bloquee el acceso. Si acierta, muestre "Bienvenido".

### Nivel Desafiante

**Ejercicio 5 — Calculadora robusta:**
Cree una calculadora que valide ambos operandos y el operador (+, -, *, /). Para la división, valide que el divisor no sea cero. Después de cada operación, pregunte si desea continuar.

---

## 6. Errores Comunes

### Error 1: No verificar el retorno de `scanf`

```c
//  Si el usuario escribe "abc", scanf falla y numero queda con basura
int numero;
scanf("%d", &numero);
printf("El doble es: %d\n", numero * 2); // Resultado impredecible

//  CORRECTO: Verificar que scanf leyó correctamente
int numero;
if (scanf("%d", &numero) == 1) {
    printf("El doble es: %d\n", numero * 2);
} else {
    printf("Error: no se ingreso un numero valido.\n");
}
```

### Error 2: No limpiar el buffer después de un fallo

```c
//  BUCLE INFINITO: scanf falla, "abc" sigue en el buffer, vuelve a fallar
int numero;
do {
    printf("Ingrese un numero: ");
} while (scanf("%d", &numero) != 1);
// El programa imprime "Ingrese un numero: " infinitamente

//  CORRECTO: Limpiar el buffer
int numero;
do {
    printf("Ingrese un numero: ");
    if (scanf("%d", &numero) != 1) {
        printf("Error: ingrese un numero.\n");
        while (getchar() != '\n'); // Limpiar buffer
    } else {
        break;
    }
} while (1);
```

### Error 3: Olvidar el espacio antes de `%c`

```c
int edad;
char sexo;

printf("Ingrese edad: ");
scanf("%d", &edad);

//  Lee el '\n' residual del scanf anterior, no espera al usuario
printf("Ingrese sexo (M/F): ");
scanf("%c", &sexo);  // sexo = '\n'

//  El espacio antes de %c descarta el '\n' residual
printf("Ingrese sexo (M/F): ");
scanf(" %c", &sexo);  // Ahora sí espera al usuario
```

### Error 4: Validar solo el rango, no el tipo

```c
//  Si el usuario escribe "abc", edad tendrá basura y la comparación es inútil
int edad;
printf("Ingrese edad: ");
scanf("%d", &edad);
if (edad >= 1 && edad <= 120) {
    printf("Edad valida\n");
}

//  Validar PRIMERO el tipo, LUEGO el rango
int edad;
printf("Ingrese edad: ");
if (scanf("%d", &edad) != 1) {
    printf("Error: no es un numero.\n");
} else if (edad < 1 || edad > 120) {
    printf("Error: fuera de rango.\n");
} else {
    printf("Edad valida: %d\n", edad);
}
```

---

## 7. Buenas Prácticas

1. **Siempre verifique el retorno de `scanf`.** Es la única forma de saber si la lectura fue exitosa.

2. **Siempre limpie el buffer** después de un fallo de `scanf`. Sin limpieza, el siguiente `scanf` fallará con los mismos datos.

3. **Use `" %c"` (con espacio)** para leer caracteres después de otras lecturas. El espacio descarta whitespace residual.

4. **Limite la lectura de cadenas** con `%Ns` o use `fgets`. Nunca use `scanf("%s")` sin límite.

5. **Separe la validación de tipo de la validación de rango.** Primero verifique que el dato sea del tipo correcto, luego que esté en rango.

6. **Dé mensajes de error claros.** No diga solo "Error". Diga "Error: La edad debe ser un número entre 1 y 120."

7. **Considere intentos máximos** para datos sensibles. No permita intentos infinitos en contraseñas o PINs.

8. **Cree funciones reutilizables** para patrones de validación que use frecuentemente:
   ```c
   int leerEnteroEnRango(const char *mensaje, int min, int max);
   float leerDecimalEnRango(const char *mensaje, float min, float max);
   char leerCaracterValido(const char *mensaje, const char *validos);
   ```

---

## 8. Resumen

| Concepto | Descripción |
|---|---|
| **Retorno de `scanf`** | Devuelve el número de elementos leídos exitosamente (0 si falla). |
| **Limpieza de buffer** | `while (getchar() != '\n');` — Descarta caracteres residuales. |
| **Espacio en `" %c"`** | Descarta whitespace residual antes de leer un carácter. |
| **Validación de tipo** | Verificar que `scanf` devuelva el número esperado de lecturas. |
| **Validación de rango** | Verificar que el valor esté entre un mínimo y un máximo. |
| **Intentos limitados** | Usar un contador que se incrementa en cada intento fallido. |
| **`fgets` vs `scanf`** | `fgets` es más seguro para cadenas: limita la lectura automáticamente. |
| **Buffer overflow** | Escribir más datos de los que caben en un arreglo. Causa crashes o vulnerabilidades. |

### Archivos de este módulo:

| Archivo | Contenido |
|---|---|
| `ValidacionTipoRango.c` | Validación completa de enteros, decimales y caracteres con limpieza de buffer en línea |
| `ValidacionMenu.c` | Menú bancario robusto con validación de opciones, montos y confirmación |
