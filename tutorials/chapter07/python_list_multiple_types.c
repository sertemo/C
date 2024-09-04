/* En esta versión de la lista, los elementos pueden ser de distinto tipo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enumeración para los tipos de datos soportados
typedef enum {
    TYPE_INT,
    TYPE_CHAR,
    TYPE_STRING,
    TYPE_FLOAT
} DataType;

// Estructura para un elemento de la lista, que contiene el dato y su tipo
typedef struct {
    void *data;     // Dato almacenado como puntero genérico
    DataType type;  // Tipo del dato
} ListItem;

// Estructura de la lista dinámica
typedef struct {
    int alloc;      // Capacidad de la lista
    int len;        // Longitud actual
    ListItem *items;  // Array de elementos
} list;

// Constructor de nueva lista
list* new(void) {
    list* l = malloc(sizeof(list));
    l->alloc = 2;
    l->len = 0;
    l->items = malloc(l->alloc * sizeof(ListItem));  // Alocamos 2 elementos
    return l;
}

// Destructor de lista
void del(list* self) {
    for (int i = 0; i < self->len; i++) {
        // Si el tipo es cadena, liberamos la memoria asignada
        if (self->items[i].type == TYPE_STRING) {
            free(self->items[i].data);
        }
    }
    free(self->items);
    free(self);
}

// Función para imprimir un item de la lista
void print_item(ListItem item) {
    if (item.type == TYPE_INT) {
        printf("%d", *(int*)item.data);
    } else if (item.type == TYPE_CHAR) {
        printf("'%c'", *(char*)item.data);
    } else if (item.type == TYPE_STRING) {
        printf("\"%s\"", (char*)item.data);
    } else if (item.type == TYPE_FLOAT) {
        printf("%f", *(float*)item.data);
    }
}

// Función para imprimir la lista
void print(const list* self) {
    printf("[");
    for (int i = 0; i < self->len; i++) {
        print_item(self->items[i]);
        if (i < self->len - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Redimensionar la lista si es necesario
void resize_list(list* self) {
    if (self->len == self->alloc) {
        self->alloc *= 2;
        self->items = realloc(self->items, self->alloc * sizeof(ListItem));
        if (self->items == NULL) {
            printf("Error: no se pudo asignar más memoria.\n");
            exit(EXIT_FAILURE);
        }
    }
}

// Función para agregar un entero a la lista
void append_int(list* self, int value) {
    resize_list(self);
    int *data = malloc(sizeof(int));
    *data = value;
    self->items[self->len].data = data;
    self->items[self->len].type = TYPE_INT;
    self->len++;
}

// Función para agregar un carácter a la lista
void append_char(list* self, char value) {
    resize_list(self);
    char *data = malloc(sizeof(char));
    *data = value;
    self->items[self->len].data = data;
    self->items[self->len].type = TYPE_CHAR;
    self->len++;
}

// Función para agregar una cadena a la lista
void append_string(list* self, const char *value) {
    resize_list(self);
    char *data = malloc(strlen(value) + 1);
    strcpy(data, value);
    self->items[self->len].data = data;
    self->items[self->len].type = TYPE_STRING;
    self->len++;
}

// Función para agregar un flotante a la lista
void append_float(list* self, float value) {
    resize_list(self);
    float *data = malloc(sizeof(float));
    *data = value;
    self->items[self->len].data = data;
    self->items[self->len].type = TYPE_FLOAT;
    self->len++;
}

// Obtener la longitud de la lista
int len(const list* self) {
    return self->len;
}

// Obtener un elemento de la lista
ListItem get_item(list* self, int index) {
    if (index < 0 || index >= self->len) {
        printf("IndexError: Índice fuera de rango.\n");
        exit(EXIT_FAILURE);
    }
    return self->items[index];
}

int main(void) {
    printf("Testing pylist class\n");
    list *x = new();  // Creamos una nueva lista

    // Añadimos diferentes tipos de elementos
    append_int(x, 42);
    printf("Longitud de la lista: %d\n", len(x));
    append_char(x, 'A');
    print(x);
    printf("Longitud de la lista: %d\n", len(x));
    append_string(x, "Hello, World");
    append_float(x, 3.1415);
    printf("Longitud de la lista: %d\n", len(x));

    // Mostramos la lista
    print(x);

    // Obtener e imprimir un elemento indexado
    printf("Get item 0: \n");
    print_item(get_item(x, 0));
    printf("\n");
    printf("Get item 1: \n");
    print_item(get_item(x, 1));
    printf("\n");
    printf("Get item 2: \n");
    print_item(get_item(x, 2));
    printf("\n");
    printf("Get item 10: \n");
    print_item(get_item(x, 10));
    printf("\n");

    // Liberamos la memoria
    del(x);

    return 0;
}
