#include <stdio.h>

int es_par(int x) {
    return x % 2 == 0;
}

int main(void) {
    int i;
    printf("Escribe un numero: ");
    scanf("%d", &i);   

    if (es_par(i)) {
        printf("El numero es par\n");
    } else {
        printf("El numero es impar\n");
    }
}