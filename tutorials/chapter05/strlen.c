# include <stdio.h>

// strlen retorna la longitud de un array o string

int strlen_old(char *s) {  // char s[] y char *s son equivalentes
    int i = 0;
    for (i = 0; *s != '\0'; s++);{  // s es un pointer variable y se puede incrementar
        i++;
    }
    return i;
}

// otra versión

int strlen(char *s) {  // char s[] y char *s son equivalentes
    int i = 0;
    while (*s != '\0') {  // o while(*s) ya que '\0' es 0 y saldría del bucle
        s++;
        i++;
    }
    return i;
}