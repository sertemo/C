// Problema en el que hay multiples writers y readers que quieren acceder a una base de datos
// En este caso está permitido multiples Readers en la DB (Critical Zone) pero no Writers y Readers ni multiples Writers
// Hay que añadir un mecanismo extra al mutex para que solo un writer pueda acceder a la DB
// hay que impedir la starvation de los writers tambien

# include <stdio.h>

typedef struct {
    // Suponiendo que la cola tenga un tamaño fijo
    int items[10];
    int front, rear;
} QueueType;


typedef struct {
    int value;  // Solo puede ser 0 o 1. 0 = bloqueado, 1 = libre
    QueueType L;
} BSEM;

void DOWN(BSEM *sem) {
    if (sem->value == 1) {
        sem->value = 0;  // Tomar el semáforo, bloqueándolo
    } else {
        // Si el semáforo está bloqueado, añadir el proceso a la cola L
        Enqueue(&sem->L, currentProcess);
        Block(currentProcess);
    }
}

void UP(BSEM *sem) {  // UP operation
    if (IsQueueEmpty(&sem->L)) {
        sem->value = 1;  // Liberar el semáforo si no hay procesos esperando
    } else {  // Awake
        // Si hay procesos en espera, desbloquear uno de ellos, value sigue siendo 0 
        ProcessType nextProcess = Dequeue(&sem->L);
        Unblock(nextProcess);
    }
}

int rc = 0;  // Contador de Readers
BSEM mutex = 1;  // Usado por los readers para el readers count rc
BSEM db = 1;  // Usado por Readers y Writers para acceder a la CS de db

void writer(void) {
    while (1) {
        DOWN(&db);
        // escribimos
        printf("Escribiendo en la base de datos\n");
        UP(&db);        
    }
}

void reader(void) {
    while (1) {
        DOWN(&mutex);  // evitamos inconsistencias en rc
        rc++;
        if (rc == 1) DOWN(&db);
        UP(&mutex);
        // Leemos
        printf("Leyendo de la base de datos\n");
        DOWN(&mutex);
        rc--;
        if (rc == 0) UP(&db);  // El último reader desbloquea el lock para que los writers puedan entrar
        UP(&mutex);
    }
}
