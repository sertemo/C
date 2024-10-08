#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1

typedef struct MapEntry {
    char *key;            // public
    volatile int value;   // public
    struct MapEntry *__next;  // private
    struct MapEntry *__prev;  // private
} MapEntry;

typedef struct MapIterator {
    MapEntry *__current;
    MapEntry* (*next)(struct MapIterator *self);
    void (*del)(struct MapIterator *self);
} MapIterator;

typedef struct Map {
    // Atributos privados
    MapEntry *__head;
    MapEntry *__tail;
    int __count;

    // Métodos públicos
    MapIterator* (*iter)(struct Map *self);
    void (*put)(struct Map *self, char *key, int value);  // Define un puntero que apunta a una función que devuelve void
    int (*get)(struct Map *self, char *key, int def);
    int (*size)(struct Map *self);
    void (*dump)(struct Map *self);
    void (*del)(struct Map *self);
} Map;



// Metodos privados
void __Map_dump(Map *self) {
    MapEntry *cur = self->__head;
    while (cur) {
        printf("%s: %d\n", cur->key, cur->value);
        cur = cur->__next;
    }
}

// Función next
MapEntry* __MapIter_next(MapIterator *self) {
    MapEntry *retval = self->__current;
    if (retval == NULL) return NULL;
    self->__current = self->__current->__next;
    return retval;
}

void __Map_del(Map *self) {
    MapEntry *cur = self->__head;
    while (cur) {
        MapEntry *next = cur->__next;
        free(cur->key);
        free(cur);
        cur = next;
    }
    free(self);
}

int __Map_size(Map *self) {
    return self->__count;
}

int __Map_get(Map *self, char *key, int def) {
    MapEntry *cur = self->__head;
    while (cur) {
        if (strcmp(cur->key, key) == 0) {
            return cur->value;
        }
        cur = cur->__next;
    }
    return def;
}

// Método find que devuelve un nodo con la clave dada
MapEntry* __find(Map *self, char *k) {
    MapEntry *cur;
    cur = self->__head;
    while (cur) {
        if (strcmp(cur->key, k) == 0) return cur;
        cur = cur->__next;
    }
    return NULL;
}

void __Map_put(Map *self, char *key, int value) {
    // Verificamos primero si existe la key
    MapEntry *cur = __find(self, key);
    if (cur) {
        cur->value = value;
    } else {
        // hay que crear un nodo nuevo ( MapEntry)
        MapEntry* n = malloc(sizeof(MapEntry));
        // asignamos memoria para k
        n->key = malloc(strlen(key) + 1);
        strcpy(n->key, key);
        n->value = value;
        n->__next = NULL;
        n->__prev = self->__tail;
        if (self->__head == NULL) {
            self->__head = n;
            self->__tail = n;
        } else {
            self->__tail->__next = n;
            n->__prev = self->__tail;
            self->__tail = n;
        }
        self->__count++;
    }
}
// Función del
void __MapIter_del(MapIterator *self) {
    free(self);
}

// Función que crea un iterador para iterar sobre un objeto Map
MapIterator* __CreateMapIter(Map *self) {
    MapIterator *iter = malloc(sizeof(MapIterator));
    iter->__current = self->__head;
    iter->next = &__MapIter_next;
    iter->del = &__MapIter_del;
    return iter;
}

// Constructor
Map* new() {
    Map* p = malloc(sizeof(Map));
    p->__head = NULL;
    p->__tail = NULL;
    p->__count = 0;

    p->put = &__Map_put;
    p->get = &__Map_get;
    p->size = &__Map_size;
    p->dump = &__Map_dump;
    p->del = &__Map_del;
    p->iter = &__CreateMapIter;
    return p;
}



int main(void) {
    // Instanciamos un mapa nuevo
    Map* d = new();
    d->put(d, "Sergio", 40);
    d->put(d, "Leire", 36);
    d->put(d, "Inhar", 3);
    d->dump(d);
    printf("Getting Sergio: %d\n", d->get(d, "Sergio", 0));
    printf("Getting Inhar: %d\n", d->get(d, "Inhar", 0));
    printf("Getting Miguel: %d\n", d->get(d, "Miguel", 0));
    printf("Size: %d\n", d->size(d));

    printf("\nIterando sobre el Map\n");

    // Creamos el iterador
    MapIterator* iter = d->iter(d);
    while (TRUE) {
        MapEntry *cur;
        cur = iter->next(iter);  // Pedimos una entrada al iterador
        if (cur == NULL) break;
        printf("%s: %d\n", cur->key, cur->value);
    }
    iter->del(iter);
    d->del(d);
    return 0;
}
