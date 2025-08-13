//Check Palindrome number in c [Day 4]

#include <stdio.h>

void palindrome(int num) {
    int n, rev = 0, rem;
    n = num;
    while (num > 0) {
        rem = num % 10;
        rev = rev * 10 + rem;
        num = num / 10;
    }
    if (n == rev)
        printf("Palindrome\n");
    else
        printf("Not palindrome\n");
}

int main() {
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    palindrome(a);
    return 0;
}
