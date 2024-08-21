# include <stdio.h>

/* Explorando
el uso de 'register' para ver código ensamblador
Las variables declaradas con register se almacenan
en el registro de la CPU, siendo accesibles mucho más
rapido que desde memoria RAM

gcc -S prueba_assembly_code.c -o prueba_assembly*/

int main(void) {

    int compute;
    register int iter;

    scanf("%d", &compute);
    printf("Compute: %d\n", compute);
    for (iter = 0; iter < 1000; iter++) {
        compute = (compute * 22) * 7;
        if (compute > 1000) {
            compute = compute % 1000;
        }
    }
    printf("Compute: %d\n", compute);
    return 0;
}