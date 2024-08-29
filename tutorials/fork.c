#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        // Este es el proceso hijo
        printf("Hello from the child process!\n");
    } else if (pid > 0) {
        // Este es el proceso padre
        printf("Hello from the parent process!\n");
    } else {
        // Ocurrió un error
        perror("fork");
        return 1;
    }

    return 0;
}
