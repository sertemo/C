#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeMapEntry {
    char *key;
    int value;
    struct TreeMapEntry *__left;
    struct TreeMapEntry *__right;
} TreeMapEntry;


typedef struct TreeMap {
    TreeMapEntry *__head;
    TreeMapEntry *__root;
} TreeMap;

TreeMap* new() {
    TreeMap *map = malloc(sizeof(TreeMap));
    map->__head = NULL;
    map->__root = NULL;
    return map;
}
