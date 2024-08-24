#include <stdlib.h>

char *strsave(char *s) {  // Guarda el string s en algún sitio de memoria. Devuelve un puntero
    char *p, *alloc();

    if ((p = alloc(strlen(s) + 1)) != NULL)
        strcpy(p, s);
    return p;
}