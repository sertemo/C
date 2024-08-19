#include <stdio.h>

int main(void) {
    int number;

    while (1) {  // Bucle infinito
        printf("Introduce un número (introduce un número negativo para salir): ");
        scanf("%d", &number);

        if (number < 0) {
            break;  // Salir del bucle si el número es negativo
        }

        printf("Has introducido: %d\n", number);
    }

    printf("Programa terminado.\n");

    return 0;
}

