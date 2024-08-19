# include <stdio.h>
# include "functions.h"

# define MAXLINE 1000


int main(void) {
    char line[MAXLINE];

    while (get_line(line, MAXLINE) > 0) {
        if (custom_index(line, "the") >= 0) {
            printf("%s\n", line);
        }
    }
}

