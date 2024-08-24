#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

// Declaración de la función getline que leerá una línea desde stdin
int get_line(char line[], int max);

main(int argc, char *argv[]) /* find pattern from first argument */
    {
    char line[MAXLINE], *s;
    long lineno = 0;
    int except = 0, number = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
        for (s = argv[0]+1; *s != '\0'; s++)
        switch (*s) {
        case 'x':
            except = 1;
            break;
        case 'n':
            number = 1;
            break;
        default:
            printf("find: illegal option %c\n", *s);
            argc = 0;
            break;
        }
    if (argc != 1)
        printf("Usage: find -x -n pattern\n");
    else
        while (get_line(line, MAXLINE) > 0) {
        lineno++;
        if ((strstr(line, *argv) >= 0) != except) {
            if (number)
            printf("%ld: ", lineno);
            printf("%s", line);
            }
        }
    }


// Implementación de get_line para leer una línea desde stdin
int get_line(char line[], int max) {
    if (fgets(line, max, stdin) != NULL) {
        return strlen(line);
    } else {
        return 0;
    }
}