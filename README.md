# Guía Completa de Programación en C

Repositorio de estudio con guías de aprendizaje de nivel universitario que cubren las **tres estructuras fundamentales** de la programación imperativa en C.

---

## Estructura del Proyecto

```
alfa/
├── README.md                          ← Este archivo
│
├── estructura-secuenciacion/          ← Clase 1
│   ├── README.md                      ← Guía completa (~520 líneas)
│   ├── Secuenciacion.c                ← Ejemplo: Registro de paciente + IMC
│   ├── EjemploOperadores.c            ← Operadores aritméticos y precedencia
│   └── EjemploConversiones.c          ← Casting implícito y explícito
│
├── estructura-seleccion/              ← Clase 2
│   ├── README.md                      ← Guía completa (~600 líneas)
│   ├── Seleccion.c                    ← Ejemplo: Booleanos, ternario, switch
│   ├── EjemploIfElseAnidado.c         ← Clasificador de calificaciones
│   └── EjemploSwitchMenu.c            ← Calculadora con menú switch
│
├── estructra-repeticion/              ← Clase 3
│   ├── README.md                      ← Guía completa (~900 líneas)
│   ├── Repeticion.c                   ← Ejemplo: Contadores, acumuladores, banderas
│   ├── EjemploBuclesAnidados.c        ← Patrones con asteriscos (cuadrado, triángulo)
│   ├── EjemploWhileValidacion.c       ← Validación robusta de entrada con while(1)
│   ├── practica/                      ← Ejercicios complementarios
│   │   ├── eje1.c                     ← Tabla de multiplicar (for, while, do-while)
│   │   ├── caso1.c                    ← Cuadrado de asteriscos
│   │   ├── rectangulo.c              ← Rectángulo hueco con ternarios
│   │   └── ternario.c                ← Clasificación con ternarios anidados
│   └── validaciones/                  ← Módulo Complementario (Validaciones)
│       ├── README.md                  ← Guía de validación de entrada
│       ├── ValidacionTipoRango.c      ← Validación de tipo + rango + caracteres
│       └── ValidacionMenu.c          ← Menú bancario robusto con do-while
```

---

## Orden de Estudio Recomendado

| Orden | Clase | Carpeta | Tema Principal |
|-------|-------|---------|----------------|
| 1 | Secuenciación | `estructura-secuenciacion/` | Flujo lineal, tipos de datos, E/S, operadores |
| 2 | Selección | `estructura-seleccion/` | if-else, switch, operador ternario, lógica booleana |
| 3 | Repetición | `estructra-repeticion/` | for, while, do-while, bucles anidados, validaciones |

Cada carpeta contiene:
- **README.md** — Guía teórica completa con 9 secciones (Introducción, Objetivos, Fundamentos, Sintaxis, Ejemplos, Ejercicios, Errores, Buenas Prácticas, Resumen).
- **Archivos `.c`** — Ejemplos prácticos completamente comentados y listos para compilar.

---

## Compilar y Ejecutar

Todos los archivos usan el estándar **C99**. Para compilar cualquier ejemplo:

```bash
# Compilar con warnings activados (recomendado)
gcc -Wall -std=c99 archivo.c -o programa

# Ejecutar
./programa
```

### Compilar todos los ejemplos de una vez

```bash
# Clase 1 — Secuenciación
gcc -Wall -std=c99 estructura-secuenciacion/Secuenciacion.c -o secuenciacion
gcc -Wall -std=c99 estructura-secuenciacion/EjemploOperadores.c -o operadores
gcc -Wall -std=c99 estructura-secuenciacion/EjemploConversiones.c -o conversiones

# Clase 2 — Selección
gcc -Wall -std=c99 estructura-seleccion/Seleccion.c -o seleccion
gcc -Wall -std=c99 estructura-seleccion/EjemploIfElseAnidado.c -o anidado
gcc -Wall -std=c99 estructura-seleccion/EjemploSwitchMenu.c -o menu

# Clase 3 — Repetición
gcc -Wall -std=c99 estructra-repeticion/Repeticion.c -o repeticion
gcc -Wall -std=c99 estructra-repeticion/EjemploBuclesAnidados.c -o bucles_anidados
gcc -Wall -std=c99 estructra-repeticion/EjemploDoWhileValidacion.c -o validacion
```

---

## Requisitos

- **GCC** (GNU Compiler Collection) o cualquier compilador de C compatible con C99.
- Sistema operativo: Linux, macOS o Windows (con MinGW/WSL).

---

## Conceptos Clave por Clase

### Clase 1 — Secuenciación
`int`, `float`, `double`, `char` · `printf` / `scanf` · Operadores aritméticos · Precedencia · Casting · Variables de trabajo · Constantes

### Clase 2 — Selección
`if` / `if-else` / `if-else if-else` · `switch-case` · Operador ternario `? :` · Operadores relacionales y lógicos · `<stdbool.h>` · Evaluación de cortocircuito

### Clase 3 — Repetición
`for` · `while` · `do-while` · Contadores · Acumuladores · Banderas · `break` / `continue` · Bucles anidados · `i++` vs `++i`
