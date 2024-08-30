#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_BUCKETS 8
#define TRUE 1

typedef struct HashMapEntry {
    char *key;
    int value;
    struct HashMapEntry *__next;
    struct HashMapEntry *__prev;
} HashMapEntry;

typedef struct HashMapIterator HashMapIterator;  // Forward declaration

typedef struct HashMap {
    HashMapEntry *__heads[DEFAULT_BUCKETS];  // 8 buckets
    HashMapEntry *__tails[DEFAULT_BUCKETS];
    int __buckets;
    int __count;

    // Métodos públicos
    HashMapIterator* (*iter)(struct HashMap *self);
    void (*put)(struct HashMap *self, char *key, int value);
    int (*get)(struct HashMap *self, char *key, int def);
    int (*size)(struct HashMap *self);
    void (*dump)(struct HashMap *self);
    void (*del)(struct HashMap *self);
} HashMap;

struct HashMapIterator {
    int __bucket;
    HashMapEntry *__current;
    HashMap *__map;

    HashMapEntry* (*next)(struct HashMapIterator *self);
    void (*del)(struct HashMapIterator *self);
};

// Función que hashea y devuelve un numero de bucket
int getBucket(char *str, int buckets) {
    unsigned int hash = 123456789;
    //printf("\nHashing %s\n", str);
    for (; *str; str++) {
        hash = (hash << 3) ^ *str;
        //printf("%c = 0x%08x %d\n", *str, hash, hash % buckets);
    }
    return hash % buckets;
}

HashMapEntry* __HashMapIter_next(HashMapIterator *self) {
    HashMapEntry *retval = self->__current;
    
    while (self->__current == NULL) {
        self->__bucket++;
        if (self->__bucket >= self->__map->__buckets) return NULL;
        self->__current = self->__map->__heads[self->__bucket];
    }

    retval = self->__current;
    if (self->__current != NULL) self->__current = self->__current->__next;
    return retval;
}

void __HashMapIter_del(HashMapIterator *self) {
    free(self);
}

HashMapIterator* __CreateHashMapIter(HashMap *map) {
    HashMapIterator *iter = malloc(sizeof(HashMapIterator));
    iter->__map = map;
    iter->__bucket = 0;
    iter->__current = map->__heads[iter->__bucket];
    iter->next = &__HashMapIter_next;
    iter->del = &__HashMapIter_del;
    return iter;
}

void __HashMap_del(HashMap *self) {
    HashMapIterator *iter = __CreateHashMapIter(self);

    while (TRUE) {
        HashMapEntry *cur = iter->next(iter);
        if (cur == NULL) break;
        free(cur->key);
        free(cur);
    }
    iter->del(iter);
    free(self);
}

HashMapEntry* __find(HashMap *self, char *k, int bucket) {
    HashMapEntry *cur;
    if (self == NULL || k == NULL) return NULL;

    cur = self->__heads[bucket];
    while (cur) {
        if (strcmp(cur->key, k) == 0) return cur;
        cur = cur->__next;
    }
    return NULL;
}

void __HashMap_put(HashMap *self, char *key, int value) {
    int bucket = getBucket(key, self->__buckets);
    HashMapEntry *cur = __find(self, key, bucket);
    if (cur) {
        cur->value = value;
    } else {
        HashMapEntry* n = malloc(sizeof(HashMapEntry));
        n->key = malloc(strlen(key) + 1);
        strcpy(n->key, key);
        n->value = value;
        n->__next = NULL;
        n->__prev = self->__tails[bucket];
        if (self->__heads[bucket] == NULL) {
            self->__heads[bucket] = n;
            self->__tails[bucket] = n;
        } else {
            self->__tails[bucket]->__next = n;
            self->__tails[bucket] = n;
        }
        self->__count++;
    }
}

int __HashMap_get(HashMap *self, char *key, int def) {
    int bucket = getBucket(key, self->__buckets);
    HashMapEntry *retval = __find(self, key, bucket);
    if (retval == NULL) return def;
    return retval->value;
}

void __HashMap_dump(HashMap *self) {
    HashMapEntry *cur;

    printf("Object HashMap@%p count=%d buckets=%d\n", self, self->__count, self->__buckets);
    for (int i = 0; i < self->__buckets; i++) {
        for (cur = self->__heads[i]; cur; cur = cur->__next) {
            printf("%s=%d\n", cur->key, cur->value);
        }
    }
}

int __HashMap_size(HashMap *self) {
    if (self == NULL) return 0;
    return self->__count;
}

// Constructor
HashMap* new() {
    HashMap *p = malloc(sizeof(HashMap));
    p->__buckets = DEFAULT_BUCKETS;
    p->__count = 0;
    for (int i = 0; i < p->__buckets; i++) {
        p->__heads[i] = NULL;
        p->__tails[i] = NULL;
    }

    p->put = &__HashMap_put;
    p->get = &__HashMap_get;
    p->size = &__HashMap_size;
    p->dump = &__HashMap_dump;
    p->del = &__HashMap_del;
    p->iter = &__CreateHashMapIter;
    return p;
}

int main(void) {
    // Instanciamos un mapa nuevo
    HashMap* d = new();

    d->put(d, "Sergio", 40);
    d->put(d, "Leire", 50);
    d->put(d, "Inhar", 3);
    d->dump(d);
    printf("Getting 'Sergio': %d\n", d->get(d, "Sergio", 0));
    printf("Size: %d\n", d->size(d));
    d->del(d);
    return 0;
}
