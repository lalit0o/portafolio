+++
date = '2025-02-21T10:18:14-08:00'
draft = false
title = 'Practica 1'
+++

***Primer código: memory_management.h***

```c
#ifndef MEMORY_MANAGEMENT_H
#define MEMORY_MANAGEMENT_H

#include <stdio.h>

// Define a macro to enable or disable memory management display
#ifndef MEMORY_MANAGEMENT_DISPLAY
#define MEMORY_MANAGEMENT_DISPLAY 0
#endif

// Counters for memory usage
extern int heap_allocations;
extern int heap_deallocations;
extern int stack_allocations;
extern int stack_deallocations;

#if MEMORY_MANAGEMENT_DISPLAY
void displayMemoryUsage();
void incrementHeapAllocations(void *pointer, size_t size);
void incrementHeapDeallocations(void *pointer);
void incrementStackAllocations();
void incrementStackDeallocations();
#else
#define displayMemoryUsage() ((void)0)
#define incrementHeapAllocations(pointer, size) ((void)0)
#define incrementHeapDeallocations(pointer) ((void)0)
#define incrementStackAllocations() ((void)0)
#define incrementStackDeallocations() ((void)0)
#endif

#endif // MEMORY_MANAGEMENT_H
```



1. **Nombres**:  
   - Los identificadores como `MEMORY_MANAGEMENT_H`, `MEMORY_MANAGEMENT_DISPLAY`, `heap_allocations`, `displayMemoryUsage`, etc., son nombres usados para macros, variables y funciones.

2. **Objetos**:  
   - Las variables `heap_allocations`, `heap_deallocations`, `stack_allocations`, `stack_deallocations` representan objetos en memoria.

3. **Entornos**:  
   - El entorno de ejecución incluye la memoria dinámica (heap) y la memoria de pila (stack), representadas en este código mediante contadores.

4. **Bloques**:  
   - Aunque el código es un archivo de encabezado, las funciones declaradas definirán bloques de código en su implementación.

5. **Alcance**:  
   - Las variables `heap_allocations`, `heap_deallocations`, etc., son `extern`, lo que sugiere que su definición real está en otro archivo, indicando un alcance global.

6. **Administración de memoria**:  
   - El código incluye funciones y macros para rastrear la asignación y liberación de memoria en el heap y la pila.

7. **Expresiones**:  
   - Las macros como `#define MEMORY_MANAGEMENT_DISPLAY 0` pueden verse como expresiones preprocesadas.

8. **Comandos**:  
   - Las funciones `incrementHeapAllocations`, `incrementHeapDeallocations`, etc., son comandos que modificarán valores de las variables de seguimiento.

9. **Secuencia**:  
   - La ejecución de funciones de administración de memoria seguiría una secuencia lógica en el código fuente que las implemente.

10. **Selección**:  
    - `#if MEMORY_MANAGEMENT_DISPLAY` es una estructura de selección condicional para compilar o no las funciones de administración de memoria.

11. **Iteración**:  
    - No hay iteraciones en este código, pero podrían aparecer en la implementación (por ejemplo, recorrer una lista de asignaciones).

12. **Recursión**:  
    - No hay recursión en este código.

13. **Subprogramas**:  
    - Se definen funciones como `displayMemoryUsage`, `incrementHeapAllocations`, etc.

14. **Tipos de datos**:  
    - Se usan tipos primitivos como `int`, `size_t`, y `void *`.

***Segundo código: biblioteca.c***

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/memory_management.h"

// Variable estatica (almacenada en el segmento de datos)
static int static_var = 0;

// Variable del segmento BSS (variable global no inicializada)
int bss_var;

typedef enum {
    FICTION,
    NON_FICTION,
    SCIENCE,
    HISTORY,
    FANTASY,
    BIOGRAPHY,
    OTHER
} genre_t;

typedef struct _book {
    int id;
    char title[100];
    char author[100];
    int publication_year;
    genre_t genre;
    int quantity;
    struct _book *next;
} book_t;

