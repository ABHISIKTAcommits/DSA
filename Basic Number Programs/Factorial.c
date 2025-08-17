// Program to perform Factorial of a number in C [Day: 19]

#include <stdio.h>

int fact(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Factorial = %d\n", fact(n));
    return 0;
}
