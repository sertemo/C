// Función para copiar un array a otro array de caracteres

#include <stdio.h>

#define MAXSIZE 10

void copy(char from[], char to[]){

    int i;
    for(i = 0; from[i] != '\0'; i++){
        to[i] = from[i];
    }
    to[i] = '\0';
}

int main(void){

    char from[MAXSIZE] = "hello";
    char to[MAXSIZE];
    copy(from, to);
    printf("Array copiado: %s\nArray original: %s\n", to, from);
    return 0;
}