typedef struct _member {
    int id;
    char name[100];
    int issued_count;
    int *issued_books;
    struct _member *next;
} member_t;

// Prototipos de funciones
const char* genreToString(genre_t genre);
void addBook(book_t **library, int* count);
book_t* findBookById(book_t *library, int bookID);
void displayBooksRecursive(book_t *library);
void displayBooks(book_t *library);
void addMember(member_t **members, int *memberCount);
void issueBook(book_t *library, member_t *members);
void returnBook(book_t *library, member_t *members);
void freeLibrary(book_t *library);
void freeMembers(member_t *members);
void saveLibraryToFile(book_t *library, const char *filename);
void loadLibraryFromFile(book_t **library, int *bookCount, const char *filename);
void saveMembersToFile(member_t *members, const char *filename);
void loadMembersFromFile(member_t **members, int *memberCount, const char *filename);
void displayMembers(member_t *members, book_t *library);
void searchMember(member_t *members, book_t *library);

// Función para convertir el género a texto
const char* genreToString(genre_t genre) {
    switch (genre) {
        case FICTION: return "Ficcion";
        case NON_FICTION: return "No Ficcion";
        case SCIENCE: return "Ciencia";
        case HISTORY: return "Historia";
        case FANTASY: return "Fantasia";
        case BIOGRAPHY: return "Biografia";
        case OTHER: return "Otro";
        default: return "Desconocido";
    }
}

void addBook(book_t **library, int* count ) {
    // Asignacion de memoria en el heap
    book_t *new_book = (book_t *)malloc(sizeof(book_t));
    if (!new_book) {
        printf("Error al asignar memoria para el nuevo libro.\n");
        return;
    }
    incrementHeapAllocations(new_book, sizeof(book_t));
    printf("Memoria asignada para un nuevo libro (ID: %d) en el heap\n", new_book->id);

    printf("\nIngresa ID del libro: ");
    scanf("%d", &new_book->id);

    printf("Ingresa titulo del libro: ");
    getchar();
    fgets(new_book->title, 100, stdin);
    new_book->title[strcspn(new_book->title, "\n")] = '\0';

    printf("Ingresa nombre del autor: ");
    fgets(new_book->author, 100, stdin);
    new_book->author[strcspn(new_book->author, "\n")] = '\0';

    printf("Ingresa el ano de publicacion: ");
    scanf("%d", &new_book->publication_year);

    printf("Ingresa el genero del libro (0: FICTION, 1: NON_FICTION, 2: SCIENCE, 3: HISTORY, 4: FANTASY, 5: BIOGRAPHY, 6: OTHER): ");
    int genre;
    scanf("%d", &genre);
    new_book->genre = (genre_t)genre;

    printf("Ingresa la cantidad de libros: ");
    scanf("%d", &new_book->quantity);

    new_book->next = *library;
    *library = new_book;
    (*count)++;

    printf("\nEl libro fue agregado exitosamente!\n");
    displayMemoryUsage();
}

