#include <stdio.h>

int string_length(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main(void) {
    char str[100];
    char final[100];
    int i, j;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Eliminar el salto de línea al final si fgets lo añade
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    int len = string_length(str);

    for (i = 0, j = len - 1; j >= 0; i++, j--) {
        final[i] = str[j];
    }
    final[i] = '\0'; // Terminar la cadena correctamente

    printf("Reversed string: %s\n", final);

    return 0;
}
