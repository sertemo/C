# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// Simulamos una clase list de Python pero en C

// Creamos la lista como un linked list

typedef struct node {
    char *text;
    struct node *next;
} node;

typedef struct pylist {
    node *head;
    node *tail;
    int length;
} list;

// Creamos el constructor de la lista
list* new(void) {
    list* p = malloc(sizeof(list));
    p->head = NULL;
    p->tail = NULL;
    p->length = 0;
    return p;
}

// Destructor de la lista
void del(list *self) {
    node *cur, *next;  // Creamos dos punteros para recorrer la lista e ir borrando los nodos
    cur = self->head;
    while (cur) {
        free(cur->text);  // limpiamos el texto del nodo
        next = cur->next;  // Guardamos el siguiente nodo en next
        free(cur);  // limpiamos definitivamente el nodo. Despues de esto no podemos tocar cur
        cur = next;  // cur ahora apunta al siguiente nodo y repetimos
    }
    free(self);
}

// Función para printear la lista
void dump(list *self) {
    node *cur;
    cur = self->head;
    printf("[");
    while (cur) {
        printf("'%s'", cur->text);
        if (cur->next) printf(", ");
        cur = cur->next;
    }
    printf("]\n");
}

// Función que devuelve la longitud de la lista (número de elementos)
int len(list *self) {
    return self->length;
}

// Función para insertar un elemento en la lista
void append(list *self, char *text) {
    node *n = malloc(sizeof(node));
    n->text = malloc(strlen(text) + 1);  // Asignar memoria para text
    strcpy(n->text, text);
    n->next = NULL;
    if (self->head == NULL) {
        self->head = n;
        self->tail = n;
    } else {
        self->tail->next = n;
        self->tail = n;
    }
    self->length++;
}

// Método para devolver el índice en el que se encuentra un elemento
int get_index(list *self, char *text) {
    node *cur;
    cur = self->head;
    int i = 0;
    while (cur) {
        if (strcmp(cur->text, text) == 0) return i;  // Si se encuentra, devuelve el índice
        cur = cur->next;  // Avanza al siguiente nodo
        i++;  // Incrementa el índice
    }
    return -1;  // Si no se encuentra, devuelve -1
}

int main(void) {
    printf("Testing pylist class\n");
    list *x = new();  // llamamos al constructor

    dump(x);  // printeamos el contenido de la lista
    printf("len: %d\n", len(x));
    append(x, "Hello");
    dump(x);

    append(x, "World");
    append(x, "Juan");
    dump(x);
    printf("len: %d\n", len(x));

    printf("Index of 'World': %d\n", get_index(x, "World"));
    printf("Index of 'Bob': %d\n", get_index(x, "Bob"));
    printf("Index of 'Juan': %d\n", get_index(x, "Juan"));

    del(x);
    return 0;
}