book_t* findBookById(book_t *library, int bookID) {
    book_t *current = library;
    while (current) {
        if (current->id == bookID) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void displayBooksRecursive(book_t *library) {
    if (!library) {
        return;
    }
    printf("\nID libro: %d\nTitulo: %s\nAutor: %s\nAno de publicacion: %d\nGenero: %s\nCantidad: %d\n",
        library->id, library->title, library->author, library->publication_year, genreToString(library->genre), library->quantity);
    displayBooksRecursive(library->next);
}

void displayBooks(book_t *library) {
    if (!library) {
        printf("\nNo hay libros disponibles.\n");
        return;
    }

    printf("\nLibros disponibles en biblioteca:\n");
    displayBooksRecursive(library);
    displayMemoryUsage();
}

void addMember(member_t **members, int *memberCount) {
    // Asignacion de memoria en el heap
    member_t *new_member = (member_t *)malloc(sizeof(member_t));
    if (!new_member) {
        printf("Error al asignar memoria para el nuevo miembro.\n");
        return;
    }
    incrementHeapAllocations(new_member, sizeof(member_t));
    printf("Memoria asignada para un nuevo miembro (ID: %d) en el heap\n", new_member->id);

    printf("\nIngresa el ID del miembro: ");
    scanf("%d", &new_member->id);
    printf("Ingresa el nombre del miembro: ");
    getchar();
    fgets(new_member->name, 100, stdin);
    new_member->name[strcspn(new_member->name, "\n")] = '\0';
    new_member->issued_count = 0;
    new_member->issued_books = NULL;
    new_member->next = *members;
    *members = new_member;
    (*memberCount)++;
    printf("\nMiembro agregado exitosamente!\n");
    displayMemoryUsage();
}

void issueBook(book_t *library, member_t *members) {
    int bookID, memberID;
    printf("\nIngresa el ID del miembro: ");
    scanf("%d", &memberID);
    printf("Ingresa el ID del libro: ");
    scanf("%d", &bookID);

    book_t *bookFound = NULL;
    member_t *memberFound = NULL;

    book_t *current_book = library;
    while (current_book) {
        if (current_book->id == bookID && current_book->quantity > 0) {
            bookFound = current_book;
            break;
        }
        current_book = current_book->next;
    }

    member_t *current_member = members;
    while (current_member) {
        if (current_member->id == memberID) {
            memberFound = current_member;
            break;
        }
        current_member = current_member->next;
    }

    if (bookFound && memberFound) {
        bookFound->quantity--;
        memberFound->issued_count++;
        memberFound->issued_books = realloc(memberFound->issued_books, memberFound->issued_count * sizeof(int));
        incrementHeapAllocations(memberFound->issued_books, memberFound->issued_count * sizeof(int));
        printf("Memoria reasignada para los libros prestados del miembro (ID: %d) en el heap\n", memberFound->id);
        memberFound->issued_books[memberFound->issued_count - 1] = bookID;
        printf("\nLibro prestado satisfactoriamente!\n");
    } else {
        printf("\nLibro o miembro no encontrados.\n");
    }
    displayMemoryUsage();
}

void returnBook(book_t *library, member_t *members) {
    int bookID, memberID;
    printf("\nIngresa el ID del miembro: ");
    scanf("%d", &memberID);
    printf("Ingresa el ID del libro: ");
    scanf("%d", &bookID);

    book_t *bookFound = NULL;
    member_t *memberFound = NULL;

    book_t *current_book = library;
    while (current_book) {
        if (current_book->id == bookID) {
            bookFound = current_book;
            break;
        }
        current_book = current_book->next;
    }

    member_t *current_member = members;
    while (current_member) {
        if (current_member->id == memberID) {
            memberFound = current_member;
            break;
        }
        current_member = current_member->next;
    }

    if (bookFound && memberFound) {
        int found = 0;
        for (int i = 0; i < memberFound->issued_count; i++) {
            if (memberFound->issued_books[i] == bookID) {
                found = 1;
                for (int j = i; j < memberFound->issued_count - 1; j++) {
                    memberFound->issued_books[j] = memberFound->issued_books[j + 1];
                }
                memberFound->issued_count--;
                memberFound->issued_books = realloc(memberFound->issued_books, memberFound->issued_count * sizeof(int));
                incrementHeapAllocations(memberFound->issued_books, memberFound->issued_count * sizeof(int));
                printf("Memoria reasignada para los libros prestados del miembro (ID: %d) en el heap\n", memberFound->id);
                break;
            }
        }
        if (found) {
            bookFound->quantity++;
            printf("\nLibro devuelto satisfactoriamente!\n");
        } else {
            printf("\nEl miembro no tiene este libro prestado.\n");
        }
    } else {
        printf("\nLibro o miembro no encontrados.\n");
    }
    displayMemoryUsage();
}

void freeLibrary(book_t *library) {
    book_t *current = library;
    while (current) {
        book_t *next = current->next;
        incrementHeapDeallocations(current);
        free(current);
        current = next;
    }
    displayMemoryUsage();
}

void freeMembers(member_t *members) {
    member_t *current = members;
    while (current) {
        member_t *next = current->next;
        incrementHeapDeallocations(current->issued_books);
        free(current->issued_books);
        incrementHeapDeallocations(current);
        free(current);
        current = next;
    }
    displayMemoryUsage();
}

void saveLibraryToFile(book_t *library, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error al abrir el archivo para guardar la biblioteca.\n");
        return;
    }

    book_t *current = library;
    while (current) {
        fprintf(file, "%d\n%s\n%s\n%d\n%s\n%d\n", current->id, current->title, current->author, current->publication_year, genreToString(current->genre), current->quantity);
        current = current->next;
    }

    fclose(file);
    printf("Biblioteca guardada exitosamente en %s\n", filename);
    displayMemoryUsage();
}

void loadLibraryFromFile(book_t **library, int *bookCount, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error al abrir el archivo para cargar la biblioteca.\n");
        return;
    }

    while (!feof(file)) {
        book_t *new_book = (book_t *)malloc(sizeof(book_t));
        if (!new_book) {
            printf("Error al asignar memoria para el nuevo libro.\n");
            fclose(file);
            return;
        }

        fscanf(file, "%d\n", &new_book->id);
        fgets(new_book->title, 100, file);
        new_book->title[strcspn(new_book->title, "\n")] = '\0';
        fgets(new_book->author, 100, file);
        new_book->author[strcspn(new_book->author, "\n")] = '\0';
        fscanf(file, "%d\n", &new_book->publication_year);
        char genre_str[50];
        fgets(genre_str, 50, file);
        genre_str[strcspn(genre_str, "\n")] = '\0';
        if (strcmp(genre_str, "Ficcion") == 0) new_book->genre = FICTION;
        else if (strcmp(genre_str, "No Ficcion") == 0) new_book->genre = NON_FICTION;
        else if (strcmp(genre_str, "Ciencia") == 0) new_book->genre = SCIENCE;
        else if (strcmp(genre_str, "Historia") == 0) new_book->genre = HISTORY;
        else if (strcmp(genre_str, "Fantasia") == 0) new_book->genre = FANTASY;
        else if (strcmp(genre_str, "Biografia") == 0) new_book->genre = BIOGRAPHY;
        else new_book->genre = OTHER;
        fscanf(file, "%d\n", &new_book->quantity);

        new_book->next = *library;
        *library = new_book;
        (*bookCount)++;
        incrementHeapAllocations(new_book, sizeof(book_t));
    }

    fclose(file);
    printf("Biblioteca cargada exitosamente desde %s\n", filename);
    displayMemoryUsage();
}

