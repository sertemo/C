# include <stdio.h>
# include <string.h>

int main(int argc, char *argv[]) {  // argv es un pointer a un array de pointers
    int i;

    for (i = 1; i < argc; i++) {
        printf("%s%c", argv[i], (i < argc - 1) ? ' ' : '\n');
    }
}

// otra forma de hacerlo

int __main(int argc, char *argv[]) {
    int i;

    while (--argv > 0) {
        printf("%s%c", *++argv, (argc > 1) ? ' ' : '\n');
    }
}

// argv es un puntero a un array de punteros (que son las palabras pasadas como argumento)
// por lo tanto *argv será el primer elemento del array, que es la primera palabra pasada como argumento