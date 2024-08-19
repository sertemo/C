#include <stdio.h>
#include <stdlib.h> // Incluye stdlib.h para usar exit()

int mymult(int a, int b) {
    int c = a * b;
    return c;
}

int check_result(int result) {
    // chequea que se haya introducido un número
    if (result != 1) {
        printf("Por favor, introduce un número\n");
        return 1;
    }
    return 0;
}

int main(void) {
    int mult1;
    int mult2;
    int result;

    printf("Escribe dos números para multiplicar\n");

    // Primer número
    printf("Primer número:\n");
    result = scanf("%d", &mult1);
    if (check_result(result)) {
        exit(1); // Termina el programa si la entrada no es válida
    }

    // Segundo número
    printf("Segundo número:\n");
    result = scanf("%d", &mult2);
    if (check_result(result)) {
        exit(1); // Termina el programa si la entrada no es válida
    }

    // Multiplicación
    int z = mymult(mult1, mult2);
    printf("%d * %d = %d\n", mult1, mult2, z);
    return 0;
}