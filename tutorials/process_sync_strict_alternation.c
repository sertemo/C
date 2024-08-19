// Implementación del problema de consumidor productor con strict alternation
// Valido solo para 2 procesos

// Uninterested process bloquea a interested process (que quiere ir a la misma sección critica)
// Unbounded waiting
// Bloquea el progreso
// SÍ garantiza la mutual exclusion

#include <stdio.h>

int turn;

// Process1 espera si el turno es 1. Actua con turno 0

void Process0(void) {
    while (1) {
        // Acciones no criticas
        printf("Process 0 executes Non Critical Actions.\n");
        while (turn == 1) {
            printf("Process 0 is waiting.\n");
        }
        // Acciones criticas
        printf("Process 0 executes Critical Actions.\n");
        turn = 1;
    }
}

void Process1(void) {
    while (1) {
        // Acciones no criticas
        printf("Process 1 executes Non Critical Actions.\n");
        while (turn == 0) {
            printf("Process 1 is waiting.\n");
        }
        // Acciones criticas
        printf("Process 1 executes Critical Actions.\n");
        turn = 0;
    }
}