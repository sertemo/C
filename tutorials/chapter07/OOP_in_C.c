# include <stdio.h>
# include <stdlib.h>
# include <math.h>

// Vamos a construir un objeto tipo Punto en C, simulando Python

struct Point {
    double x;
    double y;

    void (*del)(const struct Point* self);  // las definimos como punteros a funciones que aceptan el parámetro self que es un puntero a un Point
    void (*dump)(const struct Point* self);
    double (*origin)(const struct Point* self);  // Es un puntero a una función en alguna parte, que devuelve un 'double'
};

void point_dump(const struct Point* self) {  // una especie de repr
    printf("Object point@%p x: %f, y: %f\n", self, self->x, self->y);
};

void point_del(const struct Point* self) {  // una especie de del
    free((void *) self);
};

double point_origin(const struct Point* self) {  // un método para calcular el origen
    return sqrt(pow(self->x, 2) + pow(self->y, 2));
};

struct Point* point_new(double x, double y) {  // una especie de inicializador
    struct Point *p = malloc(sizeof(struct Point));
    p->x = x;
    p->y = y;
    p->del = &point_del;
    p->dump = &point_dump;
    p->origin = &point_origin;
    return p;
};

int main(void) {
    struct Point *pt = point_new(3.2, 4.7);

    pt->dump(pt);
    printf("Origin: %f\n", pt->origin(pt));
    printf("Size of *pt: %ld\n", sizeof(*pt));
    printf("Size of pt: %ld\n", sizeof(pt));

    pt->del(pt);

    return 0;
}

