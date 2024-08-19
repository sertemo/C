# include <stdio.h>

int fibo(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibo(n - 1) + fibo(n - 2);
    }
}

int main(void) {
    int i;
    printf("Enter a number: ");
    scanf("%d", &i);
    printf("Fibonacci(%d) = %d\n", i, fibo(i));
    return 0;
}   
