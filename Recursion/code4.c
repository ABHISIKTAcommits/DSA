// Program to print number 1 to n in c [Day: 10]

#include <stdio.h>

void printNumbers(int current, int n) {
    if (current > n) 
        return;
    printf("%d ", current); 
    printNumbers(current + 1, n); 
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printNumbers(1, n);
    return 0;
}
