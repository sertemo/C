#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int x = 5; 
    int y = 10;

    printf("Antes de swap: x = %d, y = %d\n", x, y);

    swap(&x, &y);  // Pasar las direcciones de memoria  de x e y a la función

    printf("Después de swap: x = %d, y = %d\n", x, y);

    return 0;
}
