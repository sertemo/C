# include <stdio.h>

void func(int a, int *pb) {
    a = 1;
    *pb = 2;
}

int main() {
    int x, y;
    int* px;

    x = 42;
    px = &x;
    y = *px;

    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("&x = %p\n", &x);
    printf("&y = %p\n", &y);
    printf("&px = %p\n", &px);
    printf("px = %p\n", px);
    printf("*px = %d\n", *px);
    /*
    x = 42
    y = 42
    &x = 0x7ffc2b6835e8
    &y = 0x7ffc2b6835ec
    &px = 0x7ffc2b6835f0
    px = 0x7ffc2b6835e8
    \ *px = 42

    Es decir:
    y = x es lo mismo que decir y = *px y es cuando px = $x
    */

    // Seccion
    x = 42;
    y = 43;
    printf("main x=%d y=%d\n", x, y);
    func(x, &y);
    printf("main x=%d y=%d\n", x, y);

    // Seccion
    
    return 0;
}
