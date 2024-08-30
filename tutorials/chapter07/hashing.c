#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función para hashear una cadena

int getBucket(char *str, int buckets) {
    unsigned int hash = 123456789;
    printf("\nHashing %s\n", str);
    for (; *str; str++) {
        hash = (hash << 3) ^ *str;
        printf("%c = 0x%08x %d\n", *str, hash, hash % buckets);
    }
    return hash % buckets;
}

int main(void) {
    int h;

    h = getBucket("Sergio", 8);
}