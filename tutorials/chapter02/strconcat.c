// Concatena dos strings en el primero

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

void strconcat(char s1[], char s2[]) {
    int i = 0;
    // llegamos al final del primer string
    while (s1[i] != '\0') {
        i++;
    }
    int j = 0;
    while (s2[j] != '\0') {
        s1[i] = s2[j];  // también podríamos poner s1[i++] = s2[j++]
        i++;
        j++;
    }
    s1[i] = '\0';
}

int main(void) {
    char s1[MAXSIZE];
    char s2[MAXSIZE];
    printf("Escribe una cadena de caracteres: ");
    fgets(s1, MAXSIZE, stdin);
    // Opcionalmente eliminar el salto de línea que fgets puede agregar
    eliminar_salto_linea(s1);
    printf("Escribe otra cadena de caracteres: ");
    fgets(s2, MAXSIZE, stdin);
    // Opcionalmente eliminar el salto de línea que fgets puede agregar
    eliminar_salto_linea(s2);
    strconcat(s1, s2);
    printf("La cadena concatenada es: %s\n", s1);
    return 0;
}