void saveMembersToFile(member_t *members, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error al abrir el archivo para guardar los miembros.\n");
        return;
    }

    member_t *current = members;
    while (current) {
        fprintf(file, "%d\n%s\n%d\n", current->id, current->name, current->issued_count);
        for (int i = 0; i < current->issued_count; i++) {
            fprintf(file, "%d\n", current->issued_books[i]);
        }
        current = current->next;
    }

    fclose(file);
    printf("Miembros guardados exitosamente en %s\n", filename);
}

void loadMembersFromFile(member_t **members, int *memberCount, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error al abrir el archivo para cargar los miembros.\n");
        return;
    }

    while (!feof(file)) {
        member_t *new_member = (member_t *)malloc(sizeof(member_t));
        if (!new_member) {
            printf("Error al asignar memoria para el nuevo miembro.\n");
            fclose(file);
            return;
        }

        fscanf(file, "%d\n", &new_member->id);
        fgets(new_member->name, 100, file);
        new_member->name[strcspn(new_member->name, "\n")] = '\0';
        fscanf(file, "%d\n", &new_member->issued_count);
        new_member->issued_books = (int *)malloc(new_member->issued_count * sizeof(int));
        for (int i = 0; i < new_member->issued_count; i++) {
            fscanf(file, "%d\n", &new_member->issued_books[i]);
        }

        new_member->next = *members;
        *members = new_member;
        (*memberCount)++;
        incrementHeapAllocations(new_member, sizeof(member_t));
        incrementHeapAllocations(new_member->issued_books, new_member->issued_count * sizeof(int));
    }

    fclose(file);
    printf("Miembros cargados exitosamente desde %s\n", filename);
    displayMemoryUsage();
}

