//count the number of digits in a number [Day 2]

#include <stdio.h>
int main() {
    int num, count = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    while (num > 0) {     
        num = num / 10;   
        count++;           
    }
    printf("Number of digits: %d\n", count);
    return 0;
}
