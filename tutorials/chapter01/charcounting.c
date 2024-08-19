#include <stdio.h>

int CountCharsPointer(char *ch) {
    // Cuenta los caracteres de un string pasandole un puntero
    int count = 0;
    while (*ch != '\0') {
        count++;
        ch++;
    }
    return count;
    
}

int CountCharsArray(char ch[]) {
    int count = 0;
    while (ch[count] != '\0') {
        count++;
    }
    return count;
}


int main(void) {
    
    printf("Enter a string: \n");
    char ch[100];
    scanf("%100s", ch);
    printf("The number of characters is: %d\n", CountCharsArray(ch));
    
    return 0;
}