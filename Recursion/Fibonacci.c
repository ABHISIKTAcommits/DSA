// Program to perform Fibonacci number check in C [Day: 18]

#include <stdio.h>

int fibo(int n) {
    if(n <= 2)
        return 1;
    else
        return (fibo(n-1) + fibo(n-2));
}

int main() {
    int n, res;
    printf("Enter n value: ");
    scanf("%d", &n);

    res = fibo(n);
    printf("The %dth Fibonacci number is: %d\n", n, res);

    return 0;
}
