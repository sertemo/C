#include <stdio.h>

int binary(int x, int v[], int n) {/* find x in v[0] ... v[n-1] */
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low+high) / 2;
        if (x < v[mid])
        high = mid - 1;
        else if (x > v[mid])
        low = mid + 1;
        else /* found match */
        return (mid);
    }
    return -1;
}

void main(void) {
    int v[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    printf("Escibe un numero entero: \n");
    int x;
    scanf("%d", &x);
    int i = binary(x, v, 10);
    if (i == -1)
    printf("No se encontro el elemento\n");
    else
    printf("Se encontro el elemento en la posicion %d\n", i);
}