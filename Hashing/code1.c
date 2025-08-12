// Program 1: Find number of times each element appears in the array [Day: 1] 
#include <stdio.h>
int n = 5;
int main() {
    int arr[n];
    printf("Enter the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    int hash[max + 1];
    for (int i = 0; i <= max; i++)
        hash[i] = 0;
    for (int i = 0; i < n; i++)
        hash[arr[i]]++;
    printf("Number of times each element appears:\n");
    for (int i = 0; i <= max; i++) {
        if (hash[i] > 0)
            printf("%d appears %d times\n", i, hash[i]);
    }
    return 0;
}