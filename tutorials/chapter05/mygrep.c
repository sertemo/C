#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

// Declaración de la función getline que leerá una línea desde stdin
int get_line(char line[], int max);

int main(int argc, char *argv[]) {
    char line[MAXLINE];

    if (argc != 2) {
        printf("Usage: find pattern\n");
        return 1;
    } else {
        while (get_line(line, MAXLINE) > 0) {
            if (strstr(line, argv[1]) != NULL) {  // strstr es una función de la librería string.h como index
                printf("%s", line);
            }
        }
    }
    return 0;
}

// Implementación de get_line para leer una línea desde stdin
int get_line(char line[], int max) {
    if (fgets(line, max, stdin) != NULL) {
        return strlen(line);
    } else {
        return 0;
    }
}
