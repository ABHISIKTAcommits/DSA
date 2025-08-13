// Program to print name N times in c [Day: 9]

#include <stdio.h>

void printName(char name[], int count, int n) {
    if (count > n)  
        return;
    printf("%s\n", name); 
    printName(name, count + 1, n);
}

int main() {
    char name[50];
    int times;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter how many times to print your name: ");
    scanf("%d", &times);
    printName(name, 1, times);
    return 0;
}
