# include <stdio.h>
# include <stdlib.h>

struct Point
{
    double x;
    double y;
};

int main()
{
    struct Point p1, *pp;

    printf("sizeof p1 %ld\n", sizeof(p1));
    printf("sizeof pp %ld\n", sizeof(pp));
    printf("sizeof point %ld\n", sizeof(struct Point));

    p1.x = 10.8;
    p1.y = 20.2;
    printf("p1.x = %f\n", p1.x);
    printf("p1.y = %f\n", p1.y);

    // Memoria dinámica

    pp = (struct Point *) malloc(sizeof(struct Point));  // Busca en memoria 16 bytes de espacio y devuelve un puntero a ese espacio
    pp->x = 10.8;
    pp->y = 20.2;
    printf("pp->x = %f\n", pp->x);
    printf("pp->y = %f\n", pp->y);
    free(pp);

    return 0;
}