void displayMembers(member_t *members, book_t *library) {
    if (!members) {
        printf("\nNo hay miembros disponibles.\n");
        return;
    }

    member_t *current = members;
    printf("\nMiembros disponibles en biblioteca:\n");
    while (current) {
        printf("\nID miembro: %d\nNombre: %s\nCantidad de libros prestados: %d\n",
            current->id, current->name, current->issued_count);
        for (int i = 0; i < current->issued_count; i++) {
            book_t *book = findBookById(library, current->issued_books[i]);
            if (book) {
                printf("  Libro ID: %d\n  Titulo: %s\n  Autor: %s\n", book->id, book->title, book->author);
            }
        }
        current = current->next;
    }
    displayMemoryUsage();
}

void searchMember(member_t *members, book_t *library) {
    int memberID;
    printf("\nIngresa el ID del miembro: ");
    scanf("%d", &memberID);

    member_t *current = members;
    while (current) {
        if (current->id == memberID) {
            printf("\nID miembro: %d\nNombre: %s\nCantidad de libros prestados: %d\n",
                current->id, current->name, current->issued_count);
            for (int i = 0; i < current->issued_count; i++) {
                book_t *book = findBookById(library, current->issued_books[i]);
                if (book) {
                    printf("  Libro ID: %d\n  Titulo: %s\n  Autor: %s\n", book->id, book->title, book->author);
                }
            }
            displayMemoryUsage();
            return;
        }
        current = current->next;
    }
    printf("\nMiembro no encontrado.\n");
    displayMemoryUsage();
}

int main() {
    // Variables automaticas (almacenadas en el stack)
    book_t *library = NULL;
    member_t *members = NULL;
    int bookCount = 0, memberCount = 0;
    int choice = 0;

    loadLibraryFromFile(&library, &bookCount, "library.txt");
    loadMembersFromFile(&members, &memberCount, "members.txt");

    do {
        printf("\nMenu de sistema de manejo de biblioteca\n");
        printf("\t1. Agregar un libro\n");
        printf("\t\t- Ingresa los detalles del libro como ID, titulo, autor, ano de publicacion, genero y cantidad.\n");
        printf("\t2. Mostrar libros disponibles\n");
        printf("\t\t- Muestra todos los libros disponibles en la biblioteca.\n");
        printf("\t3. Agregar un miembro\n");
        printf("\t\t- Ingresa los detalles del miembro como ID y nombre.\n");
        printf("\t4. Prestar libro\n");
        printf("\t\t- Ingresa el ID del miembro y el ID del libro para prestar el libro al miembro.\n");
        printf("\t5. Devolver libro\n");
        printf("\t\t- Ingresa el ID del miembro y el ID del libro para devolver el libro a la biblioteca.\n");
        printf("\t6. Mostrar miembros disponibles\n");
        printf("\t\t- Muestra todos los miembros disponibles en la biblioteca.\n");
        printf("\t7. Buscar miembro\n");
        printf("\t\t- Busca un miembro por ID y muestra sus detalles.\n");
        printf("\t8. Guardar y salir\n");
        printf("\t\t- Guarda los datos de la biblioteca en un archivo y sale del programa.\n");
        printf("Indica tu opcion: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(&library, &bookCount);
                break;
            case 2:
                displayBooks(library);
                break;
            case 3:
                addMember(&members, &memberCount);
                break;
            case 4:
                issueBook(library, members);
                break;
            case 5:
                returnBook(library, members);
                break;
            case 6:
                displayMembers(members, library);
                break;
            case 7:
                searchMember(members, library);
                break;
            case 8:
                saveLibraryToFile(library, "library.txt");
                saveMembersToFile(members, "members.txt");
                printf("Saliendo del programa\n");
                break;
            default:
                printf("Esta no es una opcion valida!!!\n");
                break;
        }
    } while(choice != 8);

    freeLibrary(library);
    freeMembers(members);

    return 0;
}



