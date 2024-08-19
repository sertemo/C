#include <stdio.h>

int main(void) {
    int guess;
    int result;

    while (1) {
        printf("Guess the number: ");
        result = scanf("%d", &guess);

        if (result == 1) {            
            if (guess == 42) {
                printf("Good job!\n");
                break;
            } else if (guess < 42) {
                printf("Too low\n");
            } else {
                printf("Too high\n");
            }
        } else {
            // La entrada no fue un entero, limpiar la entrada
            printf("Please enter a valid integer.\n");
            while (getchar() != '\n'); // Descartar la entrada inválida
        }

    }
    return 0;
}