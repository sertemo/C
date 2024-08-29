#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int *ptr = malloc(sizeof(int));  // Asignamos memoria para un entero
    *ptr = 42;  // Inicializamos el valor

    printf("Original value in parent process: %d\n", *ptr);

    int f = fork();

    if (f == 0) {
        // Este es el proceso hijo
        printf("Child process sees value: %d\n", *ptr);
        *ptr = 99;  // Cambiamos el valor en el proceso hijo
        printf("Child process changed value to: %d\n", *ptr);
    } else if (f > 0) {
        // Este es el proceso padre
        sleep(1);  // Dormimos el proceso padre para asegurar que el hijo cambie el valor primero
        printf("Parent process sees value after fork: %d\n", *ptr);
    } else {
        // Ocurrió un error
        perror("fork");
        return 1;
    }

    free(ptr);  // Liberamos la memoria
    return 0;
}

/*
Después de fork(), tanto el proceso padre como el proceso hijo 
tendrán punteros que apuntan a la misma dirección de memoria, 
pero en sus respectivos espacios de memoria. Cualquier cambio en la memoria 
por parte del proceso hijo no afectará al proceso padre y viceversa.

OUTPUT:
Original value in parent process: 42
Child process sees value: 42
Child process changed value to: 99
Parent process sees value after fork: 42*/