```



### **1. Nombres**  
Son los identificadores utilizados para variables, funciones, estructuras, etc.  
Ejemplo en el código:  
```c
typedef struct {
    char titulo[50];
    char autor[50];
    int anio;
} Libro;
```
Aquí `Libro`, `titulo`, `autor` y `anio` son nombres usados para la estructura y sus miembros.  

### **2. Objetos**  
Representan entidades con almacenamiento en memoria.  
Ejemplo:  
```c
Libro nuevoLibro;
```
Aquí `nuevoLibro` es un objeto (una instancia de `Libro`).  

### **3. Entornos**  
Se refiere al contexto donde se ejecuta el código. En C, el entorno de ejecución es el sistema operativo y la memoria del programa.  

### **4. Bloques**  
Secciones de código delimitadas por `{}` que agrupan instrucciones.  
Ejemplo:  
```c
void agregarLibro() {
    Libro nuevoLibro;
    printf("Ingrese el título: ");
    scanf("%s", nuevoLibro.titulo);
}
```
El bloque `{ ... }` agrupa las instrucciones de la función `agregarLibro()`.  

### **5. Alcance**  
Determina la visibilidad de variables y funciones. Puede ser:  
- **Local**: Solo accesible dentro de una función o bloque.  
- **Global**: Accesible en todo el programa.  
Ejemplo:  
```c
int totalLibros; // Global
void agregarLibro() {
    int librosAgregados = 0; // Local
}
```

### **6. Administración de Memoria**  
Incluye la asignación y liberación de memoria. En C, se usa `malloc()` y `free()`.  
Ejemplo:  
```c
Libro *biblioteca = (Libro*)malloc(10 * sizeof(Libro));
free(biblioteca);
```

### **7. Expresiones**  
Son combinaciones de valores y operadores que devuelven un resultado.  
Ejemplo:  
```c
totalLibros = librosAgregados + 1;
```
Aquí `librosAgregados + 1` es una expresión.  

### **8. Comandos**  
Son las instrucciones ejecutables, como `printf()` o `scanf()`.  
Ejemplo:  
```c
printf("Ingrese el título: ");
```

### **9. Secuencia**  
Es el flujo normal de ejecución de instrucciones.  
Ejemplo:  
```c
printf("Bienvenido a la biblioteca\n");
scanf("%s", nuevoLibro.titulo);
```
Se ejecutan en orden.  

### **10. Selección**  
Permite tomar decisiones (`if`, `switch`).  
Ejemplo:  
```c
if (totalLibros > 0) {
    printf("Hay libros disponibles\n");
} else {
    printf("No hay libros\n");
}
```

### **11. Iteración**  
Repetición de código (`for`, `while`).  
Ejemplo:  
```c
for (int i = 0; i < totalLibros; i++) {
    printf("Libro %d: %s\n", i + 1, biblioteca[i].titulo);
}
```

### **12. Recursión**  
Función que se llama a sí misma.  
Ejemplo (búsqueda recursiva de un libro):  
```c
int buscarLibro(Libro biblioteca[], int n, char titulo[]) {
    if (n < 0) return -1;
    if (strcmp(biblioteca[n].titulo, titulo) == 0) return n;
    return buscarLibro(biblioteca, n - 1, titulo);
}
```

### **13. Subprogramas**  
Funciones que encapsulan código reutilizable.  
Ejemplo:  
```c
void mostrarLibros() {
    for (int i = 0; i < totalLibros; i++) {
        printf("%s\n", biblioteca[i].titulo);
    }
}
```

### **14. Tipos de Datos**  
Definen el tipo de valores que pueden almacenarse.  
Ejemplo:  
```c
int anio;
float precio;
char titulo[50];
Libro miLibro;
```
Incluyen tipos primitivos (`int`, `float`, `char`) y compuestos (`struct`).  

---

***Segundo código: memory_management.c***

```c
#include "memory_management.h"
#include <stdlib.h>

