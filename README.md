# Guía Completa de Programación en C

Repositorio de estudio con guías de aprendizaje de nivel universitario que cubren las **tres estructuras fundamentales** de la programación imperativa en C.

---

## Estructura del Proyecto

```
alfa/
├── README.md                             <- Este archivo
│
├── estructura-secuenciacion/             <- Clase 1
│   ├── README.md                         <- Guía completa
│   ├── Secuenciacion.c                   <- Registro de paciente + IMC
│   ├── EjemploOperadores.c               <- Operadores aritméticos y precedencia
│   └── EjemploConversiones.c             <- Casting implícito y explícito
│
├── estructura-seleccion/                 <- Clase 2
│   ├── README.md                         <- Guía completa
│   ├── Seleccion.c                       <- Booleanos, ternario, switch
│   ├── EjemploIfElseAnidado.c            <- Clasificador de calificaciones
│   └── EjemploSwitchMenu.c               <- Calculadora con menú switch
│
├── estructra-repeticion/                 <- Clase 3
│   ├── README.md                         <- Guía completa
│   ├── Repeticion.c                      <- Contadores, acumuladores, banderas
│   ├── EjemploBuclesAnidados.c           <- Patrones con asteriscos
│   ├── EjemploWhileValidacion.c          <- Validación robusta con while(1)
│   ├── practica/                         <- Ejercicios de repetición
│   │   ├── eje1.c
│   │   ├── caso1.c
│   │   ├── rectangulo.c
│   │   └── ternario.c
│   ├── validaciones/                     <- Módulo de validaciones
│   │   ├── README.md
│   │   ├── ValidacionTipoRango.c
│   │   └── ValidacionMenu.c
│   └── areglos/                          <- Módulo: Arreglos 1D y 2D
│       ├── README.md                     <- Guía completa de arreglos
│       ├── EjemploArreaglo.c             <- Gestor de notas con VLA
│       ├── arreglo2d.c                   <- Empleados con arreglos paralelos
│       └── practica/
│           ├── eje1_estadisticas.c       <- Mayor, menor, suma, promedio
│           ├── eje2_busqueda.c           <- Búsqueda lineal
│           ├── eje3_invertir.c           <- Inversión in-place
│           ├── eje4_ordenamiento.c       <- Bubble Sort
│           └── eje5_tabla2d.c            <- Tabla de multiplicar en 2D
│
└── funciones/                            <- Clase 4
    ├── README.md                         <- Guía completa de funciones
    ├── ejemplo1.c                        <- Empleados refactorizado con funciones
    └── practica/
        ├── eje1_calculadora.c            <- Calculadora con función por operación
        ├── eje2_conversion_temperatura.c <- Funciones puras de conversión
        ├── eje3_numeros_primos.c         <- Función booleana esPrimo()
        ├── eje4_estadisticas_arreglo.c   <- Paso de arreglos a funciones
        └── eje5_validaciones.c           <- Biblioteca de validaciones
```

---

## Orden de Estudio Recomendado

| Orden | Clase | Carpeta | Tema Principal |
|-------|-------|---------|----------------|
| 1 | Secuenciación | `estructura-secuenciacion/` | Flujo lineal, tipos de datos, E/S, operadores |
| 2 | Selección | `estructura-seleccion/` | if-else, switch, operador ternario, lógica booleana |
| 3 | Repetición | `estructra-repeticion/` | for, while, do-while, bucles anidados, validaciones |
| 4 | Arreglos | `estructra-repeticion/areglos/` | Arreglos 1D, 2D, VLA, arreglos paralelos, búsqueda, ordenamiento |
| 5 | Funciones | `funciones/` | Prototipos, parámetros, retorno, void, variables locales/globales |

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
