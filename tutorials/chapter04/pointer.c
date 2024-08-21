# include <stdio.h>

int suma_3_val(int num) {
    num += 3;
    return num;
}

int suma_3_ptr(int *num) {
    *num += 3;
    return *num;
}

int main(void) {
    printf("Escribe un numero: ");
    int num;
    scanf("%d", &num);
    int resultado_valor = suma_3_val(num);
    printf("%d + 3 (por valor) = %d\n", num, resultado_valor);
    printf("Variable num: %d\n", num);
    suma_3_ptr(&num);
    printf("Resultado (por puntero) = %d\n", num);
    printf("Variable num: %d\n", num);

    return 0;
}