#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h>

int main()
{
    int a = 5, b = 3, c;
    c = ++a * b++;  // Primero incrementa a (a=6), luego multiplica por b (c=18), y finalmente incrementa b (b=4)
    printf("[MAIN] a=%d, b=%d, c=%d\n", a, b, c);

    int f = fork();  // Crea un nuevo proceso

    if (f == 0) {  // Código ejecutado por el proceso hijo
        a = a + 5;  // a = 6 + 5 = 11
        b = b + 3;  // b = 4 + 3 = 7
        printf("[CHILD] a=%d, b=%d\n", a, b);
    }
    else {  // Código ejecutado por el proceso padre
        b += a += 2;  // a = a + 2 = 8, luego b = b + a = 4 + 8 = 12
        printf("[PARENT] a=%d, b=%d\n", a, b);
        c = c - 1;  // c = 18 - 1 = 17
    }

    printf("[MAIN] c=%d\n", c);
    return 0;
}

/*
Nota: Un child creado a partir de un child sigue siendo un child. Solo hay 1 parent
[MAIN] a=6, b=4, c=18
[PARENT] a=8, b=12
[MAIN] c=17
[CHILD] a=11, b=7
[MAIN] c=18
*/