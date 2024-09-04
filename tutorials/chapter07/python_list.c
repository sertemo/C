/*
Versión de cómo Guido Van Rossum
implementó en su día una lista en Python
En esta versión solo se aceptan caracteres*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
    int alloc;
    int len;
    char **items;
} list;

// Constructor de nueva lista
list* new(void) {
    list* l = malloc(sizeof(list));
    l->alloc = 2;
    l->len = 0;
    l->items = malloc(l->alloc * sizeof(char*));  // Asignamos espacio para 2 punteros a char
    return l;
}

// Destructor de lista
void del(list* self) {
    for (int i = 0; i < self->len; i++) {
        free(self->items[i]);  // Liberamos cada cadena almacenada
    }
    free(self->items);  // Liberamos el array de punteros
    free(self);  // Liberamos la estructura de la lista
}

// Printear la lista
void print(const list* self) {
    printf("[");
    for (int i = 0; i < self->len; i++) {
        printf("\"%s\"", self->items[i]);
        if (i < self->len - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Obtener la longitud de la lista
int len(const list* self) {
    return self->len;
}

// Función que devuelve un índice
int get_index(const list* self, const char* text) {
    for (int i = 0; i < self->len; i++) {
        if (strcmp(self->items[i], text) == 0) {
            return i;
        }
    }
    return -1;  // Retorna -1 si no se encuentra
}

// Añadir un elemento a la lista
void append(list* self, const char* text) {
    // Redimensionar si es necesario
    if (self->len == self->alloc) {
        self->alloc *= 2;
        printf("Redimensionando para %d elementos\n", self->alloc);
        char **temp = realloc(self->items, self->alloc * sizeof(char*));
        if (temp == NULL) {
            printf("Error: no se pudo asignar más memoria.\n");
            exit(EXIT_FAILURE);
        }
        self->items = temp;
    }
    // Añadimos el nuevo elemento
    self->items[self->len] = malloc(strlen(text) + 1);  // Reservamos memoria para la cadena
    strcpy(self->items[self->len], text);  // Copiamos la cadena
    self->len++;
}

int main(void) {
    printf("Testing pylist class\n");
    list *x = new();  // Creamos una nueva lista

    print(x);  // Printeamos el contenido de la lista
    printf("len: %d\n", len(x));

    // Añadimos elementos
    append(x, "Hello");
    print(x);

    append(x, "World");
    append(x, "Juan");
    print(x);
    printf("len: %d\n", len(x));

    // Obtener índices
    printf("Index of 'World': %d\n", get_index(x, "World"));
    printf("Index of 'Bob': %d\n", get_index(x, "Bob"));
    printf("Index of 'Juan': %d\n", get_index(x, "Juan"));

    print(x);
    printf("len: %d\n", len(x));

    append(x, "Journey through the dark");
    append(x, "Imaginations");
    print(x);

    del(x);  // Liberamos la lista
    return 0;
}
