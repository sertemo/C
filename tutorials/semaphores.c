// Counting Sempahores y Binary Semaphores

# include <stdio.h>

typedef struct {
    int value;
    Queuetype L;  // Lista de items en espera o bloqueados cuando el value es negativo
} CSEM;  // CountingSEMaphore

void P(CSEM *sem) {  // Hace una DOWN operation añadiendo a cola si value es negativo
    sem->value--;  // accede a value: es como sem.value pero para punteros
    if (sem->value < 0) {
        // Bloquear proceso y añadirlo a la cola L
        Enqueue(&sem->L, currentProcess);
        Block(currentProcess);
    }
}

void V(CSEM *sem) {  // Hace una UP operation quitando de la cola si value es positivo
    sem->value++;
    if (sem->value <= 0) {
        // Desbloquear proceso de la cola L
        ProcessType nextProcess = Dequeue(&sem->L);  // awake
        Unblock(nextProcess);
    }
}

// Binary Semaphore
// Los valores de un Binary Semaphore pueden ser 0 o 1. no hay valores negativos de value

typedef struct {
    int value;  // Solo puede ser 0 o 1. 0 = bloqueado, 1 = libre
    Queuetype L;
} BSEM;

// User Mode -> inicializamos el Binary Semaphore

void P(BSEM *sem) {
    if (sem->value == 1) {
        sem->value = 0;  // Tomar el semáforo, bloqueándolo
    } else {
        // Si el semáforo está bloqueado, añadir el proceso a la cola L
        Enqueue(&sem->L, currentProcess);
        Block(currentProcess);
    }
}

void V(BSEM *sem) {  // UP operation
    if (IsQueueEmpty(&sem->L)) {
        sem->value = 1;  // Liberar el semáforo si no hay procesos esperando
    } else {  // Awake
        // Si hay procesos en espera, desbloquear uno de ellos, value sigue siendo 0 
        ProcessType nextProcess = Dequeue(&sem->L);
        Unblock(nextProcess);
    }
}

int main() {
    BSEM sem;
    sem.value = 1;  // Inicializar el semáforo a 1 (recurso disponible)
    // Resto del código...
    return 0;
}

// Como no toma valores negativos, no podemos saber cuantos procesos bloqueados hay en la cola