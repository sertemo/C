// Problema de la cena de los filósofos
// N >= 2 ( filósofos )
// Si cada filósofo coge un tenedor y es preempted, se produce un deadlock

# include <stdio.h>
# define N 6  // número de filósofos

void Philosopher(int i) {
    while (1) {
        // Pensar
        printf("Filósofo %d pensando\n", i);
        // Coger tenedor izquierdo
        printf("Filósofo %d cogiendo tenedor izquierdo\n", i);
        // Coger tenedor derecho
        printf("Filósofo %d cogiendo tenedor derecho\n", (i + 1) % N);
        // Comer
        printf("Filósofo %d comiendo\n", i);
        // dejar tenedor izquierdo
        printf("Filósofo %d dejando tenedor izquierdo\n", i);
        // dejar tenedor derecho
        printf("Filósofo %d dejando tenedor derecho\n", (i + 1) % N);
    }
}

// Para evitar el deadlock sin usar semáforos (o monitors) hay que asegurarse de que un filósofo coja primero el
// tenedor izquierdo y luego el derecho y el filósofo de al lado primero el tenedor derecho y luego el izquierdo.
// de esta manera el segundo, al no poder coger el tenedor derecho que está en uso, se bloquearía inmediatamente
// y el primer filósofo podría coger el tenedor y seguir el proceso.
// Es decir: LR, LR, LR, LR y RL (el último cambia el patrón para evitar el deadlock)
// Otra forma es que los filósofos pares coja RL y los impares LR

// En otro script se verá la resolución usando Monitors