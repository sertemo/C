#include <stdio.h>

int main(void) {
    char name[5];
    printf("Enter your name: \n");
    scanf("%5s", name);
    printf("Your name is: %s\n", name);
    return 0;
}