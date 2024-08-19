// Implementación del problema de consumidor productor con Lock variable
// NO se garantiza la mutual exclusion si hay premature preemption en uno de los procesos
// NO bloquea el progreso
// Es una solución multiproceso

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

int buffer[BUFFER_SIZE];
int count = 0;
int lock = 0;  // Lock variable -> Busy waiting solution

void producer(void) {
    int itemp;
    while (1) {
        // El productor produce un item
        itemp = rand() % 100;
        printf("Producer produces item %d\n", itemp);
        // Esperamos si el buffer está lleno
        while (count == BUFFER_SIZE) {
            printf("Buffer is full. Producer is waiting.\n");
        }
        // Chequeamos el lock
        while (lock == 1) {
            printf("Buffer is locked. Producer is waiting.\n");
        }
        lock = 1;
        // Insertamos el item en el buffer (critical section)
        buffer[count] = itemp;
        count++;
        lock = 0;
        printf("Producer inserts item %d\n", itemp);  
    }
}

void consumer(void) {
    int itemc;
    while (1) {
        // El consumidor extrae un item si el buffer no está vacío
        while (count == 0) {
            printf("Buffer is empty. Consumer is waiting.\n");
        }
        // verificamos el lock
        while (lock == 1) {
            printf("Buffer is locked. Consumer is waiting.\n");
        }
        lock = 1;
        // extraemos un item (critical section)
        itemc = buffer[--count];
        lock = 0;
        printf("Consumer consumes item %d\n", itemc);
    }
}
