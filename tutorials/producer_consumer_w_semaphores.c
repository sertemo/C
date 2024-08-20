# include <stdio.h>

# define N 100

typedef struct {
    // Suponiendo que la cola tenga un tamaño fijo
    int items[10];
    int front, rear;
} Queuetype;

typedef enum { BINARY, COUNTING } SemaphoreType;

typedef struct {
    SemaphoreType type;  // Identifica si el semáforo es binario o contado
    int value;
    Queuetype L;
} GenericSemaphore;


int buffer[N];  // No hace falta la variable count
GenericSemaphore empty = { COUNTING, N, {{0}, 0, 0}};  // Numero de slots vacíos
GenericSemaphore full = {COUNTING, 0, {{0}, 0, 0}};  // número de slots llenos
GenericSemaphore mutex = {BINARY, 1, {{0}, 0, 0}};  // usado entre producer y consumer para asegurar mutual exclusion

void DOWN(GenericSemaphore *sem) {
    if (sem->type == BINARY) {
        if (sem->value == 1) {
            sem->value = 0;  // Tomar el semáforo binario
        } else {
            Enqueue(&sem->L, currentProcess);
            Block(currentProcess);
        }
    } else if (sem->type == COUNTING) {
        if (sem->value > 0) {
            sem->value--;  // Decrementar el contador
        } else {
            Enqueue(&sem->L, currentProcess);
            Block(currentProcess);
        }
    }
}

void UP(GenericSemaphore *sem) {
    if (IsQueueEmpty(&sem->L)) {
        if (sem->type == BINARY) {
            sem->value = 1;  // Liberar el semáforo binario
        } else if (sem->type == COUNTING) {
            sem->value++;  // Incrementar el contador
        }
    } else {
        ProcessType nextProcess = Dequeue(&sem->L);
        Unblock(nextProcess);
    }
}

// Producer and Consumer
void Producer(void) {
    int itemp, in = 0;
    while (1) {
        // Producimos el item (zona no critica)
        itemp = 42;
        DOWN(&empty.base); DOWN(&mutex.base);  // Entry section. mutex SIEMPRE debe ser la 2da instruccion
        // Ponemos en buffer
        buffer[in] = itemp; in = (in + 1) % N;  // critical section
        UP(&mutex.base); UP(&full.base);  // Exit section
    }
}

void Consumer(void) {
    int itemc, out = 0;
    while (1) {
        // Producimos el item (zona no critica)
        itemc = 42;
        DOWN(&full.base); DOWN(&mutex.base);  // Entry section. mutex SIEMPRE debe ser la 2da instruccion
        // Ponemos en buffer
        buffer[out] = itemc; out = (out + 1) % N;  // critical section
        printf("Consumed %d\n", itemc);
        UP(&mutex.base); UP(&empty.base);  // Exit section
    }
}
