#include <stdio.h>

int main(void) {
    char line[1000];
    FILE *hand;
    hand = fopen("romeo.txt", "r");

    while (fgets(line, 1000, hand) != NULL) {
        printf("%s", line);
    }
    fclose(hand);
    return 0;
}