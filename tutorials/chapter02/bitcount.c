
#include <stdio.h>


void int_to_binary(int n, char *binary_str) {
    int i;
    int num_bits = sizeof(int) * 8; // Número de bits en un int

    for (i = num_bits - 1; i >= 0; i--) {
        int bit = (n >> i) & 1; // Desplazar y obtener el bit menos significativo
        binary_str[num_bits - 1 - i] = bit ? '1' : '0';
    }

    binary_str[num_bits] = '\0'; // Terminar la cadena con carácter nulo
}

int bitcount(unsigned x)
{
    int b = 0;
    while (x != 0)
    {
        if (x & 1)
            b++;
        x >>= 1;
    }
    return b;
}

int main(void) {
    printf("Enter an integer: \n");
    int n;
    scanf("%d", &n);
    char binary_str[33];
    int_to_binary(n, binary_str);
    printf("Binary representation: %s\n", binary_str);
    printf("Bit count: %d\n", bitcount(n));
    return 0;
}