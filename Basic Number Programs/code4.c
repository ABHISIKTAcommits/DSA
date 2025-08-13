//Check Armstrong number in c [Day 5]

#include <stdio.h>

int main() {
    int num, temp, rem, digits = 0, sum = 0, i;
    printf("Enter a number: ");
    scanf("%d", &num);
    temp = num;
    while (temp > 0) {
        temp /= 10;
        digits++;
    }
    temp = num;
    while (temp > 0) {
        rem = temp % 10;
        int power = 1;  
        for (i = 0; i < digits; i++) {
            power *= rem;
        }
        sum += power;
        temp /= 10;
    }
    if (sum == num)
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);
    return 0;
}
