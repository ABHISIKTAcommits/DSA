//Program 3: Find the most frequent element and number of times it appears [Day: 1]
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
    int mostFreq = arr[0];
    for (int i = 1; i <= max; i++) {
        if (hash[i] > hash[mostFreq] ||
           (hash[i] == hash[mostFreq] && i < mostFreq)) {
            mostFreq = i;
        }
    }
    printf("Most frequent element: %d\n", mostFreq);
    printf("It appears %d times\n", hash[mostFreq]);
    return 0;
}
