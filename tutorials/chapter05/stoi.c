# include <stdio.h>

int stoi(char *s) {
    int resultado = 0;
    char c;
    while (c = *s) {
        if (c < '0' || c > '9') {
            return -1;
        }
        resultado = resultado * 10 + (c - '0');
        s++;
    }
    return resultado;
}