// Initialize counters for memory usage
int heap_allocations = 0;
int heap_deallocations = 0;
int stack_allocations = 0;
int stack_deallocations = 0;

typedef struct MemoryRecord {
    void *pointer;
    size_t size;
    struct MemoryRecord *next;
} MemoryRecord;

MemoryRecord *heap_memory_records = NULL;

void addMemoryRecord(void *pointer, size_t size) {
    MemoryRecord *record = (MemoryRecord *)malloc(sizeof(MemoryRecord));
    record->pointer = pointer;
    record->size = size;
    record->next = heap_memory_records;
    heap_memory_records = record;
}

void removeMemoryRecord(void *pointer) {
    MemoryRecord **current = &heap_memory_records;
    while (*current) {
        if ((*current)->pointer == pointer) {
            MemoryRecord *to_free = *current;
            *current = (*current)->next;
            free(to_free);
            return;
        }
        current = &(*current)->next;
    }
}

#if MEMORY_MANAGEMENT_DISPLAY
void displayMemoryUsage() {
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("|                   Uso de Memoria              |\n");
    printf("-------------------------------------------------\n");
    printf("| Segmento de Texto (Codigo)                    |\n");
    printf("|-----------------------------------------------|\n");
    printf("| Segmento de Datos (Globales y Estaticos)      |\n");
    printf("|-----------------------------------------------|\n");
    printf("| Segmento BSS (Globales y Estaticos no inicializados) |\n");
    printf("|-----------------------------------------------|\n");
    printf("| Heap (Memoria Dinamica)                       |\n");
    printf("|   Asignaciones: %-28d |\n", heap_allocations);
    printf("|   Liberaciones: %-28d |\n", heap_deallocations);
    printf("|-----------------------------------------------|\n");
    printf("| Stack (Variables Locales)                     |\n");
    printf("|   Asignaciones: %-28d |\n", stack_allocations);
    printf("|   Liberaciones: %-28d |\n", stack_deallocations);
    printf("-------------------------------------------------\n");
    printf("\n");

    printf("-------------------------------------------------\n");
    printf("|             Detalles de Memoria Heap          |\n");
    printf("-------------------------------------------------\n");
    printf("| Puntero          | Tamano (bytes)             |\n");
    printf("-------------------------------------------------\n");
    MemoryRecord *current = heap_memory_records;
    while (current) {
        printf("| 0x%-14p | %-27zu |\n", current->pointer, current->size);
        current = current->next;
    }
    printf("-------------------------------------------------\n");
    printf("\n");
}

void incrementHeapAllocations(void *pointer, size_t size) {
    heap_allocations++;
    addMemoryRecord(pointer, size);
    #if MEMORY_MANAGEMENT_DISPLAY
    printf("Memoria asignada en el heap: Puntero=0x%p, Tamano=%zu bytes\n", pointer, size);
    #endif
}

void incrementHeapDeallocations(void *pointer) {
    heap_deallocations++;
    removeMemoryRecord(pointer);
    #if MEMORY_MANAGEMENT_DISPLAY
    printf("Memoria liberada en el heap: Puntero=0x%p\n", pointer);
    #endif
}

void incrementStackAllocations() {
    stack_allocations++;
}

void incrementStackDeallocations() {
    stack_deallocations++;
}
#endif


``



---

### **1. Nombres**  
Son los identificadores utilizados para variables, estructuras y funciones.  
Ejemplo en el código:  
```c
int heap_allocations = 0;
int heap_deallocations = 0;
int stack_allocations = 0;
int stack_deallocations = 0;
```
Aquí `heap_allocations`, `heap_deallocations`, etc., son nombres de variables que almacenan conteos de asignaciones y liberaciones.

---

