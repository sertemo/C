# include <stdio.h>
# include "myFunctions.h"

# define MAXLINE 1000
# define MAX_CAPACITY 10


int main_1(void) {
    char line[MAXLINE];

    while (get_line(line, MAXLINE) > 0) {
        if (custom_index(line, "the") >= 0) {
            printf("%s\n", line);
        }
    }
}


// Probar push pop clear


int main(void) {
    int stack[MAX_CAPACITY] = {0};

    int i;
    for (i = 0; i < MAX_CAPACITY; i++) {
        push(stack, i);
    }

    print_array(stack);

    for (i = 0; i < 4; i++) {
        printf("Elemento: %d\n", pop(stack));
    }

    print_array(stack);

    printf("Limpiamos el array\n");
    clear(stack);
    print_array(stack);

    return 0;
}
