//code to reverse a number in c [Day 3]

#include <stdio.h>
int main() {
    int n, rem, rev = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    while (n > 0) {              
        rem = n % 10;
        rev = rev * 10 + rem;
        n = n / 10;
    }
    printf("Reversed number: %d\n", rev);
    return 0;
}
