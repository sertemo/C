#include <stdio.h>
#define N 100

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
    printf("Enter an array: \n");
    char a[N];
    fgets(a, N, stdin);
    // Opcionalmente eliminar el salto de línea que fgets puede agregar
    eliminar_salto_linea(a);
    int i;
    for (i = 0; i < N; i++){
        printf("%c%c", a[i], (i % 10 == 9 || i == N - 1) ? '\n' : ' ');
    }
    return 0;
}