#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h>

int main() {
    int i, n;
    n = 10;
    for (i = 0; i < n; i++) {
        if (fork() == 0);
            printf("*");  // No está en el for loop
    }
}
