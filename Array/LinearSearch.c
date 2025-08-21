// Program to perform Linear Search [Day: 28]

#include <stdio.h>

void ls(int arr[], int n, int s) {
    int found = 0;  
    for (int i = 0; i < n; i++) {
        if (arr[i] == s) {
            printf("Element %d is present at position: %d\n", s, i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d is not present in the array.\n", s);
    }
}

int main() {
    int n, s;
    printf("Enter the array size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to be searched: ");
    scanf("%d", &s);

    printf("Array entered by you is:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    ls(arr, n, s);

    return 0;
}