### **2. Objetos**  
Son instancias en memoria de una estructura o una variable.  
Ejemplo:  
```c
MemoryRecord *heap_memory_records = NULL;
```
Aquí `heap_memory_records` es un **objeto** que almacena la lista de registros de memoria asignada.

---

### **3. Entornos**  
El entorno es donde se ejecuta el programa. En este código, se gestiona el **heap** y el **stack**, que son segmentos de memoria en tiempo de ejecución.

---

### **4. Bloques**  
Son grupos de instrucciones dentro de `{}`.  
Ejemplo:  
```c
void addMemoryRecord(void *pointer, size_t size) {
    MemoryRecord *record = (MemoryRecord *)malloc(sizeof(MemoryRecord));
    record->pointer = pointer;
    record->size = size;
    record->next = heap_memory_records;
    heap_memory_records = record;
}
```
Aquí `{ ... }` define el **bloque** de la función `addMemoryRecord`.

---

### **5. Alcance**  
Determina la visibilidad de variables y funciones.  
Ejemplo:  
```c
int heap_allocations = 0;  // Variable global
void incrementHeapAllocations(void *pointer, size_t size) {
    heap_allocations++;  // Accede a una variable global
}
```
Las variables `heap_allocations`, `heap_deallocations` son **globales**, accesibles desde cualquier parte del código.  
Mientras que `record` en `addMemoryRecord` es **local**, solo existe dentro de esa función.

---

### **6. Administración de Memoria**  
Incluye la asignación y liberación de memoria con `malloc()` y `free()`.  
Ejemplo:  
```c
MemoryRecord *record = (MemoryRecord *)malloc(sizeof(MemoryRecord));
free(to_free);
```
Aquí `malloc()` asigna memoria dinámica, y `free()` la libera.

---

### **7. Expresiones**  
Son combinaciones de valores y operadores que devuelven un resultado.  
Ejemplo:  
```c
heap_allocations++;
```
Aquí `heap_allocations++` es una **expresión** que incrementa el valor de la variable.

---

### **8. Comandos**  
Son instrucciones ejecutables.  
Ejemplo:  
```c
printf("Memoria asignada en el heap: Puntero=0x%p, Tamano=%zu bytes\n", pointer, size);
```
`printf()` es un **comando** que imprime información sobre la memoria asignada.

---

### **9. Secuencia**  
Ejemplo de ejecución en orden:  
```c
incrementHeapAllocations(pointer, size);
addMemoryRecord(pointer, size);
```
Primero se incrementa el contador y luego se guarda el registro. Se ejecutan en secuencia.

---

### **10. Selección**  
Uso de `if` para condicionales.  
Ejemplo:  
```c
if ((*current)->pointer == pointer) {
    MemoryRecord *to_free = *current;
    *current = (*current)->next;
    free(to_free);
    return;
}
```
Aquí se verifica si el puntero coincide antes de eliminarlo.

---

### **11. Iteración**  
Uso de `while` para recorrer la lista de registros.  
Ejemplo:  
```c
MemoryRecord *current = heap_memory_records;
while (current) {
    printf("| 0x%-14p | %-27zu |\n", current->pointer, current->size);
    current = current->next;
}
```
Este `while` **itera** sobre los registros de memoria en el heap.

---

### **12. Recursión**  
Este código no usa recursión, pero podría implementarse en `removeMemoryRecord()` en lugar del `while`.

---

### **13. Subprogramas**  
Funciones que encapsulan lógica reutilizable.  
Ejemplo:  
```c
void incrementHeapAllocations(void *pointer, size_t size) {
    heap_allocations++;
    addMemoryRecord(pointer, size);
}
```
Esta función encapsula el incremento del contador y el registro de memoria.

---

### **14. Tipos de Datos**  
Definen qué valores pueden almacenarse.  
Ejemplo:  
```c
typedef struct MemoryRecord {
    void *pointer;
    size_t size;
    struct MemoryRecord *next;
} MemoryRecord;
```
Aquí `MemoryRecord` es un **tipo de dato compuesto** (estructura).  
También se usan **tipos primitivos** como `int`, `size_t` y `void *`.

---