// Definición de funciones para insertar en una pila

# include <stdio.h>
# define MAX_CAPACITY 100

int ps = 0;

void clear(int stack[]) {
    ps = 0;
}

int push(int stack[], int item) {
    if (ps < MAX_CAPACITY) {
        stack[ps++] = item;
        return 1;
    }
    else {
        printf("Stack overflow\n");
        clear(stack);
        return 0;
    }
}

int pop(int stack[]) {
    if (ps > 0) {
        return stack[--ps];
    }
    else {
        printf("Stack underflow\n");
        return 0;
    }
}


void print_array(int stack[]) {
    int i;
    for (i = 0; i < ps; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}