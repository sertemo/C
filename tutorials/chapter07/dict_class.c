# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define DEFAULT "None"
// Simulamos un diccionario en python

typedef struct node {
    char *key;
    char *value;
    struct node *next;
} node;

typedef struct dict {
    node *head;
    node *tail;
    int length;
} dict;

// Constructor de un diccionario
dict* new(void) {
    dict* p = malloc(sizeof(dict));
    p->head = NULL;
    p->tail = NULL;
    p->length = 0;
    return p;
}

// Destructor de un diccionario
void del(dict *self) {
    node *cur, *next;
    cur = self->head;
    while (cur) {
        free(cur->key);
        free(cur->value);
        next = cur->next;
        free(cur);
        cur = next;
    }
    free(self);
}

// Método para insertar un par clave valor al diccionario
void insert(dict *self, char *k, char *v) {
    // verificamos si la clave ya existe
    node* __find(dict *self, char *k);
    node *cur = __find(self, k);
    if (cur) {
        free(cur->value);
        cur->value = malloc(strlen(v) + 1);
        strcpy(cur->value, v);
        return;
    }
    node *n = malloc(sizeof(node));  // Pedimos memoria para un nodo nuevo
    // asignamos memoria para k y para v
    n->key = malloc(strlen(k) + 1);
    n->value = malloc(strlen(v) + 1);
    strcpy(n->key, k);
    strcpy(n->value, v);
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

int len(dict *self) {
    return self->length;
}

void dump(dict *self) {
    node *cur;
    cur = self->head;
    printf("{");
    while (cur) {
        printf("'%s': '%s'", cur->key, cur->value);
        if (cur->next) printf(", ");
        cur = cur->next;
    }
    printf("}\n");
}

// Método find que devuelve un nodo con la clave dada
node* __find(dict *self, char *k) {
    node *cur;
    cur = self->head;
    while (cur) {
        if (strcmp(cur->key, k) == 0) return cur;
        cur = cur->next;
    }
    return NULL;
}

// Método get de python
char* get(dict *self, char *k) {
    node *n = __find(self, k);
    if (n) return n->value;
    return DEFAULT;
}

int main(void) {
    dict *d = new();
    insert(d, "a", "value1");
    insert(d, "b", "value2");
    insert(d, "c", "value3");
    printf("Length: %d\n", len(d));
    // Insertamos con una clave que ya existe
    insert(d, "a", "value4");
    printf("Length: %d\n", len(d));
    printf("Value for 'd': %s\n", get(d, "d"));
    printf("Value for 'b': %s\n", get(d, "b"));
    dump(d);

    del(d);
    return 0;
}
