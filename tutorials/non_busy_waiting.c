// El busy waiting se daba cuando se usa while en la entry condition a la zona critica
// Pero esta situación no es ideal ya que se chequea la condición una y otra vez
// Es mejor usar if-then-else para chequear la condición una sola vez y si la CS está ocupada,
// El proceso abandona la CPU.
// Los mecanismos son: sleep & wakeup, Semaphores, Monitors

// Sleep & wakeup
// Es multiproceso
// No preemptive
// Existe una sleep Queue
// Convertimos el problema producer - consumer en un problema sin busy waiting
// El producer despierta al consumer cuando el primer item es insertado en la Queue
// El consumer despierta al producer cuando un item es consumido del buffer LLENO

# include <stdio.h>

# define N 100

int buffer[N];
int count = 0;

void Producer(void) {
    int itemp, in = 0;  // in es el index del siguiente slot vacío
    while (1) {
        // Producimos un item
        itemp = "item";
        // Chequeamos si el buffer está lleno, si lo está dormimos
        if (count == N) {
            sleep();
        }
        // Insertamos el item
        buffer[in] = itemp;
        in = (in + 1) % N;
        count++;
        if (count == 1) {
            wakeup(Consumer);  // despertamos al Consumer cuando el primer item es insertado
        }
    }
}

void Consumer(void) {
    int itemc, out = 0;  // out es el index del siguiente slot vacío
    while (1) {
        if (count == 0) {
            sleep();
        }
        itemc = buffer[out];
        out = (out + 1) % N;
        count--;
        if (count == N - 1) {
            wakeup(Producer);
        }
        // Consumimos el item
        printf("Consumiendo el item %d\n", itemc);
    }
}

// Puede pasar en caso de preemtion despues del if, que ambos acaben durmiendo
// También puede haber race condition en la variable count
// La solución => SEMAPHORES
// Los Semaphores son lo que habitualmente se usa
// Son componentes del Kernel de OS => Operaciones atómicas por naturaleza (no preemptive)
// Implementada como un abstract data type (ADT)
// Down y Up
// General Semaphores (Counting semaphores) => La variable puede tomar en -inf y inf valores