# Prácticas - 3er Parcial

### Programación Orientada a Objetos | C++

Repositorio que contiene el desarrollo de cinco ejercicios correspondientes al tercer parcial. El objetivo es aplicar conceptos de programación en C++, manejo de excepciones, manipulación de archivos, conexión a bases de datos e integración de bibliotecas externas.

Los ejercicios están organizados en directorios independientes, cada uno con su propio archivo `CMakeLists.txt`, permitiendo compilar y ejecutar los programas de manera individual o en conjunto desde el proyecto principal.

## 👩‍🎓 Datos del estudiante

| Campo                      | Información                               |
| -------------------------- | ----------------------------------------- |
| **Nombre del estudiante:** | Camila Andrea Jaiems Martinez             |
| **Materia:**               | Programación Orientada a Objetos          |
| **Nombre del profesor:**   | Manuel Balderas Victoria.                 |
| **Nombre de la tarea:**    | Prácticas - 3er Parcial                   |
| **Fecha de entrega:**      | 20 de noviembre de 2026                   |
| **Carrera:**               | Ingeniería en Software y Minería de Datos |

---

## 📁 Estructura del proyecto

```text
practicas3_poo/
│
├── Archivo_lista/
│   ├── CMakeLists.txt
│   └── lista.cpp
│
├── DB_Excepcion/
│   ├── sqlite/
│   │   ├── sqlite3.c
│   │   └── sqlite3.h
│   │
│   ├── basedatos.cpp
│   └── CMakeLists.txt
│
├── Libreria_ext/
│   ├── nlohmann/
│   │   └── json.hpp
│   │
│   ├── ventas.cpp
│   └── CMakeLists.txt
│
├── Validacion/
│   ├── valid.cpp
│   └── CMakeLists.txt
│
├── build/
│
├── .gitignore
├── CMakeLists.txt
├── pendientes.txt
├── tienda.db
└── README.md
```

### Descripción de los directorios

| Directorio      | Descripción                                                           |
| --------------- | --------------------------------------------------------------------- |
| `Archivo_lista` | Lectura y escritura de archivos de texto.                             |
| `DB_Excepcion`  | Conexión y operaciones con SQLite, incluyendo manejo de excepciones.  |
| `Libreria_ext`  | Procesamiento de información mediante la biblioteca JSON de nlohmann. |
| `Validacion`    | Validación de datos utilizando excepciones.                           |
| `build`         | Archivos generados durante la configuración y compilación con CMake.  |

Cada ejercicio cuenta con su propio `CMakeLists.txt`, mientras que el archivo de CMake de la raíz permite administrar todos los subproyectos.

---

## 📝 Ejercicios desarrollados

### 1. Validación con excepciones

**Directorio:** `Validacion/`

**Archivo principal:** `valid.cpp`

Este programa solicita al usuario dos datos: una edad y una dirección de correo electrónico. Posteriormente, verifica que ambos cumplan con las condiciones establecidas.

**Funcionalidades:**

- Solicita una edad al usuario.
- Comprueba que la edad sea un número válido.
- Valida que el correo electrónico tenga un formato correcto.
- Utiliza excepciones para identificar y controlar entradas incorrectas.
- Captura los errores mediante bloques `try-catch` y muestra mensajes descriptivos al usuario.

---

### 2. Manejo de archivos de texto

**Directorio:** `Archivo_lista/`

**Archivo principal:** `lista.cpp`

Este ejercicio implementa un programa que permite almacenar y recuperar una lista de elementos mediante un archivo de texto.

Se utiliza el archivo `pendientes.txt` para guardar la información.

**Funcionalidades:**

- Almacena una lista de al menos cinco elementos.
- Escribe los elementos en un archivo `.txt`.
- Permite recuperar la información almacenada.
- Lee el contenido del archivo y lo muestra en pantalla.

**Archivo generado:**

`pendientes.txt`

Este archivo almacena los elementos de la lista y permite conservar la información entre ejecuciones.

---

### 3. Conexión a base de datos SQLite

**Directorio:** `DB_Excepcion/`

**Archivo principal:** `basedatos.cpp`

**Motor de base de datos:** SQLite.

Este ejercicio implementa una conexión a una base de datos SQLite desde C++. Se utiliza la biblioteca de SQLite para establecer la conexión y ejecutar instrucciones SQL.

La base de datos utilizada es `tienda.db`.

**Funcionalidades:**

