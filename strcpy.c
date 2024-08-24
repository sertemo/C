# include <stdio.h>

void strcpy(char *dest, char *src) {
    while ((*dest = *src) != '\0') {  // es redundante
        dest++;
        src++;
    }
    *dest = '\0';
}

// otra versión
void strcpy(char *dest, char *src) {
    while ((*dest++ = *src++));
}
