// algoritmo para ordenar un array de enteros
#include <stdio.h>
#define N 10

void sort(int v[]) {
    int i, j, aux;
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            if (v[i] > v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

void print_array(int v[]) {
    for (int i = 0; i < N; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(void) {
    int v[N] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    
    // Mostramos el array original por terminal
    printf("Array original: \n");
    print_array(v);
    
    // Ordenamos el array
    printf("Array ordenado: \n");
    sort(v);
    print_array(v);
    
    return 0;
}

