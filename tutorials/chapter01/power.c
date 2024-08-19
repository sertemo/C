// practicar la creación de una función para calcular la potencia de un número

#include <stdio.h>

int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int main(void) {
    int base, exp;
    printf("Enter a base: \n");
    scanf("%d", &base);
    printf("Enter an exponent: \n");
    scanf("%d", &exp);
    printf("%d^%d = %d\n", base, exp, power(base, exp));
    printf("-------------\n");

    for (int i = 0; i < 10; i++) {
        printf("%d^%d = %d\n", base, i, power(base, i));
    }
    return 0;
}
