+++
date = '2025-02-21T10:19:38-08:00'
draft = false
title = 'Practica 1'
+++


#Practica 1

En esta práctica utilizaremos `make` y aprenderemos cómo configurarlo para depurar un archivo. Además, analizaremos los elementos fundamentales de los lenguajes de programación, tales como:

- Nombres
- Marcos de activación
- Bloques de alcance
- Administración de memoria
- Expresiones
- Comandos
- Control de secuencia (selección, iteración y recursión)
- Subprogramas
- Tipos de datos

## Resumen del Makefile

Este `Makefile` está diseñado para compilar y gestionar un proyecto en C utilizando `gcc` como compilador. A continuación se describen las principales funcionalidades y objetivos del archivo:

1. **Variables de Configuracion**:
   - `CC`: Define el compilador a utilizar (`gcc`).
   - `CFLAGS`: Define las banderas de compilacion, incluyendo advertencias adicionales y la inclusión del directorio de encabezados (`include`).
   - `SRC_DIR`, `BUILD_DIR`, `INCLUDE_DIR`: Definen los directorios de código fuente, de construcción y de encabezados, respectivamente.

2. **Archivos de Código Fuente y Objetivo**:
   - `SRC_FILES`: Lista de archivos fuente (`.c`) que serán compilados.
   - `OBJ_FILES_VERBOSE`, `OBJ_FILES_NORMAL`: Listas de archivos objeto (`.o`) para compilaciones con y sin visualización de gestión de memoria.
   - `EXEC_WITH_DISPLAY`, `EXEC_WITHOUT_DISPLAY`: Nombres de los ejecutables generados para compilaciones con y sin visualizacion de gestion de memoria.
   - `MAP_WITH_DISPLAY`, `MAP_WITHOUT_DISPLAY`: Nombres de los archivos de mapa generados para las compilaciones.

3. **Objetivos del Makefile**:
   - `all`: Objetivo principal que compila ambos ejecutables (`EXEC_WITH_DISPLAY` y `EXEC_WITHOUT_DISPLAY`).
   - `$(EXEC_WITH_DISPLAY)`: Compila el ejecutable con visualización de gestion de memoria (`MEMORY_MANAGEMENT_DISPLAY=1`).
   - `$(EXEC_WITHOUT_DISPLAY)`: Compila el ejecutable sin visualización de gestion de memoria (`MEMORY_MANAGEMENT_DISPLAY=0`).

4. **Compilación de Archivos Objeto**:
   - `$(BUILD_DIR)/%_verbose.o`: Compila archivos objeto para la compilacion con visualización de gestión de memoria.
   - `$(BUILD_DIR)/%.o`: Compila archivos objeto para la compilacion normal.

5. **Creación y Limpieza del Directorio de Construcción**:
   - `$(BUILD_DIR)`: Crea el directorio de construcción si no existe.
   - `clean`: Limpia el directorio de construcción eliminando todos los archivos generados.

6. **Phony Targets**:
   - `.PHONY: all clean`: Define `all` y `clean` como objetivos que no corresponden a archivos reales, asegurando que se ejecuten siempre que se invoquen.

Este `Makefile` permite una gestión eficiente del proceso de compilación, facilitando la creación de ejecutables con diferentes configuraciones y asegurando una limpieza adecuada del entorno de construcción.

# Sistema de Gestión de Biblioteca en C

## Descripción General
Este programa en C administra una biblioteca, permitiendo la gestión de libros y miembros, además del control de préstamos y devoluciones. Utiliza estructuras de datos dinámicas y maneja memoria en el heap.

## Características Principales
- **Gestión de Libros:**
  - Agregar libros a la biblioteca.
  - Buscar libros por ID.
  - Mostrar todos los libros disponibles.
  - Guardar y cargar libros desde archivos.

- **Gestión de Miembros:**
  - Agregar miembros a la biblioteca.
  - Buscar miembros por ID.
  - Mostrar miembros y sus libros prestados.
  - Guardar y cargar miembros desde archivos.

- **Préstamos y Devoluciones:**
  - Prestar libros a miembros.
  - Registrar la devolución de libros.
  - Control de la cantidad de copias disponibles.

## Lenguajes de Programación en el Proyecto
Este sistema está desarrollado en **C**, un lenguaje de programación estructurado de bajo nivel con control manual de memoria.

## Conceptos Aplicados

### 1. **Nombres y Bloques de Alcance**
   - Uso de variables con **nombres únicos** en diferentes ámbitos (global, local y dentro de funciones).
   - Identificadores de variables y estructuras bien definidos en `book_t` y `member_t`.
   - Bloques de alcance definidos en funciones (`{}`) para evitar colisiones de nombres.

### 2. **Marcos de Activación**
   - Cada función tiene su **propio marco de activación** en la pila, asegurando la correcta gestión de variables locales.
   - Uso de llamadas recursivas (`displayBooksRecursive`), generando múltiples marcos en la pila.

### 3. **Administración de Memoria**
   - Asignación dinámica de memoria con `malloc()` y `realloc()` para listas enlazadas.
   - Liberación de memoria con `free()` para evitar **fugas de memoria**.
   - Almacenamiento y recuperación de datos desde archivos.

### 4. **Expresiones y Comandos**
   - Uso de expresiones en comparaciones (`if`, `switch`).
   - Comandos secuenciales en la gestión de entradas de usuario (`scanf`, `fgets`).

### 5. **Control de Secuencia**
   - **Selección**: Uso de `if-else` y `switch` para ejecutar decisiones según la entrada del usuario.
   - **Iteración**: Uso de bucles `for` y `while` para recorrer listas de libros y miembros.
   - **Recursión**: Implementación en la función `displayBooksRecursive()` para recorrer y mostrar libros.

### 6. **Subprogramas**
   - Implementación de **funciones reutilizables** para modularidad y claridad.
   - Ejemplo: `findBookById()` y `addBook()`, evitando redundancia en el código.

### 7. **Tipos de Datos**
   - **Primitivos**: `int`, `char`, `enum` (para géneros de libros).
   - **Estructuras personalizadas** (`struct`): `book_t` y `member_t` para organizar datos.
   - **Punteros**: Uso de `book_t *next` en listas enlazadas.

## Estructuras de Datos

### `genre_t`
Enumera los géneros disponibles:
```c
typedef enum {
    FICTION, NON_FICTION, SCIENCE, HISTORY, FANTASY, BIOGRAPHY, OTHER
} genre_t;

