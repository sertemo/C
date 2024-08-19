#include <stdio.h>
#define MAXSIZE 100



void lowercase(char s[MAXSIZE], char z[MAXSIZE]) {
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            z[i] = s[i] + 32;
        } else {
            z[i] = s[i];
        }
        i++;
    }
    z[i] = '\0';
}

int main(void) {
    char s[MAXSIZE];
    char z[MAXSIZE];

    printf("Escribe una cadena de caracteres en mayúsculas: ");
    fgets(s, MAXSIZE, stdin);

    lowercase(s, z);

    printf("La cadena en minúsculas es: %s\n", z);
    return 0;
}