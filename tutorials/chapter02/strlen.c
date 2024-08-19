#include <stdio.h>
#define MAXSIZE 100


int strlen(char s[]) {  // Calcula longitud de una cadena
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }

    return i;
}

void eliminar_salto_linea(char s[]) {
    int len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}

int main(void) {
    printf("Escribe una cadena de caracteres: ");
    char s[MAXSIZE];
    // Leer hasta MAXSIZE-1 caracteres y deja el espacio para '\0'
    fgets(s, MAXSIZE, stdin);
    // Opcionalmente eliminar el salto de línea que fgets puede agregar
    eliminar_salto_linea(s);

    printf("La longitud de la cadena es: %d\n", strlen(s));

    return 0;
}