- Inicializa una conexión con SQLite.
- Abre una base de datos existente o crea una nueva cuando no existe.
- Permite crear una tabla para almacenar productos.
- Realiza inserciones de registros mediante instrucciones SQL.
- Ejecuta consultas para recuperar y mostrar información almacenada.
- Cierra la conexión al finalizar las operaciones.

**Archivos de SQLite incluidos:**

```text
DB_Excepcion/
└── sqlite/
    ├── sqlite3.c
    └── sqlite3.h
```

Se utiliza la distribución amalgamada de SQLite, que permite integrar el motor de base de datos directamente en el proyecto sin necesitar una instalación independiente de SQLite para compilarlo.

---

### 4. Uso de una librería externa

**Directorio:** `Libreria_ext/`

**Archivo principal:** `ventas.cpp`

**Biblioteca utilizada:** [nlohmann/json](https://github.com/nlohmann/json).

Este ejercicio utiliza una biblioteca externa para trabajar con información estructurada en formato JSON.

Se implementa un pequeño sistema de procesamiento de ventas que permite analizar productos, cantidades y precios.

**Funcionalidades:**

- Procesa información de ventas representada en formato JSON.
- Convierte cadenas JSON en objetos manipulables desde C++.
- Agrupa y procesa las ventas de los productos.
- Calcula los ingresos generados por cada producto.
- Obtiene los ingresos totales.
- Identifica el producto con mayores y menores ingresos.
- Genera un reporte con los resultados obtenidos.

#### Instalación e inclusión de la biblioteca

Se utiliza la versión _single-header_ de nlohmann/json.

La biblioteca se incluye directamente en el proyecto mediante el archivo:

```text
Libreria_ext/
└── nlohmann/
    └── json.hpp
```

---

### 5. Integración con manejo de errores

**Directorio:** `DB_Excepcion/`

**Archivo principal:** `basedatos.cpp`

Este ejercicio integra la conexión a una base de datos con el manejo de excepciones.

Se busca evitar que el programa termine abruptamente cuando ocurre un problema durante la conexión o ejecución de operaciones SQL.

**Funcionalidades:**

- Intenta establecer una conexión con la base de datos.
- Comprueba si la conexión se realizó correctamente.
- Detecta errores durante la ejecución de instrucciones SQL.
- Utiliza excepciones para comunicar los errores encontrados.
- Captura las excepciones y muestra mensajes descriptivos.
- Cierra la conexión cuando corresponde, evitando mantener recursos abiertos innecesariamente.

Este ejercicio complementa el punto anterior de conexión a bases de datos, demostrando que las operaciones deben contemplar posibles fallos y no únicamente los casos exitosos.

---

## ⚙️ Requisitos

Para compilar y ejecutar los ejercicios se necesitan las siguientes herramientas:

| Herramienta           | Uso                                                            |
| --------------------- | -------------------------------------------------------------- |
| C++17 o superior      | Lenguaje de programación.                                      |
| CMake 3.20 o superior | Configuración y generación del proyecto.                       |
| Ninja                 | Sistema de compilación utilizado como generador de CMake.      |
| Compilador compatible | MSVC, GCC o Clang.                                             |
| SQLite                | Motor de base de datos integrado mediante sus archivos fuente. |
| nlohmann/json         | Biblioteca externa para manipular JSON.                        |

---

## 🔨 1. Configuración y compilación

El proyecto utiliza CMake para administrar los diferentes ejercicios.

### 2. Generar los archivos de compilación

```bash
cmake -S . -B build -G Ninja
```

Este comando:

- `-S .`: indica que el código fuente se encuentra en el directorio actual.
- `-B build`: establece `build/` como directorio de compilación.
- `-G Ninja`: selecciona Ninja como generador.

### 3. Compilar el proyecto

```bash
cmake --build build
```

Este comando compila todos los subproyectos agregados al `CMakeLists.txt` principal.

---

## ▶️ Ejecución individual de los ejercicios

También es posible compilar cada ejercicio por separado sin necesidad de compilar todo el proyecto.

### Opción A: Utilizando el CMake principal

Primero, genera los archivos de compilación desde la raíz:

```bash
cmake -S . -B build -G Ninja
```

Para conocer los nombres exactos de los ejecutables definidos en cada `CMakeLists.txt`, utiliza:

```bash
cmake --build build --target help
```

Después, compila únicamente el ejercicio deseado:

```bash
cmake --build build --target NOMBRE_DEL_TARGET
```

Por ejemplo, si el ejecutable de `DB_Excepcion` está definido con el nombre `db_excepcion`:

```bash
cmake --build build --target db_excepcion
```
